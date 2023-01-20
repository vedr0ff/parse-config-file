cmake_minimum_required(VERSION 3.0)

project(parse-config-file)

# Configure required libraries ...
if(UNIX) # Darwing or Linux
    
    find_package(Boost REQUIRED COMPONENTS system program_options)

elseif(WIN32) # Windows systems including Win64.
    message(FATAL_ERROR "-- Windows is not supported for now.")
else()
    message(FATAL_ERROR "-- Unsupported platform sorry! :( ")
endif()
# Configure compiler options ...
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")

    message("-- configuring clang options")
    set(CMAKE_CXX_FLAGS "-arch x86_64 -std=c++1z -stdlib=libc++ -DBOOST_LOG_DYN_LINK -Wno-deprecated-declarations")

elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")

    message("-- configuring gcc options")

    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++1z -DBOOST_LOG_DYN_LINK")

endif()

# Project construction ...

# source files ...
add_executable(${PROJECT_NAME} ./source/main.cpp
                               ./source/JSON_ParserConfigFile.cpp
                               )
set(PROJECT_INCLUDE_DIR "./include")
set(HEADER_SEARCH_PATHS ${PROJECT_INCLUDE_DIR} ${Boost_INCLUDE_DIR})
set(LIBRARIES_SEARCH_PATHS ${Boost_LIBRARIES})

message(BOOST_INCLUDE_DIR " ${Boost_INCLUDE_DIR}")
message(LIBRARIES_SEARCH_PATHS " ${LIBRARIES_SEARCH_PATHS}")

include_directories(${HEADER_SEARCH_PATHS})
target_link_libraries(${PROJECT_NAME} ${LIBRARIES_SEARCH_PATHS} dl)