# CROSS COMPILER SETTING
SET(CMAKE_SYSTEM_NAME Generic)
CMAKE_MINIMUM_REQUIRED (VERSION 2.6)

# THE VERSION NUMBER
SET (Tutorial_VERSION_MAJOR 1)
SET (Tutorial_VERSION_MINOR 0)

# ENABLE ASM
ENABLE_LANGUAGE(ASM)

SET(CMAKE_STATIC_LIBRARY_PREFIX)
SET(CMAKE_STATIC_LIBRARY_SUFFIX)

SET(CMAKE_EXECUTABLE_LIBRARY_PREFIX)
SET(CMAKE_EXECUTABLE_LIBRARY_SUFFIX)

 
# CURRENT DIRECTORY
SET(ProjDirPath ${CMAKE_CURRENT_SOURCE_DIR})

SET(EXECUTABLE_OUTPUT_PATH ${ProjDirPath}/${CMAKE_BUILD_TYPE})
SET(LIBRARY_OUTPUT_PATH ${ProjDirPath}/${CMAKE_BUILD_TYPE})


project(dsp_naturedsp_fusionf1)

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -DDEBUG")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -DNDEBUG")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DDEBUG")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DSDK_DEBUGCONSOLE=1")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DXOS_CLOCK_FREQ=198000000")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DXF_CORE_ID=0")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DXF_CFG_CORES_NUM=1")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DCPU_MIMXRT595SFFOC_dsp")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DMCUXPRESSO_SDK")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} --xtensa-core=nxp_rt500_RI23_11_newlib")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} --xtensa-system=${XTENSA_SYSTEM}")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fsigned-char")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wno-unused")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wno-missing-braces")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fmessage-length=0")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -std=gnu99")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -DNDEBUG")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -DSDK_DEBUGCONSOLE=1")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -DXOS_CLOCK_FREQ=198000000")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -DXF_CORE_ID=0")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -DXF_CFG_CORES_NUM=1")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -DCPU_MIMXRT595SFFOC_dsp")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -DMCUXPRESSO_SDK")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Os")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} --xtensa-core=nxp_rt500_RI23_11_newlib")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} --xtensa-system=${XTENSA_SYSTEM}")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Wall")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -fsigned-char")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Wno-unused")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Wno-missing-braces")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -fmessage-length=0")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -std=gnu99")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DMCUXPRESSO_SDK")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DNDEBUG")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DMCUXPRESSO_SDK")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -mlsp=${ProjDirPath}/../../../../../../core/devices/MIMXRT595S/xtensa/gdbio")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -g")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} --xtensa-core=nxp_rt500_RI23_11_newlib")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} --xtensa-system=${XTENSA_SYSTEM}")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -Wl,--orphan-handling=place")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -mlsp=${ProjDirPath}/../../../../../../core/devices/MIMXRT595S/xtensa/min-rt")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} --xtensa-core=nxp_rt500_RI23_11_newlib")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} --xtensa-system=${XTENSA_SYSTEM}")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -Wl,--orphan-handling=place")

include_directories(${ProjDirPath}/..)

include_directories(${ProjDirPath}/../../../../../../core/drivers/inputmux)

include_directories(${ProjDirPath}/../../../../../../core/components/uart)

include_directories(${ProjDirPath}/../../../../../../core/drivers/flexcomm/usart)

include_directories(${ProjDirPath}/../../../../../../core/utilities/str)

include_directories(${ProjDirPath}/../../../../../../core/utilities/debug_console_lite)

include_directories(${ProjDirPath}/../../../../../../core/utilities/assert)

include_directories(${ProjDirPath}/../../../../../../core/drivers/lpc_gpio)

include_directories(${ProjDirPath}/../../../../../../core/drivers/lpc_iopctl)

include_directories(${ProjDirPath}/../../../../../../middleware/dsp/naturedsp/fusionf1/include)

include_directories(${ProjDirPath}/../../../../../../core/drivers/common)

include_directories(${ProjDirPath}/../../../../../../core/devices/MIMXRT595S/drivers)

include_directories(${ProjDirPath}/../../../../../../core/devices/MIMXRT595S)

include_directories(${ProjDirPath}/../../../../../../core/drivers/flexcomm)

include_directories(${ProjDirPath}/../../../../../../core/CMSIS/Core/Include)

add_executable(dsp_naturedsp_fusionf1.elf 
"${ProjDirPath}/../main_dsp.c"
"${ProjDirPath}/../srtm_naturedsp_test.h"
"${ProjDirPath}/../srtm_naturedsp_test.c"
"${ProjDirPath}/../pin_mux.c"
"${ProjDirPath}/../pin_mux.h"
"${ProjDirPath}/../naturedsp_input.h"
"${ProjDirPath}/../board_fusionf1.c"
"${ProjDirPath}/../board_fusionf1.h"
"${ProjDirPath}/../../../../../../core/drivers/inputmux/fsl_inputmux.h"
"${ProjDirPath}/../../../../../../core/drivers/inputmux/fsl_inputmux.c"
"${ProjDirPath}/../../../../../../core/components/uart/fsl_adapter_uart.h"
"${ProjDirPath}/../../../../../../core/components/uart/fsl_adapter_usart.c"
"${ProjDirPath}/../../../../../../core/drivers/flexcomm/usart/fsl_usart.h"
"${ProjDirPath}/../../../../../../core/drivers/flexcomm/usart/fsl_usart.c"
"${ProjDirPath}/../../../../../../core/utilities/str/fsl_str.c"
"${ProjDirPath}/../../../../../../core/utilities/str/fsl_str.h"
"${ProjDirPath}/../../../../../../core/utilities/debug_console_lite/fsl_debug_console.c"
"${ProjDirPath}/../../../../../../core/utilities/debug_console_lite/fsl_debug_console.h"
"${ProjDirPath}/../../../../../../core/utilities/assert/fsl_assert.c"
"${ProjDirPath}/../../../../../../core/utilities/assert/fsl_assert.h"
"${ProjDirPath}/../../../../../../core/drivers/lpc_gpio/fsl_gpio.h"
"${ProjDirPath}/../../../../../../core/drivers/lpc_gpio/fsl_gpio.c"
"${ProjDirPath}/../../../../../../core/drivers/lpc_iopctl/fsl_iopctl.h"
"${ProjDirPath}/../../../../../../middleware/dsp/naturedsp/fusionf1/include/NatureDSP_Signal.h"
"${ProjDirPath}/../../../../../../middleware/dsp/naturedsp/fusionf1/include/NatureDSP_types.h"
"${ProjDirPath}/../../../../../../core/drivers/common/fsl_common.h"
"${ProjDirPath}/../../../../../../core/drivers/common/fsl_common.c"
"${ProjDirPath}/../../../../../../core/drivers/common/fsl_common_dsp.c"
"${ProjDirPath}/../../../../../../core/drivers/common/fsl_common_dsp.h"
"${ProjDirPath}/../../../../../../core/devices/MIMXRT595S/drivers/fsl_clock.h"
"${ProjDirPath}/../../../../../../core/devices/MIMXRT595S/drivers/fsl_clock.c"
"${ProjDirPath}/../../../../../../core/devices/MIMXRT595S/drivers/fsl_reset.h"
"${ProjDirPath}/../../../../../../core/devices/MIMXRT595S/drivers/fsl_reset.c"
"${ProjDirPath}/../../../../../../core/devices/MIMXRT595S/MIMXRT595S_dsp.h"
"${ProjDirPath}/../../../../../../core/devices/MIMXRT595S/MIMXRT595S_dsp_features.h"
"${ProjDirPath}/../../../../../../core/devices/MIMXRT595S/system_MIMXRT595S_dsp.c"
"${ProjDirPath}/../../../../../../core/devices/MIMXRT595S/system_MIMXRT595S_dsp.h"
"${ProjDirPath}/../../../../../../core/drivers/flexcomm/fsl_flexcomm.h"
"${ProjDirPath}/../../../../../../core/drivers/flexcomm/fsl_flexcomm.c"
)


TARGET_LINK_LIBRARIES(dsp_naturedsp_fusionf1.elf -Wl,--start-group)

target_link_libraries(dsp_naturedsp_fusionf1.elf debug ${ProjDirPath}/../../../../../../middleware/dsp/naturedsp/fusionf1/libnaturedsp.a)


target_link_libraries(dsp_naturedsp_fusionf1.elf optimized ${ProjDirPath}/../../../../../../middleware/dsp/naturedsp/fusionf1/libnaturedsp.a)

TARGET_LINK_LIBRARIES(dsp_naturedsp_fusionf1.elf -Wl,--end-group)

ADD_CUSTOM_COMMAND(TARGET dsp_naturedsp_fusionf1.elf POST_BUILD COMMAND ${CMAKE_OBJCOPY}
--xtensa-params= -Obinary ${EXECUTABLE_OUTPUT_PATH}/dsp_naturedsp_fusionf1.elf ${EXECUTABLE_OUTPUT_PATH}/../../../../../../../examples/evkmimxrt595/dsp_examples/naturedsp/dsp/binary/dsp_reset_${CMAKE_BUILD_TYPE}.bin
--xtensa-core=nxp_rt500_RI23_11_newlib
--xtensa-system=${XTENSA_SYSTEM}
--only-section=.ResetVector.text
)

ADD_CUSTOM_COMMAND(TARGET dsp_naturedsp_fusionf1.elf POST_BUILD COMMAND ${CMAKE_OBJCOPY}
--xtensa-params= -Obinary ${EXECUTABLE_OUTPUT_PATH}/dsp_naturedsp_fusionf1.elf ${EXECUTABLE_OUTPUT_PATH}/../../../../../../../examples/evkmimxrt595/dsp_examples/naturedsp/dsp/binary/dsp_text_${CMAKE_BUILD_TYPE}.bin
--xtensa-core=nxp_rt500_RI23_11_newlib
--xtensa-system=${XTENSA_SYSTEM}
--only-section=.WindowVectors.text
--only-section=.Level2InterruptVector.text
--only-section=.Level3InterruptVector.literal
--only-section=.Level3InterruptVector.text
--only-section=.DebugExceptionVector.literal
--only-section=.DebugExceptionVector.text
--only-section=.NMIExceptionVector.literal
--only-section=.NMIExceptionVector.text
--only-section=.KernelExceptionVector.text
--only-section=.UserExceptionVector.text
--only-section=.DoubleExceptionVector.text
--only-section=.text
)

ADD_CUSTOM_COMMAND(TARGET dsp_naturedsp_fusionf1.elf POST_BUILD COMMAND ${CMAKE_OBJCOPY}
--xtensa-params= -Obinary ${EXECUTABLE_OUTPUT_PATH}/dsp_naturedsp_fusionf1.elf ${EXECUTABLE_OUTPUT_PATH}/../../../../../../../examples/evkmimxrt595/dsp_examples/naturedsp/dsp/binary/dsp_data_${CMAKE_BUILD_TYPE}.bin
--xtensa-core=nxp_rt500_RI23_11_newlib
--xtensa-system=${XTENSA_SYSTEM}
--only-section=.clib.rodata
--only-section=.rtos.rodata
--only-section=.rodata
--only-section=.clib.data
--only-section=.rtos.percpu.data
--only-section=.data
--only-section=.bss
)

