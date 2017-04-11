CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(example-c++)

INCLUDE_DIRECTORIES(
  ${LIBRARY_INCLUDE_DIR}
  ./armadillo-7.800.2/include/
)

SET(SOURCE
  main.cpp
)

#SET(CMAKE_CXX_FLAGS "-pthread -g -std=c++11 -DARMA_DONT_USE_WRAPPER -L./usr/lib64 -lblas -llapack")
SET(CMAKE_CXX_FLAGS "-pthread -g -std=c++11 -lblas -llapack")
ADD_EXECUTABLE(a.out ${SOURCE})

TARGET_LINK_LIBRARIES(a.out)
