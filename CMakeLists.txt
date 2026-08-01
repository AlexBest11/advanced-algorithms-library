cmake_minimum_required(VERSION 3.14)
if(POLICY CMP0135)
    cmake_policy(SET CMP0135 NEW)
endif()
project(advanced-algorithms-library CXX)

# Устанавливаем стандарт C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Указываем путь к заголовочным файлам проекта
include_directories(${CMAKE_SOURCE_DIR}/include/algorithms)

# Автоматически скачиваем и подключаем Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# --- СБОРКА ТЕСТОВ ---
add_executable(algo_tests
    tests/sorting/merge_sort_test.cpp
)

# Подключаем фреймворк и готовую точку входа main()
target_link_libraries(algo_tests GTest::gtest_main)

# Кроссплатформенные предупреждения компилятора
if(MSVC)
    target_compile_options(algo_tests PRIVATE /W4)
else()
    target_compile_options(algo_tests PRIVATE -Wall -Wextra -Wpedantic)
endif()

include(GoogleTest)
gtest_discover_tests(algo_tests)
