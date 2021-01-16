  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 10;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Control_Telegram_P)
    ;%
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% Control_Telegram_P.PIDIzda_D
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Telegram_P.PIDDcha_D
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Control_Telegram_P.PIDDcha_I
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Control_Telegram_P.PIDIzda_I
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Control_Telegram_P.DiscreteDerivative_ICPrevScaled
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Control_Telegram_P.PIDIzda_InitialConditionForFilt
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Control_Telegram_P.PIDDcha_InitialConditionForFilt
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Control_Telegram_P.PIDIzda_InitialConditionForInte
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Control_Telegram_P.PIDDcha_InitialConditionForInte
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Control_Telegram_P.PIDIzda_LowerSaturationLimit
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Control_Telegram_P.PIDDcha_LowerSaturationLimit
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Control_Telegram_P.PIDIzda_N
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Control_Telegram_P.PIDDcha_N
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Control_Telegram_P.PIDIzda_P
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Control_Telegram_P.PIDDcha_P
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Control_Telegram_P.PIDIzda_UpperSaturationLimit
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Control_Telegram_P.PIDDcha_UpperSaturationLimit
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Control_Telegram_P.CompareToConstant1_const
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Telegram_P.CompareToConstant_const
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 30;
      section.data(30)  = dumData; %prealloc
      
	  ;% Control_Telegram_P.Constant_Value
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Telegram_P.SerialReceive_Protocol
	  section.data(2).logicalSrcIdx = 20;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Control_Telegram_P.SerialTransmit_Protocol
	  section.data(3).logicalSrcIdx = 21;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Control_Telegram_P.azulobs_izq_Value
	  section.data(4).logicalSrcIdx = 22;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Control_Telegram_P.obs_izq_Threshold
	  section.data(5).logicalSrcIdx = 23;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Control_Telegram_P.amarilloobs_dcha_Value
	  section.data(6).logicalSrcIdx = 24;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Control_Telegram_P.obs_dcha_Threshold
	  section.data(7).logicalSrcIdx = 25;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Control_Telegram_P.Switch1_Threshold
	  section.data(8).logicalSrcIdx = 26;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Control_Telegram_P.rojoparpadeando_Value
	  section.data(9).logicalSrcIdx = 27;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Control_Telegram_P.Constant10_Value
	  section.data(10).logicalSrcIdx = 28;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Control_Telegram_P.Constant8_Value
	  section.data(11).logicalSrcIdx = 29;
	  section.data(11).dtTransOffset = 11;
	
	  ;% Control_Telegram_P.Bateria_SampleTime
	  section.data(12).logicalSrcIdx = 30;
	  section.data(12).dtTransOffset = 12;
	
	  ;% Control_Telegram_P.Constant9_Value
	  section.data(13).logicalSrcIdx = 31;
	  section.data(13).dtTransOffset = 13;
	
	  ;% Control_Telegram_P.Memory_InitialCondition
	  section.data(14).logicalSrcIdx = 32;
	  section.data(14).dtTransOffset = 14;
	
	  ;% Control_Telegram_P.Integrator_gainval
	  section.data(15).logicalSrcIdx = 33;
	  section.data(15).dtTransOffset = 15;
	
	  ;% Control_Telegram_P.Filter_gainval
	  section.data(16).logicalSrcIdx = 34;
	  section.data(16).dtTransOffset = 16;
	
	  ;% Control_Telegram_P.Integrator_gainval_p
	  section.data(17).logicalSrcIdx = 35;
	  section.data(17).dtTransOffset = 17;
	
	  ;% Control_Telegram_P.Filter_gainval_n
	  section.data(18).logicalSrcIdx = 36;
	  section.data(18).dtTransOffset = 18;
	
	  ;% Control_Telegram_P.PulseGenerator_Amp
	  section.data(19).logicalSrcIdx = 37;
	  section.data(19).dtTransOffset = 19;
	
	  ;% Control_Telegram_P.PulseGenerator_Period
	  section.data(20).logicalSrcIdx = 38;
	  section.data(20).dtTransOffset = 20;
	
	  ;% Control_Telegram_P.PulseGenerator_Duty
	  section.data(21).logicalSrcIdx = 39;
	  section.data(21).dtTransOffset = 21;
	
	  ;% Control_Telegram_P.PulseGenerator_PhaseDelay
	  section.data(22).logicalSrcIdx = 40;
	  section.data(22).dtTransOffset = 22;
	
	  ;% Control_Telegram_P.Switch_Threshold
	  section.data(23).logicalSrcIdx = 41;
	  section.data(23).dtTransOffset = 23;
	
	  ;% Control_Telegram_P.DataStoreMemory_InitialValue
	  section.data(24).logicalSrcIdx = 42;
	  section.data(24).dtTransOffset = 24;
	
	  ;% Control_Telegram_P.Constant11_Value
	  section.data(25).logicalSrcIdx = 43;
	  section.data(25).dtTransOffset = 25;
	
	  ;% Control_Telegram_P.Saturation_UpperSat
	  section.data(26).logicalSrcIdx = 44;
	  section.data(26).dtTransOffset = 26;
	
	  ;% Control_Telegram_P.Saturation_LowerSat
	  section.data(27).logicalSrcIdx = 45;
	  section.data(27).dtTransOffset = 27;
	
	  ;% Control_Telegram_P.verde_Value
	  section.data(28).logicalSrcIdx = 46;
	  section.data(28).dtTransOffset = 28;
	
	  ;% Control_Telegram_P.Switch_Threshold_p
	  section.data(29).logicalSrcIdx = 47;
	  section.data(29).dtTransOffset = 29;
	
	  ;% Control_Telegram_P.DataStoreMemory1_InitialValue
	  section.data(30).logicalSrcIdx = 48;
	  section.data(30).dtTransOffset = 30;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Control_Telegram_P.TSamp_WtEt
	  section.data(1).logicalSrcIdx = 49;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Control_Telegram_P.TmpRTBAtSwitch1Inport1_InitialC
	  section.data(1).logicalSrcIdx = 50;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Telegram_P.Saturation1_UpperSat
	  section.data(2).logicalSrcIdx = 51;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Control_Telegram_P.Saturation1_LowerSat
	  section.data(3).logicalSrcIdx = 52;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Control_Telegram_P.Gain1_Gain
	  section.data(1).logicalSrcIdx = 53;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Telegram_P.Gain_Gain
	  section.data(2).logicalSrcIdx = 54;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% Control_Telegram_P.MdeloRuedaIzda_InitialStates
	  section.data(1).logicalSrcIdx = 55;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Telegram_P.MdeloRuedaDcha_InitialStates
	  section.data(2).logicalSrcIdx = 56;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Control_Telegram_P.Saturation3_UpperSat
	  section.data(3).logicalSrcIdx = 57;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Control_Telegram_P.Saturation3_LowerSat
	  section.data(4).logicalSrcIdx = 58;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Control_Telegram_P.Saturation2_UpperSat
	  section.data(5).logicalSrcIdx = 59;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Control_Telegram_P.Saturation2_LowerSat
	  section.data(6).logicalSrcIdx = 60;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Control_Telegram_P.Saturation1_UpperSat_k
	  section.data(7).logicalSrcIdx = 61;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Control_Telegram_P.Saturation1_LowerSat_p
	  section.data(8).logicalSrcIdx = 62;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Control_Telegram_P.Saturation_UpperSat_o
	  section.data(9).logicalSrcIdx = 63;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Control_Telegram_P.Saturation_LowerSat_f
	  section.data(10).logicalSrcIdx = 64;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Control_Telegram_P.MdeloRuedaIzda_DenCoef
	  section.data(11).logicalSrcIdx = 65;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Control_Telegram_P.MdeloRuedaDcha_DenCoef
	  section.data(12).logicalSrcIdx = 66;
	  section.data(12).dtTransOffset = 12;
	
	  ;% Control_Telegram_P.Gain2_Gain
	  section.data(13).logicalSrcIdx = 67;
	  section.data(13).dtTransOffset = 14;
	
	  ;% Control_Telegram_P.Gain_Gain_d
	  section.data(14).logicalSrcIdx = 68;
	  section.data(14).dtTransOffset = 15;
	
	  ;% Control_Telegram_P.MdeloRuedaIzda_NumCoef
	  section.data(15).logicalSrcIdx = 69;
	  section.data(15).dtTransOffset = 16;
	
	  ;% Control_Telegram_P.MdeloRuedaDcha_NumCoef
	  section.data(16).logicalSrcIdx = 70;
	  section.data(16).dtTransOffset = 17;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Control_Telegram_P.Gain_Gain_n
	  section.data(1).logicalSrcIdx = 71;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Control_Telegram_P.SwitchControl_Value
	  section.data(1).logicalSrcIdx = 72;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% Control_Telegram_P.q_Y0
	  section.data(1).logicalSrcIdx = 73;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Telegram_P.encoders_P1
	  section.data(2).logicalSrcIdx = 74;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Control_Telegram_P.encoders_P2
	  section.data(3).logicalSrcIdx = 75;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Control_Telegram_P.encoders_P3
	  section.data(4).logicalSrcIdx = 76;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Control_Telegram_P.encoders_P4
	  section.data(5).logicalSrcIdx = 77;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Control_Telegram_P.encoders_P5
	  section.data(6).logicalSrcIdx = 78;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Control_Telegram_P.encoders_P6
	  section.data(7).logicalSrcIdx = 79;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Control_Telegram_P.Constant_Value_c
	  section.data(8).logicalSrcIdx = 80;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Control_Telegram_P.Constant1_Value
	  section.data(9).logicalSrcIdx = 81;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Control_Telegram_P.Constant3_Value
	  section.data(10).logicalSrcIdx = 82;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Control_Telegram_P.Constant4_Value
	  section.data(11).logicalSrcIdx = 83;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Control_Telegram_P.Constant5_Value
	  section.data(12).logicalSrcIdx = 84;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Control_Telegram_P.Constant6_Value
	  section.data(13).logicalSrcIdx = 85;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Control_Telegram_P.Constant7_Value
	  section.data(14).logicalSrcIdx = 86;
	  section.data(14).dtTransOffset = 13;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Control_Telegram_B)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Control_Telegram_B.TmpRTBAtSwitch1Inport1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Telegram_B.Gain1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% Control_Telegram_B.DataStoreRead
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Telegram_B.Diff
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Control_Telegram_B.NumericalUnity
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 3;
	
	  ;% Control_Telegram_B.DataTypeConversion
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 5;
	
	  ;% Control_Telegram_B.Saturation
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 7;
	
	  ;% Control_Telegram_B.v_d
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 9;
	
	  ;% Control_Telegram_B.v_i
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 10;
	
	  ;% Control_Telegram_B.modo
	  section.data(8).logicalSrcIdx = 9;
	  section.data(8).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Control_Telegram_B.encoders
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Telegram_B.SFunctionBuilder_o1
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Control_Telegram_B.SFunctionBuilder_o2
	  section.data(3).logicalSrcIdx = 12;
	  section.data(3).dtTransOffset = 3;
	
	  ;% Control_Telegram_B.TmpSignalConversionAtGain1Inpor
	  section.data(4).logicalSrcIdx = 13;
	  section.data(4).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Control_Telegram_B.Saturation3
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Telegram_B.Saturation_h
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% Control_Telegram_B.Gain2
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Telegram_B.Gain
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Control_Telegram_B.DataTypeConversion_g
	  section.data(3).logicalSrcIdx = 18;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Control_Telegram_B.RateTransition
	  section.data(4).logicalSrcIdx = 19;
	  section.data(4).dtTransOffset = 4;
	
	  ;% Control_Telegram_B.SerialReceive_o1
	  section.data(5).logicalSrcIdx = 20;
	  section.data(5).dtTransOffset = 22;
	
	  ;% Control_Telegram_B.SerialReceive_o2
	  section.data(6).logicalSrcIdx = 21;
	  section.data(6).dtTransOffset = 23;
	
	  ;% Control_Telegram_B.In1
	  section.data(7).logicalSrcIdx = 22;
	  section.data(7).dtTransOffset = 24;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Control_Telegram_B.Compare
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Telegram_B.Compare_a
	  section.data(2).logicalSrcIdx = 24;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 13;
    sectIdxOffset = 6;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Control_Telegram_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Control_Telegram_DW.obj
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Control_Telegram_DW.obj_b
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Control_Telegram_DW.obj_c
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Control_Telegram_DW.obj_d
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Telegram_DW.obj_p
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Control_Telegram_DW.obj_n
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Control_Telegram_DW.obj_l
	  section.data(4).logicalSrcIdx = 6;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Control_Telegram_DW.obj_e
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Telegram_DW.obj_eu
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Control_Telegram_DW.obj_m
	  section.data(3).logicalSrcIdx = 9;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Control_Telegram_DW.obj_j
	  section.data(4).logicalSrcIdx = 10;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Control_Telegram_DW.obj_l0
	  section.data(5).logicalSrcIdx = 11;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% Control_Telegram_DW.encoders_DSTATE
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Telegram_DW.UD_DSTATE
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Control_Telegram_DW.Integrator_DSTATE
	  section.data(3).logicalSrcIdx = 14;
	  section.data(3).dtTransOffset = 3;
	
	  ;% Control_Telegram_DW.Filter_DSTATE
	  section.data(4).logicalSrcIdx = 15;
	  section.data(4).dtTransOffset = 4;
	
	  ;% Control_Telegram_DW.Integrator_DSTATE_o
	  section.data(5).logicalSrcIdx = 16;
	  section.data(5).dtTransOffset = 5;
	
	  ;% Control_Telegram_DW.Filter_DSTATE_o
	  section.data(6).logicalSrcIdx = 17;
	  section.data(6).dtTransOffset = 6;
	
	  ;% Control_Telegram_DW.SFunctionBuilder_DSTATE
	  section.data(7).logicalSrcIdx = 18;
	  section.data(7).dtTransOffset = 7;
	
	  ;% Control_Telegram_DW.Memory_PreviousInput
	  section.data(8).logicalSrcIdx = 19;
	  section.data(8).dtTransOffset = 8;
	
	  ;% Control_Telegram_DW.led
	  section.data(9).logicalSrcIdx = 20;
	  section.data(9).dtTransOffset = 10;
	
	  ;% Control_Telegram_DW.VBateria
	  section.data(10).logicalSrcIdx = 21;
	  section.data(10).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Control_Telegram_DW.TmpRTBAtSwitch1Inport1_Buffer0
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Control_Telegram_DW.Scope1_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Telegram_DW.Scope_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 24;
	  section.data(2).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Control_Telegram_DW.clockTickCounter
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Control_Telegram_DW.is_c3_Control_Telegram
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Control_Telegram_DW.MdeloRuedaIzda_states
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Telegram_DW.MdeloRuedaDcha_states
	  section.data(2).logicalSrcIdx = 29;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Control_Telegram_DW.EnabledSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Control_Telegram_DW.RateTransition_Buffer
	  section.data(1).logicalSrcIdx = 33;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Telegram_DW.is_active_c3_Control_Telegram
	  section.data(2).logicalSrcIdx = 34;
	  section.data(2).dtTransOffset = 18;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 381385820;
  targMap.checksum1 = 3917662077;
  targMap.checksum2 = 3816226728;
  targMap.checksum3 = 1364095386;

