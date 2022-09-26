cmake_minimum_required(VERSION 3.23)
project(laboratorioProg_LorenzoDinardo)

set(CMAKE_CXX_STANDARD 14)

add_executable(laboratorioProg_LorenzoDinardo main.cpp Transazione.h Transazione.cpp Conto.cpp Conto.h Cliente.cpp Cliente.h Subject.cpp Observer.cpp FileManager.cpp FileManager.h ConcreteSubject.cpp ConcreteSubject.h)
