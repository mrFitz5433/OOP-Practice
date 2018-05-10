project(Santa CXX)

add_library(Santa
	ParaviaHelp.hpp)

add_executable(Santa
	ParaviaBuy.cpp
	ParaviaInterface.cpp
	ParaviaPlay.cpp
	main.cpp)

#add the ability to printout the source code
macro(add_printout)
  add_custom_target(printout
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMAND a2ps -Afill -o- ${ARGN} | ps2pdf - ${CMAKE_BINARY_DIR}/printout.pdf)
endmacro()

add_printout(Santa paravia.cpp)