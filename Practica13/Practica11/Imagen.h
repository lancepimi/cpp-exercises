#pragma once
class CImagen
{
public:
	~CImagen();

	int                                SetImageFile(const char* pszFile);
	unsigned int                    GetNumPixels() const;
	unsigned int                    GetUncompressedSize() const;
	const unsigned char* GetBuffer() const;
	int                                Draw() const;
	int                                InvertImage();
	char GetType();
	virtual void DeleteAlpha() = 0;

protected:
	unsigned char type;
	unsigned int        m_uResX;
	unsigned int        m_uResY;
	unsigned int        m_uColorBytes;
	unsigned char* m_pBuffer;
	unsigned int        m_uSize;
};