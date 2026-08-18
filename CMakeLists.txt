cmake_minimum_required(VERSION 4.4.2)

set(nombre_proyecto "zip_cli")

project(${nombre_proyecto})

SET(C_STANDARD 23)
SET(C_STANDARD_REQUIRED YES)

find_package(libzip REQUIRED)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(${nombre_proyecto})

target_compile_options(${nombre_proyecto} PRIVATE -static -O2 -flto -Wall -Wextra)

target_link_libraries(${nombre_proyecto} PRIVATE libzip::zip)

target_sources(${nombre_proyecto} PRIVATE
               ./src/abrir_zip.c
               ./src/eliminar_archivo.c
               ./src/listar_contenido.c
               ./src/main.c
               ./src/cli/cli_help.c
               ./src/cli/mostrar_contenido.c
               ./src/cli/get_data.c
               ./src/utils/epoch_to_date.c
               ./src/cli/get_total_archivos.c) 

include_directories(./include ./include/cli ./include/utils)