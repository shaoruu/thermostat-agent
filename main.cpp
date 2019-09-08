#include <iostream>

#include "environment.h"
#include "agent.h"

using namespace std;

int main()
{
  Environment *env = Environment::getInstance();
  Agent *agent = Agent::getInstance();

  agent->sense();
}