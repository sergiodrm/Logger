
cmake_minimum_required(VERSION 3.15)

project(Logger VERSION 0.1)


# Config file
set(config_file_name LoggerProjectConfig.h)
configure_file(${config_file_name}.in ${config_file_name})

# Set compilers
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE cxx_std_11)
target_compile_options(compiler_flags INTERFACE
    "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
    "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>")

    
# Add LoggerLib
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Logger)
    
# Testing executable
set(exe_target_name MainApp)
add_executable(${exe_target_name} Tests/MainApp.cpp)
# target_include_directories(${exe_target_name} 
#     PUBLIC 
#         "${CMAKE_CURRENT_SOURCE_DIR}/Logger/include"
# )
target_include_directories(${exe_target_name}
    PUBLIC 
        "${PROJECT_BINARY_DIR}"
)
target_link_libraries(${exe_target_name} 
    PUBLIC 
        LoggerLib
    PRIVATE
        compiler_flags
)
