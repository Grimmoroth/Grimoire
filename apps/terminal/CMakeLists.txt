add_executable(grimoire_terminal)

target_sources(grimoire_terminal
    PRIVATE
        main.cpp
)

target_link_libraries(grimoire_terminal
    PRIVATE
        grimoire::core
        grimoire::warnings
)

set_target_properties(grimoire_terminal
    PROPERTIES OUTPUT_NAME "grimoire-terminal"
)
