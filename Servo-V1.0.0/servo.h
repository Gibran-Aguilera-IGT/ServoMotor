/*
------------------------------------------------------------------------------
~ File   : servo.h
~ Author : Majid Derhambakhsh
~ Version: V1.0.0
~ Created: Jun 12, 2021 12:28:16 AM
~ Brief  :
~ Support: 
           E-Mail : Majid.do16@gmail.com (subject : Embedded Library Support)
		   
           Github : https://github.com/Majid-Derhambakhsh
------------------------------------------------------------------------------
~ Description:    

~ Attention  :    

~ Changes    :
------------------------------------------------------------------------------
*/

#ifndef __SERVO_H_
#define __SERVO_H_

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ G Include ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#include <stdint.h>

/* ------------------------------------------------------------------ */
#ifdef USE_HAL_DRIVER

	#include "main.h"

	/* --------------- Check Mainstream series --------------- */

	#ifdef STM32F0
		#include "stm32f0xx_hal.h"       /* Import HAL library */
	#elif defined(STM32F1)
		#include "stm32f1xx_hal.h"       /* Import HAL library */
	#elif defined(STM32F2)
		#include "stm32f2xx_hal.h"       /* Import HAL library */
	#elif defined(STM32F3)
		#include "stm32f3xx_hal.h"       /* Import HAL library */
	#elif defined(STM32F4)
		#include "stm32f4xx_hal.h"       /* Import HAL library */
	#elif defined(STM32F7)
		#include "stm32f7xx_hal.h"       /* Import HAL library */
	#elif defined(STM32G0)
		#include "stm32g0xx_hal.h"       /* Import HAL library */
	#elif defined(STM32G4)
		#include "stm32g4xx_hal.h"       /* Import HAL library */

	/* ------------ Check High Performance series ------------ */

	#elif defined(STM32H7)
		#include "stm32h7xx_hal.h"       /* Import HAL library */

	/* ------------ Check Ultra low power series ------------- */

	#elif defined(STM32L0)
		#include "stm32l0xx_hal.h"       /* Import HAL library */
	#elif defined(STM32L1)
		#include "stm32l1xx_hal.h"       /* Import HAL library */
	#elif defined(STM32L5)
		#include "stm32l5xx_hal.h"       /* Import HAL library */
	#elif defined(STM32L4)
		#include "stm32l4xx_hal.h"       /* Import HAL library */
	#elif defined(STM32H7)
		#include "stm32h7xx_hal.h"       /* Import HAL library */
	#else
	#endif /* STM32F1 */

	/* ------------------------------------------------------- */

	#ifdef __ICCARM__ /* ICCARM Compiler */

	#pragma diag_suppress=Pe177   /* Disable 'unused function' warning */

	#endif /* __ICCARM__ */

/* ------------------------------------------------------------------ */

#else                     /* Compiler not found */

#error Chip or Library not supported  /* Send error */

#endif /* USE_HAL_DRIVER */

/* ------------------------------------------------------------------ */

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ G Defines ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ---------------------------- Public ---------------------------- */
/* ---------------------- Define by compiler ---------------------- */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ G Types ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ G Variables ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ G Enum ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ G Struct ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ G Prototype ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Class ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
class Servo
{

	private:

	/* ~~~~~~~~~~~~~~~~~~~~~~~~~ Variable ~~~~~~~~~~~~~~~~~~~~~~~~~ */
	/* :::::::::::::: Calculation ::::::::::::: */
	float               _angRatio;

	/* ::::::::::::::: PWM timer :::::::::::::: */
	TIM_HandleTypeDef  *_htim;
	uint32_t            _channel;

	public:

	/* ~~~~~~~~~~~~~~~~~~~~~~~~~ Variable ~~~~~~~~~~~~~~~~~~~~~~~~~ */
	/* :::::::::::::: Servo param ::::::::::::: */
	uint16_t            PPMPulseWidth;
	uint16_t            MinPPMPulseWidth;
	uint16_t            MaxPPMPulseWidth;

	float               Angle;
	float               MaxAngle;

	/* ~~~~~~~~~~~~~~~~~~~~~~~~ Prototupe ~~~~~~~~~~~~~~~~~~~~~~~~~ */
	/* :::::::::::::: Constructor ::::::::::::: */
	Servo();
	Servo(TIM_HandleTypeDef *htim, uint32_t channel, uint16_t minPPMPulseWidth = 1000, uint16_t maxPPMPulseWidth = 2000, float maxAngle = 180.0F);

	/* ::::::::::::::::: Init ::::::::::::::::: */
	void Init(TIM_HandleTypeDef *htim, uint32_t channel, uint16_t minPPMPulseWidth = 1000, uint16_t maxPPMPulseWidth = 2000, float maxAngle = 180.0F);

	/* ::::::::::::::: Position ::::::::::::::: */
	void SetPPMPulseWidth(uint16_t Width);
	void SetAngle(float ang);

};

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ End of the program ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif /* __SERVO_H_ */
