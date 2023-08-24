cmake_minimum_required (VERSION 3.20)

add_library(model_utils STATIC model.cpp pin.cpp)
target_include_directories(model_utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../third_party)

set_property(TARGET model_utils PROPERTY CXX_STANDARD 23)
