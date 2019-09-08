#include "environment.h"

class Agent
{
private:
  static Agent *instance;

  Agent();

public:
  static Agent *getInstance();

  void sense();
  void decide();
  void act();
};
