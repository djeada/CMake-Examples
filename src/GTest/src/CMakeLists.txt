
add_library (vector INTERFACE)

target_sources(
    vector
    INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/vector.h
        # vector.cpp not needed - header-only template
    )

target_include_directories(
    vector
    INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}
    )
