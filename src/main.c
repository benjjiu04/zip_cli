#include <zip.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "abrir_zip.h"
#include "eliminar_archivo.h"
#include "styles.h"
#include "cli/cli_help.h"
#include "cli/mostrar_contenido.h"
#include "get_data.h"
#include "get_total_archivos.h"

/*'argc' argument count: un entero que contiene la cantidad de argumentos que se hicieron al llamar al programa.
'argv' argument vector: un array de punteros de char (basicamente un array de strings) que contiene los argumentos que se usaron al llamar el programa.*/
int main(int argc, char* argv[]){
    //si el argumento solamente es de la invocacion del programa, imprimimos un mensaje
    if (argc == 1){

        printf("%sbienvenido/a al CLI para manipular archivos zip\n", BOLD);
        printf("escriba %s'./zip_cli.exe%s -h' o './zip_cli.exe --help' para ver los comandos y sus respectivas descripciones.%s\n", ITALIC, RESET_ITALIC, RESET);
        
        return 0;
    }
    

    for (int i = 1; i < argc; i++){

        if ((strcmp(argv[i], "-h") == 0) || strcmp(argv[i], "--help") == 0){
            
            cli_help();          
        }
        else if ((strcmp(argv[i], "-l") == 0) || strcmp(argv[i], "--listar") == 0){
            /* si le sumamos 1 a el indice actual Y NO es mayor o igual a
            la cantidad de argumentos revisamos si el archivo zip existe.*/
            if (!(i + 1 >= argc) ){ 
                mostrar_contenido(argv[i + 1]);
            }
            else{
                fprintf(stderr, "%s%sno puede dejar vacio el argumento. %s\n", ROJO, BOLD, RESET);
                exit(EXIT_FAILURE);
            }
        }

        else if ((strcmp(argv[i], "-e") == 0) || (strcmp(argv[i], "--eliminar") == 0)){
            
            if (!(i + 1 >= argc) && !(i + 2 >= argc)){
        
                zip_t* archivo_zip = abrir_zip(argv[i + 1], 0);
                eliminar_archivo(archivo_zip, argv[i + 2]);
                
                zip_close(archivo_zip); //cerramos el archivo para evitar fugas de memoria.
            }

        }

        else if (strcmp(argv[i], "-g") == 0 || strcmp(argv[i], "--get-data") == 0){
            if ( (!(i + 1 >= argc)) ){

                get_data(argv[i + 1]);
            }
            else{

                fprintf(stderr, "%s%sporfavor ingrese la ruta del archivo zip.%s\n", ROJO, BOLD, RESET);
                exit(EXIT_FAILURE);
            }
        }

        else if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--contar-archivos") == 0){
           
            if ( (!(i + 1 >= argc)) ){
                printf("%stotal de archivos: %lld%s\n", BOLD, get_total_archivos(argv[i + 1]), RESET);
            }
        }


        else if (argv[i][0] == '-'){
            
            fprintf(stderr, "%s%sel argumento ingresado es invalido.%s", ROJO, BOLD, RESET);
            exit(EXIT_FAILURE);
        }

    }

    return 0;
}