#ifndef debug_h

  #define debug_h
  
  #include <Arduino.h>
  
  //-------------------------  VARIABLES  -------------------------  
  
  extern bool debug;

  //-------------------------  FUNCIONES  -------------------------  
  
  void debugFunction (String debugMsg,bool line);
  
#endif
