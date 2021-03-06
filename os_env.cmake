# Determine current OS platform
if(WIN32)
    set(SUBARCH "Windows")
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        SET(ARCH "WIN64")
    else(CMAKE_SIZEOF_VOID_P EQUAL 8)
        SET(ARCH "WIN32")
    endif(CMAKE_SIZEOF_VOID_P EQUAL 8)
endif(WIN32)

if(UNIX)
    set(SUBARCH "Unix")
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        SET(ARCH "UNIX64")
    else(CMAKE_SIZEOF_VOID_P EQUAL 8)
        SET(ARCH "UNIX32")
    endif(CMAKE_SIZEOF_VOID_P EQUAL 8)
endif(UNIX)

if(ARM)
    SET(ARCH "ARM")
endif(ARM)

set( LIB_PATH ${CMAKE_SOURCE_DIR}/../scheduler/boost-1.59-cross-platfrom)
set( LIB_PATH_3rdparty ${CMAKE_SOURCE_DIR}/3rdparty)

# Set library path for corressponding platform
if(${ARCH} STREQUAL "WIN32")
    message("Configuring for Windows 32 bit")
    add_definitions("-DWIN -DS_WIN32 -D_WIN32 ")
    set( BOOST_LIBS_PATH ${LIB_PATH}/windows/32bit)
    set( LIBS_PATH ${LIB_PATH_3rdparty}/lib/win32)
endif()

if(${ARCH} STREQUAL "WIN64")
    message("Configuring for Windows 64 bit")
    add_definitions("-DWIN -DS_WIN64 ")
    set(BOOST_LIBS_PATH ${LIB_PATH}/windows/64bit)
    set( LIBS_PATH ${LIB_PATH_3rdparty}/lib/win64)
endif()

if(${ARCH} STREQUAL "UNIX32")
    message("Configuring for Linux 32 bit")
    add_definitions("-DLINUX -DS_LINUX32 ")
    set(BOOST_LIBS_PATH ${LIB_PATH}/linux/32bit)
    set( LIBS_PATH ${LIB_PATH_3rdparty}/lib/linux32)
endif()

if (${ARCH} STREQUAL "ARM")
    message("Configuring for ARM 32 bit")
	set(SUBARCH "arm")
	add_definitions("-DIMX6 -DLINUX -DS_LINUX32 ")
	set(BOOST_LIBS_PATH ${LIB_PATH}/arm)
    set( LIBS_PATH ${LIB_PATH_3rdparty}/lib/linux-arm)
endif()
	 
if(${ARCH} STREQUAL "UNIX64")
    message("Configuring for Linux 64 bit")
    add_definitions("-DLINUX -DS_LINUX64 ")
    set(BOOST_LIBS_PATH ${LIB_PATH}/linux/64bit)
    set( LIBS_PATH ${LIB_PATH_3rdparty}/lib/linux64)
endif()


message("Library path: ${BOOST_LIBS_PATH}")
message("Library path: ${LIBS_PATH}")