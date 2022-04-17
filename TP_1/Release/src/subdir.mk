################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/biblioteca.c \
../src/tp_1.c 

C_DEPS += \
./src/biblioteca.d \
./src/tp_1.d 

OBJS += \
./src/biblioteca.o \
./src/tp_1.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/biblioteca.d ./src/biblioteca.o ./src/tp_1.d ./src/tp_1.o

.PHONY: clean-src

