
enum LadyBrownState {
  Start,
  Load,
  RideUp,
  Score,
  
  Auton,
  Test,
};

extern LadyBrownState ladyBrownPos;

void setLadyBrown(LadyBrownState state);
void LadyBrownTask(void *param);