
#include <iostream>

using namespace std;

const char *tTablaDeCadenas[] = {
	"0cadena",
	"1cadena",
	"2cadena",
	"3cadena",
	"4cadena"
};

const char *GetString( unsigned int _iIndex) 
{ 
	return tTablaDeCadenas[_iIndex -1];	
}

const char* GetReverseString(int _iIndex)
{
	const char *ptr = tTablaDeCadenas[_iIndex];
	int size = strlen(ptr);
	ptr = ptr + (size -1);
	char* sReverse = new char();
	
	for (int i = 0; i < size; i++)
	{
		*(sReverse + i) = *(ptr - i);
	}

	sReverse[size] = '\0';

	return sReverse;
}

int main()
{
	cout << "\nPRACTICA 3\n\n";

	cout << "EJERCICIO A\n";
	cout << GetString(2) << "\n\n";

	cout << "EJERCICIO B\n";
	cout << GetReverseString(3) << endl;
}
