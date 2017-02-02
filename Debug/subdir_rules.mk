################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
control.obj: ../control.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/home/patrick/ti/ccsv6/tools/compiler/ti-cgt-arm_16.9.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/home/patrick/ti/ccsv6/tools/compiler/ti-cgt-arm_16.9.1.LTS/include" --include_path="/home/patrick/tiva/rgb_matrix/modules" --include_path="/home/patrick/tiva/rgb_matrix/app" --include_path="/home/patrick/tiva/rgb_matrix" --include_path="/home/patrick/tiva/rgb_matrix/hal/hal_tiva/include" --include_path="/home/patrick/tiva/rgb_matrix/hal/hal_tiva/cmsis/Include" --include_path="/home/patrick/tiva/rgb_matrix/hal" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="control.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

display.obj: ../display.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/home/patrick/ti/ccsv6/tools/compiler/ti-cgt-arm_16.9.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/home/patrick/ti/ccsv6/tools/compiler/ti-cgt-arm_16.9.1.LTS/include" --include_path="/home/patrick/tiva/rgb_matrix/modules" --include_path="/home/patrick/tiva/rgb_matrix/app" --include_path="/home/patrick/tiva/rgb_matrix" --include_path="/home/patrick/tiva/rgb_matrix/hal/hal_tiva/include" --include_path="/home/patrick/tiva/rgb_matrix/hal/hal_tiva/cmsis/Include" --include_path="/home/patrick/tiva/rgb_matrix/hal" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="display.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

highside.obj: ../highside.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/home/patrick/ti/ccsv6/tools/compiler/ti-cgt-arm_16.9.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/home/patrick/ti/ccsv6/tools/compiler/ti-cgt-arm_16.9.1.LTS/include" --include_path="/home/patrick/tiva/rgb_matrix/modules" --include_path="/home/patrick/tiva/rgb_matrix/app" --include_path="/home/patrick/tiva/rgb_matrix" --include_path="/home/patrick/tiva/rgb_matrix/hal/hal_tiva/include" --include_path="/home/patrick/tiva/rgb_matrix/hal/hal_tiva/cmsis/Include" --include_path="/home/patrick/tiva/rgb_matrix/hal" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="highside.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

lowside.obj: ../lowside.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/home/patrick/ti/ccsv6/tools/compiler/ti-cgt-arm_16.9.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/home/patrick/ti/ccsv6/tools/compiler/ti-cgt-arm_16.9.1.LTS/include" --include_path="/home/patrick/tiva/rgb_matrix/modules" --include_path="/home/patrick/tiva/rgb_matrix/app" --include_path="/home/patrick/tiva/rgb_matrix" --include_path="/home/patrick/tiva/rgb_matrix/hal/hal_tiva/include" --include_path="/home/patrick/tiva/rgb_matrix/hal/hal_tiva/cmsis/Include" --include_path="/home/patrick/tiva/rgb_matrix/hal" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="lowside.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/home/patrick/ti/ccsv6/tools/compiler/ti-cgt-arm_16.9.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/home/patrick/ti/ccsv6/tools/compiler/ti-cgt-arm_16.9.1.LTS/include" --include_path="/home/patrick/tiva/rgb_matrix/modules" --include_path="/home/patrick/tiva/rgb_matrix/app" --include_path="/home/patrick/tiva/rgb_matrix" --include_path="/home/patrick/tiva/rgb_matrix/hal/hal_tiva/include" --include_path="/home/patrick/tiva/rgb_matrix/hal/hal_tiva/cmsis/Include" --include_path="/home/patrick/tiva/rgb_matrix/hal" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="main.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

timer.obj: ../timer.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/home/patrick/ti/ccsv6/tools/compiler/ti-cgt-arm_16.9.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/home/patrick/ti/ccsv6/tools/compiler/ti-cgt-arm_16.9.1.LTS/include" --include_path="/home/patrick/tiva/rgb_matrix/modules" --include_path="/home/patrick/tiva/rgb_matrix/app" --include_path="/home/patrick/tiva/rgb_matrix" --include_path="/home/patrick/tiva/rgb_matrix/hal/hal_tiva/include" --include_path="/home/patrick/tiva/rgb_matrix/hal/hal_tiva/cmsis/Include" --include_path="/home/patrick/tiva/rgb_matrix/hal" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="timer.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

tm4c123gh6pm_startup_ccs.obj: ../tm4c123gh6pm_startup_ccs.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/home/patrick/ti/ccsv6/tools/compiler/ti-cgt-arm_16.9.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/home/patrick/ti/ccsv6/tools/compiler/ti-cgt-arm_16.9.1.LTS/include" --include_path="/home/patrick/tiva/rgb_matrix/modules" --include_path="/home/patrick/tiva/rgb_matrix/app" --include_path="/home/patrick/tiva/rgb_matrix" --include_path="/home/patrick/tiva/rgb_matrix/hal/hal_tiva/include" --include_path="/home/patrick/tiva/rgb_matrix/hal/hal_tiva/cmsis/Include" --include_path="/home/patrick/tiva/rgb_matrix/hal" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="tm4c123gh6pm_startup_ccs.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


