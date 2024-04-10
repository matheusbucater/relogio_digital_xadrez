################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/Src/app.c \
../App/Src/button.c \
../App/Src/buzzer.c \
../App/Src/display.c \
../App/Src/game.c \
../App/Src/player.c \
../App/Src/timer.c \
../App/Src/tm1637.c 

OBJS += \
./App/Src/app.o \
./App/Src/button.o \
./App/Src/buzzer.o \
./App/Src/display.o \
./App/Src/game.o \
./App/Src/player.o \
./App/Src/timer.o \
./App/Src/tm1637.o 

C_DEPS += \
./App/Src/app.d \
./App/Src/button.d \
./App/Src/buzzer.d \
./App/Src/display.d \
./App/Src/game.d \
./App/Src/player.d \
./App/Src/timer.d \
./App/Src/tm1637.d 


# Each subdirectory must supply rules for building sources it contributes
App/Src/%.o App/Src/%.su App/Src/%.cyclo: ../App/Src/%.c App/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../App/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-App-2f-Src

clean-App-2f-Src:
	-$(RM) ./App/Src/app.cyclo ./App/Src/app.d ./App/Src/app.o ./App/Src/app.su ./App/Src/button.cyclo ./App/Src/button.d ./App/Src/button.o ./App/Src/button.su ./App/Src/buzzer.cyclo ./App/Src/buzzer.d ./App/Src/buzzer.o ./App/Src/buzzer.su ./App/Src/display.cyclo ./App/Src/display.d ./App/Src/display.o ./App/Src/display.su ./App/Src/game.cyclo ./App/Src/game.d ./App/Src/game.o ./App/Src/game.su ./App/Src/player.cyclo ./App/Src/player.d ./App/Src/player.o ./App/Src/player.su ./App/Src/timer.cyclo ./App/Src/timer.d ./App/Src/timer.o ./App/Src/timer.su ./App/Src/tm1637.cyclo ./App/Src/tm1637.d ./App/Src/tm1637.o ./App/Src/tm1637.su

.PHONY: clean-App-2f-Src

