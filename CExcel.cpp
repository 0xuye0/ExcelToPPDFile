#include "StdAfx.h"
#include "CExcel.h"
#include <string>
CExcel::CExcel(void)
{
}

CExcel::~CExcel(void)
{
}

void CExcel::Attach(CString a)
{
	COleVariant covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);  
	
    if(!app.CreateDispatch(L"Excel.Application"))  
    {
		AfxMessageBox(L"无法启动Excel服务器!");
		_exit(0);
    } 
	books.AttachDispatch( app.get_Workbooks() );  
	lpDisp = books.Open( a ,covOptional, covOptional, covOptional, covOptional, 
		covOptional,covOptional, covOptional, covOptional, covOptional, covOptional,
		covOptional, covOptional, covOptional,covOptional);  
      
    //得到Workbook  
    book.AttachDispatch( lpDisp );  
    //得到Worksheets  
    sheets.AttachDispatch(book.get_Worksheets());  
	sheets = book.get_Sheets();
}


void CExcel::ReadSheet(CString a)
{  
	int b=0;
	for( long i = 0 ; i < sheets.get_Count () ; i++)
	{
		sheet = sheets.get_Item(COleVariant((long)(i+1)));
		if( sheet.get_Name() == a )
		{
			b=1;
			range.AttachDispatch(sheet.get_Cells());
			break;
		}
	}
	if(b==0)
	{
		AfxMessageBox(L"无"+ a + L"页!" );
		_exit(0);
	}
}//链接并读取参数所表示的sheet，若不存在则提示。

CString CExcel::GetValue(int i, int j)
{
	range.AttachDispatch( sheet.get_Cells() ); 
	range.AttachDispatch( range.get_Item ( COleVariant((long)i),
		COleVariant((long)j)).pdispVal );  
	return range.get_Value2();
}

void CExcel::WriteSheet( std::string a ,std::string Lang,std::string Device)
//a为要输出的字符串，Lang为表示语言的字符串用于确定PPD文件名，Device为确定设备的字符串用于确定PPD文件名
{
	std::ofstream output;
	std::string fname = "ppd\\" +  Lang + "--" + Device + ".txt";
	output.open( fname.c_str(),std::ios_base::app);
	output<<a;
}//生成ppd文件，命名规则为"语言--设备.txt"。