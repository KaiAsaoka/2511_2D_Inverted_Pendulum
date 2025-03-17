cmake_minimum_required(VERSION 3.11)
project(PendulumControlESP32)

include(FetchContent)
FetchContent_Declare(
  matplotlibcpp
  GIT_REPOSITORY https://github.com/lava/matplotlib-cpp.git
  GIT_TAG master
)
FetchContent_MakeAvailable(matplotlibcpp)

# Print the fetched source directory
message(STATUS "matplotlibcpp source dir: ${matplotlibcpp_SOURCE_DIR}")

# Although matplotlibcpp is header-only, create an INTERFACE target:
add_library(MatplotLibCPP INTERFACE)
target_include_directories(MatplotLibCPP INTERFACE ${matplotlibcpp_SOURCE_DIR})