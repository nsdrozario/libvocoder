# https://stackoverflow.com/questions/17511496/how-to-create-a-shared-library-with-cmake
cmake_minimum_required(VERSION 3.0)
project(libvocoder VERSION 1.0 DESCRIPTION "small audio backend-agnostic dsp library for filter bank based effects")

add_library(vocoder SHARED
    src/AudioFileReader.cpp
    src/EnvelopeDetector.cpp
    src/FilterBank.cpp
    src/FilterDistributor.cpp
    src/VocoderFilterDistributor.cpp
    src/VocoderProcessor.cpp
)

target_include_directories(
    vocoder
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_target_properties(vocoder PROPERTIES PUBLIC_HEADER 
    include/miniaudio.h
    include/AudioFileReader.hpp
    include/EnvelopeDetector.hpp
    include/FilterBank.hpp
    include/FilterDistributor.hpp
    include/VocoderFilterDistributor.hpp
    include/VocoderProcessor.hpp
)

install (
    TARGETS vocoder
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDED}
)