cmake_minimum_required(VERSION 3.6)
project(BoostCommandLineParserSample)

find_package(Boost 1.40 COMPONENTS program_options REQUIRED )

include_directories(${Boost_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(BoostCommandLineParserSample ${SOURCE_FILES})
target_link_libraries(BoostCommandLineParserSample ${Boost_LIBRARIES})
