cmake_minimum_required(VERSION 2.8 FATAL_ERROR) #Minimum required version of cmake is 2.8
set(CMAKE_LEGACY_CYGWIN_WIN32 0) #Don't define WIN32 when building with cygwin 

enable_testing() 

project("To Do List")
add_executable(todo main.cpp Todo.cpp)

add_executable(todo_test test.cpp Todo.cpp)
add_test(todoTest todo_test)
