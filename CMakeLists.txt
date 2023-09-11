cmake_minimum_required(VERSION 3.10)

project(blackjack)

# Add source files
file(GLOB SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

# Add compiler options
target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall        # Enable all compiler warnings
    -std=c++17   # Use C++17 standard
    # Add more options as needed
)