
enum LadyBrownState {
  Start,
  Load,
  RideUp,
  Score,

  Test,
};

extern LadyBrownState ladyBrownPos;

void setLadyBrown(LadyBrownState state);
void LadyBrownTask(void *param);