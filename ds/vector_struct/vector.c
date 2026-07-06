#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "vector.h"

status_type VectorConstruct(vector_type* vector, size_t capacity)
{
  status_type status = 0;
    
  vector->array = malloc(capacity * sizeof(int));
    
  if (vector->array == NULL)
  {
      printf("Memory allocation failed\n");
      status = -1; 
  }
   vector->capacity = capacity; 
   vector->size = 0;
    
  return status;
}
void VectorDestruct(vector_type* vector)
{
    free(vector->array);
}
void VectorResize(vector_type* vector, int addition)
{
     assert(vector->size + addition <= vector->capacity);
     vector->size += addition;
}
void VectorPush(vector_type* vector, int data)
{
    assert(vector->size < vector->capacity);
    vector->array[vector->size++] = data;
}
int VectorPop(vector_type* vector)
{
    assert(vector->size > 0);
    return vector->array[--vector->size];
}











