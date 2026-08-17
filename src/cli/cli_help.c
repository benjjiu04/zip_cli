#include "cli/cli_help.h"
#include "styles.h"
#include <stdio.h>
#include <windows.h>

void cli_help(){

   SetConsoleCP(CP_UTF8);
   SetConsoleOutputCP(CP_UTF8);

   printf("\n%s-e | --eliminar:  elimina un archivo que esté dentro de un archivo ZIP.\n\n", BOLD);
   printf("-l | --listar:    imprime una lista de todos los archivos que esten dentro de un archivo ZIP.\n"
   "\t\t  el primer argumento debe ser la ruta del archivo zip y el segundo el nombre del archivo.\n\n");
   printf("-h | --help:      obtener ayuda con los comandos.\n\n");
   printf("-g | --get-data:  obtiene metadatos de todos los archivo dentro de un archivo ZIP.\n\n");
   printf("-e | --enumerar:  regresa la cantidad de archivos que hay dentro de un archivo ZIP.%s\n", RESET);
   
   return;
}