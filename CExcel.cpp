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
		AfxMessageBox(L"�޷�����Excel������!");
		_exit(0);
    } 
	books.AttachDispatch( app.get_Workbooks() );  
	lpDisp = books.Open( a ,covOptional, covOptional, covOptional, covOptional, 
		covOptional,covOptional, covOptional, covOptional, covOptional, covOptional,
		covOptional, covOptional, covOptional,covOptional);  
      
    //�õ�Workbook  
    book.AttachDispatch( lpDisp );  
    //�õ�Worksheets  
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
		AfxMessageBox(L"��"+ a + L"ҳ!" );
		_exit(0);
	}
}//���Ӳ���ȡ��������ʾ��sheet��������������ʾ��

CString CExcel::GetValue(int i, int j)
{
	range.AttachDispatch( sheet.get_Cells() ); 
	range.AttachDispatch( range.get_Item ( COleVariant((long)i),
		COleVariant((long)j)).pdispVal );  
	return range.get_Value2();
}

void CExcel::WriteSheet( std::string a ,std::string Lang,std::string Device)
//aΪҪ������ַ�����LangΪ��ʾ���Ե��ַ�������ȷ��PPD�ļ�����DeviceΪȷ���豸���ַ�������ȷ��PPD�ļ���
{
	std::ofstream output;
	std::string fname = "ppd\\" +  Lang + "--" + Device + ".txt";
	output.open( fname.c_str(),std::ios_base::app);
	output<<a;
}//����ppd�ļ�����������Ϊ"����--�豸.txt"��