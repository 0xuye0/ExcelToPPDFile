#include "StdAfx.h"
#include "CommandFactory.h"


CCommandFactory::CCommandFactory(void)
{
}

CCommandFactory::~CCommandFactory(void)
{
}

CBuildCommands* CCommandFactory::CommandConvert(CString a) 
{
	if(a.MakeUpper () ==L"DEFINE")
	{
		CDefine *p=&cdefine;
		return p;
	}
	else if(a.MakeUpper () == L"INSERTTEMP")
	{
		CInsertTemp *p=&cinserttemp;
		return p;
	}
	else
	{
		CBuildCommands bb;
		CBuildCommands *p=&bb;
		return p;
	}
	/*else if( a.MakeUpper()==L"MAKEPOPUP" )
	{
		CMakePopUp b;
	}*/

}