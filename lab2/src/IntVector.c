#include "IntVector.h"

IntVector *int_vector_new(size_t initial_capacity)
{
    IntVector* v;
    v = (IntVector*)malloc(sizeof(IntVector));
    v->data = (int*)malloc(initial_capacity * sizeof(v->data));
    if ((v==NULL) || (v->data==NULL))
        return NULL;
    else
        return &v;
}

IntVector *int_vector_copy(const IntVector *v)
{
    IntVector* vcopy;
    vcopy = (IntVector*)malloc(sizeof(v));
    if (vcopy==NULL) return NULL;
    memcpy(vcopy,v,sizeof(v));
    return vcopy;
}

void int_vector_free(IntVector *v)
{
    free(v->data);
    free(v);
}

int int_vector_get_item(const IntVector *v, size_t index)
{
    return v->data[index];
}

void int_vector_set_item(IntVector *v, size_t index, int item)
{
    v->data[index] = item;
}

size_t int_vector_get_size(const IntVector *v)
{
    return v->size;
}

size_t int_vector_get_capacity(const IntVector *v)
{
    return v->capacity;
}

int int_vector_push_back(IntVector *v, int item)
{
    if (v->size<v->capacity)
        {
            v->data[v->size+1] = item;
            return 0;
        } else
            {
                v = realloc(v,v->capacity*2);
                if (v!=NULL)
                    return 0;
                else    
                    return -1;
            }
}

void int_vector_pop_back(IntVector *v)
{
    if (v->size!=0)
        {
            v->data[v->size] = NULL;
        }
}

int int_vector_shrink_to_fit(IntVector *v)
{
    v->data = realloc(v->data,v->size);
    return 0;
}

