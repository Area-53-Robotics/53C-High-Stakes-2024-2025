class LadyBrown {
  enum LadyBrownState {
    Start,
    Load,
    RideUp,
    Score,
    Test,
  };

public:
  LadyBrownState ladyBrownPos;

  LadyBrown();

  void setLadyBrown(LadyBrownState state);
  static void LadyBrownTask(void *param);
};