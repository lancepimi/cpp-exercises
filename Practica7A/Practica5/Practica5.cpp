#include <iostream>
#include "file.h"

int main()
{
	printf("***PRACTICA 7A***\n\n");

	const unsigned int uBUFFER_SIZE(1000);
	char sBuffer[uBUFFER_SIZE];
	unsigned int uReadBytes = 0;

	const char* sFile1Path = "test.txt";
	// Test open file
	void* pFile1 = MyNamespace::OpenFile(sFile1Path, "r");
	if (pFile1 != nullptr)
	{
		// Test read file
		uReadBytes = MyNamespace::ReadFile(pFile1, sBuffer, uBUFFER_SIZE);
		printf("Se han leido %d bytes del fichero %s\n", uReadBytes, sFile1Path);
		printf("Buffer:\n");
		printf("-------------------\n");
		printf("%.*s\n", uReadBytes, sBuffer);
		printf("-------------------\n");

		// Test close file
		int iCloseFileResult = MyNamespace::CloseFile(pFile1);
		printf("El resultado de cerrar el fichero %s ha sido %d\n", sFile1Path, iCloseFileResult);
	}
	else
	{
		printf("ERROR: no se econtro el fichero %s\n", sFile1Path);
	}

	// Test open file
	const char* sFile2Path = "test_write.txt";
	void* pFile2 = MyNamespace::OpenFile(sFile2Path, "w");
	if (pFile2 != nullptr)
	{
		// Test write file
		MyNamespace::WriteFile(pFile2, sBuffer, uReadBytes);

		// Test close file
		int iCloseFileResult = MyNamespace::CloseFile(pFile2);
		printf("El resultado de cerrar el fichero %s ha sido %d\n", sFile2Path, iCloseFileResult);
	}
	else
	{
		printf("ERROR: no se econtro el fichero %s\n", sFile2Path);
	}

	printf("\n");
}
