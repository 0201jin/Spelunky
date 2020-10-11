#include "InGame.h"
#include "StageMgr.h"

void InGame::Init(ID2D1HwndRenderTarget* _D2DRenderTarget)
{
	D2DRenderTarget = _D2DRenderTarget;

	MapGen = new MapGenerator();

	//최적화 하기 블록을 선언하는 부분에서 속도가 너무 느림
	vector<vector<RoomStruct>> RoomArr = MapGen->Level.front();

	D2D_VECTOR_2F Start;

	for (int rx = 0; rx < 4; rx++)
		for (int ry = 0; ry < 4; ry++)
		{
			if (RoomArr[rx][ry].bStart)
				Start = { (float)(rx * 16 + 8) * 80, 0.0f };

			for (int x = 0; x < 16; x++)
				for (int y = 0; y < 16; y++)
				{
					int BlockNumber = RoomArr[rx][ry].Blocks[x][y];

					if (BlockNumber != 0)
					{
						/*cout << BlockNumber;
						cout << " rx: " << rx;
						cout << " ry: " << ry;
						cout << " x :" << x;
						cout << " y " << y << endl;*/

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

	float Scale = 0.1375f; //1.0f;

	D2D1_MATRIX_3X2_F Center = D2D1::Matrix3x2F::Translation(640, 360);
	D2D1_MATRIX_3X2_F Vertical = { 1, 0, 0, 1, 0, 0 };
	D2D_VECTOR_2F Lo = { 2560, 2560 };//Player->GetLocation();
	D2D1_MATRIX_3X2_F ScaleM = D2D1::Matrix3x2F::Scale(Scale, Scale);
	D2D1_MATRIX_3X2_F TransM = D2D1::Matrix3x2F::Translation(-Lo.x * Scale, -Lo.y * Scale);

	D2DRenderTarget->SetTransform(ScaleM * Vertical * Center * TransM);
}

void InGame::Render(float _deltaTime)
{
	for (int i = 0; i < Blocks.size(); i++)
		Blocks[i]->Render(_deltaTime);

	Player->Render(_deltaTime);
}
