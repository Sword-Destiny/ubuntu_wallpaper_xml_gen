cmake_minimum_required(VERSION 3.10)
project(wallpaper)

set(CMAKE_CXX_STANDARD 14)

add_executable(wallpaper_xml_gen main.cpp c_enum_file.h)