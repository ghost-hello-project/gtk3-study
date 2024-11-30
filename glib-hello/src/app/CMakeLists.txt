aux_source_directory(. SRCS_MAIN)
add_executable(${PROJECT_NAME} ${SRCS_MAIN})

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${bin_dir})

target_link_libraries(${PROJECT_NAME}
    ${GLIB_LIBRARIES}
)

if(UNIX)
    set_target_properties(${PROJECT_NAME} PROPERTIES INSTALL_RPATH "\${ORIGIN}/../lib")
endif()
