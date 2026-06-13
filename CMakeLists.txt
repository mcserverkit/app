cmake_minimum_required(VERSION 3.16)
project(mcserverkit_gui LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
    webview
    GIT_REPOSITORY https://github.com/webview/webview
    GIT_TAG 0.12.0
)
FetchContent_MakeAvailable(webview)

add_executable(mcserverkit_gui MACOSX_BUNDLE WIN32)
target_sources(mcserverkit_gui PRIVATE src/main.cc)
target_link_libraries(mcserverkit_gui PRIVATE webview::core)

if(WIN32)
    target_sources(mcserverkit_gui PRIVATE resources/windows/resources.rc)
elseif(APPLE)
    set_target_properties(mcserverkit_gui PROPERTIES MACOSX_BUNDLE_ICON_FILE "icon.icns")
    set_source_files_properties(resources/macos/icon.icns PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
    target_sources(mcserverkit_gui PRIVATE resources/macos/icon.icns)
endif()

# https://stackoverflow.com/questions/13429656/how-to-copy-contents-of-a-directory-into-build-directory-after-make-with-cmake
add_custom_command(TARGET mcserverkit_gui POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/ui ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/ui)

if (MSVC)
    target_compile_definitions(mcserverkit_gui PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()
