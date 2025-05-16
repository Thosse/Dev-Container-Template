find_package(Doxygen REQUIRED)

# Add documentation targets
add_custom_target(Doxygen
    COMMAND doxygen Doxyfile
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Generating documentation with Doxygen"
    VERBATIM
)
