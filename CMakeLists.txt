cmake_minimum_required(VERSION 3.28)
project(ChatSystem)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(test)

set(SOURCE_FILES main.cpp
        User.h
        Message.h
        Chat.h
        ChatRegister.h
        User.cpp
        Chat.cpp
        ChatRegister.cpp
        User.cpp
        UserList.h)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})
add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCE_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}_lib)


