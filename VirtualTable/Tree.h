#pragma once

namespace virtualtable
{
	class Tree
	{
	public:
		Tree(unsigned int age);
		virtual ~Tree();

	private:
		unsigned int mAge;
	};
}
