################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../capteurs.cpp \
../charma.cpp \
../logique.cpp \
../main.cpp \
../matrixLED.cpp \
../mouvement.cpp \
../valeurs.cpp 

OBJS += \
./capteurs.o \
./charma.o \
./logique.o \
./main.o \
./matrixLED.o \
./mouvement.o \
./valeurs.o 

CPP_DEPS += \
./capteurs.d \
./charma.d \
./logique.d \
./main.d \
./matrixLED.d \
./mouvement.d \
./valeurs.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking ARM-Linux C++ Compiler'
	arm-softfloat-linux-gnueabi-g++ -c -I"D:/Program Files (x86)/Armus/ArmusIDE/librairie/include" -I"D:/Program Files (x86)/Armus/ArmusIDE/toolchain/sysroot/usr/include" -I"D:/Program Files (x86)/Armus/ArmusIDE/toolchain/sysroot/usr/include/c++/4.2.4/" -I"D:/Program Files (x86)/Armus/ArmusIDE/toolchain/sysroot/usr/lib" -I"D:/Program Files (x86)/Armus/ArmusIDE/librairie/include" -ggdb --sysroot="D:/Program Files (x86)/Armus/ArmusIDE/toolchain/sysroot" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


