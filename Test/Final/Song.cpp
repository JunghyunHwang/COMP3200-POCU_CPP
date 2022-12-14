#include "Song.h"

namespace test
{
	Song::Song(const char* title, const char* artist)
		: mTitle(title)
		, mArtist(artist)
	{
	}

	Song::Song(const Song& other)
		: mTitle(other.mTitle)
		, mArtist(other.mArtist)
	{
		std::cout << "Copy: (" << mTitle << ", " << mArtist << ")" << std::endl;
	}

	std::string Song::GetTitle() const
	{
		return mTitle;
	}

	std::string Song::GetArtist() const
	{
		return mArtist;
	}
}