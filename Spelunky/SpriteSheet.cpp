#include "SpriteSheet.h"

SpriteSheet::SpriteSheet(const wchar_t* _fileName, ID2D1HwndRenderTarget* _renderTarget, D2D_VECTOR_2F _Size, D2D_VECTOR_2F _Location)
{
	D2DRenderTarget = _renderTarget;

	IWICImagingFactory* wicFactory = nullptr;
	CoCreateInstance(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER,
		IID_IWICImagingFactory, (LPVOID*)&wicFactory);

	IWICBitmapDecoder* wicDecoder = nullptr;
	wicFactory->CreateDecoderFromFilename(_fileName, nullptr, GENERIC_READ,
		WICDecodeMetadataCacheOnLoad, &wicDecoder);

	IWICBitmapFrameDecode* wicFrame = nullptr;
	wicDecoder->GetFrame(0, &wicFrame);

	IWICFormatConverter* wicConverter = nullptr;
	wicFactory->CreateFormatConverter(&wicConverter);

	wicConverter->Initialize(wicFrame, GUID_WICPixelFormat32bppPBGRA,
		WICBitmapDitherTypeNone, nullptr, 0.0, WICBitmapPaletteTypeCustom);

	_renderTarget->CreateBitmapFromWicBitmap(wicConverter, nullptr, &bmp);

	wicFactory->Release();
	wicDecoder->Release();
	wicConverter->Release();
	wicFrame->Release();

	Size = _Size;
	Location = _Location;
}

SpriteSheet::~SpriteSheet()
{
	bmp->Release();
}

void SpriteSheet::Draw() //UI와 같은 스프라이트가 아닌 이미지를 드로우
{
	D2DRenderTarget->DrawBitmap(bmp, D2D1::RectF(Location.x, Location.y, Location.x + Size.x, Location.y + Size.y),
		fOpacity, D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
		D2D1::RectF(0.0f, 0.0f, bmp->GetSize().width, bmp->GetSize().height));
}

void SpriteSheet::Draw(float _deltaTime)
{
	fOpacity = sin(30 * fTime * 3.141592) * 0.5 + 0.5;

	D2DRenderTarget->DrawBitmap(bmp, D2D1::RectF(Location.x, Location.y, Location.x + Size.x, Location.y + Size.y),
		fOpacity, D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
		D2D1::RectF(0.0f, 0.0f, bmp->GetSize().width, bmp->GetSize().height));

	fTime += _deltaTime;

	std::cout << fOpacity << std::endl;
}
