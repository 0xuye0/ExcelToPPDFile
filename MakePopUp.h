#pragma once
#include "buildcommands.h"

class CMakePopUp :
	public CBuildCommands
{
public:
	CMakePopUp(void);
	~CMakePopUp(void);
	void excute(CExcel &a,int i,int j);
};
