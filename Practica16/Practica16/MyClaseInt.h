#pragma once
#include "ListElement.h"
#include <stdio.h>

class CMyClaseInt : public IListElement
{
public:
	CMyClaseInt(int _sValue);
	virtual void PrintElement() override;
private:
	int m_sValue = 0;
};

