#pragma once
#include "CExcel.h"
#include <map>
class CBuildCommands
{
public:
	CBuildCommands(void);
	~CBuildCommands(void);
	virtual void excute(CExcel &a,int i,int j){}
};
