add_library(sonnytestproj SHARED dllmain.h dllmain.cpp)

target_link_libraries(sonnytestproj sonny minhook)

target_include_directories(sonnytestproj PUBLIC ${CMAKE_SOURCE_DIR}/include)