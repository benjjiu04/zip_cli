#include "listar_contenido.h"
#include <zip.h>

void listar_contenido(zip_t* archivo_zip){

    long long int total_archivos = zip_get_num_entries(archivo_zip, ZIP_FL_UNCHANGED);
    
    if (total_archivos == -1){

        return;
    }

    for (long long int index = 0; index < total_archivos; index++){
        printf("%s\n", zip_get_name(archivo_zip, index, ZIP_FL_ENC_GUESS));
    }
    
}