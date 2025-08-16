#include <Arduino.h>
#include "definations___variable.h"

extern int readLineSensors(int* out);

// Compute line error: center=3500; left negative, right positive
int computeLineError(){
  int pos = readLineSensors(sensorVal); // 0..7000 or -1 if lost
  if(pos < 0) return 0; // line lost: keep going straight (or implement search)
  return pos - 3500;
}
