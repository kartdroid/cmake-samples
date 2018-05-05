#Minimum required version of cmake is 3.0
cmake_minimum_required(VERSION 3.0 FATAL_ERROR) 

#Don't define WIN32 when building with cygwin 
set(CMAKE_LEGACY_CYGWIN_WIN32 0) 

#set( ENV{DEVELOPER_DIR} "/Applications/Xcode.app/Contents/Developer/")

enable_testing() 


#Add Compiler Specific Warning Flags
message("CMAKE_CXX_COMPILER_ID = ${CMAKE_CXX_COMPILER_ID}")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	set(warnings "-Wall -Wextra -Werror")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	set(warnings "/W4 /WX /EHsc")
endif()

#Save in Cache for Once 
if (NOT CONFIGURED_ONCE)
	set(CMAKE_CXX_FLAGS "${warnings}" 
		CACHE 
		STRING 
		"Flags used by compiler during all build types"
		FORCE)
	set(CMAKE_C_FLAGS "${warnings}"
		CACHE
		STRING
		"Flags used by the compiler during all build types"
		FORCE)
endif()

############################################################# 

project("To Do List")

#include current source dir
message("CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")
message("CMAKE_CURRENT_BINARY_DIR = ${CMAKE_CURRENT_BINARY_DIR}")
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(TodoCore)

add_executable(todo main.cpp)
target_link_libraries(todo todo_core)

add_executable(todo_test test.cpp)
target_link_libraries(todo_test todo_core)

add_test(todoTest todo_test)


set(CONFIGURED_ONCE TRUE
	CACHE  
	INTERNAL 
	"A flag showing that CMake has configured atleast once")
