#include "Bar.h"

Bar::Bar()
{
}

Bar::~Bar()
{
}

void Bar::DoMagic() const
{
	std::cout << "Bar magic" << std::endl;
}

void Bar::BlackMagic() const
{
	std::cout << mX << std::endl;
}
