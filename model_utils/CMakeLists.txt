cmake_minimum_required (VERSION 3.20)

add_library(model_utils STATIC model.cpp pin.cpp)
target_include_directories(model_utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../third_party)

if (MSVC)
    target_compile_options(model_utils PRIVATE "/Zc:__cplusplus")
    if (MSVC_VERSION GREATER_EQUAL 1930)
        set_property(TARGET model_utils PROPERTY CXX_STANDARD 23)
    else()
        set_property(TARGET model_utils PROPERTY CXX_STANDARD 17)
    endif()
    set_target_properties(model_utils PROPERTIES CXX_STANDARD_REQUIRED ON)
endif()
