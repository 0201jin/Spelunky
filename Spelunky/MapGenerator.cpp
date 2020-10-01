#include "MapGenerator.h"
#include <iostream>

MapGenerator::MapGenerator()
{
	for (int i = 0; i < 3; i++)
	{
		int StartIndex = rand() % 4;

		RoomStruct room[4][4];
		room[StartIndex][0].bStart = true;

		Position PrevRoom = { StartIndex, 0 };

		for (char y = 0; y < 4; y++)
		{
			bool Course = rand() % 2; //true ¿ÞÂÊ false ¿À¸¥ÂÊ

			if (PrevRoom.X == 0)
				Course = false;
			else if (PrevRoom.X == 3)
				Course = true;

			for (char x = 0; x < 4; x++)
			{
				char MoveX = Course ? -1 : 1;

				room[PrevRoom.X][PrevRoom.Y].ConnectRoom.push_back({ PrevRoom.X + MoveX ,y });
				room[PrevRoom.X + MoveX][PrevRoom.Y].ConnectRoom.push_back({ PrevRoom.X ,y });

				PrevRoom = { PrevRoom.X + MoveX ,y };

				if ((PrevRoom.X == 0 || PrevRoom.X == 3) && (PrevRoom.Y == y))
					break;

				if (rand() % 2 == 0)
					break;
			}

			room[PrevRoom.X][PrevRoom.Y].bEnd = true;
		}

		Level.push(*room);
	}
}