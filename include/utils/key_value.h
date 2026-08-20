#pragma once

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "styles.h"

typedef struct{
    int key;
    const char* value;
}KeyValue;

const char* get_value(KeyValue* self, int llave, size_t total_elementos){
    

    if (total_elementos == 0){

        fprintf(stderr, "%s%sel total de elementos no puede ser igual a 0. %s", ROJO, BOLD, RESET);
        exit(EXIT_FAILURE);
    }


    for (size_t i = 0; i < total_elementos; i++){

        if (self[i].key == llave){
            return self[i].value;
        }
    }

    fprintf(stderr, "valor no encontrado.");
    return nullptr;
}
