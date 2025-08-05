#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H
#include <errno.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef int16_t buffer_value_t;
typedef struct{
    uint8_t read;
    uint8_t write;
    uint8_t size;
    buffer_value_t array[];
}circular_buffer_t;

circular_buffer_t* new_circular_buffer(uint8_t size);
buffer_value_t read(circular_buffer_t *buffer, buffer_value_t *value);
buffer_value_t write(circular_buffer_t *buffer, buffer_value_t value);
buffer_value_t overwrite(circular_buffer_t *buffer, buffer_value_t value);
void clear_buffer(circular_buffer_t *buffer);
void delete_buffer(circular_buffer_t *buffer);



#endif
