cmake_minimum_required(VERSION 3.26)
project(Code-Cacahuetes)

set(CMAKE_C_STANDARD 11)

add_executable(Code-Cacahuetes main.c
        characters/shrek/shrek.c
        move/move.h
        move/move.c
        map/map.h
        map/map.c
        menu/menu.c
        menu/menu.h
        characters/donkey/donkey.c
        characters/donkey/donkey.h
        characters/gingy/gingy.c
        characters/gingy/gingy.h
        characters/children/children.c
        characters/children/children.h
        collisions/collisions.c
        collisions/collisions.h
        flag/flag.c
        flag/flag.h
)
