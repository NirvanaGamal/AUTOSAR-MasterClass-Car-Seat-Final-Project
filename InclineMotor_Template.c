/**
 *
 * \file InclineMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: InclineMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 9/26/2023 10:10 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_InclineMotor.h"


/**
 *
 * Runnable InclineMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppInclineMotor_Opr_InclineMotorMove
 *
 */

void InclineMotor_Move (StepMotorStepType Step)
{
	Std_ReturnType status;

	/* Server Call Points */
	if(Step==MOTOR_STEP_PLUS)
	status = Rte_Call_rpIoSetIncline_IOSetForward();
	else if(Step==MOTOR_STEP_MINUS)
	status = Rte_Call_rpIoSetIncline_IOSetReverse();
	
}

