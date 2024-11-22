cmake_minimum_required(VERSION 3.29)
project(ChatSystem)

set(CMAKE_CXX_STANDARD 20)

add_executable(ChatSystem main.cpp
        User.h
        Message.h
        Chat.h
        ChatRegister.h)
