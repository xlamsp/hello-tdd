#Set this to @ to keep the makefile quiet
#SILENCE = @

#---- Outputs ----#
COMPONENT_NAME = hello_tdd

#--- Inputs ----#
UNITY_HOME = unity
PROJECT_HOME_DIR = .
PROJECT_TEST_DIR = tests
#CPP_PLATFORM = Gcc
UNITY_BUILD_HOME = unity

#UNITY_CFLAGS += -DUNITY_OUTPUT_CHAR=UnityOutputCharSpy_OutputChar
UNITY_WARNINGFLAGS = -Wall -Werror -Wswitch-default
#UNITY_WARNINGFLAGS += -Wshadow 

SRC_DIRS = \
	$(PROJECT_HOME_DIR)/src

TEST_SRC_DIRS = \
	$(PROJECT_TEST_DIR) \
	$(UNITY_HOME)

MOCKS_SRC_DIRS = \
	$(PROJECT_TEST_DIR)/mocks

INCLUDE_DIRS = \
	.\
	$(UNITY_HOME) \
	$(PROJECT_HOME_DIR)/mocks
  
include $(UNITY_BUILD_HOME)/MakefileWorker.mk
