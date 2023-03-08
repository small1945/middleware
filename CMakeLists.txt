cmake_minimum_required(VERSION 3.0)

project(TEST)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -Wall -pthread")
include_directories(${CMAKE_SOURCE_DIR}/Timer/include)

# add_executable(TimeTest.out
#                test/TimeTest.cpp
#                src/CBuffer.cpp
#                src/CLogfile.cpp
#                src/CLogstream.cpp
#                src/CTime.cpp
#                )

add_executable(
               TimerTest.out
               test/TimerTest.cpp
               Timer/src/CTimerManager.cpp
               Timer/src/CTimer.cpp
               Timer/src/CTime.cpp
               Timer/src/CTimerqueue.cpp
               )
             
             