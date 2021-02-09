
#include<iostream>
#include<string>  

using namespace std;

#define LIFE_MASK 0xFF000000 //Cada valor equivale a 4 bits
#define BULLETS_MASK 0x00FF0000
#define MATES_MASK 0x0000F000
#define BIT_0 0x00000001 
#define BIT_1 0x00000002 
#define BIT_2 0x00000004 
#define BIT_3 0x00000008

unsigned int uValue = 0xF372A545;

string hextobin(const string& s) {
	string out;
	for (auto i : s) {
		uint8_t n;
		if (i <= '9' and i >= '0')
			n = i - '0';
		else
			n = 10 + i - 'A';
		for (int8_t j = 3; j >= 0; --j)
			out.push_back((n & (1 << j)) ? '1' : '0');
	}

	return out;
}

bool IsInvulnerableEnabled(unsigned int _uValue) {

	bool bIsInvulnerableEnabled(false); //podemos usarlo así para la declaración de la variable pero es igual que "bIsInfiniteAmmoEnabled = false" (no vale para modificar la variable)

	if ((_uValue & BIT_0) != 0) {
		bIsInvulnerableEnabled = true;
	}
	return bIsInvulnerableEnabled;

}

bool IsInfiniteAmmoEnabled(unsigned int _uValue) {

	bool bIsInfiniteAmmoEnabled = false; 

	if ((_uValue & BIT_1) != 0) {
		bIsInfiniteAmmoEnabled = true;
	}
	return bIsInfiniteAmmoEnabled;

}

bool IsShieldEnabled(unsigned int _uValue) {

	bool bIsShieldEnabled = false; 

	if ((_uValue & BIT_2) != 0) {
		bIsShieldEnabled = true;
	}
	return bIsShieldEnabled;

}

bool IsBerserkEnabled(unsigned int _uValue) {

	bool bIsBerserkEnabled = false; 

	if ((_uValue & BIT_3) != 0) {
		bIsBerserkEnabled = true;
	}
	return bIsBerserkEnabled;

}

unsigned int GetLife(unsigned int _uValue) {
	unsigned int uResult = _uValue & LIFE_MASK;
	uResult = uResult >> 24; //C entiende que al estar a la derecha del todo es un entero
	return uResult;
}

unsigned int GetBullets(unsigned int _uValue) {

	unsigned int uResult = _uValue & BULLETS_MASK;
	uResult = uResult >> 16;
	return uResult;
}

void AddBullets(unsigned int _uValue, unsigned int extraBullets) {

	unsigned int uResult = GetBullets(_uValue );
	uResult += extraBullets;
	unsigned int tempValue = _uValue & ~BULLETS_MASK; //La inversa de esta mascara es 0xFF00FFFF. De esta manera todos los valores de uValue permanecen igual y los de las balas estarán a 0 para sumar directamente los valores que tenemos en uResult sin afectar al resto.
	uResult = uResult << 16;
	uValue = tempValue | uResult;
}

void ActiveInfiniteBullets(unsigned int _uValue) {

	unsigned int uResult = IsInfiniteAmmoEnabled(_uValue );
	
	if (uResult == 0) {
		uResult = 1;
		uValue = uValue | BIT_1;
	}
}




int main() {

	printf("***PRACTICA 10***\n\n");

	string s = "0xF372A545";
	string b = hextobin(s);
	cout << b << endl;

	printf("\nEJERCICIO A\n");
	cout << "Bullets: " << GetBullets(uValue) << endl;
	
	printf("\nEJERCICIO B\n");
	unsigned int add = 0;
	cout << "Teclee el numero de balas a anyadir: "; cin >> add; 
	AddBullets(uValue, add);
	cout << "Bullets: " << GetBullets(uValue) << endl;

	printf("\nEJERCICIO C\n");
	cout << "Invulnerability: " << IsInvulnerableEnabled(uValue) << endl;
	cout << "Infinite Ammo: " << IsInfiniteAmmoEnabled(uValue) << endl;
	cout << "Armor: " << IsShieldEnabled(uValue) << endl;
	cout << "Berserk: " << IsBerserkEnabled(uValue) << endl;

	printf("\nEJERCICIO D\n");
	ActiveInfiniteBullets(uValue);

	cout << "Invulnerability: " << IsInvulnerableEnabled(uValue) << endl;
	cout << "Infinite Ammo: " << IsInfiniteAmmoEnabled(uValue) << endl;
	cout << "Armor: " << IsShieldEnabled(uValue) << endl;
	cout << "Berserk: " << IsBerserkEnabled(uValue) << endl;

	return 0;
}