################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
components/mrfi/mrfi.obj: C:/Users/jmanton/ti/SimpliciTI-CCS-1.1.1/Components/mrfi/mrfi.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv5/tools/compiler/msp430_4.2.1/bin/cl430" --cmd_file="C:\Users\jmanton\ti\SimpliciTI-CCS-1.1.1\Projects\Examples\eZ430RF\Simple_Peer_to_Peer\CCS\Configuration\smpl_nwk_config.dat" --cmd_file="C:\Users\jmanton\ti\SimpliciTI-CCS-1.1.1\Projects\Examples\eZ430RF\Simple_Peer_to_Peer\CCS\Configuration\End_Device\smpl_config.dat"  -vmsp --abi=eabi --opt_for_speed=0 -g --include_path="C:/ti/ccsv5/ccs_base/msp430/include" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/bsp/drivers" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/bsp" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/bsp/boards/LP_AIR_CC110L_G2553" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/mrfi" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/simpliciti/nwk" --include_path="C:/ti/SimpliciTI-CCS-1.1.1/Components/simpliciti/nwk_applications" --include_path="C:/ti/ccsv5/tools/compiler/msp430_4.2.1/include" --advice:power=all --define=__MSP430G2553__ --define=FREQUENCY_AGILITY --define=MRFI_CC1101 --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="components/mrfi/mrfi.pp" --obj_directory="components/mrfi" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


