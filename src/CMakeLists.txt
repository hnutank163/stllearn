#project vector test
SET(CMAKE_CXX_COMPILER "clang++")
SET(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -g -Wall")
ADD_EXECUTABLE(vector_test vector_test.cpp )
ADD_EXECUTABLE(list_test list_test.cpp)
ADD_EXECUTABLE(tree_test Tree/tree_test.cpp)

