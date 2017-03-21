CMAKE_MINIMUM_REQUIRED (VERSION 2.6)

PROJECT ( utest )
if(WIN32)
	if(MSVC_VERSION EQUAL 1700)
	  add_definitions(-D_VARIADIC_MAX=10)
	endif()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_WIN32_WINNT=0x0501")
	# force this option to ON so that Google Test will use /MD instead of /MT
	# /MD is now the default for Visual Studio, so it should be our default, too
	#option(gtest_force_shared_crt ON)
endif(WIN32)

if(UNIX)
	CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
	CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)

	find_package (Threads)
	add_definitions("-DLINUX -O2 -s -Wall -Dlinux")

	if(COMPILER_SUPPORTS_CXX11)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
	elseif(COMPILER_SUPPORTS_CXX0X)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
	else()
	    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no
			C++11 support. Please use a different C++ compiler.")
	endif()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ")
endif(UNIX)

link_directories(${LIBS_PATH}/gtest)

INCLUDE_DIRECTORIES(${LIB_PATH_3rdparty}/include)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/inc)
INCLUDE_DIRECTORIES(inc)

file(GLOB_RECURSE SOURCE_FILES
	${CMAKE_SOURCE_DIR}/inc/*.hpp 
	${CMAKE_SOURCE_DIR}/inc/*.h 
	${CMAKE_SOURCE_DIR}/src/*.cpp
)

ADD_EXECUTABLE(utest 
	${SOURCE_FILES}
	src/main.cpp
	test/T_Utilities.cpp
)

target_link_libraries(utest gtestd )
target_link_libraries(utest ${Boost_LIBRARIES})