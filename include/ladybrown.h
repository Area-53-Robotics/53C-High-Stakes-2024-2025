
enum LadyBrownState {
  Start,
  Load,
  RideUp,
  Score,
};

extern LadyBrownState ladyBrownPos;

void LadyBrownTask(void *param);