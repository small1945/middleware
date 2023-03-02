cmake_minimum_required(VERSION 3.0)

project(TEST)



set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -Wall -pthread -lmysqlclient")
include_directories(/usr/include/mysql)
include_directories(${CMAKE_SOURCE_DIR}/include)






add_executable(
               sqlpooltest
               src/CMysqlpool.cpp
               src/CMysqlconn.cpp
               src/CMysqlrecordset.cpp
               test/test.cpp
               )
             
target_link_libraries(sqlpooltest mysqlclient)
   