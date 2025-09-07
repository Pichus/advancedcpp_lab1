cmake_minimum_required(VERSION 3.20)
project(advancedcpp_lab1)

enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(advancedcpp_lab1
        src/main.cpp
        src/DeckManager.cpp
        src/DeckManager.h
        src/Card.h
 "src/statistics.cpp" "src/statistics.h" "src/safeInputs.h" "src/safeInputs.cpp")

add_executable(advancedcpp_lab1_tests
        tests/hello_test.cpp
        src/DeckManager.cpp
        src/DeckManager.h
        src/Card.h
        tests/hello_test.cpp
 "src/statistics.cpp" "src/statistics.h" "src/safeInputs.h" "src/safeInputs.cpp")

target_link_libraries(advancedcpp_lab1_tests
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(advancedcpp_lab1_tests)
