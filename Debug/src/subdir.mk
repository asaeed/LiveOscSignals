################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/LiveOscSignalsApp.cpp 

OBJS += \
./src/LiveOscSignalsApp.o 

CPP_DEPS += \
./src/LiveOscSignalsApp.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/Users/asaeed/code/cinder/boost -I/Users/asaeed/code/cinder/include -I"/Users/asaeed/work/LiveOscSignals/thirdparty" -I/System/Library/Frameworks/OpenGL.framework/Headers -I"/Users/asaeed/work/LiveOscSignals/src" -I"/Users/asaeed/work/LiveOscSignals/include" -I"/Users/asaeed/work/LiveOscSignals/include/ip" -I"/Users/asaeed/work/LiveOscSignals/include/osc" -O0 -g -Wall -c -fmessage-length=0 -arch i386 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


