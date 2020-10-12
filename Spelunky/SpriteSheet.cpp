#include "SpriteSheet.h"

ID2D1HwndRenderTarget* D2DRenderTarget = nullptr;

SpriteSheet::SpriteSheet(const wchar_t* _fileName, D2D_VECTOR_2F _Size, D2D_VECTOR_2F _Location, D2D_VECTOR_2F _ImageSize, D2D_VECTOR_2F _ImageLocation)
{
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

	D2DRenderTarget->CreateBitmapFromWicBitmap(wicConverter, nullptr, &bmp);

	wicFactory->Release();
	wicDecoder->Release();
	wicConverter->Release();
	wicFrame->Release();

	Size = _Size;
	Location = _Location;

	if (_ImageSize.x == -1)
		fImageWidth = bmp->GetSize().width;
	else
		fImageWidth = _ImageSize.x;

	if (_ImageSize.y == -1)
		fImageHeight = bmp->GetSize().height;
	else
		fImageHeight = _ImageSize.y;

	fImageX = _ImageLocation.x;
	fImageY = _ImageLocation.y;
}

SpriteSheet::SpriteSheet(ID2D1Bitmap* _bmp, D2D_VECTOR_2F _Size, D2D_VECTOR_2F _Location, D2D_VECTOR_2F _ImageSize, D2D_VECTOR_2F _ImageLocation)
{
	bmp = _bmp;

	Size = _Size;
	Location = _Location;

	if (_ImageSize.x == -1)
		fImageWidth = bmp->GetSize().width;
	else
		fImageWidth = _ImageSize.x;

	if (_ImageSize.y == -1)
		fImageHeight = bmp->GetSize().height;
	else
		fImageHeight = _ImageSize.y;

	fImageX = _ImageLocation.x;
	fImageY = _ImageLocation.y;
}

SpriteSheet::SpriteSheet(ID2D1HwndRenderTarget* _renderTarget)
{
	if (_renderTarget != nullptr)
		D2DRenderTarget = _renderTarget;
}

SpriteSheet::~SpriteSheet()
{
	bmp->Release();
}

void SpriteSheet::SetLocation(D2D_VECTOR_2F _Location)
{
	Location = _Location;
}

void SpriteSheet::SetImageLocation(D2D_VECTOR_2F _Location)
{
	ImageLocation = _Location;
}

void SpriteSheet::Draw() //UI와 같은 스프라이트가 아닌 이미지를 드로우
{
	D2DRenderTarget->DrawBitmap(bmp, D2D1::RectF(Location.x, Location.y, Location.x + Size.x, Location.y + Size.y),
		fOpacity, D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
		D2D1::RectF(
			fImageX + (ImageLocation.x * fImageWidth), 
			fImageY + (ImageLocation.y * fImageHeight), 
			fImageX + (ImageLocation.x * fImageWidth) + fImageWidth, 
			fImageY + (ImageLocation.y * fImageHeight) + fImageHeight));
}

void SpriteSheet::Draw(float _deltaTime)
{
	fOpacity = sin(2 * fTime * 3.141592) + 1;

	D2DRenderTarget->DrawBitmap(bmp, D2D1::RectF(Location.x, Location.y, Location.x + Size.x, Location.y + Size.y),
		fOpacity, D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
		D2D1::RectF(
			fImageX + (ImageLocation.x * fImageWidth),
			fImageY + (ImageLocation.y * fImageHeight),
			fImageX + (ImageLocation.x * fImageWidth) + fImageWidth,
			fImageY + (ImageLocation.y * fImageHeight) + fImageHeight));

	fTime += _deltaTime;
}