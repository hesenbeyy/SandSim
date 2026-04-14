cmake_minimum_required(VERSION 3.15)
project(SandSimulation VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. FIND PACKAGE FIRST
if(WIN32)
    # Strict version check for your Windows environment
    find_package(SFML 2.6.1 COMPONENTS graphics window system REQUIRED)
else()
    # Flexible version check for Linux/macOS
    find_package(SFML COMPONENTS graphics window system REQUIRED)
endif()

# 2. DEFINE EXECUTABLE
set(SOURCES 
    main.cpp 
    funcs.cpp
)
add_executable(${PROJECT_NAME} ${SOURCES})

# 3. CONFIGURE DIRECTORIES
target_include_directories(${PROJECT_NAME} PRIVATE .)

# 4. LINK LIBRARIES (Using official namespaced targets)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)

