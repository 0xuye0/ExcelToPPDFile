#pragma once
#include "CApplication.h"
#include "CRange.h"
#include "CWorkbook.h"
#include "CWorkbooks.h"
#include "CWorksheet.h"
#include "CWorksheets.h"
#include <fstream>
#include <map>
class CExcel
{
public:
	CExcel(void);
	~CExcel(void);
	CApplication app;  
    CWorkbooks books;  
    CWorkbook book;  
    CWorksheets sheets;  
    CWorksheet sheet;  
    CRange range;  
    CRange iCell;  
    LPDISPATCH lpDisp;  
    COleVariant vResult; 
	void Attach(CString a);
	std::map<std::string,std::string> map1;
	void ReadSheet(CString a);
	void WriteSheet( std::string a ,std::string Lang,std::string Device);
	CString GetValue(int i,int j);
};
