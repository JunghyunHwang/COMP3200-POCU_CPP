#include <stdio.h>

#include "vector_by_c.h"

int main(void)
{
	init_vector_class();

	vector_t* vec = new_vector_at_heap(2, 1);

	printf("X: %d", vec->m_x);
	printf("Y: %d", vec->m_y);

	return 0;
}
