################################################################################
# Automatically-generated file. Do not edit!
################################################################################

CG_TOOL_ROOT := /home/patrick/ti/ccsv6/tools/compiler/ti-cgt-arm_16.9.1.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./control.obj" \
"./highside.obj" \
"./lowside.obj" \
"./main.obj" \
"./timer.obj" \
"./tm4c123gh6pm_startup_ccs.obj" \
"./hal/hal.obj" \
"./hal/hal_tiva/cmsis/Source/system_FM4F.obj" \
"../tm4c123gh6pm.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := rm -rf
RMDIR := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include hal/subdir_vars.mk
-include hal/hal_tiva/cmsis/Source/subdir_vars.mk
-include subdir_rules.mk
-include hal/subdir_rules.mk
-include hal/hal_tiva/cmsis/Source/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
rgb_matrix.out \

EXE_OUTPUTS__QUOTED += \
"rgb_matrix.out" \

BIN_OUTPUTS += \
rgb_matrix.hex \

BIN_OUTPUTS__QUOTED += \
"rgb_matrix.hex" \


# All Target
all: rgb_matrix.out

# Tool invocations
rgb_matrix.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM Linker'
	"/home/patrick/ti/ccsv6/tools/compiler/ti-cgt-arm_16.9.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi -z -m"rgb_matrix.map" --heap_size=0 --stack_size=512 -i"/home/patrick/ti/ccsv6/tools/compiler/ti-cgt-arm_16.9.1.LTS/lib" -i"/home/patrick/ti/ccsv6/tools/compiler/ti-cgt-arm_16.9.1.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="rgb_matrix_linkInfo.xml" --rom_model -o "rgb_matrix.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

rgb_matrix.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: ARM Hex Utility'
	"/home/patrick/ti/ccsv6/tools/compiler/ti-cgt-arm_16.9.1.LTS/bin/armhex"  -o "rgb_matrix.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "control.d" "highside.d" "lowside.d" "main.d" "timer.d" "tm4c123gh6pm_startup_ccs.d" "hal/hal.d" "hal/hal_tiva/cmsis/Source/system_FM4F.d" 
	-$(RM) "control.obj" "highside.obj" "lowside.obj" "main.obj" "timer.obj" "tm4c123gh6pm_startup_ccs.obj" "hal/hal.obj" "hal/hal_tiva/cmsis/Source/system_FM4F.obj" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

