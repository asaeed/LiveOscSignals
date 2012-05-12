################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/osc/OscBundle.cpp \
../src/osc/OscListener.cpp \
../src/osc/OscMessage.cpp \
../src/osc/OscSender.cpp 

OBJS += \
./src/osc/OscBundle.o \
./src/osc/OscListener.o \
./src/osc/OscMessage.o \
./src/osc/OscSender.o 

CPP_DEPS += \
./src/osc/OscBundle.d \
./src/osc/OscListener.d \
./src/osc/OscMessage.d \
./src/osc/OscSender.d 


# Each subdirectory must supply rules for building sources it contributes
src/osc/%.o: ../src/osc/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/Users/asaeed/code/cinder/boost -I/Users/asaeed/code/cinder/include -I"/Users/asaeed/work/LiveOscSignals/thirdparty" -I/System/Library/Frameworks/OpenGL.framework/Headers -I"/Users/asaeed/work/LiveOscSignals/src" -I"/Users/asaeed/work/LiveOscSignals/include" -I"/Users/asaeed/work/LiveOscSignals/include/ip" -I"/Users/asaeed/work/LiveOscSignals/include/osc" -O0 -g -Wall -c -fmessage-length=0 -arch i386 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


