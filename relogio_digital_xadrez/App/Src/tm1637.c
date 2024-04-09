#include "tm1637.h"


void _tm1637Start(tm1637_t display);
void _tm1637Stop(tm1637_t display);
void _tm1637ReadResult(tm1637_t display);
void _tm1637WriteByte(tm1637_t display, unsigned char b);
void _tm1637DelayUsec(unsigned int i);
void _tm1637ClkHigh(tm1637_t display);
void _tm1637ClkLow(tm1637_t display);
void _tm1637DioHigh(tm1637_t display);
void _tm1637DioLow(tm1637_t display);

const char segmentMap[] = {
    0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, // 0-7
    0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71, // 8-9, A-F
    0x00
};


void tm1637Init(tm1637_t* display, GPIO_TypeDef* clk_port, GPIO_TypeDef* dio_port, uint16_t clk_pin, uint16_t dio_pin)
{
	display->clk_port = clk_port;
	display->dio_port = dio_port;
	display->clk_pin = clk_pin;
	display->dio_pin = dio_pin;
}

void tm1637DisplayDecimal(tm1637_t display, int v, int displaySeparator)
{
    unsigned char digitArr[4];
    for (int i = 0; i < 4; ++i) {
        digitArr[i] = segmentMap[v % 10];
        if (i == 2 && displaySeparator) {
            digitArr[i] |= 1 << 7;
        }
        v /= 10;
    }

    _tm1637Start(display);
    _tm1637WriteByte(display, 0x40);
    _tm1637ReadResult(display);
    _tm1637Stop(display);

    _tm1637Start(display);
    _tm1637WriteByte(display, 0xc0);
    _tm1637ReadResult(display);

    for (int i = 0; i < 4; ++i) {
        _tm1637WriteByte(display, digitArr[3 - i]);
        _tm1637ReadResult(display);
    }

    _tm1637Stop(display);
}

// Valid brightness values: 0 - 8.
// 0 = display off.
void tm1637SetBrightness(tm1637_t display, char brightness)
{
    // Brightness command:
    // 1000 0XXX = display off
    // 1000 1BBB = display on, brightness 0-7
    // X = don't care
    // B = brightness
    _tm1637Start(display);
    _tm1637WriteByte(display, 0x87 + brightness);
    _tm1637ReadResult(display);
    _tm1637Stop(display);
}

void _tm1637Start(tm1637_t display)
{
    _tm1637ClkHigh(display);
    _tm1637DioHigh(display);
    _tm1637DelayUsec(2);
    _tm1637DioLow(display);
}

void _tm1637Stop(tm1637_t display)
{
    _tm1637ClkLow(display);
    _tm1637DelayUsec(2);
    _tm1637DioLow(display);
    _tm1637DelayUsec(2);
    _tm1637ClkHigh(display);
    _tm1637DelayUsec(2);
    _tm1637DioHigh(display);
}

void _tm1637ReadResult(tm1637_t display)
{
    _tm1637ClkLow(display);
    _tm1637DelayUsec(5);
    // while (dio); // We're cheating here and not actually reading back the response.
    _tm1637ClkHigh(display);
    _tm1637DelayUsec(2);
    _tm1637ClkLow(display);
}

void _tm1637WriteByte(tm1637_t display, unsigned char b)
{
    for (int i = 0; i < 8; ++i) {
        _tm1637ClkLow(display);
        if (b & 0x01) {
            _tm1637DioHigh(display);
        }
        else {
            _tm1637DioLow(display);
        }
        _tm1637DelayUsec(3);
        b >>= 1;
        _tm1637ClkHigh(display);
        _tm1637DelayUsec(3);
    }
}

void _tm1637DelayUsec(unsigned int i)
{
    for (; i>0; i--) {
        for (int j = 0; j < 10; ++j) {
            __asm__ __volatile__("nop\n\t":::"memory");
        }
    }
}

void _tm1637ClkHigh(tm1637_t display)
{
    HAL_GPIO_WritePin(display.clk_port, display.clk_pin, GPIO_PIN_SET);
}

void _tm1637ClkLow(tm1637_t display)
{
    HAL_GPIO_WritePin(display.clk_port, display.clk_pin, GPIO_PIN_RESET);
}

void _tm1637DioHigh(tm1637_t display)
{
    HAL_GPIO_WritePin(display.dio_port, display.dio_pin, GPIO_PIN_SET);
}

void _tm1637DioLow(tm1637_t display)
{
    HAL_GPIO_WritePin(display.dio_port, display.dio_pin, GPIO_PIN_RESET);
}
