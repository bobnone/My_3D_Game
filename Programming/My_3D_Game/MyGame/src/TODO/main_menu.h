#ifndef TILE
#define TILE

#include <string>
using namespace std;

class Tile
{
private:
	string path;
	void Init(string path);
public:
	Tile(string path);
	~Tile();
	void Render(int x, int y);
	string getTexturePath();
};
#endif