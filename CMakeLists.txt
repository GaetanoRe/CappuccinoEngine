cmake_minimum_required(VERSION 3.10)
project(CappuccinoEngine)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set JSON Compile Commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find GLFW
if(WIN32)
	find_package(glfw REQUIRED)

else()
	find_package(glfw3 3.3 REQUIRED)
endif()


# Find Bullet
find_package(Bullet REQUIRED)

# Set object file directory
set(CMAKE_CURRENT_BINARY_DIR ${CMAKE_BINARY_DIR}/obj)

# Set executable directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add source files
add_executable(${PROJECT_NAME}
	src/main.cpp
	src/engine.cpp
	src/window.cpp
	)

# Link against GLFW libraries
target_link_libraries(${PROJECT_NAME} glfw)

# Link against Bullet libraries
target_link_libraries(${PROJECT_NAME} ${BULLET_LIBRARIES})

# Inlcude GLFW headers
target_include_directories(${PROJECT_NAME} PRIVATE ${GLFW_INCLUDE_DIR})

# Include Bullet headers
target_include_directories(${PROJECT_NAME} PRIVATE ${BULLET_INCLUDE_DIR})

# Install executable
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
