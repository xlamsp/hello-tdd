#include "driver_led.h"
#include "mocks.h"
#include "mocksArduino.h"

#include "unity_fixture.h"

TEST_GROUP(DriverLed);

TEST_SETUP(DriverLed)
{
  TEST_ASSERT_EQUAL_MESSAGE(EXIT_SUCCESS, MocksInit(), "in TEST_SETUP");
}

TEST_TEAR_DOWN(DriverLed)
{
}

TEST(DriverLed, InitializationSystemCalls)
{
  mocks_pinMode_t args_pinMode = {
    .pin = 10,
    .mode = OUTPUT
  };
  MockExpectation_t expect_pinMode = {
    .kind = mocks_pinMode,
    .args = &args_pinMode,
    .ret  = NULL
  };

  TEST_ASSERT_EQUAL(EXIT_SUCCESS, MocksExpect(&expect_pinMode));
  driver_led_init();
  TEST_ASSERT_EQUAL(EXIT_SUCCESS, MocksVerify());
}

