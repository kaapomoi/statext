add_library(statext 
    STATIC 
        src/context.cpp
        src/state.cpp
    )

target_include_directories(statext 
    PUBLIC
        include
    )
