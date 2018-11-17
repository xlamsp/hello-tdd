#include "unity_fixture.h"

TEST_GROUP_RUNNER(Mocks)
{
  RUN_TEST_CASE(Mocks, ExpectNull);
  RUN_TEST_CASE(Mocks, ExpectOne);
  RUN_TEST_CASE(Mocks, ExpectMax);
  RUN_TEST_CASE(Mocks, ExpectAfterFailure);
  RUN_TEST_CASE(Mocks, InvokeWithoutExpect);
  RUN_TEST_CASE(Mocks, InvokeNull);
  RUN_TEST_CASE(Mocks, InvokeAfterFailure);
  RUN_TEST_CASE(Mocks, InvokeAfterExpect);
  RUN_TEST_CASE(Mocks, InvokeAfterExpectNotMatch);
  RUN_TEST_CASE(Mocks, InvokeAfterExpectMatchArgsAndRet);
  RUN_TEST_CASE(Mocks, InvokeAfterExpectWrongOrder);
  RUN_TEST_CASE(Mocks, InvokeMoreThanExpected);
  RUN_TEST_CASE(Mocks, VerifyEmptyList);
  RUN_TEST_CASE(Mocks, VerifyExpectWithoutInvoke);
  RUN_TEST_CASE(Mocks, VerifyExpectMatchInvoke);
  RUN_TEST_CASE(Mocks, VerifyAfterExpectFailure);
  RUN_TEST_CASE(Mocks, VerifyAfterInvokeFailure);
}

