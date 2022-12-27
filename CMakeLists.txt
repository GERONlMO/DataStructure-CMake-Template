# указывайте последнюю доступную вам версию CMake
cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

# название проекта
project(ProgrammingLabsWork_2022_2023)

# затем следует список инструкций для подключения проектов из подкаталогов

include(cmake/function.cmake)    # подхватываем функции, реализованные в файле function.cmake
                                 # для простоты мы объединили наборы команд для создания статической библиотеки
								 # и для создания исполняемого проекта в отдельные функции

add_subdirectory(LIBS/lib_example)    # подключаем дополнительный CMakeLists.txt из подкаталога с именем lib_example
add_subdirectory(LIBS/lib_matrix)     # подключаем дополнительный CMakeLists.txt из подкаталога с именем lib_matrix
add_subdirectory(LIBS/lib_stack)
add_subdirectory(LIBS/lib_parser)
add_subdirectory(LIBS/lib_bitfield)
add_subdirectory(LIBS/lib_set)
add_subdirectory(APPS/app_example)    # подключаем дополнительный CMakeLists.txt из подкаталога с именем main
add_subdirectory(APPS/app_lab3)
add_subdirectory(APPS/app_lab1)

option(BTEST "build test?" ON)   # указываем подключаем ли google-тесты (ON или YES) или нет (OFF или NO)

if(BTEST)                        # если тесты подключены
    add_subdirectory(gtest)      # подключаем дополнительный CMakeLists.txt из подкаталога с именем gtest
    add_subdirectory(TESTS)      # подключаем дополнительный CMakeLists.txt из подкаталога с именем test
endif()
