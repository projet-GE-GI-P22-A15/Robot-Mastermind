################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Robot-code/main.cpp \
../Robot-code/pid.cpp \
../Robot-code/rotation.cpp \
../Robot-code/valeurs.cpp 

OBJS += \
./Robot-code/main.o \
./Robot-code/pid.o \
./Robot-code/rotation.o \
./Robot-code/valeurs.o 

CPP_DEPS += \
./Robot-code/main.d \
./Robot-code/pid.d \
./Robot-code/rotation.d \
./Robot-code/valeurs.d 


# Each subdirectory must supply rules for building sources it contributes
Robot-code/%.o: ../Robot-code/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking ARM-Linux C++ Compiler'
	arm-softfloat-linux-gnueabi-g++ -c -I"C:/Program Files (x86)/Armus/ArmusIDE/librairie/lib" -I"D:\Documents\Genie\S1\Projet session\ArmusIDE\Robot-MasterMind\Robot-code" -I"C:/Program Files (x86)/Armus/ArmusIDE/librairie/include" -ggdb --sysroot="C:/Program Files (x86)/Armus/ArmusIDE/toolchain/sysroot" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


