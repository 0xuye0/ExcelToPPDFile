#pragma once
#include "BuildCommands.h"

class CDefine :
	public CBuildCommands
{
public:
	CDefine(void);
	~CDefine(void);
	virtual void excute(CExcel &a,int i,int j);
};
