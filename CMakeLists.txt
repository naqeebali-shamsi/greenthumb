cmake_minimum_required(VERSION 3.14)

if(POLICY CMP0091)
  cmake_policy(SET CMP0091 NEW) 
endif()

project(GreenThumb)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


find_package(Threads REQUIRED)

# Specify the source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Add the executable
add_executable(greenthumb ${SOURCES})
set_target_properties(greenthumb PROPERTIES OUTPUT_NAME "GreenThumb")

# Include directories
target_include_directories(greenthumb PRIVATE ${PROJECT_SOURCE_DIR}/include ${CONAN_INCLUDE_DIRS})

# Add dependencies
find_package(Crow REQUIRED)
find_package(asio REQUIRED)

# Link libraries
target_link_libraries(greenthumb PRIVATE asio::asio)
target_link_libraries(greenthumb PRIVATE Crow::Crow)

# Set MSVC runtime library property
if(MSVC)
    set_property(TARGET greenthumb PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

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
