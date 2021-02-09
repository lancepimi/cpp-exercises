
#include <iostream>

#include "Jpg.h"
#include "Png.h"

void PrintImageInfo(const CImagen& oImagen);

int main()
{
	
	printf("\nPRACTICA 13\n\n");

	CPng *oPng = new CPng();
	CJpg *oJpg = new CJpg();
	CImagen *table[10];
	
	oPng->SetPngFile("Fichero.png");
	
	printf("\nEJERCICIO A\n");
	oPng->DeleteAlpha();
	oJpg->SetJpgFile("Fichero.jpg");


	printf("\nEJERCICIO B\n");

	table[0] = oPng;
	table[1] = oJpg;
	
	for (int i = 0; i < 1; i++)
	{
		if (table[i]->GetType() == 'P')
		{
			oPng->DeleteAlpha();
		}
	}

	PrintImageInfo(*oPng);
	PrintImageInfo(*oJpg);

	getchar();

	return 0;
}

void PrintImageInfo(const CImagen& oImagen)
{
	printf("NumPixes: %d \nSize: %d\n", oImagen.GetNumPixels(), oImagen.GetUncompressedSize());
}

