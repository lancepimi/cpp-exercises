#include "Imagen.h"
#include <string>


CImagen::~CImagen()
{
	delete[]m_pBuffer;
}

int    CImagen::SetImageFile(const char* pszFile)
{
	printf("int    CImagen::SetImage(const char *pszFile)\n");
	printf("Loaded file read\n");
	m_uResX = 1280;
	m_uResY = 800;
	m_uColorBytes = 4;
	m_uSize = m_uResX * m_uResY * m_uColorBytes;
	m_pBuffer = new unsigned char[m_uSize];
	strcpy_s(reinterpret_cast<char*>(m_pBuffer), m_uSize, "Buffer bytes");

	return 0;
}

unsigned int CImagen::GetNumPixels() const
{
	return (m_uResX * m_uResY);
}

unsigned int CImagen::GetUncompressedSize() const
{
	return m_uSize;
}

const unsigned char* CImagen::GetBuffer() const
{
	return m_pBuffer;
}

int CImagen::Draw() const
{
	printf("Loaded image draw\n");
	return 0;
}

int CImagen::InvertImage()
{
	printf("Loaded image invert\n");
	return 0;
}

char CImagen::GetType()
{
	return type;
}
