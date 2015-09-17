#project vector test
SET(CMAKE_CXX_COMPILER "clang++")
SET(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -g -Wall")
ADD_EXECUTABLE(vector_test vector_test.cpp myvector.cpp)
ADD_EXECUTABLE(list_test list_test.cpp)
ADD_EXECUTABLE(tree_test Tree/tree_test.cpp)
ADD_EXECUTABLE(sort_test algor/sort_test.cpp algor/Sort.cpp)
ADD_EXECUTABLE(heap_test Heap/BinaryHeap.cpp Heap/headp_test.cpp)