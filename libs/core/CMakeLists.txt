set(GM_CORE_SOURCES
    src/opencv_frame_source.cpp
    src/pipeline/pipeline.cpp

    #interfaces
    src/interfaces/i_ascii_converter.cpp
    src/interfaces/i_frame_processor.cpp
    src/interfaces/i_frame_source.cpp
    src/interfaces/i_output_writter.cpp
)

add_library(grimoire_core STATIC ${GM_CORE_SOURCES})

target_include_directories(grimoire_core
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_include_directories(grimoire_core
    SYSTEM PUBLIC
        ${OpenCV_INCLUDE_DIRS}
)


target_link_libraries(grimoire_core
    PUBLIC
        fmt::fmt
        spdlog::spdlog
    PRIVATE
        ${OpenCV_LIBRARIES}
        grimoire::warnings
)


target_compile_features(grimoire_core PUBLIC cxx_std_23)

add_library(grimoire::core ALIAS grimoire_core)
