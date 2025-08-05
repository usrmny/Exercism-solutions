#include "circular_buffer.h"


circular_buffer_t* new_circular_buffer(uint8_t size){
    circular_buffer_t *buffer = malloc(sizeof(circular_buffer_t) + sizeof(buffer_value_t) * (size + 1));
    //remember to leave one empty
    // read == write => empty
    // write + 1 == read => full
    //ps, write point to the next place to write, not the last place written

    buffer->read = 0;
    buffer->write = 0;
    buffer->size = size;
    return buffer;
}

buffer_value_t read(circular_buffer_t *buffer, buffer_value_t *value){
    printf("read:%d, write:%d\n", buffer->read, buffer->write);
    if(buffer->read == buffer->write) {
        errno = ENODATA;
        return 1;
    }
    *value = buffer->array[buffer->read];
    buffer->read = (buffer->read + 1) % (buffer->size + 1);
    return 0;
}


buffer_value_t write(circular_buffer_t *buffer, buffer_value_t value){
    if((buffer->write + 1) % (buffer->size + 1) == buffer->read) {
        errno = ENOBUFS;
        return 1;
    }
    buffer->array[buffer->write] = value;
    buffer->write = (buffer->write + 1) % (buffer->size + 1);
    return 0;
}
buffer_value_t overwrite(circular_buffer_t *buffer, buffer_value_t value){
    if((buffer->write + 1) % (buffer->size + 1) == buffer->read) {
        buffer->read = (buffer->read + 1) % (buffer->size + 1);
    } // if full, gotta update read
    buffer->write %= (buffer->size + 1);
    buffer->array[buffer->write] = value;
    buffer->write = (buffer->write + 1) % (buffer->size + 1);
    return 0;
}

void clear_buffer(circular_buffer_t *buffer){
    buffer->read = buffer->write = 0;
}

void delete_buffer(circular_buffer_t *buffer){
    free(buffer);
}
