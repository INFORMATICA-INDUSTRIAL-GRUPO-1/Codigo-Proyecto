#include "__cf_SerialSendReceive_etiqueta.h"
#include "SerialSendReceive_etiqueta.h"
#include "rtwtypes.h"
#include <ext_work.h>
#include <ext_svr.h>
#include <ext_share.h>
#include <updown.h>
volatile int IsrOverrun = _PIqWtbzrbQqv_KS_31HnE2 ; static boolean_T
OverrunFlag = _PIqWtbzrbQqv_KS_31HnE2 ; void rt_OneStep ( void ) { if (
OverrunFlag ++ ) { IsrOverrun = _QHNSjd8JBrVVYZAcs7Zm32 ; OverrunFlag -- ;
return ; }
#ifndef _MW_ARDUINO_LOOP_ 
sei ( ) ;
#endif
; SerialSendReceive_etiqueta_step ( ) ;
#ifndef _MW_ARDUINO_LOOP_ 
cli ( ) ;
#endif
; OverrunFlag -- ; rtExtModeCheckEndTrigger ( ) ; } volatile boolean_T
stopRequested ; volatile boolean_T runModel ; int main ( void ) { float
modelBaseRate = _9sORNlLawtAqgKqUzCJc20 ; float systemClock =
_PIqWtbzrbQqv_KS_31HnE2 ; stopRequested = false ; runModel = false ; init ( )
; MW_Arduino_Init ( ) ; rtmSetErrorStatus ( ko4lmggyew ,
_PIqWtbzrbQqv_KS_31HnE2 ) ; rtParseArgsForExtMode ( _PIqWtbzrbQqv_KS_31HnE2 ,
NULL ) ; SerialSendReceive_etiqueta_initialize ( ) ; cli ( ) ; sei ( ) ;
rtSetTFinalForExtMode ( & rtmGetTFinal ( ko4lmggyew ) ) ; rtExtModeCheckInit
( _nfvdmbxYkVXzXnpHyWwmg2 ) ; { boolean_T rtmStopReq = false ;
rtExtModeWaitForStartPkt ( ko4lmggyew -> extModeInfo ,
_nfvdmbxYkVXzXnpHyWwmg2 , & rtmStopReq ) ; if ( rtmStopReq ) {
rtmSetStopRequested ( ko4lmggyew , true ) ; } } rtERTExtModeStartMsg ( ) ;
cli ( ) ; configureArduinoAVRTimer ( ) ; runModel = ( rtmGetErrorStatus (
ko4lmggyew ) == ( NULL ) ) && ! rtmGetStopRequested ( ko4lmggyew ) ;
#ifndef _MW_ARDUINO_LOOP_ 
sei ( ) ;
#endif
; sei ( ) ; while ( runModel ) { { boolean_T rtmStopReq = false ;
rtExtModeOneStep ( ko4lmggyew -> extModeInfo , _nfvdmbxYkVXzXnpHyWwmg2 , &
rtmStopReq ) ; if ( rtmStopReq ) { rtmSetStopRequested ( ko4lmggyew , true )
; } } stopRequested = ! ( ( rtmGetErrorStatus ( ko4lmggyew ) == ( NULL ) ) &&
! rtmGetStopRequested ( ko4lmggyew ) ) ; runModel = ! ( stopRequested ) ;
MW_Arduino_Loop ( ) ; } SerialSendReceive_etiqueta_terminate ( ) ;
rtExtModeShutdown ( _nfvdmbxYkVXzXnpHyWwmg2 ) ; cli ( ) ; return
_PIqWtbzrbQqv_KS_31HnE2 ; }
