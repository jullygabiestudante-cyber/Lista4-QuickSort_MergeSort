cmake_minimum_required(VERSION 4.3)

project(ed2___advanced___sorting___list04)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Exer01_MergeSortCountInversions
        src/Exer01_MergeSortCountInversions.cpp
)

add_executable(Exer02_StabilityMergeSortVsQuickSort
        src/Exer02_StabilityMergeSortVsQuickSort.cpp
)

add_executable(Exer03_QuickselectLomutoKthLargest
        src/Exer03_QuickselectLomutoKthLargest.cpp
)

add_executable(Exer04_HoarePartitionParitySort
        src/Exer04_HoarePartitionParitySort.cpp
)