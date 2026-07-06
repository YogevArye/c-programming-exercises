#include "move_elements.h"

static void ShiftLeft(int array [], size_t size)
{
size_t i;    
for (i = 0; i < size - 1; ++i)
{
array[i] = array [i + 1];
}
}

void MoveElements(int array [], size_t size, size_t count)
{
int temp;
size_t i;
count %= size;
for (i = 0; i < count; ++i)
{
temp = array[0]; 
ShiftLeft(array, size);
array[size - 1] = temp;
}
}