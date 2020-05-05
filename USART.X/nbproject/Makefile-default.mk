#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/USART.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/USART.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../../UART.X/Main.c ../../UART.X/mUart.c ../../UART.X/Timer.c ../../UART.X/lcd.c "../../ADC task1/First task ADC.X/DIO.c" MADCC.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1773344296/Main.o ${OBJECTDIR}/_ext/1773344296/mUart.o ${OBJECTDIR}/_ext/1773344296/Timer.o ${OBJECTDIR}/_ext/1773344296/lcd.o ${OBJECTDIR}/_ext/894582462/DIO.o ${OBJECTDIR}/MADCC.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1773344296/Main.o.d ${OBJECTDIR}/_ext/1773344296/mUart.o.d ${OBJECTDIR}/_ext/1773344296/Timer.o.d ${OBJECTDIR}/_ext/1773344296/lcd.o.d ${OBJECTDIR}/_ext/894582462/DIO.o.d ${OBJECTDIR}/MADCC.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1773344296/Main.o ${OBJECTDIR}/_ext/1773344296/mUart.o ${OBJECTDIR}/_ext/1773344296/Timer.o ${OBJECTDIR}/_ext/1773344296/lcd.o ${OBJECTDIR}/_ext/894582462/DIO.o ${OBJECTDIR}/MADCC.o

# Source Files
SOURCEFILES=../../UART.X/Main.c ../../UART.X/mUart.c ../../UART.X/Timer.c ../../UART.X/lcd.c ../../ADC task1/First task ADC.X/DIO.c MADCC.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/USART.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega32A
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1773344296/Main.o: ../../UART.X/Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1773344296" 
	@${RM} ${OBJECTDIR}/_ext/1773344296/Main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1773344296/Main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp=${DFP_DIR}  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/1773344296/Main.o.d" -MT "${OBJECTDIR}/_ext/1773344296/Main.o.d" -MT ${OBJECTDIR}/_ext/1773344296/Main.o -o ${OBJECTDIR}/_ext/1773344296/Main.o ../../UART.X/Main.c 
	
${OBJECTDIR}/_ext/1773344296/mUart.o: ../../UART.X/mUart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1773344296" 
	@${RM} ${OBJECTDIR}/_ext/1773344296/mUart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1773344296/mUart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp=${DFP_DIR}  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/1773344296/mUart.o.d" -MT "${OBJECTDIR}/_ext/1773344296/mUart.o.d" -MT ${OBJECTDIR}/_ext/1773344296/mUart.o -o ${OBJECTDIR}/_ext/1773344296/mUart.o ../../UART.X/mUart.c 
	
${OBJECTDIR}/_ext/1773344296/Timer.o: ../../UART.X/Timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1773344296" 
	@${RM} ${OBJECTDIR}/_ext/1773344296/Timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1773344296/Timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp=${DFP_DIR}  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/1773344296/Timer.o.d" -MT "${OBJECTDIR}/_ext/1773344296/Timer.o.d" -MT ${OBJECTDIR}/_ext/1773344296/Timer.o -o ${OBJECTDIR}/_ext/1773344296/Timer.o ../../UART.X/Timer.c 
	
${OBJECTDIR}/_ext/1773344296/lcd.o: ../../UART.X/lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1773344296" 
	@${RM} ${OBJECTDIR}/_ext/1773344296/lcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1773344296/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp=${DFP_DIR}  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/1773344296/lcd.o.d" -MT "${OBJECTDIR}/_ext/1773344296/lcd.o.d" -MT ${OBJECTDIR}/_ext/1773344296/lcd.o -o ${OBJECTDIR}/_ext/1773344296/lcd.o ../../UART.X/lcd.c 
	
${OBJECTDIR}/_ext/894582462/DIO.o: ../../ADC\ task1/First\ task\ ADC.X/DIO.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/894582462" 
	@${RM} ${OBJECTDIR}/_ext/894582462/DIO.o.d 
	@${RM} ${OBJECTDIR}/_ext/894582462/DIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp=${DFP_DIR}  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/894582462/DIO.o.d" -MT "${OBJECTDIR}/_ext/894582462/DIO.o.d" -MT ${OBJECTDIR}/_ext/894582462/DIO.o -o ${OBJECTDIR}/_ext/894582462/DIO.o "../../ADC task1/First task ADC.X/DIO.c" 
	
${OBJECTDIR}/MADCC.o: MADCC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MADCC.o.d 
	@${RM} ${OBJECTDIR}/MADCC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp=${DFP_DIR}  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/MADCC.o.d" -MT "${OBJECTDIR}/MADCC.o.d" -MT ${OBJECTDIR}/MADCC.o -o ${OBJECTDIR}/MADCC.o MADCC.c 
	
else
${OBJECTDIR}/_ext/1773344296/Main.o: ../../UART.X/Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1773344296" 
	@${RM} ${OBJECTDIR}/_ext/1773344296/Main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1773344296/Main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp=${DFP_DIR}  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/1773344296/Main.o.d" -MT "${OBJECTDIR}/_ext/1773344296/Main.o.d" -MT ${OBJECTDIR}/_ext/1773344296/Main.o -o ${OBJECTDIR}/_ext/1773344296/Main.o ../../UART.X/Main.c 
	
${OBJECTDIR}/_ext/1773344296/mUart.o: ../../UART.X/mUart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1773344296" 
	@${RM} ${OBJECTDIR}/_ext/1773344296/mUart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1773344296/mUart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp=${DFP_DIR}  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/1773344296/mUart.o.d" -MT "${OBJECTDIR}/_ext/1773344296/mUart.o.d" -MT ${OBJECTDIR}/_ext/1773344296/mUart.o -o ${OBJECTDIR}/_ext/1773344296/mUart.o ../../UART.X/mUart.c 
	
${OBJECTDIR}/_ext/1773344296/Timer.o: ../../UART.X/Timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1773344296" 
	@${RM} ${OBJECTDIR}/_ext/1773344296/Timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1773344296/Timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp=${DFP_DIR}  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/1773344296/Timer.o.d" -MT "${OBJECTDIR}/_ext/1773344296/Timer.o.d" -MT ${OBJECTDIR}/_ext/1773344296/Timer.o -o ${OBJECTDIR}/_ext/1773344296/Timer.o ../../UART.X/Timer.c 
	
${OBJECTDIR}/_ext/1773344296/lcd.o: ../../UART.X/lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1773344296" 
	@${RM} ${OBJECTDIR}/_ext/1773344296/lcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1773344296/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp=${DFP_DIR}  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/1773344296/lcd.o.d" -MT "${OBJECTDIR}/_ext/1773344296/lcd.o.d" -MT ${OBJECTDIR}/_ext/1773344296/lcd.o -o ${OBJECTDIR}/_ext/1773344296/lcd.o ../../UART.X/lcd.c 
	
${OBJECTDIR}/_ext/894582462/DIO.o: ../../ADC\ task1/First\ task\ ADC.X/DIO.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/894582462" 
	@${RM} ${OBJECTDIR}/_ext/894582462/DIO.o.d 
	@${RM} ${OBJECTDIR}/_ext/894582462/DIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp=${DFP_DIR}  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/894582462/DIO.o.d" -MT "${OBJECTDIR}/_ext/894582462/DIO.o.d" -MT ${OBJECTDIR}/_ext/894582462/DIO.o -o ${OBJECTDIR}/_ext/894582462/DIO.o "../../ADC task1/First task ADC.X/DIO.c" 
	
${OBJECTDIR}/MADCC.o: MADCC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MADCC.o.d 
	@${RM} ${OBJECTDIR}/MADCC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp=${DFP_DIR}  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/MADCC.o.d" -MT "${OBJECTDIR}/MADCC.o.d" -MT ${OBJECTDIR}/MADCC.o -o ${OBJECTDIR}/MADCC.o MADCC.c 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/USART.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/USART.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp=${DFP_DIR}  -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2 -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -Wall -gdwarf-3     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/USART.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o dist/${CND_CONF}/${IMAGE_TYPE}/USART.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group  -Wl,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/USART.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/USART.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/USART.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp=${DFP_DIR}  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -Wall -gdwarf-3     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/USART.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o dist/${CND_CONF}/${IMAGE_TYPE}/USART.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}\\avr-objcopy -O ihex "dist/${CND_CONF}/${IMAGE_TYPE}/USART.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "dist/${CND_CONF}/${IMAGE_TYPE}/USART.X.${IMAGE_TYPE}.hex"
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
