#include <iostream>
#include "file.h"

int main()
{
	printf("***PRACTICA 8***\n\n");

	const unsigned int uBUFFER_SIZE(1000);
	char sBuffer[uBUFFER_SIZE];
	unsigned int uReadBytes = 0;

	TFile file1("test.txt");
	
	printf("\nEJERCICIO A\n\n");
	
	void* pFile = file1.OpenFile(file1.GetPath(), "r");
	if (pFile != nullptr)
	{
		uReadBytes = file1.ReadFile(pFile, sBuffer, uBUFFER_SIZE);
		
		printf("%.*s\n", uReadBytes, sBuffer);
		printf("-------------------\n");

		char sSearch[] = "ar";
		unsigned int size = sizeof(sSearch) - 1;
		unsigned int j = 0;
		unsigned int numberOfCoincidences = 0;

		for (int i = 0; i < uReadBytes; i++)
		{		
			if( sBuffer[i] == sSearch[j])
			{
				j = j+1;
			}
			else if( j == size ) {
				numberOfCoincidences++;
				j = 0;
			}
			else 
			{
				j = 0;
			}
		}
		std::cout << "Numero de coincidencias con la cadena '" << sSearch << "': " << numberOfCoincidences;
		printf("\n-------------------\n");
		
		int iCloseFileResult = file1.CloseFile(pFile);
	}
	else
	{
		printf("ERROR: no se econtro el fichero %s\n", file1.GetPath());
	}

	TFile file2("test2.txt");
	
	printf("\nEJERCICIO B\n\n");
	void* pFile2 = file1.OpenFile(file2.GetPath(), "r");
	if (pFile2 != nullptr)
	{
		uReadBytes = file1.ReadFile(pFile2, sBuffer, uBUFFER_SIZE);
		int textToChar[uBUFFER_SIZE];
		unsigned int j = 0;
		int total = 0;
		unsigned int newCharSize = uReadBytes;

		printf("%.*s\n", uReadBytes, sBuffer);
		printf("-------------------\n");
		
		for (int i = 0; i < uReadBytes; i++)
		{
			textToChar[j] = sBuffer[i] - 48; // 48 is the ASCII Number for '0' (first number)

			if (sBuffer[i] != ',')
			{
				++j;
				--newCharSize;
			}
			else 
			{	
			}
		}

		for (int i = 0; i < newCharSize + 1; i++)
		{
			total = total + textToChar[i];	
		}
		
		std::cout << "Total de la suma de los numeros enteros presentes en el archivo: " << total << std::endl;

		printf("-------------------\n");

		int iCloseFileResult = file2.CloseFile(pFile2);
	}
	else
	{
		printf("ERROR: no se econtro el fichero %s\n", file2.GetPath());
	}

	printf("\n");
}
