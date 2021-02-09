#include <iostream>
#include "file.h"
#include "list.h"
#include <string.h>

int main()
{
	printf("***PRACTICA 10***\n\n");

	TList sList;

	const unsigned int uBUFFER_SIZE(1000);
	char sBuffer[uBUFFER_SIZE];
	unsigned int uReadBytes = 0;

	const char* sFile2Path = "test2.txt";
	
	void* pFile2 = MyNamespace::OpenFile(sFile2Path, "r");
	if (pFile2 != nullptr)
	{
		uReadBytes = MyNamespace::ReadFile(pFile2, sBuffer, uBUFFER_SIZE);

		unsigned int index = 0;
		while (index < uReadBytes)
		{
			char* sNumber = new char[10];
			unsigned int j = 0;
			while (sBuffer[index] != ',' && index < uReadBytes)
			{
				sNumber[j] = sBuffer[index];
				j++;
				index++;
			}
			sNumber[j] = '\0';
			sList.Push(sNumber);
			index++;
			delete[] sNumber;
		}

		printf("\n\nEJERCICIO A\n");
		TList sList2 = sList;
		sList2.ShowList();	

		printf("\n\nEJERCICIO B\n");
		TList sReverseList;
		TList::GetReverseList( sList2, sReverseList);
		sReverseList.ShowList();

		int iCloseFileResult = MyNamespace::CloseFile(pFile2);
	}
	else
	{
		printf("ERROR: no se econtro el fichero %s\n", sFile2Path);
	}

	printf("\n");
}
