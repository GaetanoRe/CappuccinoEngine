cmake_minimum_required(VERSION 3.10)
project(CappuccinoEngine)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set JSON Compile Commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Determine the platform-specific output directory
if (WIN32)
    set(PLATFORM "windows")
elseif (APPLE)
    set(PLATFORM "macos")
elseif (UNIX)
    set(PLATFORM "linux")
else()
    set(PLATFORM "unknown")
endif()

# Set output directories for runtime (executables), libraries, and archives
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${PLATFORM}/$<CONFIG>)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/${PLATFORM}/$<CONFIG>)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/${PLATFORM}/$<CONFIG>)

# Ensure compatibility with multi-configuration generators (e.g., Visual Studio)
foreach(config ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${config} config_upper)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${config_upper} ${CMAKE_BINARY_DIR}/bin/${PLATFORM}/${config})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${config_upper} ${CMAKE_BINARY_DIR}/lib/${PLATFORM}/${config})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${config_upper} ${CMAKE_BINARY_DIR}/lib/${PLATFORM}/${config})
endforeach()

# Find GLFW
find_package(glfw3 REQUIRED)

# Find Bullet
find_package(Bullet REQUIRED)

# Find OpenAL
find_package(OpenAL REQUIRED)

# Add source files for the executable
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/engine.cpp
    src/window.cpp
)

# Link libraries
target_link_libraries(${PROJECT_NAME}
    glfw
    ${BULLET_LIBRARIES}
    OpenAL::OpenAL
)

# Include directories for GLFW, Bullet, and OpenAL
target_include_directories(${PROJECT_NAME} PRIVATE
    ${GLFW_INCLUDE_DIR}
    ${BULLET_INCLUDE_DIR}
    ${OPENAL_INCLUDE_DIR}
)

# Platform-specific configurations
if (WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        WIN32_EXECUTABLE TRUE
        LINK_FLAGS "/ENTRY:mainCRTStartup"
    )
elseif (APPLE)
    # macOS-specific linker flags
    set(CMAKE_EXE_LINKER_FLAGS "-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo")
endif()

# Install executable to platform-specific bin directory
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin/${PLATFORM}
    LIBRARY DESTINATION lib/${PLATFORM}
    ARCHIVE DESTINATION lib/${PLATFORM}
)
