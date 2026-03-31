set(TPSTUB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../tp_stub CACHE PATH "Path to tp_stub directory")
include(${TPSTUB_DIR}/krkrz.cmake)

message(STATUS "Using tp_stub from: ${TPSTUB_DIR}")

krkrz_plugin(KAGParserEx
    SOURCES
        KAGParser.h
        KAGParserEx.cpp
        KAGParserEx.hpp
        Main.cpp
        tjsHashSearch.h
)
