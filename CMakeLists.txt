cmake_minimum_required(VERSION 3.29)
project(vertinimas)

set(CMAKE_CXX_STANDARD 14)

# Add an option for enabling tests
option(ENABLE_TESTING "Build with testing support" ON)

# Define the main executable
add_executable(vertinimas
    studentas.h
    studentas.cpp
    main.cpp
    duomenys.cpp
    duomenys.h
    rezultatas.cpp
    rezultatas.h
    rikiavimas.cpp
    rikiavimas.h
    vertinimas.cpp
    vertinimas.h
    ivedimas.cpp
    ivedimas.h
    zmogus.h
    zmogus.cpp
)

# Add test executable if ENABLE_TESTING is ON
if(ENABLE_TESTING)
    add_executable(testavimas
        studentas.h
        studentas.cpp
        tests.cpp
        main.cpp
        duomenys.cpp
        duomenys.h
        rezultatas.cpp
        rezultatas.h
        rikiavimas.cpp
        rikiavimas.h
        vertinimas.cpp
        vertinimas.h
        ivedimas.cpp
        ivedimas.h
        zmogus.h
        zmogus.cpp
    )
    target_compile_definitions(testavimas PRIVATE TESTING) # Define TESTING
endif()
