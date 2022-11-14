#include "Test.h"

namespace lab9
{
	void TestOfficial()
	{

	}

	void TestWiki()
	{

	}

	void TestObjectPool()
	{
		ObjectPool<IceCube>* op = new ObjectPool<IceCube>(3);
		assert(op->GetMaxFreeObjectCount() == 3);

		IceCube* i1 = op->Get();
		assert(op->GetFreeObjectCount() == 0);

		IceCube* i2 = op->Get();
		assert(op->GetFreeObjectCount() == 0);

		IceCube* i3 = op->Get();
		assert(op->GetFreeObjectCount() == 0);

		IceCube* i4 = op->Get();
		assert(op->GetFreeObjectCount() == 0);

		op->Return(i1);
		assert(op->GetFreeObjectCount() == 1);
		op->Return(i2);
		assert(op->GetFreeObjectCount() == 2);
		op->Return(i3);
		assert(op->GetFreeObjectCount() == 3);
		op->Return(i4);
		assert(op->GetFreeObjectCount() == 3);

		delete op;
	}
}