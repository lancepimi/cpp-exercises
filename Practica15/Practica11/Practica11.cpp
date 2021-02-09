
#include <iostream>
#include "CCom.h"
#include "CFile.h"
#include "CTcp.h"

int main()
{
	
	printf("\nPRACTICA 15\n\n");

	CFile *oCFile = new CFile();
	CCom *oCCom = new CCom();
	CTcp*oCTcp = new CTcp();


	printf("Llamadas a los metodos\n");
	oCCom->Open();
	oCFile->Open();
	oCCom->Write();
	oCTcp->Close();
	oCTcp->Read();
	
	getchar();

	return 0;
}


