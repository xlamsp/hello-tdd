#include "unity_fixture.h"

static void RunAllTests(void)
{
  RUN_TEST_GROUP(Mocks);
  RUN_TEST_GROUP(DriverLed);
}

int main(int argc, const char **argv)
{
  return UnityMain(argc, argv, RunAllTests);
}

