cmake_minimum_required(VERSION 3.31.5)

project(
  dm-brige
  VERSION 0.0.1
  LANGUAGES CXX
)

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(FATAL_ERROR "In-source builds not allowed")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include("cmake/cpm-dependencies.cmake")

add_executable(main
  src/main.cpp
  src/RpcCall.cpp
  src/RpcCall.hpp
)
target_compile_options(main PRIVATE "-Wall" "-Wextra" "-pedantic")
target_link_libraries(main PRIVATE Boost::json Boost::asio Boost::beast)