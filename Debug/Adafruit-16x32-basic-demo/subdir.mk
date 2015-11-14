################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Adafruit-16x32-basic-demo/main.cpp 

OBJS += \
./Adafruit-16x32-basic-demo/main.o 

CPP_DEPS += \
./Adafruit-16x32-basic-demo/main.d 


# Each subdirectory must supply rules for building sources it contributes
Adafruit-16x32-basic-demo/%.o: ../Adafruit-16x32-basic-demo/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking ARM-Linux C++ Compiler'
	arm-softfloat-linux-gnueabi-g++ -c -I"C:/Program Files (x86)/Armus/ArmusIDE/librairie/lib" -I"D:\Documents\Genie\S1\Projet session\ArmusIDE\Robot-MasterMind\Robot-code" -I"C:/Program Files (x86)/Armus/ArmusIDE/librairie/include" -ggdb --sysroot="C:/Program Files (x86)/Armus/ArmusIDE/toolchain/sysroot" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


