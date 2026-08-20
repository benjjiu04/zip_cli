#include <stdio.h>
#include <stdlib.h>
#include <zip.h>
#include <windows.h>
#include "get_data.h"
#include "utils/key_value.h"
#include "utils/epoch_to_date.h"
#include "abrir_zip.h"
#include "styles.h"

void get_data(const char* ruta_archivo_zip){

    
    KeyValue metodo_compresion[] = { //imitacion de un diccionario/map/object.

        {ZIP_CM_DEFAULT, "default"},
        {ZIP_CM_XZ, "xz"},
        {ZIP_CM_DEFLATE, "deflate"},
        {ZIP_CM_STORE, "store (sin compresion)"},
        {ZIP_CM_DEFLATE64, "deflate64"},
        {ZIP_CM_IMPLODE, "implode"},
        {ZIP_CM_TERSE, "IBM terse"}
    };
    //constante para no tener que cambiar la capacidad en la funcion get_value cada vez que le agregue mas cosas al array.
    const long long int CAPACIDAD_MAX_COMPRESION = sizeof(metodo_compresion) / sizeof(metodo_compresion[0]);

    KeyValue metodo_encriptacion[] = {

        {ZIP_EM_NONE, "sin encriptación"},
        {ZIP_EM_AES_128, "WinZip AES-128"},
        {ZIP_EM_AES_192, "WinZip AES-192"},
        {ZIP_EM_AES_256, "WinZip AES-256"},
        {ZIP_EM_TRAD_PKWARE, "traditional PKWARE, metodo de encriptacion viejo y obsoleto"}
    };

    const long long int CAPACIDAD_MAX_ENCRIPTACIONES = sizeof(metodo_encriptacion) / sizeof(metodo_encriptacion[0]);

    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

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
    printf("%scomentario del archivo zip: %s%s\n\n", BOLD, RESET, zip_get_archive_comment(archivo_zip_usuario, NULL, ZIP_FL_ENC_GUESS));
    for (long long int i = 0; i < cantidad_archivos; i++){
        
        zip_stat_index(archivo_zip_usuario, i, 0, &info_archivos[i]); //llena el struct con la info de los archivos dentro del zip.
        
        printf("%snombre del archivo: %s%s\n", BOLD, RESET, info_archivos[i].name);
        printf("%stamaño del archivo sin comprimir: %s%lld bytes\n", BOLD, RESET, info_archivos[i].size);
        printf("%stamaño del archivo al comprimirse: %s%lld bytes\n", BOLD, RESET, info_archivos[i].comp_size);
        printf("%sfecha de la ultima modificacion: %s%s\n", BOLD, RESET, epoch_to_date(buffer_fecha, sizeof(buffer_fecha), info_archivos[i].mtime) );
        printf("%smetodo de compresión usado: %s%s\n", BOLD, RESET, get_value(metodo_compresion, info_archivos[i].comp_method, CAPACIDAD_MAX_COMPRESION) );
        printf("%smetodo de encriptacion usado: %s%s\n\n", BOLD, RESET, get_value(metodo_encriptacion, info_archivos[i].encryption_method, CAPACIDAD_MAX_ENCRIPTACIONES) );
    }

    //liberacion de recursos.
    for (int i = 0; i < cantidad_archivos; i++){
        zip_fclose(archivos_en_zip[i]); //cerramos todos los archivos que hay dentro del zip para evitar fugas de memoria.
    }

    zip_close(archivo_zip_usuario);

}