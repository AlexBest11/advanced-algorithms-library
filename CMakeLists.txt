cmake_minimum_required(VERSION 3.14)
project(advanced-algorithms-library CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include/algorithms)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()


add_executable(run_tests
    tests/sorting/merge_sort_test.cpp

)

# Подключаем gtest_main, чтобы не писать свой int main()
target_link_libraries(run_tests gtest_main)

# --- КРОССПЛАТФОРМЕННЫЕ ПРЕДУПРЕЖДЕНИЯ ---
if(MSVC)
    # Для Windows (Visual Studio)
    target_compile_options(run_tests PRIVATE /W4)
else()
    # Для macOS (Clang) и Linux (GCC)
    target_compile_options(run_tests PRIVATE -Wall -Wextra -Wpedantic)
endif()

include(GoogleTest)
gtest_discover_tests(run_tests)