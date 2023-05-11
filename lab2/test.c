#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} IntVector;

IntVector *int_vector_new(size_t initial_capacity)
{
    IntVector* v;
    v = (IntVector*)malloc(sizeof(IntVector));
    if (v==NULL)
        return NULL;
    v->data = (int*)malloc(initial_capacity * sizeof(int));
    if (v->data==NULL)
    {
        free(v);
        return NULL;
    }
    else
    {
        v->capacity = initial_capacity;
        v->size = 0;
        return v;
    }
}

IntVector *int_vector_copy(const IntVector *v)
{
    IntVector* vcopy;
    vcopy = int_vector_new(v->capacity);
    printf("%ld\n",sizeof(v));
    printf("%ld\n",sizeof(vcopy));    
    vcopy->size = v->size;
    for (int i = 0; i < v->size; i++)
        vcopy->data[i] = v->data[i];
        
    return vcopy;
}

// IntVector *int_vector_copy(const IntVector *v)
// {
//     IntVector* vcopy;
//     vcopy = int_vector_new(v->capacity);
    
//     memcpy(&vcopy->data,&v->data,sizeof(&v->data));
//     memcpy(&vcopy->size,&v->size,sizeof(&v->size));
//     return vcopy;
// }

int main()
{
    IntVector* vec = int_vector_new(110);
    vec->size = 100;
    vec->data[0] = 3;
    vec->data[1] = 1;
    vec->data[2] = 6;
    vec->data[3] = 2;
    vec->data[4] = 10;
    for (int i = 0;i<vec->size;i++)
        vec->data[i] = 242422;
    IntVector* copy;
    copy = int_vector_copy(vec);
    int b[10] = {3,1,2,3,6,1,4,4,2,31};
    printf("data: ");
    for (int i = 0;i<copy->size;i++)
        printf("%d ",copy->data[i]);
    printf("\ncapacity: %ld\nsize: %ld\n",copy->capacity,copy->size);
    printf("!original!\n");
    printf("data: ");
    for (int i = 0;i<vec->size;i++)
        printf("%d ",vec->data[i]);
    printf("\ncapacity: %ld\nsize: %ld\n",vec->capacity,vec->size);
    printf("%ld\n",sizeof(b));
    return 0;
}