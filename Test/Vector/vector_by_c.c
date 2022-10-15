#include <stdlib.h>
#include "vector_by_c.h"

void init_vector_class()
{
	(void(*)(vector_t* const, const int))s_base.set_x = set_x;
	(void(*)(vector_t* const, const int))s_base.set_y = set_y;
	(int(*)(const vector_t* const))s_base.get_x = get_x;
	(int(*)(const vector_t* const))s_base.get_y = get_y;
}

vector_t make_vector_at_stack(vector_t* this, const int x, const int y)
{
	this->base = &s_base;
	this->this = this;

	this->m_x = x;
	this->m_y = y;
	
	return *this;
}

vector_t* new_vector_at_heap(const int x, const int y)
{
	vector_t* new_vector = (vector_t*)malloc(sizeof(vector_t));

	new_vector->base = &s_base;
	new_vector->this = new_vector;

	new_vector->m_x = x;
	new_vector->m_y = y;

	return new_vector;
}

void set_x(vector_t* const this, const int x)
{
	this->m_x = x;
}

void set_y(vector_t* const this, const int y)
{
	this->m_y = y;
}

int get_x(const vector_t* const this)
{
	return this->m_x;
}

int get_y(const vector_t* const this)
{
	return this->m_y;
}