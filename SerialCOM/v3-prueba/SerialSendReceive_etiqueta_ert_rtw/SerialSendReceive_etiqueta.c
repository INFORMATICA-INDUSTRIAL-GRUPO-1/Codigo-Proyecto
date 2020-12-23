#include "__cf_SerialSendReceive_etiqueta.h"
#include "SerialSendReceive_etiqueta.h"
#include "SerialSendReceive_etiqueta_private.h"
#include "SerialSendReceive_etiqueta_dt.h"
ebhzclbyr4 ebhzclbyr4h ; fqtrsoriac fqtrsoriac0 ; static omz5fpy4jn
ko4lmggyew_ ; omz5fpy4jn * const ko4lmggyew = & ko4lmggyew_ ; static void
rate_scheduler ( void ) ; void mul_wide_s32 ( int32_T in0 , int32_T in1 ,
uint32_T * ptrOutBitsHi , uint32_T * ptrOutBitsLo ) { uint32_T absIn0 ;
uint32_T absIn1 ; uint32_T in0Hi ; uint32_T in0Lo ; uint32_T in1Hi ; uint32_T
productHiLo ; uint32_T productLoHi ; absIn0 = in0 < _aWd3gbBrc_Jy1c_Zu6M8Q1 ?
~ ( uint32_T ) in0 + _iH_Kzj_enDaacwnT_H0mk0 : ( uint32_T ) in0 ; absIn1 =
in1 < _aWd3gbBrc_Jy1c_Zu6M8Q1 ? ~ ( uint32_T ) in1 + _iH_Kzj_enDaacwnT_H0mk0
: ( uint32_T ) in1 ; in0Hi = absIn0 >> _yyyX1zEDAY_yCFxar7Tzo1 ; in0Lo =
absIn0 & _bDpu7APnIO_c9kogj6zPd1 ; in1Hi = absIn1 >> _yyyX1zEDAY_yCFxar7Tzo1
; absIn0 = absIn1 & _bDpu7APnIO_c9kogj6zPd1 ; productHiLo = in0Hi * absIn0 ;
productLoHi = in0Lo * in1Hi ; absIn0 *= in0Lo ; absIn1 =
_dWsPtmyX92L8Xr5uhF_Oz0 ; in0Lo = ( productLoHi << _yyyX1zEDAY_yCFxar7Tzo1 )
+ absIn0 ; if ( in0Lo < absIn0 ) { absIn1 = _iH_Kzj_enDaacwnT_H0mk0 ; }
absIn0 = in0Lo ; in0Lo += productHiLo << _yyyX1zEDAY_yCFxar7Tzo1 ; if ( in0Lo
< absIn0 ) { absIn1 ++ ; } absIn0 = ( ( ( productLoHi >>
_yyyX1zEDAY_yCFxar7Tzo1 ) + ( productHiLo >> _yyyX1zEDAY_yCFxar7Tzo1 ) ) +
in0Hi * in1Hi ) + absIn1 ; if ( ( in0 != _aWd3gbBrc_Jy1c_Zu6M8Q1 ) && ( ( in1
!= _aWd3gbBrc_Jy1c_Zu6M8Q1 ) && ( ( in0 > _aWd3gbBrc_Jy1c_Zu6M8Q1 ) != ( in1
> _aWd3gbBrc_Jy1c_Zu6M8Q1 ) ) ) ) { absIn0 = ~ absIn0 ; in0Lo = ~ in0Lo ;
in0Lo ++ ; if ( in0Lo == _dWsPtmyX92L8Xr5uhF_Oz0 ) { absIn0 ++ ; } } *
ptrOutBitsHi = absIn0 ; * ptrOutBitsLo = in0Lo ; } int32_T mul_s32_hiSR (
int32_T a , int32_T b , uint32_T aShift ) { uint32_T u32_chi ; uint32_T
u32_clo ; mul_wide_s32 ( a , b , & u32_chi , & u32_clo ) ; return ( int32_T )
u32_chi >> aShift ; } static void rate_scheduler ( void ) { ( ko4lmggyew ->
Timing . TaskCounters . TID [ _QHNSjd8JBrVVYZAcs7Zm32 ] ) ++ ; if ( (
ko4lmggyew -> Timing . TaskCounters . TID [ _QHNSjd8JBrVVYZAcs7Zm32 ] ) >
_aoel664zPcTjzpXADn7l40 ) { ko4lmggyew -> Timing . TaskCounters . TID [
_QHNSjd8JBrVVYZAcs7Zm32 ] = _PIqWtbzrbQqv_KS_31HnE2 ; } ( ko4lmggyew ->
Timing . TaskCounters . TID [ _gN74BbsU5wqNjkJbC9b672 ] ) ++ ; if ( (
ko4lmggyew -> Timing . TaskCounters . TID [ _gN74BbsU5wqNjkJbC9b672 ] ) >
_Q8Zx6w1Ri_gAqqAnlebNg1 ) { ko4lmggyew -> Timing . TaskCounters . TID [
_gN74BbsU5wqNjkJbC9b672 ] = _PIqWtbzrbQqv_KS_31HnE2 ; } } real_T
rt_roundd_snf ( real_T u ) { real_T y ; if ( fabs ( u ) <
_mf_qXIpI67Q5cqiNut81q2 ) { if ( u >= _IE_h0ySUMKhEY_mtQbaOn_ ) { y = floor (
u + _IE_h0ySUMKhEY_mtQbaOn_ ) ; } else if ( u > - _IE_h0ySUMKhEY_mtQbaOn_ ) {
y = u * _Z77Ee2RGrs6HvPP38e_Kk_ ; } else { y = ceil ( u -
_IE_h0ySUMKhEY_mtQbaOn_ ) ; } } else { y = u ; } return y ; } void
SerialSendReceive_etiqueta_step ( void ) { static const char_T tmp_p [
_aoel664zPcTjzpXADn7l40 ] = "s\145\x6e\163\x6fr\145\x73" ; real_T tmp ;
int16_T i ; char_T labelTerminated [ _aoel664zPcTjzpXADn7l40 ] ; uint8_T
dataIn [ _t0CSRdt0cj28FWcY3kSLw_ ] ; uint8_T o3yfx1sqbi [
_KYlcoOk9rSSGYswizhYqZ2 ] ; Sensores_VL53L0X_I2C_Outputs_wrapper ( &
ebhzclbyr4h . giqeouty1t , & ebhzclbyr4h . pbs5mwmqrj , & fqtrsoriac0 .
bcedhddhvb ) ; ebhzclbyr4h . gwltblspoh [ _PIqWtbzrbQqv_KS_31HnE2 ] =
ebhzclbyr4h . giqeouty1t ; ebhzclbyr4h . gwltblspoh [ _QHNSjd8JBrVVYZAcs7Zm32
] = ebhzclbyr4h . pbs5mwmqrj ; ebhzclbyr4h . hkii005xpr [
_PIqWtbzrbQqv_KS_31HnE2 ] = ( uint8_T ) mul_s32_hiSR ( oh2zabronu .
Gain1_Gain , ebhzclbyr4h . gwltblspoh [ _PIqWtbzrbQqv_KS_31HnE2 ] ,
_FybvBdhErrG_jS08oUVod1 ) ; ebhzclbyr4h . hkii005xpr [
_QHNSjd8JBrVVYZAcs7Zm32 ] = ( uint8_T ) mul_s32_hiSR ( oh2zabronu .
Gain1_Gain , ebhzclbyr4h . gwltblspoh [ _QHNSjd8JBrVVYZAcs7Zm32 ] ,
_FybvBdhErrG_jS08oUVod1 ) ; for ( i = _PIqWtbzrbQqv_KS_31HnE2 ; i <
_KYlcoOk9rSSGYswizhYqZ2 ; i ++ ) { tmp = floor ( oh2zabronu . Gain_Gain *
oh2zabronu . Constant2_Value [ i ] ) ; if ( rtIsNaN ( tmp ) || rtIsInf ( tmp
) ) { tmp = _Z77Ee2RGrs6HvPP38e_Kk_ ; } else { tmp = fmod ( tmp ,
_mV7fMPW7aO3s7_nIRdzCv1 ) ; } o3yfx1sqbi [ i ] = ( uint8_T ) ( tmp <
_Z77Ee2RGrs6HvPP38e_Kk_ ? ( int16_T ) ( uint8_T ) - ( int8_T ) ( uint8_T ) -
tmp : ( int16_T ) ( uint8_T ) tmp ) ; } if ( ko4lmggyew -> Timing .
TaskCounters . TID [ _gN74BbsU5wqNjkJbC9b672 ] == _PIqWtbzrbQqv_KS_31HnE2 ) {
fqtrsoriac0 . chlkmcuptj [ _PIqWtbzrbQqv_KS_31HnE2 ] = oh2zabronu .
Constant6_Value ; fqtrsoriac0 . chlkmcuptj [ _QHNSjd8JBrVVYZAcs7Zm32 ] =
oh2zabronu . Constant6_Value ; fqtrsoriac0 . chlkmcuptj [
_gN74BbsU5wqNjkJbC9b672 ] = oh2zabronu . Constant_Value ; fqtrsoriac0 .
chlkmcuptj [ _nfvdmbxYkVXzXnpHyWwmg2 ] = ebhzclbyr4h . hkii005xpr [
_PIqWtbzrbQqv_KS_31HnE2 ] ; fqtrsoriac0 . chlkmcuptj [
_g7WFphbd05O6bEjctOzUc1 ] = oh2zabronu . Constant1_Value ; fqtrsoriac0 .
chlkmcuptj [ _KYlcoOk9rSSGYswizhYqZ2 ] = ebhzclbyr4h . hkii005xpr [
_QHNSjd8JBrVVYZAcs7Zm32 ] ; fqtrsoriac0 . chlkmcuptj [
_RAQgyWVtpyqfEVcLRZFTL_ ] = oh2zabronu . Constant3_Value ; fqtrsoriac0 .
chlkmcuptj [ _2KXuAphrqc_TLcinUGD4E1 ] = o3yfx1sqbi [ _gN74BbsU5wqNjkJbC9b672
] ; fqtrsoriac0 . chlkmcuptj [ _hCXUd_x6pbKZfXtyKXEw82 ] = oh2zabronu .
Constant4_Value ; fqtrsoriac0 . chlkmcuptj [ _aoel664zPcTjzpXADn7l40 ] =
o3yfx1sqbi [ _nfvdmbxYkVXzXnpHyWwmg2 ] ; fqtrsoriac0 . chlkmcuptj [
_IjHdoOm5hGk4VAbwwsvcL1 ] = oh2zabronu . Constant5_Value ; fqtrsoriac0 .
chlkmcuptj [ _9rHO1ek1Om1saeRq2pf3_0 ] = o3yfx1sqbi [ _g7WFphbd05O6bEjctOzUc1
] ; for ( i = _PIqWtbzrbQqv_KS_31HnE2 ; i < _t0CSRdt0cj28FWcY3kSLw_ ; i ++ )
{ ebhzclbyr4h . hsrk1r2bkt [ i ] = fqtrsoriac0 . chlkmcuptj [ i ] ; } if (
fqtrsoriac0 . a31elyyjaa . Protocol != oh2zabronu . SerialTransmit_Protocol )
{ fqtrsoriac0 . a31elyyjaa . Protocol = oh2zabronu . SerialTransmit_Protocol
; } for ( i = _PIqWtbzrbQqv_KS_31HnE2 ; i < _t0CSRdt0cj28FWcY3kSLw_ ; i ++ )
{ dataIn [ i ] = ebhzclbyr4h . hsrk1r2bkt [ i ] ; } for ( i =
_PIqWtbzrbQqv_KS_31HnE2 ; i < _aoel664zPcTjzpXADn7l40 ; i ++ ) {
labelTerminated [ i ] = tmp_p [ i ] ; } MW_Serial_write ( fqtrsoriac0 .
a31elyyjaa . port , & dataIn [ _PIqWtbzrbQqv_KS_31HnE2 ] ,
__3qf8mu_7Sc40t6xdY2j4_ , fqtrsoriac0 . a31elyyjaa . dataSizeInBytes ,
fqtrsoriac0 . a31elyyjaa . sendModeEnum , fqtrsoriac0 . a31elyyjaa . dataType
, fqtrsoriac0 . a31elyyjaa . sendFormatEnum , _IfqgJOo_0kGGrK4yerXJx_ , &
labelTerminated [ _PIqWtbzrbQqv_KS_31HnE2 ] ) ; } if ( ko4lmggyew -> Timing .
TaskCounters . TID [ _QHNSjd8JBrVVYZAcs7Zm32 ] == _PIqWtbzrbQqv_KS_31HnE2 ) {
if ( fqtrsoriac0 . e5wtxf33l1 . Protocol != oh2zabronu .
SerialReceive_Protocol ) { fqtrsoriac0 . e5wtxf33l1 . Protocol = oh2zabronu .
SerialReceive_Protocol ; } MW_Serial_read ( _nfvdmbxYkVXzXnpHyWwmg2 ,
fqtrsoriac0 . e5wtxf33l1 . DataSizeInBytes , & ebhzclbyr4h . fi5qrvpi1g [
_PIqWtbzrbQqv_KS_31HnE2 ] , & ebhzclbyr4h . k55qp225xb ) ; }
Sensores_VL53L0X_I2C_Update_wrapper ( & ebhzclbyr4h . giqeouty1t , &
ebhzclbyr4h . pbs5mwmqrj , & fqtrsoriac0 . bcedhddhvb ) ;
rtExtModeUploadCheckTrigger ( _nfvdmbxYkVXzXnpHyWwmg2 ) ; { rtExtModeUpload (
_PIqWtbzrbQqv_KS_31HnE2 , ( real_T ) ko4lmggyew -> Timing . taskTime0 ) ; }
if ( ko4lmggyew -> Timing . TaskCounters . TID [ _QHNSjd8JBrVVYZAcs7Zm32 ] ==
_PIqWtbzrbQqv_KS_31HnE2 ) { rtExtModeUpload ( _QHNSjd8JBrVVYZAcs7Zm32 , (
real_T ) ( ( ( ko4lmggyew -> Timing . clockTick1 + ko4lmggyew -> Timing .
clockTickH1 * _Nn3DUUbvuyRrgaA48_gSO0 ) ) * _mFnttH_CHRfmeN2fhYikZ2 ) ) ; }
if ( ko4lmggyew -> Timing . TaskCounters . TID [ _gN74BbsU5wqNjkJbC9b672 ] ==
_PIqWtbzrbQqv_KS_31HnE2 ) { rtExtModeUpload ( _gN74BbsU5wqNjkJbC9b672 , (
real_T ) ( ( ( ko4lmggyew -> Timing . clockTick2 + ko4lmggyew -> Timing .
clockTickH2 * _Nn3DUUbvuyRrgaA48_gSO0 ) ) * _p01KwLUrlxQyp_iCq4iLA2 ) ) ; } {
if ( ( rtmGetTFinal ( ko4lmggyew ) != - _QHNSjd8JBrVVYZAcs7Zm32 ) && ! ( (
rtmGetTFinal ( ko4lmggyew ) - ko4lmggyew -> Timing . taskTime0 ) > ko4lmggyew
-> Timing . taskTime0 * ( DBL_EPSILON ) ) ) { rtmSetErrorStatus ( ko4lmggyew
, "\123\x69\155\x75l\141\x74\151\x6f\156 \x66\151\x6e\151\x73he\144" ) ; } if
( rtmGetStopRequested ( ko4lmggyew ) ) { rtmSetErrorStatus ( ko4lmggyew ,
"\123\x69\155\x75l\141\x74\151\x6f\156 \x66\151\x6e\151\x73he\144" ) ; } } if
( ! ( ++ ko4lmggyew -> Timing . clockTick0 ) ) { ++ ko4lmggyew -> Timing .
clockTickH0 ; } ko4lmggyew -> Timing . taskTime0 = ko4lmggyew -> Timing .
clockTick0 * ko4lmggyew -> Timing . stepSize0 + ko4lmggyew -> Timing .
clockTickH0 * ko4lmggyew -> Timing . stepSize0 * _Nn3DUUbvuyRrgaA48_gSO0 ; if
( ko4lmggyew -> Timing . TaskCounters . TID [ _QHNSjd8JBrVVYZAcs7Zm32 ] ==
_PIqWtbzrbQqv_KS_31HnE2 ) { ko4lmggyew -> Timing . clockTick1 ++ ; if ( !
ko4lmggyew -> Timing . clockTick1 ) { ko4lmggyew -> Timing . clockTickH1 ++ ;
} } if ( ko4lmggyew -> Timing . TaskCounters . TID [ _gN74BbsU5wqNjkJbC9b672
] == _PIqWtbzrbQqv_KS_31HnE2 ) { ko4lmggyew -> Timing . clockTick2 ++ ; if (
! ko4lmggyew -> Timing . clockTick2 ) { ko4lmggyew -> Timing . clockTickH2 ++
; } } rate_scheduler ( ) ; } void SerialSendReceive_etiqueta_initialize (
void ) { rt_InitInfAndNaN ( sizeof ( real_T ) ) ; ( void ) memset ( ( void *
) ko4lmggyew , _PIqWtbzrbQqv_KS_31HnE2 , sizeof ( omz5fpy4jn ) ) ;
rtmSetTFinal ( ko4lmggyew , - _QHNSjd8JBrVVYZAcs7Zm32 ) ; ko4lmggyew ->
Timing . stepSize0 = _9sORNlLawtAqgKqUzCJc20 ; ko4lmggyew -> Sizes .
checksums [ _PIqWtbzrbQqv_KS_31HnE2 ] = ( _OaxDkp5FEEVdZttIYwf6T2 ) ;
ko4lmggyew -> Sizes . checksums [ _QHNSjd8JBrVVYZAcs7Zm32 ] = (
_iF2bCtvjeqfsnHGH9LLsq2 ) ; ko4lmggyew -> Sizes . checksums [
_gN74BbsU5wqNjkJbC9b672 ] = ( _IIZs1Q_cX3LPZkeLBnlmO0 ) ; ko4lmggyew -> Sizes
. checksums [ _nfvdmbxYkVXzXnpHyWwmg2 ] = ( _6RfCYAYQpyCrNYp5pvvZn1 ) ; {
static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static
RTWExtModeInfo rt_ExtModeInfo ; static const sysRanDType * systemRan [
_nfvdmbxYkVXzXnpHyWwmg2 ] ; ko4lmggyew -> extModeInfo = ( & rt_ExtModeInfo )
; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ _PIqWtbzrbQqv_KS_31HnE2 ] = & rtAlwaysEnabled ; systemRan [
_QHNSjd8JBrVVYZAcs7Zm32 ] = & rtAlwaysEnabled ; systemRan [
_gN74BbsU5wqNjkJbC9b672 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ko4lmggyew -> extModeInfo , & ko4lmggyew -> SpecialInfo . mappingInfo ) ;
rteiSetChecksumsPtr ( ko4lmggyew -> extModeInfo , ko4lmggyew -> Sizes .
checksums ) ; rteiSetTPtr ( ko4lmggyew -> extModeInfo , rtmGetTPtr (
ko4lmggyew ) ) ; } ( void ) memset ( ( ( void * ) & ebhzclbyr4h ) ,
_PIqWtbzrbQqv_KS_31HnE2 , sizeof ( ebhzclbyr4 ) ) ; ( void ) memset ( ( void
* ) & fqtrsoriac0 , _PIqWtbzrbQqv_KS_31HnE2 , sizeof ( fqtrsoriac ) ) ; {
static DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) & dtInfo ,
_PIqWtbzrbQqv_KS_31HnE2 , sizeof ( dtInfo ) ) ; ko4lmggyew -> SpecialInfo .
mappingInfo = ( & dtInfo ) ; dtInfo . numDataTypes = _JJlCQ5gAz2DYzHC9O21lX2
; dtInfo . dataTypeSizes = & rtDataTypeSizes [ _PIqWtbzrbQqv_KS_31HnE2 ] ;
dtInfo . dataTypeNames = & rtDataTypeNames [ _PIqWtbzrbQqv_KS_31HnE2 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; } { real_T tmp ; uint8_T tmp_p ; fqtrsoriac0 . a31elyyjaa .
matlabCodegenIsDeleted = false ; fqtrsoriac0 . lenk4esffu = true ;
fqtrsoriac0 . a31elyyjaa . Protocol = oh2zabronu . SerialTransmit_Protocol ;
fqtrsoriac0 . a31elyyjaa . isInitialized = _mR8zwDRVQf6fD24pj1BlT1 ;
fqtrsoriac0 . a31elyyjaa . port = __HOkNYCCIgIkrPMzfarLc2 ; fqtrsoriac0 .
a31elyyjaa . dataSizeInBytes = _p01KwLUrlxQyp_iCq4iLA2 ; fqtrsoriac0 .
a31elyyjaa . dataType = _Z77Ee2RGrs6HvPP38e_Kk_ ; fqtrsoriac0 . a31elyyjaa .
sendModeEnum = _Z77Ee2RGrs6HvPP38e_Kk_ ; fqtrsoriac0 . a31elyyjaa .
sendFormatEnum = _Z77Ee2RGrs6HvPP38e_Kk_ ; tmp = rt_roundd_snf ( fqtrsoriac0
. a31elyyjaa . port ) ; if ( tmp < _mV7fMPW7aO3s7_nIRdzCv1 ) { if ( tmp >=
_Z77Ee2RGrs6HvPP38e_Kk_ ) { tmp_p = ( uint8_T ) tmp ; } else { tmp_p =
_TPQ_vWWUSL7ze3htINC_W2 ; } } else { tmp_p = MAX_uint8_T ; } MW_SCI_Open (
tmp_p ) ; fqtrsoriac0 . a31elyyjaa . isSetupComplete = true ; fqtrsoriac0 .
e5wtxf33l1 . matlabCodegenIsDeleted = false ; fqtrsoriac0 . dr3gt0fkg4 = true
; fqtrsoriac0 . e5wtxf33l1 . Protocol = oh2zabronu . SerialReceive_Protocol ;
fqtrsoriac0 . e5wtxf33l1 . isInitialized = _mR8zwDRVQf6fD24pj1BlT1 ;
fqtrsoriac0 . e5wtxf33l1 . DataTypeWidth = _TlYaTpHyOy3h9kx50A0_s2 ; if (
fqtrsoriac0 . e5wtxf33l1 . DataTypeWidth > _oaFk_GdzNa8LqA4kdwvwh_ ) {
fqtrsoriac0 . e5wtxf33l1 . DataSizeInBytes = MAX_uint16_T ; } else {
fqtrsoriac0 . e5wtxf33l1 . DataSizeInBytes = fqtrsoriac0 . e5wtxf33l1 .
DataTypeWidth << _QHNSjd8JBrVVYZAcs7Zm32 ; } MW_SCI_Open (
_nfvdmbxYkVXzXnpHyWwmg2 ) ; fqtrsoriac0 . e5wtxf33l1 . isSetupComplete = true
; } { real_T initVector [ _QHNSjd8JBrVVYZAcs7Zm32 ] = {
_PIqWtbzrbQqv_KS_31HnE2 } ; { int_T i1 ; for ( i1 = _PIqWtbzrbQqv_KS_31HnE2 ;
i1 < _QHNSjd8JBrVVYZAcs7Zm32 ; i1 ++ ) { fqtrsoriac0 . bcedhddhvb =
initVector [ _PIqWtbzrbQqv_KS_31HnE2 ] ; } } } } void
SerialSendReceive_etiqueta_terminate ( void ) { if ( ! fqtrsoriac0 .
a31elyyjaa . matlabCodegenIsDeleted ) { fqtrsoriac0 . a31elyyjaa .
matlabCodegenIsDeleted = true ; } if ( ! fqtrsoriac0 . e5wtxf33l1 .
matlabCodegenIsDeleted ) { fqtrsoriac0 . e5wtxf33l1 . matlabCodegenIsDeleted
= true ; } }
