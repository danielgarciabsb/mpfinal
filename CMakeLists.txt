cmake_minimum_required(VERSION 2.8)

# Nome do projeto
project(projetoFinal)

# Localizar GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(INCLUDE_DIR include)
include_directories (${INCLUDE_DIR})

# Modulos do projeto
set(MODULES elemento cidade adaptador gerador interconexao repositorio relatorio)
FOREACH(subdir ${MODULES})
    ADD_SUBDIRECTORY(${subdir})
ENDFOREACH()

# Configuracoes do GCOV
# Determina a build para Debug do GCOV
SET(CMAKE_BUILD_TYPE Debug)
INCLUDE(CodeCoverage.cmake)
set(GCOV_PARMS "-g -O0 -fprofile-arcs -ftest-coverage --coverage")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCOV_PARMS}")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCOV_PARMS}")
SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${GCOV_PARMS}")
SET(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} ${GCOV_PARMS}")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCOV_PARMS}")
SETUP_TARGET_FOR_COVERAGE(${PROJECT_NAME}_coverage ${PROJECT_NAME} coverage)

# Linkar projeto com a biblioteca GTest, pthread e gcov
add_executable(${PROJECT_NAME} projetoFinal.cpp)
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread ${MODULES} gcov)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
