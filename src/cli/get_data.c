#include <stdio.h>
#include <stdlib.h>
#include <zip.h>
#include <regex.h>
#include "get_data.h"
#include "abrir_zip.h"
#include "utils/epoch_to_date.h"
#include "styles.h"

void get_data(const char* ruta_archivo_zip){

    if (ruta_archivo_zip[0] == '\n'){
        
        fprintf(stderr, "%s%sporfavor ingrese la ruta del archivo zip.%s", ROJO, BOLD, RESET);
        exit(EXIT_FAILURE);
    }
    zip_t* archivo_zip_usuario = abrir_zip(ruta_archivo_zip, 0);
    long long int cantidad_archivos = zip_get_num_entries(archivo_zip_usuario, ZIP_FL_ENC_GUESS);
    
    zip_file_t* archivos_en_zip[cantidad_archivos];
    for (long long int i = 0; i < cantidad_archivos; i++){

        archivos_en_zip[i] = zip_fopen_index(archivo_zip_usuario, i, 0);
    }

    struct zip_stat info_archivos[cantidad_archivos]; //array de structs con la info de los archivos.
    
    for (long long int i = 0; i < cantidad_archivos; i++){
        zip_stat_init(&info_archivos[i]); //inicia todos los elementos de el struct para usarse.
    }

    char buffer_fecha[200];
    for (long long int i = 0; i < cantidad_archivos; i++){
        
        zip_stat_index(archivo_zip_usuario, i, 0, &info_archivos[i]); //popula el struct con la info de los archivos dentro del zip.
        
        printf("%snombre del archivo: %s%s\n", BOLD, RESET, info_archivos[i].name);
        printf("%stamaño del archivo: %s%lld bytes\n", BOLD, RESET, info_archivos[i].size);
        printf("%sfecha de la ultima modificacion: %s%s\n\n", BOLD, RESET, epoch_to_date(buffer_fecha, sizeof(buffer_fecha), info_archivos[i].mtime));
    }

    //liberacion de recursos.
    for (int i = 0; i < cantidad_archivos; i++){
        zip_fclose(archivos_en_zip[i]); //cerramos todos los archivos que hay dentro del zip para evitar fugas de memoria.
    }

    zip_close(archivo_zip_usuario);

    
}