
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
# ifndef MATLAB_MEX_FILE

#include <Arduino.h>

#include <math.h>

#include <Wire.h>
#include <Wire.cpp>
#include <twi.h>
#include <twi.c>
#include <VL53L0X.h>
#include <VL53L0X.cpp>
#define XSHUT2 43
#define XSHUT3 45
#define sensor2_newAddress 42
#define sensor3_newAddress 43
VL53L0X sensor1;
VL53L0X sensor2;
VL53L0X sensor3;

#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
extern "C" void Sensores_VL53L0X_I2C_Outputs_wrapper(int32_T *Sensor1,
			int32_T *Sensor2,
			int32_T *Sensor3,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0]==1) {
    
    /* don't do anything for mex file generation */
    # ifndef MATLAB_MEX_FILE
    
Sensor1[0] = sensor1.readRangeContinuousMillimeters();
Sensor2[0] = sensor2.readRangeContinuousMillimeters();
Sensor3[0] = sensor3.readRangeContinuousMillimeters();
    
    # endif
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
extern "C" void Sensores_VL53L0X_I2C_Update_wrapper(int32_T *Sensor1,
			int32_T *Sensor2,
			int32_T *Sensor3,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0]!=1) {

    /* don't do anything for mex file generation */
# ifndef MATLAB_MEX_FILE
        
 
  pinMode(XSHUT2, OUTPUT);
  pinMode(XSHUT3, OUTPUT);
  Wire.begin();
  delay(10);
  
  sensor3.setAddress(sensor3_newAddress);
  pinMode(XSHUT3, INPUT);
  delay(10);
  sensor2.setAddress(sensor2_newAddress);
  pinMode(XSHUT2, INPUT);                                                                                              
  delay(10);
    
  sensor1.init();
  sensor2.init();
  sensor3.init();
  sensor1.setTimeout(5000);
  sensor2.setTimeout(5000);
  sensor3.setTimeout(5000);
  sensor1.startContinuous();
  sensor2.startContinuous();
  sensor3.startContinuous();
    
        # endif
    
    /* initialization done */ 
    xD[0]=1;
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

