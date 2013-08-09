#pragma once
#include "BuildCommands.h"
#include "Define.h"
#include "InsertTemp.h"
class CCommandFactory
{
public:
	CCommandFactory(void);
	~CCommandFactory(void);
	CBuildCommands* CommandConvert(CString a);
	CDefine cdefine;
	CInsertTemp cinserttemp;
};
