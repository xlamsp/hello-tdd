#include <stdlib.h>
#include "mocks.h"
#include "unity_fixture.h"

TEST_GROUP(Mocks);

TEST_SETUP(Mocks)
{
  TEST_ASSERT_EQUAL_MESSAGE(EXIT_SUCCESS, MocksInit(), "in TEST_SETUP");
}

TEST_TEAR_DOWN(Mocks)
{
}

TEST(Mocks, ExpectNull)
{
  TEST_ASSERT_NOT_EQUAL(EXIT_SUCCESS, MocksExpect(NULL));
}

TEST(Mocks, ExpectOne)
{
  MockExpectation_t expectation = {0, NULL, NULL};
  TEST_ASSERT_EQUAL(EXIT_SUCCESS, MocksExpect(&expectation));
}

TEST(Mocks, ExpectMax)
{
  int i;
  MockExpectation_t expectation = {0, NULL, NULL};
  for (i = 0; i < MOCK_MAX_EXPECTATIONS; i++) {
    TEST_ASSERT_EQUAL(EXIT_SUCCESS, MocksExpect(&expectation));
  }
  TEST_ASSERT_NOT_EQUAL(EXIT_SUCCESS, MocksExpect(&expectation));
}

TEST(Mocks, ExpectAfterFailure)
{
  MockExpectation_t expectation = {0, NULL, NULL};
  MocksExpect(NULL); /* Failure */
  TEST_ASSERT_NOT_EQUAL(EXIT_SUCCESS, MocksExpect(&expectation));
}

TEST(Mocks, InvokeWithoutExpect)
{
  MockExpectation_t expectation = {0, NULL, NULL};
  TEST_ASSERT_NOT_EQUAL(EXIT_SUCCESS, MocksInvoke(&expectation));
}

TEST(Mocks, InvokeAfterExpect)
{
  MockExpectation_t expectation = {0, NULL, NULL};
  MocksExpect(&expectation);
  TEST_ASSERT_EQUAL(EXIT_SUCCESS, MocksInvoke(&expectation));
}

TEST(Mocks, InvokeNull)
{
  MockExpectation_t expectation = {0, NULL, NULL};
  MocksExpect(&expectation);
  TEST_ASSERT_NOT_EQUAL(EXIT_SUCCESS, MocksInvoke(NULL));
}

TEST(Mocks, InvokeAfterFailure)
{
  MockExpectation_t expectation = {0, NULL, NULL};
  MocksExpect(&expectation);
  MocksInvoke(NULL); /* Failure */
  TEST_ASSERT_NOT_EQUAL(EXIT_SUCCESS, MocksInvoke(&expectation));
}

TEST(Mocks, InvokeAfterExpectNotMatch)
{
  MockExpectation_t expectation = {0, NULL, NULL};
  MocksExpect(&expectation);
  expectation.kind = 1;
  TEST_ASSERT_NOT_EQUAL(EXIT_SUCCESS, MocksInvoke(&expectation));
}

TEST(Mocks, InvokeAfterExpectMatchArgsAndRet)
{
  int expected_args = 100;
  int expected_ret = 200;
  MockExpectation_t expectation = {0, &expected_args, &expected_ret};
  MockExpectation_t invocation = {0, NULL, NULL};
  MocksExpect(&expectation);
  MocksInvoke(&invocation);
  TEST_ASSERT_NOT_NULL(invocation.args);
  TEST_ASSERT_NOT_NULL(invocation.ret);
  TEST_ASSERT_EQUAL(100, *((int*)(invocation.args)));
  TEST_ASSERT_EQUAL(200, *((int*)(invocation.ret)));
}

TEST(Mocks, InvokeAfterExpectWrongOrder)
{
  MockExpectation_t expectationA = {0, NULL, NULL};
  MockExpectation_t expectationB = {1, NULL, NULL};
  MocksExpect(&expectationA);
  MocksExpect(&expectationB);
  TEST_ASSERT_NOT_EQUAL(EXIT_SUCCESS, MocksInvoke(&expectationB));
}

TEST(Mocks, InvokeMoreThanExpected)
{
  MockExpectation_t expectationA = {0, NULL, NULL};
  MockExpectation_t expectationB = {1, NULL, NULL};

  /* preparation phase */
  MocksExpect(&expectationA);
  MocksExpect(&expectationB);
  MocksInit();

  /* actual testing */
  MocksExpect(&expectationA);
  MocksInvoke(&expectationA);
  TEST_ASSERT_NOT_EQUAL(EXIT_SUCCESS, MocksInvoke(&expectationB));
}

TEST(Mocks, VerifyEmptyList)
{
  TEST_ASSERT_EQUAL(EXIT_SUCCESS, MocksVerify());
}

TEST(Mocks, VerifyExpectWithoutInvoke)
{
  MockExpectation_t expectation = {0, NULL, NULL};
  MocksExpect(&expectation);
  TEST_ASSERT_NOT_EQUAL(EXIT_SUCCESS, MocksVerify());
}

TEST(Mocks, VerifyExpectMatchInvoke)
{
  MockExpectation_t expectation = {0, NULL, NULL};
  MocksExpect(&expectation);
  MocksInvoke(&expectation);
  TEST_ASSERT_EQUAL(EXIT_SUCCESS, MocksVerify());
}

TEST(Mocks, VerifyAfterExpectFailure)
{
  MocksExpect(NULL); /* Failure */
  TEST_ASSERT_NOT_EQUAL(EXIT_SUCCESS, MocksVerify());
}

TEST(Mocks, VerifyAfterInvokeFailure)
{
  MockExpectation_t expectation = {0, NULL, NULL};
  MocksExpect(&expectation);
  MocksInvoke(NULL); /* Failure */
  MocksInvoke(&expectation);
  TEST_ASSERT_NOT_EQUAL(EXIT_SUCCESS, MocksVerify());
}

