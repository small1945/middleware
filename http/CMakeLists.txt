cmake_minimum_required(VERSION 3.0)

project(TEST)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -Wall -pthread")
include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(httptest test/test.cpp src/CHttpcontext.cpp src/CHttprequest.cpp src/CHttpserver.cpp src/CHttpresponse.cpp )