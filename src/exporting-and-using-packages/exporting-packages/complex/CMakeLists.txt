add_library(complex
src/complex.cpp)

target_include_directories(complex PUBLIC 
$<INSTALL_INTERFACE:include>
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

#can have multiple files here befor DESTINATION
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/complex/complex.h DESTINATION ${CMAKE_INSTALL_PREFIX}/include/complex)

install(TARGETS complex EXPORT my_export DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/complex)

install(EXPORT my_export FILE my_math-config.cmake DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/complex)
