cmake_minimum_required(VERSION 3.25)
project(COMP282)

set(CMAKE_CXX_STANDARD 11)

add_executable(COMP282
        Main.cpp
        TuringMachine.h
        TuringMachineState.h
        TuringMachineState.cpp
        DenseTuringMachine.h
        DenseTuringMachine.cpp
        TuringTape.cpp TuringTape.h MenuSystem.cpp MenuSystem.h SparseTuringMachine.cpp SparseTuringMachine.h)

add_library(COMP282lib
        TuringMachine.h
        TuringMachineState.h
        TuringMachineState.cpp
        DenseTuringMachine.h
        DenseTuringMachine.cpp
        TuringTape.cpp TuringTape.h MenuSystem.cpp MenuSystem.h SparseTuringMachine.cpp SparseTuringMachine.h
        )

target_link_libraries(COMP282 COMP282lib)