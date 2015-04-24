cmake_minimum_required (VERSION 2.8)
project (Challenge123)

# add to the search path for include files
include_directories ("${PROJECT_SOURCE_DIR}/include")
include_directories ("${PROJECT_SOURCE_DIR}/include2")

# set path for executables and libraries
set (EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")
set (LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/lib" )

# add source subdirectory
add_subdirectory (src)

# set compiler flags
set (WFLAGS "-Wall -Wextra -Wpedantic")
set (STDFLAG "-std=c++11")
#set (OPTFLAGS "-O3")
set (CMAKE_CXX_FLAGS "${STDFLAG} ${WFLAGS} ${OPTFLAGS}")


#set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)

# add the executable
add_executable (mainMesh "src/mainMesh.cpp")
#target_link_libraries (mainMesh2D  ${EXTRA_LIBS})

# enable testing
#enable_testing ()
