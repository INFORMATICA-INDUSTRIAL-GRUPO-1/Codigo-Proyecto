#include "__cf_SerialSendReceive_etiqueta.h"
#ifndef RTW_HEADER_SerialSendReceive_etiqueta_h_
#define RTW_HEADER_SerialSendReceive_etiqueta_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef SerialSendReceive_etiqueta_COMMON_INCLUDES_
#define SerialSendReceive_etiqueta_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#endif
#include "SerialSendReceive_etiqueta_types.h"
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm) ((rtm)->Timing.tFinal)
#endif
#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm) ((rtm)->extModeInfo)
#endif
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm) ((rtm)->errorStatus)
#endif
#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val) ((rtm)->errorStatus = (val))
#endif
#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm) ((rtm)->Timing.stopRequestedFlag)
#endif
#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif
#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm) (&((rtm)->Timing.stopRequestedFlag))
#endif
#ifndef rtmGetT
#define rtmGetT(rtm) ((rtm)->Timing.taskTime0)
#endif
#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm) ((rtm)->Timing.tFinal)
#endif
#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm) (&(rtm)->Timing.taskTime0)
#endif
#define SerialSendReceive_etiqueta_M (ko4lmggyew)
typedef struct { int32_T giqeouty1t ; int32_T pbs5mwmqrj ; int32_T gwltblspoh
[ _gN74BbsU5wqNjkJbC9b672 ] ; uint8_T hkii005xpr [ _gN74BbsU5wqNjkJbC9b672 ]
; uint8_T hsrk1r2bkt [ _t0CSRdt0cj28FWcY3kSLw_ ] ; uint8_T fi5qrvpi1g [
_gN74BbsU5wqNjkJbC9b672 ] ; uint8_T k55qp225xb ; } ebhzclbyr4 ; typedef
struct { npd2rltvhp a31elyyjaa ; hqypsi2h3z e5wtxf33l1 ; real_T bcedhddhvb ;
struct { void * LoggedData ; } lzen10p5iv ; uint8_T chlkmcuptj [
_t0CSRdt0cj28FWcY3kSLw_ ] ; boolean_T lenk4esffu ; boolean_T dr3gt0fkg4 ; }
fqtrsoriac ; struct oh2zabronud_ { real_T SerialReceive_Protocol ; real_T
SerialTransmit_Protocol ; real_T Constant2_Value [ _KYlcoOk9rSSGYswizhYqZ2 ]
; real_T Gain_Gain ; int32_T Gain1_Gain ; uint8_T Constant6_Value ; uint8_T
Constant_Value ; uint8_T Constant1_Value ; uint8_T Constant3_Value ; uint8_T
Constant4_Value ; uint8_T Constant5_Value ; } ; struct mtta1czkyb { const
char_T * errorStatus ; RTWExtModeInfo * extModeInfo ; struct { uint32_T
checksums [ _g7WFphbd05O6bEjctOzUc1 ] ; } Sizes ; struct { const void *
mappingInfo ; } SpecialInfo ; struct { time_T taskTime0 ; uint32_T clockTick0
; uint32_T clockTickH0 ; time_T stepSize0 ; uint32_T clockTick1 ; uint32_T
clockTickH1 ; uint32_T clockTick2 ; uint32_T clockTickH2 ; struct { uint8_T
TID [ _nfvdmbxYkVXzXnpHyWwmg2 ] ; } TaskCounters ; time_T tFinal ; boolean_T
stopRequestedFlag ; } Timing ; } ; extern oh2zabronud oh2zabronu ; extern
ebhzclbyr4 ebhzclbyr4h ; extern fqtrsoriac fqtrsoriac0 ; extern void
SerialSendReceive_etiqueta_initialize ( void ) ; extern void
SerialSendReceive_etiqueta_step ( void ) ; extern void
SerialSendReceive_etiqueta_terminate ( void ) ; extern omz5fpy4jn * const
ko4lmggyew ; extern volatile boolean_T stopRequested ; extern volatile
boolean_T runModel ;
#endif
