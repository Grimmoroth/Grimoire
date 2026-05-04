add_executable(grimoire_virtualcam
    main.cpp
)

target_link_libraries(grimoire_virtualcam
    PRIVATE
        grimoire::core
        grimoire::warnings
)

set_target_properties(grimoire_virtualcam
    PROPERTIES OUTPUT_NAME "grimoire-virtualcam"
)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_definitions(grimoire_virtualcam PRIVATE GRIMOIRE_PLATFORM_LINUX)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    target_compile_definitions(grimoire_virtualcam PRIVATE GRIMOIRE_PLATFORM_MACOS)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_definitions(grimoire_virtualcam PRIVATE GRIMOIRE_PLATFORM_WINDOWS)
endif()
