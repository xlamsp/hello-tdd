#include "mocks.h"
#include "mocksArduino.h"

void
pinMode(uint8_t pin, uint8_t mode)
{
  mocks_pinMode_t *args_pinMode;
  MockExpectation_t expect_pinMode = {
    .kind = mocks_pinMode
  };
  TEST_ASSERT_EQUAL(EXIT_SUCCESS, MocksInvoke(&expect_pinMode));
  args_pinMode = (mocks_pinMode_t*)expect_pinMode.args;
  TEST_ASSERT_NOT_NULL_MESSAGE(args_pinMode, "pinMode(): null args");
  TEST_ASSERT_EQUAL_MESSAGE(args_pinMode->pin, pin, "pinMode(): bad pin");
  TEST_ASSERT_EQUAL_MESSAGE(args_pinMode->mode, mode, "pinMode(): bad mode");
}



