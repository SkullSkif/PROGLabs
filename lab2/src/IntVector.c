#include "IntVector.h"

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
    if (vcopy==NULL) return NULL;
    vcopy->size = v->size;
    for (int i = 0; i < v->size; i++)
        vcopy->data[i] = v->data[i];
    return vcopy;
}

void int_vector_free(IntVector *v)
{
    if (v!=NULL)
    {
        free(v->data);
        free(v);
    }
}

int int_vector_get_item(const IntVector *v, size_t index)
{
    if (v==NULL)
        return 0;
    if (v->size>index)
        return v->data[index];
    else
        return 0;
}

void int_vector_set_item(IntVector *v, size_t index, int item)
{
    if (v==NULL)
        return 0; 
    if (v->size>index)
        v->data[index] = item;
    else
        return 0;
}

size_t int_vector_get_size(const IntVector *v)
{
    if (v==NULL)
        return 0; 
    return v->size;
}

size_t int_vector_get_capacity(const IntVector *v)
{
    if (v==NULL)
        return 0; 
    return v->capacity;
}

int int_vector_push_back(IntVector *v, int item)
{
    if (v==NULL)
        return 0;     
    if (v->size<v->capacity)
        {
            v->data[v->size+1] = item;
            v->size++;
            return 0;
        } else
            {
                v = realloc(v,(v->capacity)*2);
                if (v!=NULL)
                    return 0;
                else    
                    return -1;
            }
}

void int_vector_pop_back(IntVector *v)
{
    if (v==NULL)
        return 0; 
    if (v->size>0)
            v->size--;
}

int int_vector_shrink_to_fit(IntVector *v)
{
    if (v==NULL)
        return 0;   
    if (v->size==v->capacity)
        return 0;  
    v->data = (int*)realloc(v->data,v->size*sizeof(int));
    if (v->data==NULL)
        return -1;   
    v->capacity = v->size;
    return 0;
}

int int_vector_resize(IntVector *v, size_t new_size)
{
    if (v==NULL)
        return -1;
    int* new = NULL;
    if (v->size==new_size)
        return 0;
    if (v->size>new_size)
        return 0;
    if (v->size<new_size)
        {
            if (v->capacity<new_size)
            {
                new = realloc(v->data, new_size * sizeof(int));
                }
                v->capacity = new_size
            }
        for (int i = v->size;i<new_size;i++)
            v->data[i] = 0;
        v->size = new_size;
        }
}

int int_vector_reserve(IntVector* v, size_t new_capacity)
{
    if (!v) {
        return -1;
    }
    if (new_capacity <= v->capacity) {
        return 0;
    }

    v->data = (int*)realloc(v->data, new_capacity * sizeof(int));

    if (v->data==NULL)
        return -1;
    v->capacity = new_capacity;

    return 0;
}

void int_vector_print(IntVector* v)
{
    printf("Вектор: ");
    for (int i = 0;i<v->size;i++)
        printf("%d ",v->data[i]);
    printf("\nРазмер вектора: %ld\nЕмкость вектора: %ld\n",v->size,v->capacity);
}

