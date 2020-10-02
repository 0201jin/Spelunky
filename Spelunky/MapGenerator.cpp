#include "MapGenerator.h"
#include <iostream>

MapGenerator::MapGenerator()
{
	for (int i = 0; i < 3; i++)
	{
		int StartIndex = rand() % 4;

		Level.push(vector<vector<RoomStruct>>(4));

		for (int y = 0; y < 4; y++)
			Level.back()[y] = vector<RoomStruct>(4);

		Level.back()[StartIndex][0].bStart = true;

		Position PrevRoom = { StartIndex, 0 };

		for (int y = 0; y < 4; y++)
		{
			bool Course = rand() % 2; //true 왼쪽 false 오른쪽

			if (PrevRoom.X == 0)
				Course = false;
			else if (PrevRoom.X == 3)
				Course = true;

			for (int x = 0; x < 4; x++)
			{
				int MoveX = Course ? -1 : 1;

				Level.back()[PrevRoom.X][PrevRoom.Y].ConnectRoom.push_back({ PrevRoom.X + MoveX ,y });
				Level.back()[PrevRoom.X + MoveX][PrevRoom.Y].ConnectRoom.push_back({ PrevRoom.X ,y });

				PrevRoom = { int(PrevRoom.X + MoveX) ,y };

				if ((PrevRoom.X == 0 || PrevRoom.X == 3) && (PrevRoom.Y == y))
					break;

				if (rand() % 2 == 0)
					break;
			}

			Level.back()[PrevRoom.X][PrevRoom.Y].bEnd = true;
		}

		//블럭 배치

		//통로 연결
	}
}