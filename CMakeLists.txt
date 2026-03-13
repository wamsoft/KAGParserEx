cmake_minimum_required(VERSION 3.15)
project(KAGParserEx CXX)

include(../tp_stub/krkrz.cmake)

krkrz_plugin(KAGParserEx
    SOURCES
        KAGParser.h
        KAGParserEx.cpp
        KAGParserEx.hpp
        Main.cpp
        tjsHashSearch.h
)
