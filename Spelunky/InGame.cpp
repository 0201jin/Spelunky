#include "InGame.h"
#include "StageMgr.h"

void InGame::Init(ID2D1HwndRenderTarget* _D2DRenderTarget)
{
	D2DRenderTarget = _D2DRenderTarget;

	MapGen = new MapGenerator();

	vector<vector<RoomStruct>> RoomArr = MapGen->Level.front();

	D2D_VECTOR_2F Start;

	for (int rx = 0; rx < 4; rx++)
		for (int ry = 0; ry < 4; ry++)
		{
			if (RoomArr[rx][ry].bStart)
				Start = {(float)(rx * 16 - 8) * 80, 0.0f};

			for (int x = 0; x < 16; x++)
				for (int y = 0; y < 16; y++)
				{
					int BlockNumber = RoomArr[rx][ry].Blocks[x][y];

					if (BlockNumber != 0)
					{
						cout << BlockNumber;
						cout << " rx: " << rx;
						cout << " ry: " << ry;
						cout << " x :" << x;
						cout << " y " << y << endl;

						Block* block = new Block();

						block->SetLocation((rx * 16) + x, (ry * 16) + y);
						block->SetObjectNumber(BlockNumber);

						Blocks.push_back(block);
					}
				}
		}

	Player = StageMgr::GetInst()->GetPlayer();
	Player->SetLocation(Start);

	MapGen->Level.pop();
}

void InGame::Update(float _deltaTime)
{
	Player->Update(_deltaTime);

	D2D_VECTOR_2F Lo = Player->GetLocation();
	D2DRenderTarget->SetTransform(D2D1_MATRIX_3X2_F({ 1, 0, 0, 1, -Lo.x + 640, -Lo.y + 360 }));
}

void InGame::Render(float _deltaTime)
{
	for (int i = 0; i < Blocks.size(); i++)
		Blocks[i]->Render(_deltaTime);

	Player->Render(_deltaTime);
}
