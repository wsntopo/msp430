################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
backchannel.obj: ../backchannel.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv5/tools/compiler/msp430_4.1.2/bin/cl430" --cmd_file="C:\Users\jmanton\ti\SimpliciTI-CCS-1.1.1\Projects\Examples\eZ430RF\Simple_Peer_to_Peer\CCS\Configuration\smpl_nwk_config.dat" --cmd_file="C:\Users\jmanton\ti\SimpliciTI-CCS-1.1.1\Projects\Examples\eZ430RF\Simple_Peer_to_Peer\CCS\Configuration\End_Device\smpl_config.dat"  -vmsp --abi=eabi --opt_for_speed=0 -g --include_path="C:/ti/ccsv5/ccs_base/msp430/include" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/bsp/drivers" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/bsp" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/bsp/boards/LP_AIR_CC110L_G2553" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/mrfi" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/simpliciti/nwk" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/simpliciti/nwk_applications" --include_path="C:/ti/ccsv5/tools/compiler/msp430_4.1.2/include" --advice:power=all --define=__MSP430G2553__ --define=FREQUENCY_AGILITY --define=MRFI_CC1101 --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="backchannel.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

init.obj: ../init.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv5/tools/compiler/msp430_4.1.2/bin/cl430" --cmd_file="C:\Users\jmanton\ti\SimpliciTI-CCS-1.1.1\Projects\Examples\eZ430RF\Simple_Peer_to_Peer\CCS\Configuration\smpl_nwk_config.dat" --cmd_file="C:\Users\jmanton\ti\SimpliciTI-CCS-1.1.1\Projects\Examples\eZ430RF\Simple_Peer_to_Peer\CCS\Configuration\End_Device\smpl_config.dat"  -vmsp --abi=eabi --opt_for_speed=0 -g --include_path="C:/ti/ccsv5/ccs_base/msp430/include" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/bsp/drivers" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/bsp" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/bsp/boards/LP_AIR_CC110L_G2553" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/mrfi" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/simpliciti/nwk" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/simpliciti/nwk_applications" --include_path="C:/ti/ccsv5/tools/compiler/msp430_4.1.2/include" --advice:power=all --define=__MSP430G2553__ --define=FREQUENCY_AGILITY --define=MRFI_CC1101 --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="init.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

log.obj: ../log.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv5/tools/compiler/msp430_4.1.2/bin/cl430" --cmd_file="C:\Users\jmanton\ti\SimpliciTI-CCS-1.1.1\Projects\Examples\eZ430RF\Simple_Peer_to_Peer\CCS\Configuration\smpl_nwk_config.dat" --cmd_file="C:\Users\jmanton\ti\SimpliciTI-CCS-1.1.1\Projects\Examples\eZ430RF\Simple_Peer_to_Peer\CCS\Configuration\End_Device\smpl_config.dat"  -vmsp --abi=eabi --opt_for_speed=0 -g --include_path="C:/ti/ccsv5/ccs_base/msp430/include" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/bsp/drivers" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/bsp" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/bsp/boards/LP_AIR_CC110L_G2553" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/mrfi" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/simpliciti/nwk" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/simpliciti/nwk_applications" --include_path="C:/ti/ccsv5/tools/compiler/msp430_4.1.2/include" --advice:power=all --define=__MSP430G2553__ --define=FREQUENCY_AGILITY --define=MRFI_CC1101 --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="log.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main_datalog.obj: ../main_datalog.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv5/tools/compiler/msp430_4.1.2/bin/cl430" --cmd_file="C:\Users\jmanton\ti\SimpliciTI-CCS-1.1.1\Projects\Examples\eZ430RF\Simple_Peer_to_Peer\CCS\Configuration\smpl_nwk_config.dat" --cmd_file="C:\Users\jmanton\ti\SimpliciTI-CCS-1.1.1\Projects\Examples\eZ430RF\Simple_Peer_to_Peer\CCS\Configuration\End_Device\smpl_config.dat"  -vmsp --abi=eabi --opt_for_speed=0 -g --include_path="C:/ti/ccsv5/ccs_base/msp430/include" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/bsp/drivers" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/bsp" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/bsp/boards/LP_AIR_CC110L_G2553" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/mrfi" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/simpliciti/nwk" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/simpliciti/nwk_applications" --include_path="C:/ti/ccsv5/tools/compiler/msp430_4.1.2/include" --advice:power=all --define=__MSP430G2553__ --define=FREQUENCY_AGILITY --define=MRFI_CC1101 --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="main_datalog.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

radio.obj: ../radio.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv5/tools/compiler/msp430_4.1.2/bin/cl430" --cmd_file="C:\Users\jmanton\ti\SimpliciTI-CCS-1.1.1\Projects\Examples\eZ430RF\Simple_Peer_to_Peer\CCS\Configuration\smpl_nwk_config.dat" --cmd_file="C:\Users\jmanton\ti\SimpliciTI-CCS-1.1.1\Projects\Examples\eZ430RF\Simple_Peer_to_Peer\CCS\Configuration\End_Device\smpl_config.dat"  -vmsp --abi=eabi --opt_for_speed=0 -g --include_path="C:/ti/ccsv5/ccs_base/msp430/include" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/bsp/drivers" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/bsp" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/bsp/boards/LP_AIR_CC110L_G2553" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/mrfi" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/simpliciti/nwk" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/simpliciti/nwk_applications" --include_path="C:/ti/ccsv5/tools/compiler/msp430_4.1.2/include" --advice:power=all --define=__MSP430G2553__ --define=FREQUENCY_AGILITY --define=MRFI_CC1101 --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="radio.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

tick.obj: ../tick.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv5/tools/compiler/msp430_4.1.2/bin/cl430" --cmd_file="C:\Users\jmanton\ti\SimpliciTI-CCS-1.1.1\Projects\Examples\eZ430RF\Simple_Peer_to_Peer\CCS\Configuration\smpl_nwk_config.dat" --cmd_file="C:\Users\jmanton\ti\SimpliciTI-CCS-1.1.1\Projects\Examples\eZ430RF\Simple_Peer_to_Peer\CCS\Configuration\End_Device\smpl_config.dat"  -vmsp --abi=eabi --opt_for_speed=0 -g --include_path="C:/ti/ccsv5/ccs_base/msp430/include" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/bsp/drivers" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/bsp" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/bsp/boards/LP_AIR_CC110L_G2553" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/mrfi" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/simpliciti/nwk" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/simpliciti/nwk_applications" --include_path="C:/ti/ccsv5/tools/compiler/msp430_4.1.2/include" --advice:power=all --define=__MSP430G2553__ --define=FREQUENCY_AGILITY --define=MRFI_CC1101 --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="tick.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

trigger.obj: ../trigger.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv5/tools/compiler/msp430_4.1.2/bin/cl430" --cmd_file="C:\Users\jmanton\ti\SimpliciTI-CCS-1.1.1\Projects\Examples\eZ430RF\Simple_Peer_to_Peer\CCS\Configuration\smpl_nwk_config.dat" --cmd_file="C:\Users\jmanton\ti\SimpliciTI-CCS-1.1.1\Projects\Examples\eZ430RF\Simple_Peer_to_Peer\CCS\Configuration\End_Device\smpl_config.dat"  -vmsp --abi=eabi --opt_for_speed=0 -g --include_path="C:/ti/ccsv5/ccs_base/msp430/include" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/bsp/drivers" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/bsp" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/bsp/boards/LP_AIR_CC110L_G2553" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/mrfi" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/simpliciti/nwk" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/simpliciti/nwk_applications" --include_path="C:/ti/ccsv5/tools/compiler/msp430_4.1.2/include" --advice:power=all --define=__MSP430G2553__ --define=FREQUENCY_AGILITY --define=MRFI_CC1101 --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="trigger.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

uart.obj: ../uart.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv5/tools/compiler/msp430_4.1.2/bin/cl430" --cmd_file="C:\Users\jmanton\ti\SimpliciTI-CCS-1.1.1\Projects\Examples\eZ430RF\Simple_Peer_to_Peer\CCS\Configuration\smpl_nwk_config.dat" --cmd_file="C:\Users\jmanton\ti\SimpliciTI-CCS-1.1.1\Projects\Examples\eZ430RF\Simple_Peer_to_Peer\CCS\Configuration\End_Device\smpl_config.dat"  -vmsp --abi=eabi --opt_for_speed=0 -g --include_path="C:/ti/ccsv5/ccs_base/msp430/include" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/bsp/drivers" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/bsp" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/bsp/boards/LP_AIR_CC110L_G2553" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/mrfi" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/simpliciti/nwk" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/simpliciti/nwk_applications" --include_path="C:/ti/ccsv5/tools/compiler/msp430_4.1.2/include" --advice:power=all --define=__MSP430G2553__ --define=FREQUENCY_AGILITY --define=MRFI_CC1101 --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="uart.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

vlo_rand.obj: ../vlo_rand.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv5/tools/compiler/msp430_4.1.2/bin/cl430" --cmd_file="C:\Users\jmanton\ti\SimpliciTI-CCS-1.1.1\Projects\Examples\eZ430RF\Simple_Peer_to_Peer\CCS\Configuration\smpl_nwk_config.dat" --cmd_file="C:\Users\jmanton\ti\SimpliciTI-CCS-1.1.1\Projects\Examples\eZ430RF\Simple_Peer_to_Peer\CCS\Configuration\End_Device\smpl_config.dat"  -vmsp --abi=eabi --opt_for_speed=0 -g --include_path="C:/ti/ccsv5/ccs_base/msp430/include" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/bsp/drivers" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/bsp" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/bsp/boards/LP_AIR_CC110L_G2553" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/mrfi" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/simpliciti/nwk" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/simpliciti/nwk_applications" --include_path="C:/ti/ccsv5/tools/compiler/msp430_4.1.2/include" --advice:power=all --define=__MSP430G2553__ --define=FREQUENCY_AGILITY --define=MRFI_CC1101 --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="vlo_rand.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


