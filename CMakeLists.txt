# https://stackoverflow.com/questions/17511496/how-to-create-a-shared-library-with-cmake
cmake_minimum_required(VERSION 3.0)
project(libvocoder VERSION 1.0 DESCRIPTION "small audio backend-agnostic dsp library for filter bank based effects")

add_library(libvocoder SHARED
    src/AudioFileReader.cpp
    src/EnvelopeDetector.cpp
    src/FilterBank.cpp
    src/FilterDistributor.cpp
    src/VocoderFilterDistributor.cpp
    src/VocoderProcessor.cpp
)

set_target_properties(libvocoder PROPERTIES PUBLIC_HEADER 
    include/AudioFileReader.hpp
    include/EnvelopeDetector.hpp
    include/FilterBank.hpp
    include/FilterDistributor.hpp
    include/miniaudio.h
    include/VocoderFilterDistributor.hpp
    include/VocoderProcessor.hpp
)

install(TARGETS mylib
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})