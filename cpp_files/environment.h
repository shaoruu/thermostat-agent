#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
class Environment
{
private:
  int temperature = 0;

  static Environment *instance;

  Environment();

public:
  static Environment *getInstance();

  double incrTemp(double inc);
  double decrTemp(double dec);

  void update();

  double getTemp();
};
#endif