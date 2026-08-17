#include "eliminar_archivo.h"
#include "styles.h"
#include <zip.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void eliminar_archivo(zip_t* archivo_zip, const char* nombre_archivo){

    if (nombre_archivo[0] == ' '){
        fprintf(stderr, "%s%sporfavor escriba el nombre del archivo.%s", ROJO, BOLD, RESET);
        exit(EXIT_FAILURE);
    }
    int codigo;

    int index_archivo = zip_name_locate(archivo_zip, nombre_archivo, 0);

    if (index_archivo == -1){
        //si zip_name_locate nos da -1, enviamos un mensaje de error y luego cerramos el programa de forma prematura.
        fprintf(stderr, "%s%sel archivo escrito no existe o ya se ha borrado anteriormente.%s", ROJO, BOLD, RESET);
        exit(EXIT_FAILURE);
    }

    codigo = zip_delete(archivo_zip, index_archivo);

    if (codigo == 0){
        printf("archivo: %s eliminado exitosamente.", nombre_archivo);
    }
    else{
        fprintf(stderr, "%s%sel archivo no se ha podido borrar.%s", ROJO, BOLD, RESET);
        exit(EXIT_FAILURE);
    }
}

