#include <iostream>
#include <string>

#include "Foo.h"
#include "Bar.h"
#include "Baz.h"
#include "Qux.h"

int main()
{
	Foo* f = new Foo();
	Bar* br = new Bar();
	Baz* bz = new Baz();
	Qux* q = new Qux();

	Bar* qb = static_cast<Bar*>(q);

	q->PrintBar();
	qb->PrintBar();

	return 0;
}