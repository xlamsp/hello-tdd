#include <stdlib.h>
#include "mocks.h"


static MockExpectation_t expectations[MOCK_MAX_EXPECTATIONS];
static int expectedCount;
static int invokedCount;
static int failureRegistered;


static int
expectCheckPreconditions(MockExpectation_t *expectation)
{
  if (failureRegistered) {
    return EXIT_FAILURE;
  }

  if (expectation == NULL) {
    return EXIT_FAILURE;
  }

  if (expectedCount >= MOCK_MAX_EXPECTATIONS) {
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

static int
invokeCheckPreconditions(MockExpectation_t *expectation)
{
  if (failureRegistered) {
    return EXIT_FAILURE;
  }

  if (expectation == NULL) {
    return EXIT_FAILURE;
  }

  if (invokedCount >= expectedCount) {
    return EXIT_FAILURE;
  }

  if (expectation->kind != expectations[invokedCount].kind) {
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}


int
MocksInit(void)
{
  expectedCount = 0;
  invokedCount = 0;
  failureRegistered = 0;

  return EXIT_SUCCESS;
}

int
MocksExpect(MockExpectation_t *expectation)
{
  if (expectCheckPreconditions(expectation) != EXIT_SUCCESS) {
    failureRegistered = 1;
    return EXIT_FAILURE;
  }

  expectations[expectedCount++] = *expectation;

  return EXIT_SUCCESS;
}

int
MocksInvoke(MockExpectation_t *expectation)
{
  if (invokeCheckPreconditions(expectation) != EXIT_SUCCESS) {
    failureRegistered = 1;
    return EXIT_FAILURE;
  }

  *expectation = expectations[invokedCount++];

  return EXIT_SUCCESS;
}

int
MocksVerify(void)
{
  if (failureRegistered) {
    return EXIT_FAILURE;
  }

  if (expectedCount != invokedCount) {
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

