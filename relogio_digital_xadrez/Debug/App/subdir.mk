################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/app.c \
../App/button.c \
../App/display.c \
../App/game.c \
../App/player.c \
../App/timer.c \
../App/tm1637.c 

OBJS += \
./App/app.o \
./App/button.o \
./App/display.o \
./App/game.o \
./App/player.o \
./App/timer.o \
./App/tm1637.o 

C_DEPS += \
./App/app.d \
./App/button.d \
./App/display.d \
./App/game.d \
./App/player.d \
./App/timer.d \
./App/tm1637.d 


# Each subdirectory must supply rules for building sources it contributes
App/%.o App/%.su App/%.cyclo: ../App/%.c App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../App -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-App

clean-App:
	-$(RM) ./App/app.cyclo ./App/app.d ./App/app.o ./App/app.su ./App/button.cyclo ./App/button.d ./App/button.o ./App/button.su ./App/display.cyclo ./App/display.d ./App/display.o ./App/display.su ./App/game.cyclo ./App/game.d ./App/game.o ./App/game.su ./App/player.cyclo ./App/player.d ./App/player.o ./App/player.su ./App/timer.cyclo ./App/timer.d ./App/timer.o ./App/timer.su ./App/tm1637.cyclo ./App/tm1637.d ./App/tm1637.o ./App/tm1637.su

.PHONY: clean-App

