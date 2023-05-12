#include "IntVector.h"
#include <math.h>
int getrand(int min, int max)
{
 return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

int main()
{
    IntVector* vector = int_vector_new(8);
    for (int i = 1;i<6;i++)
        int_vector_set_item(vector,i,getrand(1,40));
    int_vector_get_size(vector);
    int_vector_print(vector);
    return 0;
}