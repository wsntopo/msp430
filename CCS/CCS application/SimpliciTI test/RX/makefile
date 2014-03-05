################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv5/tools/compiler/msp430_4.2.1

ORDERED_OBJS += \
$(GEN_CMDS__FLAG) \
"./components/bsp/bsp.obj" \
"./components/mrfi/mrfi.obj" \
"./components/nwk/nwk_globals.obj" \
"./components/nwk/nwk_frame.obj" \
"./components/nwk/nwk_api.obj" \
"./components/nwk/nwk_QMgmt.obj" \
"./components/nwk/nwk.obj" \
"./components/nwk applications/nwk_security.obj" \
"./components/nwk applications/nwk_ping.obj" \
"./components/nwk applications/nwk_mgmt.obj" \
"./components/nwk applications/nwk_link.obj" \
"./components/nwk applications/nwk_join.obj" \
"./components/nwk applications/nwk_ioctl.obj" \
"./components/nwk applications/nwk_freq.obj" \
"./vlo_rand.obj" \
"./uart.obj" \
"./trigger.obj" \
"./tick.obj" \
"./radio.obj" \
"./main_rx.obj" \
"./main_datalog.obj" \
"./log.obj" \
"./init.obj" \
"./backchannel.obj" \
"../lnk_msp430g2553.cmd" \
-l"libc.a" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include components/nwk\ applications/subdir_vars.mk
-include components/nwk/subdir_vars.mk
-include components/mrfi/subdir_vars.mk
-include components/bsp/subdir_vars.mk
-include subdir_rules.mk
-include components/nwk\ applications/subdir_rules.mk
-include components/nwk/subdir_rules.mk
-include components/mrfi/subdir_rules.mk
-include components/bsp/subdir_rules.mk
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
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
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

# All Target
all: SimpliciTI\ test.out

# Tool invocations
SimpliciTI\ test.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: MSP430 Linker'
	"C:/ti/ccsv5/tools/compiler/msp430_4.2.1/bin/cl430" --cmd_file="C:\Users\jmanton\ti\SimpliciTI-CCS-1.1.1\Projects\Examples\eZ430RF\Simple_Peer_to_Peer\CCS\Configuration\smpl_nwk_config.dat" --cmd_file="C:\Users\jmanton\ti\SimpliciTI-CCS-1.1.1\Projects\Examples\eZ430RF\Simple_Peer_to_Peer\CCS\Configuration\End_Device\smpl_config.dat"  -vmsp --abi=eabi -g --advice:power=all --define=__MSP430G2553__ --define=MRFI_CC1101 --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal -z --stack_size=80 -m"SimpliciTI test.map" --heap_size=80 -i"C:/ti/ccsv5/ccs_base/msp430/include" -i"C:/ti/ccsv5/tools/compiler/msp430_4.2.1/lib" -i"C:/ti/ccsv5/tools/compiler/msp430_4.2.1/include" --reread_libs --warn_sections --display_error_number --diag_wrap=off --xml_link_info="SimpliciTI test_linkInfo.xml" --rom_model -o "SimpliciTI test.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(MSP430_EXECUTABLE_OUTPUTS__QUOTED) "SimpliciTI test.out"
	-$(RM) "backchannel.pp" "init.pp" "log.pp" "main_datalog.pp" "main_rx.pp" "radio.pp" "tick.pp" "trigger.pp" "uart.pp" "components\nwk applications\nwk_freq.pp" "components\nwk applications\nwk_ioctl.pp" "components\nwk applications\nwk_join.pp" "components\nwk applications\nwk_link.pp" "components\nwk applications\nwk_mgmt.pp" "components\nwk applications\nwk_ping.pp" "components\nwk applications\nwk_security.pp" "components\nwk\nwk.pp" "components\nwk\nwk_QMgmt.pp" "components\nwk\nwk_api.pp" "components\nwk\nwk_frame.pp" "components\nwk\nwk_globals.pp" "components\mrfi\mrfi.pp" "components\bsp\bsp.pp" 
	-$(RM) "backchannel.obj" "init.obj" "log.obj" "main_datalog.obj" "main_rx.obj" "radio.obj" "tick.obj" "trigger.obj" "uart.obj" "vlo_rand.obj" "components\nwk applications\nwk_freq.obj" "components\nwk applications\nwk_ioctl.obj" "components\nwk applications\nwk_join.obj" "components\nwk applications\nwk_link.obj" "components\nwk applications\nwk_mgmt.obj" "components\nwk applications\nwk_ping.obj" "components\nwk applications\nwk_security.obj" "components\nwk\nwk.obj" "components\nwk\nwk_QMgmt.obj" "components\nwk\nwk_api.obj" "components\nwk\nwk_frame.obj" "components\nwk\nwk_globals.obj" "components\mrfi\mrfi.obj" "components\bsp\bsp.obj" 
	-$(RM) "vlo_rand.pp" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

