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
)

# Generate Lib
add_library(${lib_target_name}
    STATIC ${lib_sources}
)

# Include directories
target_include_directories(${lib_target_name}
    INTERFACE 
        ${include_dir}
)

# Link lib
target_link_libraries(${lib_target_name} 
    PRIVATE compiler_flags
)