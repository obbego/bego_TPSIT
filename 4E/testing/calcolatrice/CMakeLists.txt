# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

project(CalcolatriceTest)

# Aggiungi il percorso dove GoogleTest è installato
set(GTEST_ROOT /usr/local)

# Aggiungi la cartella src per i file di intestazione (header)
include_directories(src)

# Impostiamo i file sorgente
add_executable(test_calcolatrice
    src/calcolatrice.c
    test/test_calcolatrice.cpp
)

# Aggiungi GoogleTest al progetto
find_package(GTest REQUIRED)
target_link_libraries(test_calcolatrice GTest::GTest GTest::Main pthread)

enable_testing()

add_test(NAME TestCalcolatrice COMMAND test_calcolatrice)
