cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build tests" ON)
option(BUILD_DOCS "Build documentation" OFF)
option(BUILD_COVERAGE "Build code coverage" OFF)

set(
  HUNTER_CACHE_SERVERS
  "https://github.com/bmstu-iu8-cpp-sem-3/hunter-cache"
  CACHE STRING "Default cache server"
)

include("cmake/HunterGate.cmake")

HunterGate(
  URL "https://github.com/cpp-pm/hunter/archive/v0.23.314.tar.gz"
  SHA1 "95c47c92f68edb091b5d6d18924baabe02a6962a"
)

project(01-lab-03-array-SwanPoi-wp-lab)
if (CMAKE_CXX_COMPILED_ID MATCHES "GNU|Clang")
  string(APPEND CMAKE_CXX_FLAGS " -pedantic -Werror -Wall -Wextra")
  string(APPEND CMAKE_CXX_FLAGS " -Wno-unused-command-line-argument")
  string(APPEND CMAKE_CXX_FLAGS " -Wshadow -Wnon-virtual-dtor")
elseif (MSVC)
  string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  string(APPEND CMAKE_CXX_FLAGS " /permissive- /WX /Zi")
endif()

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

add_library(${PROJECT_NAME} STATIC
  # enum your files and delete this comment
  ${CMAKE_CURRENT_SOURCE_DIR}/sources/string_tasks.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/sources/task_1.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/sources/task_2.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/sources/task_3.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/sources/task_4.cpp
        include/header.hpp)

add_executable(demo
  ${CMAKE_CURRENT_SOURCE_DIR}/demo/main.cpp
        include/header.hpp)

target_include_directories(${PROJECT_NAME} PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
  "$<INSTALL_INTERFACE:include>"
)

target_link_libraries(demo ${PROJECT_NAME})

if(BUILD_TESTS)
  add_executable(tests

    sources/task_1.cpp
    sources/task_2.cpp
          sources/task_3.cpp
          sources/task_4.cpp
          sources/string_tasks.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/tests/test.cpp
          include/header.hpp)
  target_link_libraries(tests ${PROJECT_NAME} GTest::gtest_main)
  enable_testing()
  add_test(NAME unit_tests COMMAND tests)
endif()

if(BUILD_COVERAGE)
  set(ENABLE_COVERAGE ON CACHE BOOL "Enable coverage build." FORCE)
  list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/tools/coverage/cmake")
  find_package(codecov)
  string(APPEND CMAKE_CXX_FLAGS " --coverage")
  add_coverage(${PROJECT_NAME})
  add_coverage(tests)
  coverage_evaluate()
endif()

if(BUILD_DOCS)
  set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/_docs)
  set(DOXYGEN_EXAMPLE_PATH examples)
  set(DOXYGEN_GENERATE_HTML NO)
  set(DOXYGEN_GENERATE_MAN YES)
  find_package(Doxygen)
  doxygen_add_docs(docs include)
  install(DIRECTORY ${DOXYGEN_OUTPUT_DIRECTORY}/man DESTINATION share)
  # add_dependencies(install docs) need to call target docs before install or package
endif()

include(CPackConfig.cmake)

install(TARGETS ${PROJECT_NAME} demo
  EXPORT "${PROJECT_NAME}-targets"
  RUNTIME DESTINATION bin
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  INCLUDES DESTINATION include
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)

install(EXPORT "${PROJECT_NAME}-targets"
  NAMESPACE "${PROJECT_NAME}::"
  DESTINATION "lib/cmake"
)
