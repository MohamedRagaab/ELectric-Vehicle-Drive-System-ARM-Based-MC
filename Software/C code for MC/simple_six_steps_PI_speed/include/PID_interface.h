/*******************************************************************************************/
/*			Auther 		: Ezzeldin Magdy                                                   */
/*			Version 	: v02                                                              */
/*			Date		: 6/2/2022														   */
/*******************************************************************************************/
#ifndef PID_INTERFACE_H
#define PID_INTERFACE_H

typedef struct {
	//	to be placed in config file 
	/*	Controller Gains 	*/
	f32 Kp  ;
	f32 Ki  ;
	f32 Kd  ;
	/*	Derivative Low Pass filter time constant 	*/
	f32  Tau ;
	/*	Sample Time In Secconds		*/
	f32  T ;
	/*	Output Limits 	*/
	f32  LimMin ; 
	f32  LimMax ; 
	/*	Controller Memory 	*/
	f32  I_term           ;
	f32  D_term	          ;
	f32  PrevError        ;
	f32  PrevMeasurement  ;
	/*	Controller Output 	*/
	f32  Output ;
	
} PIDController ;
/* PID Controller functions */
void PIDController_Init    (PIDController * pid );
f32  PIDController_Update  (PIDController * pid ,f32  SetPoint , f32  measurement );

#endif 