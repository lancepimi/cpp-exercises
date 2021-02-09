#include "MyClaseString.h"

CMyClaseString::CMyClaseString(const char* _sValue)
	: m_sValue(_sValue)
{
}

void CMyClaseString::PrintElement()
{
	printf("%s\n", m_sValue);
}