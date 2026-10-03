#include <stdlib.h>
#include <dynarray.h>

struct dynamic_array create_arr(size_t capacity) {
    struct dynamic_array arr;
    if(capacity != 0 && (arr.data = malloc(sizeof(int)*capacity)) != NULL){
        arr.length = 0;
        arr.capacity = capacity;
        return arr;
    } else {
        arr.length = 0;
        arr.capacity = 0;
        arr.data = NULL;
        return arr;
    }
}

struct dynamic_array empty_arr(void){
    struct dynamic_array arr;
    arr.length = 0;
    arr.capacity = 0;
    arr.data = NULL;
    return arr;
}
void destroy_arr(struct dynamic_array *arr){
    arr->capacity = 0;
    arr->length = 0;
    free(arr->data);
    arr->data = NULL;
}

int push(struct dynamic_array *arr, int value){
    if(arr->length == arr->capacity){
        size_t capa=0;
        if(arr->capacity == 0){
            capa = 4;
        }else{
            capa = (arr->capacity)*2;
        }
        int *p = realloc(arr->data,sizeof(int)*capa);
        if(p == NULL) return -1;
        arr->data = p;
        arr->capacity = capa;
    }
        arr -> data[arr->length] = value;
        arr->length++;
        return 0;
}
int pop(struct dynamic_array *arr, int *out){
    if(arr->length == 0 ){
        return -1;
    }else {
        *out = arr->data[(arr->length)-1];
        arr->length--;
        return 0;
    }
}

