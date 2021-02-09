#include "Png.h"
#include <string>


int CPng::SetPngFile(const char* pszPngFile)
{
	printf("Reading the compressed file PNG\n");
	type = (unsigned char)'P';
	UncompressImage();
	return 0;
}

int CPng::UncompressImage()
{
	printf("PNG Image Decompression\n");
	m_uResX = 480;
	m_uResY = 320;
	m_uColorBytes = 4;
	m_uSize = m_uResX * m_uResY * m_uColorBytes;
	m_pBuffer = new unsigned char[m_uSize];
	strcpy_s(reinterpret_cast<char*>(m_pBuffer), m_uSize, "Bytes del buffer descomprimido desde Png");
	return 0;
}

void CPng::DeleteAlpha()
{
	printf("Alpha is deleted from PNG\n");
}
