# Copyright (c) 2011 NCU OOlab <ncuoolab@gmail.com>

# core

include(xTitanUtility)

# hack MSVC path
if(MSVC)
    set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
else()
    set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/lib")
endif()

add_definitions(-DXTITAN_CORE_LIBRARY)

file(GLOB_RECURSE XTITAN_CORE_HEADERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.hpp)
file(GLOB_RECURSE XTITAN_CORE_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.cpp)

group_sources("include")
group_sources("src")

include_directories(
    "include"
    "src"
    ${CMAKE_CURRENT_BINARY_DIR})

set(XTITAN_CORE_COMPILE_UNIT ${XTITAN_CORE_HEADERS} ${XTITAN_CORE_SOURCES})
set(XTITAN_CORE_LINK_UNIT ${QT_QTCORE_LIBRARY} ${QT_QTNETWORK_LIBRARY})
add_library(xTitanCore SHARED ${XTITAN_CORE_COMPILE_UNIT})
target_link_libraries(xTitanCore ${XTITAN_CORE_LINK_UNIT})
set_target_properties(xTitanCore
    PROPERTIES
        VERSION ${XTITAN_VERSION}
        SOVERSION ${XTITAN_VERSION})

install(TARGETS xTitanCore
    RUNTIME DESTINATION "bin"
    LIBRARY DESTINATION "lib"
    ARCHIVE DESTINATION "lib")
install(DIRECTORY "include/xTitan" DESTINATION "include")
