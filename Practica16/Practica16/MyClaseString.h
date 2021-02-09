#pragma once
#include "ListElement.h"
#include <stdio.h>

class CMyClaseString : public IListElement
{
public:
	CMyClaseString(const char* _sValue);
	virtual void PrintElement() override;
private:
	const char* m_sValue = nullptr;
};