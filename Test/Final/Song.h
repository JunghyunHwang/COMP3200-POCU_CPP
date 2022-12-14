#pragma once

#include <iostream>
#include <string>

namespace test
{
	class Song final
	{
	public:
		Song(const char* title, const char* artist);
		~Song() = default;
		Song(const Song& other);
		Song& operator=(const Song& rhs) = default;

		std::string GetTitle() const;
		std::string GetArtist() const;

	private:
		std::string mTitle;
		std::string mArtist;
	};
}

