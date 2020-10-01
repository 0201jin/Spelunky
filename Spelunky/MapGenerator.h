#pragma once
#include <vector>
#include <queue>

using namespace std;

typedef struct Position
{
	char X;
	char Y;
}Position;

typedef struct RoomStruct
{
	unsigned char Blocks[16][16] = { 0, };
	vector<Position> ConnectRoom;
	bool bStart = false;
	bool bEnd = false;

	RoomStruct()
	{
		for (int x = 0; x < 16; x += 15)
			for (int i = 0; i < 16; i++)
			{
				Blocks[x][i] = 1;
			}

		for(int y = 0; y < 16; y += 15)
			for (int i = 0; i < 16; i++)
			{
				Blocks[i][y] = 1;
			}
	}
}RoomStruct;

class MapGenerator
{
public:
	MapGenerator();

public:
	queue<RoomStruct*> Level;
};