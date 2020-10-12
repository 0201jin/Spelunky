#include "MapGenerator.h"
#include <iostream>
#include <time.h>
#include <algorithm>

ostream& operator<<(ostream& os, const Position& A)
{
	return (A.X <= 15 && A.X >= 0) && (A.Y <= 15 && A.Y >= 0) ? os << A.X << " " << A.Y << " / " : os << "Error ";
}

bool Sorting(pair<int, int> A, pair<int, int> B)
{
	return A.second < B.second;
}

MapGenerator::MapGenerator()
{
	srand((unsigned)time(0));

	for (int i = 0; i < 1; i++)
	{
		int StartIndex = rand() % 4;
		bool bRoomCheck[4][4] = { false, };

		Level.push(vector<vector<RoomStruct>>(4));

		for (int y = 0; y < 4; y++)
			Level.back()[y] = vector<RoomStruct>(4);

		Level.back()[StartIndex][0].bStart = true;

		Position PrevRoom = { StartIndex, 0 };
		bRoomCheck[PrevRoom.X][PrevRoom.Y] = true;

		cout << "Start " << PrevRoom << endl;

		Level.back()[PrevRoom.X][PrevRoom.Y].Road.push_back({ 7, 7 });
		Level.back()[PrevRoom.X][PrevRoom.Y].RoomDigCenter();

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

				if (PrevRoom.Y != y)
					MoveX = 0;

				Level.back()[PrevRoom.X][PrevRoom.Y].ConnectRoom.push_back({ PrevRoom.X + MoveX ,y });
				Level.back()[PrevRoom.X + MoveX][y].ConnectRoom.push_back(PrevRoom);

				CreateRoadData(PrevRoom, { PrevRoom.X + MoveX, y });

				if ((PrevRoom.X + MoveX == 0 || PrevRoom.X + MoveX == 3) && (PrevRoom.Y == y))
				{
					PrevRoom = { int(PrevRoom.X + MoveX) ,y };
					bRoomCheck[PrevRoom.X][PrevRoom.Y] = true;

					break;
				}

				PrevRoom = { int(PrevRoom.X + MoveX) ,y };
				bRoomCheck[PrevRoom.X][PrevRoom.Y] = true;

				if (rand() % 2 == 0)
					break;
			}
		}

		Level.back()[PrevRoom.X][PrevRoom.Y].bEnd = true;
		Level.back()[PrevRoom.X][PrevRoom.Y].Road.push_back({ 7, 7 });
		Level.back()[PrevRoom.X][PrevRoom.Y].RoomDigCenter();

		cout << "End " << PrevRoom << endl;

		//나머지 방 연결
		for (int x = 0; x < 4; x++)
		{
			for (int y = 0; y < 4; y++)
				if (!bRoomCheck[x][y])
				{
					bRoomCheck[x][y] = true;

					int Random = rand() % 5;

					if (Random == 4)
						break;

					switch (Random)
					{
					case 0: //상
						if (y - 1 < 0)
						{
							y--;
							break;
						}

						Level.back()[x][y].ConnectRoom.push_back({ x, y - 1 });
						Level.back()[x][y - 1].ConnectRoom.push_back({ x, y });

						CreateRoadData({ x, y }, { x, y - 1 });

						break;

					case 1: //하
						if (y + 1 > 3)
						{
							y--;
							break;
						}

						Level.back()[x][y].ConnectRoom.push_back({ x, y + 1 });
						Level.back()[x][y + 1].ConnectRoom.push_back({ x, y });

						CreateRoadData({ x, y }, { x, y + 1 });

						break;

					case 2: //좌
						if (x - 1 < 0)
						{
							y--;
							break;
						}

						Level.back()[x][y].ConnectRoom.push_back({ x - 1, y });
						Level.back()[x - 1][y].ConnectRoom.push_back({ x, y });

						CreateRoadData({ x, y }, { x - 1, y });

						break;

					case 3: //우
						if (x + 1 > 3)
						{
							y--;
							break;
						}

						Level.back()[x][y].ConnectRoom.push_back({ x + 1, y });
						Level.back()[x + 1][y].ConnectRoom.push_back({ x, y });

						CreateRoadData({ x, y }, { x + 1, y });

						break;
					}
				}
		}

		//통로 연결
		CreateRoad();

		//블록 배치
	}
}

void MapGenerator::CreateRoadData(Position _r1, Position _r2)
{
	int Random = (rand() % 10) + 1;

	if (_r1.X == _r2.X)
	{
		//위 아래로 통로
		if (_r1.Y > _r2.Y)
		{
			//_r1은 위 _r2는 아래를 뚫는다.
			Level.back()[_r1.X][_r1.Y].Road.push_back({ Random , 0 });
			Level.back()[_r2.X][_r2.Y].Road.push_back({ Random , 15 });
		}
		else
		{
			//r1은 아래 r2는 위를 뚫는다.
			Level.back()[_r1.X][_r1.Y].Road.push_back({ Random , 15 });
			Level.back()[_r2.X][_r2.Y].Road.push_back({ Random , 0 });
		}
	}
	else if (_r1.Y == _r2.Y)
	{
		//좌 우로 통로
		if (_r1.X > _r2.X)
		{
			//r1은 왼쪽을 r2는 오른쪽을 뚫는다.
			Level.back()[_r1.X][_r1.Y].Road.push_back({ 0 , Random });
			Level.back()[_r2.X][_r2.Y].Road.push_back({ 15 , Random });
		}
		else
		{
			//r1은 오른쪽을 r2는 왼쪽을 뚫는다.
			Level.back()[_r1.X][_r1.Y].Road.push_back({ 15 , Random });
			Level.back()[_r2.X][_r2.Y].Road.push_back({ 0 , Random });
		}
	}
}

void MapGenerator::CreateRoad()
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			int Vertex = (rand() % 5) + 1;

			for (int i = 0; i < Vertex; i++)
			{
				int rx = rand() % 14 + 1;
				int ry = rand() % 14 + 1;

				Level.back()[x][y].Road.push_back({ rx, ry });
			}

			vector<pair<int, int>> Graph[10];

			for (int i = 0; i < Level.back()[x][y].Road.size(); i++)
			{
				for (int j = 0; j < Level.back()[x][y].Road.size(); j++)
					if (i != j)
					{
						int W = Level.back()[x][y].Road[i].Weight(Level.back()[x][y].Road[j]);
						Graph[i].push_back(make_pair(j, W));
					}

				if (Graph[i].size() > 2)
				{
					sort(Graph[i].begin(), Graph[i].end(), Sorting);

					int Size = Graph[i].size();
					for (int j = 0; j < Size && 1 < Graph[i].size(); j++)
					{
						int Start = i;
						int Prev = Start;

						for (int k = 1; k < Graph[i].size(); k++)
						{
							if (Graph[Prev].size() != 0)
							{
								int Now = Graph[Prev][0].first;

								if (Now == Prev || Now == Start)
								{
									Graph[i].erase(Graph[i].begin());
									break;
								}

								Prev = Now;
							}
						}
					}

					Graph[i].erase(Graph[i].begin() + 1, Graph[i].end());
				}
			}

			//지점 별로 통로 연결
			for (int i = 0; i < 10; i++)
			{
				if (Graph[i].size() == 0)
					break;

				int APointIndex = i;
				int BPointIndex = Graph[i][0].first;

				Position A = Level.back()[x][y].Road[APointIndex];
				Position B = Level.back()[x][y].Road[BPointIndex];

				Position A_, B_;

				if (A == B)
					break;

				if (rand() % 2 == 0 && abs(A.Y - B.Y) != 0)
				{
					A_.X = A.X;
					A_.Y = A.Y > B.Y ? A.Y - (rand() % abs(A.Y - B.Y)) : A.Y + (rand() % abs(A.Y - B.Y));
				}
				else if (abs(A.X - B.X) != 0)
				{
					A_.X = A.X > B.X ? A.X - (rand() % abs(A.X - B.X)) : A.X + (rand() % abs(A.X - B.X));
					A_.Y = A.Y;
				}
				else
				{
					A_.X = A.X;
					A_.Y = A.Y > B.Y ? A.Y - (rand() % abs(A.Y - B.Y)) : A.Y + (rand() % abs(A.Y - B.Y));
				}

				if (rand() % 2 == 0 && abs(A.Y - B.Y) != 0)
				{
					B_.X = B.X;
					B_.Y = A.Y < B.Y ? B.Y - (rand() % abs(A.Y - B.Y)) : B.Y + (rand() % abs(A.Y - B.Y));
				}
				else if (abs(A.X - B.X) != 0)
				{
					B_.X = A.X < B.X ? B.X - (rand() % abs(A.X - B.X)) : B.X + (rand() % abs(A.X - B.X));
					B_.Y = B.Y;
				}
				else
				{
					B_.X = B.X;
					B_.Y = A.Y < B.Y ? B.Y - (rand() % abs(A.Y - B.Y)) : B.Y + (rand() % abs(A.Y - B.Y));
				}

				//길 뚫기
				//A -> A_
				CreateRoadRecursion(A, A_, x, y);

				//B -> B_
				CreateRoadRecursion(B, B_, x, y);

				//B_ -> A_
				CreateRoadRecursion(B_, A_, x, y);
			}
		}
	}
}

void MapGenerator::CreateRoadRecursion(Position _A, Position _B, int _rx, int _ry)
{
	Position Center = { (_A.X - _B.X) / 2 + _B.X, (_A.Y - _B.Y) / 2 + _B.Y };

	if (!(_A.X == _B.X || _A.Y == _B.Y))
	{
		int randX = (rand() % 3);
		int randY = (rand() % 3);

		for (int x = -1; x <= randX; x++)
		{
			for (int y = -1; y <= randY; y++)
			{
				if (_A.X + x >= 0 && _A.X + x <= 15 && _A.Y + y >= 0 && _A.Y + y <= 15)
					Level.back()[_rx][_ry].Blocks[_A.X + x][_A.Y + y] = 0;

				if (_B.X + x >= 0 && _B.X + x <= 15 && _B.Y + y >= 0 && _B.Y + y <= 15)
					Level.back()[_rx][_ry].Blocks[_B.X + x][_B.Y + y] = 0;

				if (Center.X + x >= 0 && Center.X + x <= 15 && Center.Y + y >= 0 && Center.Y + y <= 15)
					Level.back()[_rx][_ry].Blocks[Center.X + x][Center.Y + y] = 0;
			}
		}
	}
	else
	{
		if (rand() % 2 == 0)
		{
			Level.back()[_rx][_ry].Blocks[_A.X][_A.Y] = 0;
			Level.back()[_rx][_ry].Blocks[_B.X][_B.Y] = 0;
			Level.back()[_rx][_ry].Blocks[Center.X][Center.Y] = 0;
		}
		else
		{
			int randX = (rand() % 1) - 1;
			int randY = (rand() % 1) - 1;

			for (int x = -1; x <= randX; x++)
			{
				for (int y = -1; y <= randY; y++)
				{
					if (_A.X + x >= 0 && _A.X + x <= 15 && _A.Y + y >= 0 && _A.Y + y <= 15)
						Level.back()[_rx][_ry].Blocks[_A.X + x][_A.Y + y] = 0;

					if (_B.X + x >= 0 && _B.X + x <= 15 && _B.Y + y >= 0 && _B.Y + y <= 15)
						Level.back()[_rx][_ry].Blocks[_B.X + x][_B.Y + y] = 0;

					if (Center.X + x >= 0 && Center.X + x <= 15 && Center.Y + y >= 0 && Center.Y + y <= 15)
						Level.back()[_rx][_ry].Blocks[Center.X + x][Center.Y + y] = 0;
				}
			}
		}
	}

	if (_A == _B || _A.Distance(_B) < 2)
		return;

	CreateRoadRecursion(_A, Center, _rx, _ry);
	CreateRoadRecursion(_B, Center, _rx, _ry);
}
