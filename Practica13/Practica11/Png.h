#include "Imagen.h"

class CPng : public CImagen
{
public:
	int SetPngFile(const char* pszFile);
	virtual void DeleteAlpha() override;

private:
	int UncompressImage();
};