#ifndef DATABASE_H
#define DATABASE_H

#include <unordered_map>
#include "../World Stuff/tile.h"

class Database
{
public:
	void Init();
	void destroy();
	void addTile(Tile tile);
	void removeTile(string name);
	Tile getTile(string name);
	unordered_map<string, Tile> getTiles();
protected:
private:
	unordered_map<string, Tile> tiles; // Map of tiles
};
#endif