#include "Imagen.h"

class CJpg : public CImagen
{
public:
	int SetJpgFile(const char* pszJpgFile);
	virtual void DeleteAlpha() override;

private:
	int UncompressImage();
};