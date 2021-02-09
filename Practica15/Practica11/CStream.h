#pragma once


class CStream
{
public:
	~CStream();

	virtual void Open() = 0;
	virtual void Close() = 0;
	virtual void Read() = 0;
	virtual void Write() = 0;

protected:
	

};