#ifndef MOCKS_H
#define MOCKS_H

#define MOCK_MAX_EXPECTATIONS       (16)


typedef struct {
  int kind;
  void *args;
  void *ret;
} MockExpectation_t;


int
MocksInit(void);

int
MocksExpect(MockExpectation_t *expectation);

int
MocksInvoke(MockExpectation_t *expectation);

int
MocksVerify(void);

#endif /* MOCKS_H */

