cmake_minimum_required(VERSION 3.28)
project(ChatSystem)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(test)

set(SOURCE_FILES main.cpp
        User.h
        Message.h
        Chat.h
        ChatRegister.h)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES}
        List.h
        test.h
        observer/Subject.h
        observer/Observer.h)
add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCE_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}_lib)


