################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Source_Simulink/Controller/Controller.c \
../Drivers/Source_Simulink/Controller/Controller_Decoder.c \
../Drivers/Source_Simulink/Controller/Controller_Gates.c 

OBJS += \
./Drivers/Source_Simulink/Controller/Controller.o \
./Drivers/Source_Simulink/Controller/Controller_Decoder.o \
./Drivers/Source_Simulink/Controller/Controller_Gates.o 

C_DEPS += \
./Drivers/Source_Simulink/Controller/Controller.d \
./Drivers/Source_Simulink/Controller/Controller_Decoder.d \
./Drivers/Source_Simulink/Controller/Controller_Gates.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Source_Simulink/Controller/%.o: ../Drivers/Source_Simulink/Controller/%.c Drivers/Source_Simulink/Controller/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"D:/BLDC/BSW/bldc_stm32/Drivers/Source_Simulink/CalibAdc" -I"D:/BLDC/BSW/bldc_stm32/Drivers/Source_Simulink/StateControl" -I"D:/BLDC/BSW/bldc_stm32/Drivers/Source_Simulink/Protection" -I"D:/BLDC/BSW/bldc_stm32/Drivers/Source_Simulink/BLDC_MOTOR_ASW" -I"D:/BLDC/BSW/bldc_stm32/Drivers/Source_Simulink" -I"D:/BLDC/BSW/bldc_stm32/Drivers/Source_Simulink/Controller" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

