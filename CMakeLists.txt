cmake_minimum_required(VERSION 3.16)
project(mcserverkit_gui LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

include(FetchContent)

FetchContent_Declare(
    webview
    GIT_REPOSITORY https://github.com/webview/webview
    GIT_TAG 0.12.0
)
FetchContent_MakeAvailable(webview)

add_executable(mcserverkit_gui MACOSX_BUNDLE WIN32)
target_sources(mcserverkit_gui PRIVATE main.cc)
target_link_libraries(mcserverkit_gui PRIVATE webview::core)

if(WIN32)
    target_sources(mcserverkit_gui PRIVATE resources/windows/resources.rc)
endif()


if (MSVC)
    target_compile_definitions(mcserverkit_gui PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()
