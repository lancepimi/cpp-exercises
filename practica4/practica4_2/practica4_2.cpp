// practica4.cpp
//
#include <stdio.h>
#include "consola.h"
#include <iostream>

using namespace std;

struct TEntity;
typedef void (*funcEntity)(TEntity*);


// ***************************************************************************************
// ENTIDAD
// ***************************************************************************************
struct TEntity
{
	int m_ix;
	int m_iy;
	funcEntity* m_funcs;
	TEntity(funcEntity* funcs, int x, int y)
	{
		m_ix = x;
		m_iy = y;
		m_funcs = funcs;
	}
};

void Draw(TEntity* _pEntity) {

	gotoxy(_pEntity->m_ix, _pEntity->m_iy);
	printf("X"); //El simbolo que representa lo que se va a mover
}

void Move(TEntity* _pEntity) {

	_pEntity->m_ix++;
	_pEntity->m_iy++;

}
void Draw1(TEntity* _pEntity) {

	gotoxy(_pEntity->m_ix, _pEntity->m_iy);
	printf("W"); //El simbolo que representa lo que se va a mover
}

void Move1(TEntity* _pEntity) {

	_pEntity->m_ix++;
}
void Draw2(TEntity* _pEntity) {

	gotoxy(_pEntity->m_ix, _pEntity->m_iy);
	printf("T"); //El simbolo que representa lo que se va a mover
}

void Move2(TEntity* _pEntity) {

	_pEntity->m_iy++;
}
void Draw3(TEntity* _pEntity) {

	gotoxy(_pEntity->m_ix, _pEntity->m_iy);
	printf("P"); //El simbolo que representa lo que se va a mover
}

void Move3(TEntity* _pEntity) {

	_pEntity->m_ix += 2;
	_pEntity->m_iy++;

}

// ***************************************************************************************
// MAIN
// ***************************************************************************************
unsigned int uKey;
int main(int argc, char* argv[])
{
	TEntity* tEntities[4];
	funcEntity arrayFunctions[2] = { &Move, &Draw };
	funcEntity arrayFunctions1[2] = { &Move1, &Draw1 };
	funcEntity arrayFunctions2[2] = { &Move2, &Draw2 };
	funcEntity arrayFunctions3[2] = { &Move3, &Draw3 };

	tEntities[0] = new TEntity(arrayFunctions, 0, 0);
	tEntities[1] = new TEntity(arrayFunctions1, 0, 0);
	tEntities[2] = new TEntity(arrayFunctions2, 0, 0);
	tEntities[3] = new TEntity(arrayFunctions3, 0, 0);

	while (true) {

		//Borro la pantalla
		clear();

		for (int i = 0; i < 4; i++)
		{
			tEntities[i]->m_funcs[0](tEntities[i]);
			tEntities[i]->m_funcs[1](tEntities[i]);

			if (tEntities[i]->m_ix >= 25 || tEntities[i]->m_iy >= 25) {
				tEntities[i]->m_ix = 0;
				tEntities[i]->m_iy = 0;
			}

		}

		hidecursor();
		Sleep(500);
	}

}


