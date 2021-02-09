#pragma once

template <typename T>
class TListNode
{
public:
	TListNode(T* _pValue) 
		: m_pValue(_pValue)
		, m_pNext(nullptr)
	{
	};

	T* m_pValue;
	TListNode* m_pNext;
};