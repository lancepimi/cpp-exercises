#pragma once

#include "CStream.h"
#include <iostream>

class CTcp : public CStream
{
public:
	virtual void Open() override;
	virtual void Close() override;
	virtual void Read() override;
	virtual void Write() override;
};