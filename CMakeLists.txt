cmake_minimum_required(VERSION 2.8)

INCLUDE(os_env.cmake)
INCLUDE(boost.cmake)
if(UNIX)
	add_definitions("-DLINUX -O2 -s -Wall")
endif(UNIX)

if(WIN32)
	if(MSVC_VERSION EQUAL 1700)
	  add_definitions(-D_VARIADIC_MAX=10)
	endif()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_WIN32_WINNT=0x0501")
	# force this option to ON so that Google Test will use /MD instead of /MT
	# /MD is now the default for Visual Studio, so it should be our default, too
	#option(gtest_force_shared_crt ON)
endif(WIN32)

file(GLOB_RECURSE SOURCE_FILES
	${CMAKE_SOURCE_DIR}/inc/*.hpp 
	${CMAKE_SOURCE_DIR}/inc/*.h 
	${CMAKE_SOURCE_DIR}/src/*.cpp
)
file(GLOB_RECURSE TEST_API_FILES
	test/test_api.cpp
)
include_directories(inc)

add_library(cli SHARED 
	${SOURCE_FILES}
)

target_link_libraries(cli ${Boost_LIBRARIES})
IF(UNIX)

target_link_libraries(cli pthread)

target_link_libraries(cli rt)

ENDIF(UNIX)

ADD_SUBDIRECTORY(utest)
#target_link_libraries(test_shm ${Boost_LIBRARIES})