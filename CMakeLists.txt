cmake_minimum_required(VERSION 3.6)
project(SequenceAP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp List_SequenceForm.h List_LinkForm.h List_StaticLinkForm.h)
add_executable(SequenceAP ${SOURCE_FILES})