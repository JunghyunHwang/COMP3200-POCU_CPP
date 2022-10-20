#pragma once
#include <iostream>
#include "Foo.h"

class Bar : public Foo
{
public:
	Bar();
	virtual ~Bar();
	void DoMagic() const;
	void BlackMagic() const;
private:
	int mX;
};

