#include <iostream>

#include "agent.h"
#include "environment.h"

using namespace std;

Agent::Agent() {}

Agent *Agent::instance = 0;

Agent *Agent::getInstance()
{
  if (instance == 0)
    instance = new Agent();
  return instance;
}

void Agent::sense()
{
  cout << Environment::getInstance()->getTemp() << endl;
}