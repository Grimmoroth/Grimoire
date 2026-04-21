add_library(grimoire_core STATIC)

target_sources(grimoire_core
    PRIVATE
        src/placeholder.cpp
)

target_include_directories(grimoire_core
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>

    PRIVATE
        ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(grimoire_core
    PUBLIC
        ${OpenCV_LIBRARIES}
        fmt::fmt
        spdlog::spdlog

    PRIVATE:
        grimoire::warnings
)


target_compile_features(grimoire_core PUBLIC cxx_std_23)

add_library(grimoire::core ALIAS grimoire_core)
