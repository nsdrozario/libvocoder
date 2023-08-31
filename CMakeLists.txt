# https://stackoverflow.com/questions/17511496/how-to-create-a-shared-library-with-cmake
# https://www.fsf.org/blogs/licensing/creative-commons-by-sa-4-0-declared-one-way-compatible-with-gnu-gpl-version-3
cmake_minimum_required(VERSION 3.0)
project(
    libvocoder 
    VERSION 1.0 
    DESCRIPTION "small audio backend-agnostic dsp library for filter bank based effects"
)
set(CMAKE_C_FLAGS -g)
set(CMAKE_CXX_FLAGS -g)

set(
    HEADER_FILES
    "include/miniaudio.h"
    "include/vocoder/AudioFileReader.hpp"
    "include/vocoder/EnvelopeDetector.hpp"
    "include/vocoder/FilterBank.hpp"
    "include/vocoder/FilterDistributor.hpp"
    "include/vocoder/VocoderFilterDistributor.hpp"
    "include/vocoder/VocoderProcessor.hpp"
    "include/vocoder/AudioFileWriter.hpp"
)

set(
    SOURCES
    "src/AudioFileReader.cpp"
    "src/EnvelopeDetector.cpp"
    "src/FilterBank.cpp"
    "src/FilterDistributor.cpp"
    "src/VocoderFilterDistributor.cpp"
    "src/VocoderProcessor.cpp"
    "src/AudioFileWriter.cpp"
)

add_library(vocoder SHARED "${SOURCES}")

target_include_directories(
    vocoder
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/vocoder
)

set_target_properties(vocoder PROPERTIES 
    PUBLIC_HEADER "${HEADER_FILES}"
)

install (
    TARGETS vocoder
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDED}/vocoder
)

add_executable(vocoder_cli src/VocoderTest.cpp)
add_dependencies(vocoder_cli vocoder)
target_link_libraries(vocoder_cli vocoder)
target_include_directories(vocoder_cli PUBLIC include include/vocoder)