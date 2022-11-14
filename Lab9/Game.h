#pragma once

#include <vector>
#include "IceCube.h"
#include "Random.h"

namespace lab9
{
	class Game final
	{
	public:
		Game(unsigned int seed);
		Game(const Game& other) = delete;
		~Game();

		Game& operator=(const Game&) = delete;
		void Spawn();
		void Update();
		const std::vector<IceCube*>& GetActiveGameObjects() const;

	private:
		enum { MAX_FRAME_COUNT_TO_LIVE = 100 };

		Random mRandom;
		std::vector<IceCube*> mActiveGameObjects;
	};
}
