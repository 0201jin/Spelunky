#pragma once
#include <vector>
#include <queue>

using namespace std;

typedef struct Position
{
	int X;
	int Y;

	Position operator- (const Position& A)
	{
		return { X - A.X, Y - A.Y };
	}

	bool operator == (const Position& A)
	{
		return A.X == X && A.Y == Y;
	}

	int Weight(const Position& A)
	{
		return abs(X - A.X) + abs(Y - A.Y);
	}

	double Distance(const Position& A)
	{
		return sqrt((X - A.X) * (X - A.X) + (Y - A.Y) * (Y - A.Y));
	}

}Position;

typedef struct RoomStruct
{
	int Blocks[16][16] = { 0, };
	vector<Position> ConnectRoom;
	vector<Position> Road;
	bool bStart = false;
	bool bEnd = false;

	RoomStruct()
	{
		fill_n(Blocks[0], 256, 1);
	}

	void RoomDigCenter()
	{
		for (int y = 7; y < 9; y++)
			for (int x = 6; x < 9; x++)
				Blocks[x][y] = 0;
	}
}RoomStruct;

class MapGenerator
{
public:
	MapGenerator();

private:
	void CreateRoadData(Position _r1, Position _r2);
	void CreateRoad();

	void CreateRoadRecursion(Position A, Position B, int _rx, int _ry);
	void SettingBlock();

	bool CheckFloorBlcok(Position _roomPosition, Position _position);
	bool CheckCeilBlock(Position _roomPosition, Position _position);

public:
	queue<vector<vector<RoomStruct>>> Level;
};