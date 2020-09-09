cmake_minimum_required(VERSION 3.16)
project(Design_Patterns)

#set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -std=c++17 -pthread")

#add_library(pthread)

add_executable(
        Design_Patterns
        main.cpp
        Factory/SimpleFactory.cpp
        Factory/FactoryMethod.cpp
        Factory/AbstractFactory.cpp
        Factory/TemplateFactory.cpp
        Observer/Observer.cpp
        Singleton/Singleton1.cpp Singleton/Singleton2.cpp Singleton/Singleton3.cpp)