#include <stdio.h>
#include <stdlib.h>


struct dynamic_array
{
    size_t length; //number of ints in the array
    size_t capacity; // number of ints the array can hold
    int *data; //whats inside the array

} ;
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
    if(arr->length < arr->capacity ){
        arr -> data[arr->length] = value;
        arr->length++;
        return 0;
    } else if(arr->length == arr->capacity){
        
        if((arr->data = realloc(arr->data,sizeof(int)*((arr->capacity)*2))) != NULL){
            arr->capacity = (arr->capacity)*2;
            arr -> data[(arr->length )+ 1] = value;
            arr->length++;
        } else {
            return -1;
        }
    } else {
        return -2;
    }
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


int main(void){
    struct dynamic_array x = create_arr(5);
    printf("%zu\n",x.length);
    push(&x,7);
    printf("%zu\n",x.length);
}