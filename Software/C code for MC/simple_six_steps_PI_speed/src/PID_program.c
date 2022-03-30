/*******************************************************************************************/
/*			Auther 		: Ezzeldin Magdy                                                   */
/*			Version 	: v02                                                              */
/*			Date		: 6/2/2022														   */
/*******************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PID_interface.h"
#include "PID_private.h"
#include "PID_config.h"

void PIDController_Init   (PIDController * pid )
{
	/*	Clear Controller Variables	*/
	pid ->  I_term          = 0.0f ;
	pid -> D_term		   = 0.0f ;
	pid -> PrevError       = 0.0f ;
    pid -> PrevMeasurement = 0.0f ; 
	pid -> Output 		   = 0.0f ;
}                        
f32 PIDController_Update (PIDController * pid ,f32  SetPoint , f32  Measurement ){
	/*	Error Signals 	*/
	f32  Error =  SetPoint - Measurement ;
	
	/*	Proportional term	*/
	f32  P_term = pid -> Kp * Error ;
	
	/*	Integral term 		*/
	//pid -> I_term += 0.5f   pid -> T * (Error +( pid -> PrevError));
	
	/*	Anti windup via dynamic integrator clamping 	*/
	f32  LimMinInt , LimMaxInt ;
	/*	compute integral limits 	*/
	if (pid->LimMax > P_term)
	{
		LimMaxInt = pid->LimMax - P_term;
	}
	else 
	{
		LimMaxInt = 0.0f ;
	}
	
	if (pid->LimMin < P_term)
	{
		LimMinInt = pid->LimMin - P_term;
	}
	else 
	{
		LimMinInt = 0.0f ;
	}
	/*	clamp Integrator 	*/
	if (pid->I_term > LimMaxInt)
	{
		pid->I_term = LimMaxInt;
	}
	if (pid->I_term < LimMinInt)
	{
		pid->I_term = LimMinInt;
	}
	/*  derivative term		*/
	/*	pid -> Differentiator = (   2.0 * pid -> Kd  * (Error - PrevError) 
						     +  2.0 * pid -> Tau - pid -> T  * Differentiator )
						     / (2.0 * pid -> Tau + pid -> T ) ;*/
	/* Elimination of Impulsive effect 	*/
	pid -> D_term = (2.0 * pid -> Kd  * ( pid -> PrevMeasurement - Measurement )
						     +  2.0 * pid -> Tau - pid -> T  * pid->D_term )
						     / (2.0 * pid -> Tau + pid -> T );
					
	/*	Compute the output and apply limits clamping */
	pid -> Output = P_term + pid->I_term + pid->D_term ;
	if ( pid -> Output > pid -> LimMax)
	{	 
	pid -> Output = pid -> LimMax ;	
	}
	else if ( pid -> Output < pid -> LimMin)
	{	 
	pid -> Output = pid -> LimMin ;	
	}
	
	/*	assign error and memsurement for later use  */
	pid -> PrevError   		= Error        ;
	pid -> PrevMeasurement  = Measurement  ;
	return pid -> Output ;
}


