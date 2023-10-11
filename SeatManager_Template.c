/**
 *
 * \file SeatManager_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SeatManager
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 9/26/2023 05:53 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SeatManager.h"


/**
 *
 * Runnable SeatManager_AutoHeight
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoHeight_200ms
 *
 */
  bool AdjPosition(StepMotorStepType *Step,MultuStateBtnType position, MultuStateBtnType weight)
 {
	bool needed = true;
	switch(position)
	{
		
		case SENSOR_POSITION_STEP_0:
		 	if(weight>60) Step= MOTOR_STEP_PLUS;
			else needed= false;
		 	break;
		 case SENSOR_POSITION_STEP_1:
			if(80>weight>60) needed=false;
			if(weight<60) Step= MOTOR_STEP_MINUS;
			else Step= MOTOR_STEP_PLUS; // >80
			break;
		case SENSOR_POSITION_STEP_2:
			if(weight<80) Step= MOTOR_STEP_MINUS;
			else if(100>weight>80)  needed=false;
			else Step= MOTOR_STEP_PLUS; 
			break;
		case SENSOR_POSITION_STEP_3:
			if(weight<100)  Step= MOTOR_STEP_MINUS;
			esle needed=false;

	}
	return needed;
 }


void SeatManager_AutoHeight (void)
{
	Std_ReturnType status;
	StepMotorStepType Step;
	MultuStateBtnType position;
	MultuStateBtnType weight;

	/* Server Call Points */
	
	status = Rte_Call_rpHeightSensor_GetHeightPosition(&position);
	status = Rte_Call_rpWeightSensor_GetWeight(&weight);
	// 
	if(AdjPosition(&Step,position,weight);)
	status = Rte_Call_rpHeightMotor_Opr_HeightMotorMove(Step);
}


/**
 *
 * Runnable SeatManager_AutoIncline
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoIncline_200ms
 *
 */

void SeatManager_AutoIncline (void)
{
	Std_ReturnType status;
	StepMotorStepType Step;
	MultuStateBtnType position;
	MultuStateBtnType weight;

	/* Server Call Points */
	
	status = Rte_Call_rpInclineSensor_GetInclinePosition(&position);
	status = Rte_Call_rpWeightSensor_GetWeight(&weight);
	
	if(AdjPosition(&Step,position,weight))
	status = Rte_Call_rpInclineMotor_Opr_HeightMotorMove(Step);
}


/**
 *
 * Runnable SeatManager_AutoSlide
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoSlide_200ms
 *
 */

void SeatManager_AutoSlide (void)
{
	Std_ReturnType status;
	StepMotorStepType Step;
	MultuStateBtnType position;
	MultuStateBtnType weight;

	/* Server Call Points */
	
	status = Rte_Call_rpSlideSensor_GetSlidePosition(&position);
	status = Rte_Call_rpWeightSensor_GetWeight(&weight);
	if(AdjPosition(&Step,position,weight);)
	status = Rte_Call_rpSlideMotor_Opr_SlideMotorMove(Step);
}


/**
 *
 * Runnable SeatManager_SetHeight
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_HeightBtnState
 *
 */

/**
 *
 * \file SeatManager_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SeatManager
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 9/25/2023 09:38 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */



/**
 *
 * Runnable SeatManager_SetHeight
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_HeightBtnState
 *
 */

void SeatManager_SetHeight (void)
{
	Std_ReturnType status;
	MultiStateBtnType HeightBtnState;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_HeightBtnState(&HeightBtnState);
	if(HeightBtnState == MULTI_STATE_BTN_MINUS)
		Rte_Call_rpHeightMotor_Move(MOTOR_STEP_MINUS);
	else if(HeightBtnState == MULTI_STATE_BTN_PLUS)
		Rte_Call_rpHeightMotor_Move(MOTOR_STEP_PLUS);
}


/**
 *
 * Runnable SeatManager_SetIncline
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_InclineBtnState
 *
 */

void SeatManager_SetIncline (void)
{
	Std_ReturnType status;
	MultiStateBtnType InclineBtnState;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_InclineBtnState(&InclineBtnState);
	if(InclineBtnState == MULTI_STATE_BTN_MINUS)
		Rte_Call_rpInclineMotor_Move(MOTOR_STEP_MINUS);
	else if(InclineBtnState == MULTI_STATE_BTN_PLUS)
		Rte_Call_rpInclineMotor_Move(MOTOR_STEP_PLUS);
}


/**
 *
 * Runnable SeatManager_SetSlide
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_SlideBtnState
 *
 */

void SeatManager_SetSlide (void)
{
	Std_ReturnType status;
	MultiStateBtnType SlideBtnState;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_SlideBtnState(&SlideBtnState);
	if(SlideBtnState == MULTI_STATE_BTN_MINUS)
		Rte_Call_rpSlideMotor_Move(MOTOR_STEP_MINUS);
	else if(SlideBtnState == MULTI_STATE_BTN_PLUS)
		Rte_Call_rpSlideMotor_Move(MOTOR_STEP_PLUS);
}

