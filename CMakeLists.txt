cmake_minimum_required(VERSION 3.10)
project(GreenThumb)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the source files
file(GLOB_RECURSE SOURCES "src/*.cpp" "include/*.h")

# Add the executable
add_executable(greenthumb ${SOURCES})

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add a custom clean target
add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_BINARY_DIR}/cmake_clean.cmake
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}
)

# Create a script to remove additional files
file(WRITE ${CMAKE_BINARY_DIR}/cmake_clean.cmake "
file(GLOB_RECURSE CMAKE_TEMP_FILES 
    \"${CMAKE_BINARY_DIR}/CMakeFiles/*\"
    \"${CMAKE_BINARY_DIR}/CMakeCache.txt\"
    \"${CMAKE_BINARY_DIR}/cmake_install.cmake\"
    \"${CMAKE_BINARY_DIR}/greenthumb\")
foreach(file \${CMAKE_TEMP_FILES})
    file(REMOVE \${file})
endforeach()
")
