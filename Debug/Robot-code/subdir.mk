################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Robot-code/capteurs.cpp \
../Robot-code/logique.cpp \
../Robot-code/main.cpp \
../Robot-code/matrixLED.cpp \
../Robot-code/pid.cpp \
../Robot-code/rotation.cpp \
../Robot-code/serie.cpp \
../Robot-code/valeurs.cpp 

OBJS += \
./Robot-code/capteurs.o \
./Robot-code/logique.o \
./Robot-code/main.o \
./Robot-code/matrixLED.o \
./Robot-code/pid.o \
./Robot-code/rotation.o \
./Robot-code/serie.o \
./Robot-code/valeurs.o 

CPP_DEPS += \
./Robot-code/capteurs.d \
./Robot-code/logique.d \
./Robot-code/main.d \
./Robot-code/matrixLED.d \
./Robot-code/pid.d \
./Robot-code/rotation.d \
./Robot-code/serie.d \
./Robot-code/valeurs.d 


# Each subdirectory must supply rules for building sources it contributes
Robot-code/%.o: ../Robot-code/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking ARM-Linux C++ Compiler'
	arm-softfloat-linux-gnueabi-g++ -c -I"D:\Documents\Genie\S1\Projet session\ArmusIDE\Robot-MasterMind\Robot-code" -I"D:/Program Files (x86)/Armus/ArmusIDE/librairie/include" -I"D:/Program Files (x86)/Armus/ArmusIDE/toolchain/sysroot/usr/include/c++/4.2.4/" -I"D:/Program Files (x86)/Armus/ArmusIDE/toolchain/sysroot/usr/include" -I"D:/Program Files (x86)/Armus/ArmusIDE/librairie/include" -ggdb --sysroot="D:/Program Files (x86)/Armus/ArmusIDE/toolchain/sysroot" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


