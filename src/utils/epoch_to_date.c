#include "utils/epoch_to_date.h"
#include <time.h>
#include <string.h>

#define MAX_LIMIT 200
const char* epoch_to_date(char* output_buffer, size_t size_of_buffer, long long int epoch){

    char buffer[MAX_LIMIT];

    struct tm* hora_local = localtime(&epoch);
    strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", hora_local);

    return strncpy(output_buffer, buffer, size_of_buffer);

}