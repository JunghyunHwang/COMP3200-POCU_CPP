#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
	void(*set_x)(void* const this, int x);
	void(*set_y)(void* const this, int y);
	int(*get_x)(void* const this);
	int(*get_y)(void* const this);
} vector_class_base;

typedef struct vector {
	vector_class_base* base;
	struct vector* this;
	int m_x;
	int m_y;
} vector_t;

static vector_class_base s_base;

void init_vector_class();
vector_t make_vector_at_stack(vector_t* this, const int x, const int y);
vector_t* new_vector_at_heap(const int x, const int y);
void set_x(vector_t* const this, const int x);
void set_y(vector_t* const this, const int y);
int get_x(const vector_t* const this);
int get_y(const vector_t* const this);
#endif /* VECTOR_H*/