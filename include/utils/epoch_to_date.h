#pragma once

#include <string.h>
/**
 * @brief funcion que transforma los segundos desde la epoca UNIX a una fecha legible.
 * @param output_buffer un char para modificar y regresar su valor modificado.
 * @param epoch un long long int que contenga el tiempo que pasó en segundos desde la epoca UNIX.
 * @param size_of_buffer el tamaño del buffer, teniendo en cuenta el caracter '\0'
 * @returns const char* un string literal con la fecha formateada.
 */
const char* epoch_to_date(char* output_buffer, size_t size_of_buffer, long long int epoch);