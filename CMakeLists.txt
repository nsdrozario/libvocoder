# https://stackoverflow.com/questions/17511496/how-to-create-a-shared-library-with-cmake
cmake_minimum_required(VERSION 3.0)
project(
    libvocoder 
    VERSION 1.0 
    DESCRIPTION "small audio backend-agnostic dsp library for filter bank based effects"
)

set(
    HEADER_FILES
    "include/miniaudio.h"
    "include/vocoder/AudioFileReader.hpp"
    "include/vocoder/EnvelopeDetector.hpp"
    "include/vocoder/FilterBank.hpp"
    "include/vocoder/FilterDistributor.hpp"
    "include/vocoder/VocoderFilterDistributor.hpp"
    "include/vocoder/VocoderProcessor.hpp"
)

set(
    SOURCES
    "src/AudioFileReader.cpp"
    "src/EnvelopeDetector.cpp"
    "src/FilterBank.cpp"
    "src/FilterDistributor.cpp"
    "src/VocoderFilterDistributor.cpp"
    "src/VocoderProcessor.cpp"
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