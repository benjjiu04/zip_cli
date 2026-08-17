#include "get_total_archivos.h"
#include "abrir_zip.h"
#include "styles.h"
#include <stdio.h>
#include <stdlib.h>

long long int get_total_archivos(const char* ruta_archivo_zip){

    zip_t* archivo_zip = abrir_zip(ruta_archivo_zip, 0);
    long long int total_archivos = zip_get_num_entries(archivo_zip, ZIP_FL_ENC_GUESS);

    if (total_archivos == -1){

        fprintf(stderr, "%s%socurrió un error. no se pudo obtener la cantidad de archivos.%s", BOLD, ROJO, RESET);
        exit(EXIT_FAILURE);
    }

    return total_archivos;
}