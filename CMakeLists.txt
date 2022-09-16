cmake_minimum_required(VERSION 3.14)
project(Risc-v)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB SRC_FILES "src/*.cpp" "src/*.h" "tests/*.cpp")

add_executable(Risc-v ${SRC_FILES})
target_link_libraries(Risc-v GTest::gtest_main)
target_include_directories(Risc-v PRIVATE "src")

include(GoogleTest)
gtest_discover_tests(Risc-v)
