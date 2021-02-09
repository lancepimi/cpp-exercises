#include "MyClaseInt.h"

CMyClaseInt::CMyClaseInt(int _sValue)
	: m_sValue(_sValue)
{
}

void CMyClaseInt::PrintElement()
{
	printf("%d\n", m_sValue);
}