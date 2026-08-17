#include "listar_contenido.h"
#include "cli/mostrar_contenido.h"
#include "abrir_zip.h"
#include <zip.h>
#include <stdio.h>
#include <string.h>


void mostrar_contenido(const char* nombre_archivo_zip){

    zip_t* archivo_usuario = abrir_zip(nombre_archivo_zip, 0);
    listar_contenido(archivo_usuario);

}