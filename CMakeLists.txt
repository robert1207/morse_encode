cmake_minimum_required(VERSION 3.10)

project(morse-encode-and-decode)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS, "-Wall")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_CONFIGURATION_TYPES)
	set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "My multi config types" FORCE)
elseif(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE RELEASE)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
file(GLOB SRCS "src/*.c" "src/*.h")
add_executable(${PROJECT_NAME} ${SRCS})

if(UNIX)
	set(CMAKE_INSTALL_PREFIX /usr/local)
	install(TARGETS ${PROJECT_NAME} DESTINATION bin)
elseif(WIN32)
	set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/")
	install(TARGETS ${PROJECT_NAME} DESTINATION bin)
endif()
