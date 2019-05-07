project(graph_algos)
cmake_minimum_required(VERSION 3.5)
add_definitions(-std=c++11)

if(NOT WIN32)
  string(ASCII 27 Esc)
  set(ColourReset "${Esc}[m")
  set(Red         "${Esc}[31m")
  set(Green       "${Esc}[32m")
  set(Yellow      "${Esc}[33m")
  set(Blue        "${Esc}[34m")
  set(White       "${Esc}[37m")
endif()

set(CXX_FLAGS "-w")
set(CMAKE_CXX_FLAGS "${CXX_FLAGS} -std=c++11 -pthread")

include_directories(${CMAKE_SOURCE_DIR}/inc)

file(GLOB LIB_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/inc/*)
file(GLOB LIB_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*)
list( REMOVE_ITEM LIB_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/utils.cpp )

add_library(utils SHARED ${CMAKE_CURRENT_SOURCE_DIR}/src/utils.cpp)

message("${Blue} Individual files being built ${ColourReset}")
foreach(test_source_file ${LIB_SOURCES})
  string( REPLACE ".cpp" "" test_output_file ${test_source_file} )
  string( REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/src/" "" test_output_file ${test_output_file} )
  message( ${test_output_file} )
  add_executable( ${test_output_file} ${test_source_file} ${LIB_HEADERS})
  target_link_libraries( ${test_output_file} utils )
endforeach(test_source_file ${LIB_SOURCES})
message( "${Blue}End of list ${ColourReset}" )
