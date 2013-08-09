#include "StdAfx.h"
#include "Define.h"
#include <map>
#include <string>
CDefine::CDefine(void)
{
}

CDefine::~CDefine(void)
{
}

void CDefine::excute(CExcel &a, int i, int j) 
{
	std::string s1 = CStringA(a.GetValue(i,5));
	std::string s2 = CStringA(a.GetValue(i,j));
	a.map1.insert(std::map<std::string,std::string>::value_type(s1,s2));
}