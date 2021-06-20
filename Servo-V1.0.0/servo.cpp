/*
------------------------------------------------------------------------------
~ File   : servo.cpp
~ Author : Majid Derhambakhsh
~ Version: V1.0.0
~ Created: Jun 12, 2021 12:13:43 AM
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


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Include ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#include "servo.h"

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Defines ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Variable ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Enum ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Struct ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Object ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* :::::::::::::: Constructor ::::::::::::: */
Servo::Servo(){}
Servo::Servo(TIM_HandleTypeDef *htim, uint32_t channel, uint16_t minPPMPulseWidth, uint16_t maxPPMPulseWidth, float maxAngle) : _htim(htim), _channel(channel), MinPPMPulseWidth(minPPMPulseWidth), MaxPPMPulseWidth(maxPPMPulseWidth), MaxAngle(maxAngle)
{
	_angRatio = (((float)MaxPPMPulseWidth - (float)MinPPMPulseWidth) / MaxAngle);
}

/* ::::::::::::::::: Init ::::::::::::::::: */
void Servo::Init(TIM_HandleTypeDef *htim, uint32_t channel, uint16_t minPPMPulseWidth, uint16_t maxPPMPulseWidth, float maxAngle)
{

	/* ~~~~~~~~~~~~~~~ PWM timer ~~~~~~~~~~~~~~ */
	_htim            = htim;
	_channel         = channel;

	/* ~~~~~~~~~~~~~~~~~ Param ~~~~~~~~~~~~~~~~ */
	MinPPMPulseWidth = minPPMPulseWidth;
	MaxPPMPulseWidth = maxPPMPulseWidth;
	MaxAngle         = maxAngle;

	/* ~~~~~~~~~~~~~~ Calculation ~~~~~~~~~~~~~ */
	_angRatio        = ((MaxPPMPulseWidth - MinPPMPulseWidth) / MaxAngle);

}

/* ::::::::::::::: Position ::::::::::::::: */
void Servo::SetPPMPulseWidth(uint16_t width)
{
	__HAL_TIM_SET_COMPARE(_htim, _channel, PPMPulseWidth = width);
}

void Servo::SetAngle(float ang)
{

	Angle = ang;

	if (Angle >= MaxAngle)
	{

		Angle = MaxAngle;
		__HAL_TIM_SET_COMPARE(_htim, _channel, (uint32_t)(MinPPMPulseWidth + (_angRatio * Angle) - 1));

	}
	else
	{
		__HAL_TIM_SET_COMPARE(_htim, _channel, (uint32_t)(MinPPMPulseWidth + (_angRatio * Angle)));
	}

}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~ End of the program ~~~~~~~~~~~~~~~~~~~~~~~~~~ */
