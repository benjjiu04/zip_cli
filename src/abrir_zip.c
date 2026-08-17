#include "abrir_zip.h"
#include "styles.h"
#include <zip.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

zip_t* abrir_zip(const char* ruta_archivo, int modo){
    
    SetConsoleOutputCP(CP_UTF8); //encodificacion para usar tildes y eñes en windows.
    SetConsoleCP(CP_UTF8);

    int err;
    zip_t* mi_zip;
    
    //validacion para ver si se abrió correctamente el archivo zip.
    if ((mi_zip = zip_open(ruta_archivo, modo, &err)) == nullptr){
        
        zip_error_t error_zip;
        zip_error_init_with_code(&error_zip, err);
        zip_error_fini(&error_zip);

        fprintf(stderr, "%s%socurrió un error. el archivo zip no existe o no se pudo abrir.%s\n", ROJO, BOLD, RESET);
        exit(EXIT_FAILURE);
    }
    //si todo salió bien regresamos un archivo zip.
    return mi_zip;
    
}
