# Generate static lib
set(lib_target_name LoggerLib)
# Dir vars
set(include_dir ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(src_dir ${CMAKE_CURRENT_SOURCE_DIR}/src)
message("[${lib_target_name}] IncludeDir: ${include_dir}")
message("[${lib_target_name}] SrcDir: ${src_dir}")

# Set sources
set(lib_sources 
    ${src_dir}/Logger.cpp
    ${src_dir}/LoggerTypes.cpp
)

# Generate Lib
add_library(${lib_target_name}
    STATIC ${lib_sources}
)

# Include directories
target_include_directories(${lib_target_name}
    PUBLIC
        ${include_dir}
)

# Link lib
target_link_libraries(${lib_target_name} 
    PRIVATE compiler_flags
)

string(TOLOWER ${CMAKE_BUILD_TYPE} build_type)
if (${build_type} STREQUAL "debug")
    target_compile_definitions(${lib_target_name} PUBLIC _DEBUG)
else()
target_compile_definitions(${lib_target_name} PUBLIC _NDEBUG)
endif()
