#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length){
    if(length == 0) return NULL;

    int st = 0, mid = length / 2, end = length;
    int curr = arr[mid];
    while(curr != value){
        if(curr > value){
            end = mid - 1;
            mid = (st + end)/2;
        }
        else{
            st = mid + 1;
            mid = (st + end)/2;
        }
        curr = arr[mid];
        if(st >= end) return (arr[mid] == value) ? &arr[mid] : NULL;
    }
    return &arr[mid];
}
