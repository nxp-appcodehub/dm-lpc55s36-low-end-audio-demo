/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_dac.h"
#include "fsl_power.h"

#include "fast_forward.h"
#include "rewind.h"
#include "happy_monday.h"
#include "greeting.h"
#include "volume_down.h"
#include "volume_up.h"
#include "turn_off.h"
#include "turn_on.h"
#include "play.h"
#include "pause.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define DEMO_DAC_BASEADDR         DAC0
#define DEMO_DAC_IRQ_ID           DAC0_IRQn
#define DEMO_DAC_IRQ_HANDLER_FUNC DAC0_IRQHandler
#define DEMO_DAC_VREF             kDAC_ReferenceVoltageSourceAlt1

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

volatile uint32_t g_DacInputIndex    = 0U;
volatile uint32_t g_DacOutputIndex   = 0U;
volatile uint32_t g_DacInterruptDone = false;
uint16_t sample;
uint32_t NUM_ELEMENTS;
unsigned char *data;
/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Main function
 */
int main(void)
{
	dac_config_t dacConfigStruct;

	/* attach main clock divide to FLEXCOMM0 (debug console) */
	CLOCK_SetClkDiv(kCLOCK_DivFlexcom0Clk, 0u, false);
	CLOCK_SetClkDiv(kCLOCK_DivFlexcom0Clk, 1u, true);
	CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);

	BOARD_InitPins();
	BOARD_BootClockPLL150M();
	BOARD_InitDebugConsole();

	/* Disable DAC0 power down */
	POWER_DisablePD(kPDRUNCFG_PD_DAC0);
	/*Disable VREF power down*/
	POWER_DisablePD(kPDRUNCFG_PD_VREF);

	EnableIRQ(DEMO_DAC_IRQ_ID); /* Enable interrupt in NVIC. */

	/* Configure the DAC. */
	DAC_GetDefaultConfig(&dacConfigStruct);
	dacConfigStruct.referenceVoltageSource = DEMO_DAC_VREF;
	dacConfigStruct.fifoTriggerMode        = kDAC_FIFOTriggerBySoftwareMode; /* Software trigger. */
	dacConfigStruct.fifoWorkMode           = kDAC_FIFOWorkAsPeriodTriggerMode;      /* Normal FIFO mode. */
	dacConfigStruct.periodicTriggerNumber = 0;
	dacConfigStruct.periodicTriggerWidth = 15;
	dacConfigStruct.fifoWatermarkLevel     = 7U;                             /* Watermark. */
	dacConfigStruct.enableLowerLowPowerMode = false;
	DAC_Init(DEMO_DAC_BASEADDR, &dacConfigStruct);

	DAC_Enable(DEMO_DAC_BASEADDR, true); /* Enable output. */

	while (1)
	{
		PRINTF("\r\nSelect a command from the list below to reproduce sound:\r\n");
		PRINTF("\r\n 0 - Female Greeting\r\n");
		PRINTF("\r\n 1 - Happy Monday\r\n");
		PRINTF("\r\n 2 - Turn On\r\n");
		PRINTF("\r\n 3 - Turn Off\r\n");
		PRINTF("\r\n 4 - Play\r\n");
		PRINTF("\r\n 5 - Pause\r\n");
		PRINTF("\r\n 6 - Fast Forward\r\n");
		PRINTF("\r\n 7 - Rewind\r\n");
		PRINTF("\r\n 8 - Volume Up\r\n");
		PRINTF("\r\n 9 - Volume Down\r\n\n");

		uint8_t ch = GETCHAR();

		switch(ch)
		{
		case '0' : /*Female Greeting*/
			NUM_ELEMENTS = GREETING_ARRAY;
			g_DacInputIndex = 0;
			data = &greeting_data[0];
			/* Enable DAC interrupts. */
			DAC_EnableInterrupts(DEMO_DAC_BASEADDR, kDAC_PeriodTriggerCompleteInterruptEnable|kDAC_FIFOWatermarkInterruptEnable);
			DAC_DoSoftwareTriggerFIFO(DEMO_DAC_BASEADDR);
			break;
		case '1' : /*Happy Monday*/
			NUM_ELEMENTS = MONDAY_ARRAY;
			g_DacInputIndex = 0;
			data = &hm_data[0];
			/* Enable DAC interrupts. */
			DAC_EnableInterrupts(DEMO_DAC_BASEADDR, kDAC_PeriodTriggerCompleteInterruptEnable|kDAC_FIFOWatermarkInterruptEnable);
			DAC_DoSoftwareTriggerFIFO(DEMO_DAC_BASEADDR);
			break;
		case '2' : /* Turn On*/
			NUM_ELEMENTS = ON_ARRAY;
			g_DacInputIndex = 0;
			data = &turnOn_data[0];
			/* Enable DAC interrupts. */
			DAC_EnableInterrupts(DEMO_DAC_BASEADDR, kDAC_PeriodTriggerCompleteInterruptEnable|kDAC_FIFOWatermarkInterruptEnable);
			DAC_DoSoftwareTriggerFIFO(DEMO_DAC_BASEADDR);
			break;
		case '3' : /*Turn Off*/
			NUM_ELEMENTS = OFF_ARRAY;
			g_DacInputIndex = 0;
			data = &turnOff_data[0];
			/* Enable DAC interrupts. */
			DAC_EnableInterrupts(DEMO_DAC_BASEADDR, kDAC_PeriodTriggerCompleteInterruptEnable|kDAC_FIFOWatermarkInterruptEnable);
			DAC_DoSoftwareTriggerFIFO(DEMO_DAC_BASEADDR);
			break;
		case '4' : /* Play*/
			NUM_ELEMENTS = PLAY_ARRAY;
			g_DacInputIndex = 0;
			data = &play_data[0];
			/* Enable DAC interrupts. */
			DAC_EnableInterrupts(DEMO_DAC_BASEADDR, kDAC_PeriodTriggerCompleteInterruptEnable|kDAC_FIFOWatermarkInterruptEnable);
			DAC_DoSoftwareTriggerFIFO(DEMO_DAC_BASEADDR);
			break;
		case '5' : /* Pause*/
			NUM_ELEMENTS = PAUSE_ARRAY;
			g_DacInputIndex = 0;
			data = &pause_data[0];
			/* Enable DAC interrupts. */
			DAC_EnableInterrupts(DEMO_DAC_BASEADDR, kDAC_PeriodTriggerCompleteInterruptEnable|kDAC_FIFOWatermarkInterruptEnable);
			DAC_DoSoftwareTriggerFIFO(DEMO_DAC_BASEADDR);
			break;
		case '6' : /*Fast Forward*/
			NUM_ELEMENTS = FF_ARRAY;
			g_DacInputIndex = 0;
			data = &ff_data[0];
			/* Enable DAC interrupts. */
			DAC_EnableInterrupts(DEMO_DAC_BASEADDR, kDAC_PeriodTriggerCompleteInterruptEnable|kDAC_FIFOWatermarkInterruptEnable);
			DAC_DoSoftwareTriggerFIFO(DEMO_DAC_BASEADDR);
			break;
		case '7' :/* Rewind*/
			NUM_ELEMENTS = REWIND_ARRAY;
			g_DacInputIndex = 0;
			data = &rewind_data[0];
			/* Enable DAC interrupts. */
			DAC_EnableInterrupts(DEMO_DAC_BASEADDR, kDAC_PeriodTriggerCompleteInterruptEnable|kDAC_FIFOWatermarkInterruptEnable);
			DAC_DoSoftwareTriggerFIFO(DEMO_DAC_BASEADDR);
			break;
		case '8' : /*Volume Up*/
			NUM_ELEMENTS = UP_ARRAY;
			g_DacInputIndex = 0;
			data = &vu_data[0];
			/* Enable DAC interrupts. */
			DAC_EnableInterrupts(DEMO_DAC_BASEADDR, kDAC_PeriodTriggerCompleteInterruptEnable|kDAC_FIFOWatermarkInterruptEnable);
			DAC_DoSoftwareTriggerFIFO(DEMO_DAC_BASEADDR);
			break;
		case '9' : /*Volume Down*/
			NUM_ELEMENTS = DOWN_ARRAY;
			g_DacInputIndex = 0;
			data = &vd_data[0];
			/* Enable DAC interrupts. */
			DAC_EnableInterrupts(DEMO_DAC_BASEADDR, kDAC_PeriodTriggerCompleteInterruptEnable|kDAC_FIFOWatermarkInterruptEnable);
			DAC_DoSoftwareTriggerFIFO(DEMO_DAC_BASEADDR);
			break;
		default:
			break;
		}




	}
}

/*!
 * @brief IRQ function for DAC buffer interrupt
 */
void DEMO_DAC_IRQ_HANDLER_FUNC(void)
{
	DAC_SetData(DEMO_DAC_BASEADDR, *(data + g_DacInputIndex));
	if (g_DacInputIndex >= (NUM_ELEMENTS - 1U))
	{
		g_DacInputIndex = 0U;
		/* Disable DAC interrupts until next command is selected */
		DAC_DisableInterrupts(DEMO_DAC_BASEADDR, kDAC_PeriodTriggerCompleteInterruptEnable|kDAC_FIFOWatermarkInterruptEnable);
	}
	else
	{
		g_DacInputIndex++;
	}

}
