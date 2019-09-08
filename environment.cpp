#include "environment.h"

Environment::Environment() {}

Environment *Environment::instance = 0;

Environment *Environment::getInstance()
{
  if (instance == 0)
    instance = new Environment();
  return instance;
}

double Environment::incrTemp(double inc)
{
  temperature += inc;
  return temperature;
}

double Environment::decrTemp(double dec)
{
  temperature -= dec;
  return temperature;
}

double Environment::getTemp() { return temperature; }
