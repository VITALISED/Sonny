cmake_minimum_required(VERSION 3.15)

project(
  sonny
  LANGUAGES CXX
  VERSION 0.1.0)

set(
    SONNY_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/sonny/sonny.h
    )

add_library(sonny INTERFACE)

set_property(TARGET sonny PROPERTY CXX_STANDARD 20)

if(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
    add_subdirectory(include/minhook)
    add_subdirectory(test)
endif()