option(ASCII_CAM_ENABLE_CLANG_TIDY "Enable clang-tidy static analysis" OFF)

if(ASCII_CAM_ENABLE_CLANG_TIDY)
    find_program(CLANG_TIDY_EXE
        NAMES clang-tidy-18 clang-tidy-17 clang-tidy-16 clang-tidy
    )

    if(CLANG_TIDY_EXE)
        message(STATUS "clang-tidy: ${CLANG_TIDY_EXE}")
        set(CMAKE_CXX_CLANG_TIDY
            "${CLANG_TIDY_EXE}"
            "--config-file=${CMAKE_SOURCE_DIR}/.clang-tidy"
            "--header-filter=.*libs/.*"
        )
    else()
        message(WARNING "clang-tidy requested but not found — skipping")
    endif()
endif()