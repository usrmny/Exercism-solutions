#include "gigasecond.h"

void gigasecond(time_t input, char *output, size_t size){
    time_t buffer = input + 1000000000;
    struct tm *ft = gmtime(&buffer);

    strftime(output, size, "%Y-%m-%d %H:%M:%S", ft);
}