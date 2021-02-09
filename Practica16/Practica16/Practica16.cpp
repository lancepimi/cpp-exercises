
#include <iostream>
#include <string>
#include "List.h"
#include "MyClaseInt.h"
#include "MyClaseString.h"

int main()
{
	printf("--------------------------------\nPrueba lista de ints\n--------------------------------\n");

	TList tList;

	printf("Size = %d [%s]\n", tList.Size(), tList.Size() == 0 ? "SUCCESS" : "FAILED");

	tList.Push(new CMyClaseInt(0));
	tList.Push(new CMyClaseInt(1));
	tList.Push(new CMyClaseInt(2));
	tList.Push(new CMyClaseInt(3));
	tList.Push(new CMyClaseInt(4));

	printf("Size = %d [%s]\n", tList.Size(), tList.Size() == 5 ? "SUCCESS" : "FAILED");

	IListElement* sPop = tList.Pop();
	sPop->PrintElement();
	printf("Size = %d [%s]\n", tList.Size(), tList.Size() == 4 ? "SUCCESS" : "FAILED");

	printf("--- Print tList (size = %d) ---\n", tList.Size());
	unsigned int uIndex(0);
	IListElement* sCurrentValue = tList.First();
	while (sCurrentValue != nullptr)
	{
		printf("[%d] ", uIndex);
		sCurrentValue->PrintElement();
		uIndex++;
		sCurrentValue = tList.Next();
	}

	tList.Reset();
	printf("Size = %d [%s]\n", tList.Size(), tList.Size() == 0 ? "SUCCESS" : "FAILED");

	printf("\n--------------------------------\nPrueba lista de strings\n--------------------------------\n");
	
	TList tListStrings;

	printf("Size = %d [%s]\n", tListStrings.Size(), tListStrings.Size() == 0 ? "SUCCESS" : "FAILED");

	tListStrings.Push(new CMyClaseString("Uno"));
	tListStrings.Push(new CMyClaseString("Dos"));
	tListStrings.Push(new CMyClaseString("Tres"));
	tListStrings.Push(new CMyClaseString("Cuatro"));
	tListStrings.Push(new CMyClaseString("Cinco"));

	printf("Size = %d [%s]\n", tListStrings.Size(), tListStrings.Size() == 5 ? "SUCCESS" : "FAILED");

	IListElement* sPopString = tListStrings.Pop();
	sPopString->PrintElement();
	printf("Size = %d [%s]\n", tListStrings.Size(), tListStrings.Size() == 4 ? "SUCCESS" : "FAILED");

	printf("--- Print tList (size = %d) ---\n", tListStrings.Size());
	uIndex = 0;
	IListElement* sCurrentValueString = tListStrings.First();
	while (sCurrentValueString != nullptr)
	{
		printf("[%d] ", uIndex);
		sCurrentValueString->PrintElement();
		uIndex++;
		sCurrentValueString = tListStrings.Next();
	}

	tListStrings.Reset();
	printf("Size = %d [%s]\n", tListStrings.Size(), tListStrings.Size() == 0 ? "SUCCESS" : "FAILED");
}
