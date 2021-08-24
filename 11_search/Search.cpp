#include "Search.h"

Search::Search(std::function<bool(int, int)> func)
	:func(func)
{
}

bool Search::isVisited(Pos pos)
{
	for (auto p:path)
	{
		if (pos.x == p.x && pos.y == p.y)
		{
			return true;
		}
	}
	return false;
}

bool Search::inAear(Pos pos)
{
	return func(pos.x, pos.y)&&!isVisited(pos);
}
