#pragma once
#include "CExcel.h"
#include "BuildCommands.h"
#include <string>
#include <boost/regex.hpp>

class CInsertTemp :
	public CBuildCommands
{
public:
	CInsertTemp(void);
	~CInsertTemp(void);
	virtual void excute(CExcel &a,int i,int j)
		{
	CString JumpSheet = a.GetValue(i,3);
	CString Para1 = a.GetValue(i,4);
	a.ReadSheet( JumpSheet );//链接并读取InsertTemp命令para1所对应的sheet。
	CString StartFlag;//通过此标志判断在InsertTemp页中读取的页面的开始和结束。
	int TempRow=0;
	do
	{
		TempRow++;  
		StartFlag = a.GetValue(TempRow,1);
	}while( StartFlag.MakeUpper() != Para1.MakeUpper() );//从第1行开始判断每行第一列是否为所读取的开始标志。
														 //若读到开始标志则停止循环。
	std::string temp1;//在正则匹配过程中的模板
	std::string temp2;//在正则匹配过程中被修改，将该值加到Content字符串末尾。
	std::string Content="";
	do
	{
		temp1 = CStringA(a.GetValue(TempRow,2));//得到开始标志所在行的第二列的字符串。
		temp2 = temp1;//复制temp1到temp2。
		std::string::const_iterator it=temp1.begin();
		std::string::const_iterator end=temp1.end();
		boost::regex reg("\\$\\(.*?\\)");//正则表达式，用于匹配“$(任何字符)"模式。
		boost::smatch m;
		while (boost::regex_search(it,end,m,reg))
		{
			std::string bb= m[0].str();
			std::map<std::string,std::string>::iterator iter;
			std::string cc=bb.substr(2,bb.length()-3);
			iter = a.map1.find( cc );
			if(iter!=a.map1.end())
			{
				std::string b = iter->second;
				string_replace(temp2,bb,b);
			}
			it=m[0].second;//it迭代器指向匹配字符串后的位置。
		}//此循环用于找到temp2中所有符合正则表达式模式的子字符串，并进行替换。

		Content = Content + temp2 + "\n";//将修改后的temp2加到Content字符串后，并添加换行符。
		StartFlag = a.GetValue(TempRow,1);
		TempRow++;//读取下一列
	}while( StartFlag.MakeUpper() != L"END");//若下一行的第一列是结束标志"END"（不区分大小写）则跳出循环。
	a.ReadSheet(L"Base");
	CString device = a.GetValue(4,j);
	device.Replace ('/','_');
	std::string Device = CStringA( device );//得到可做文件名的设备名称，传递给WriteSheet函数。
	for (int jj=11;jj<21;jj++)
	{
		CString CP = a.GetValue(i,jj);//得到用于比较的字符串，若该字符串在某语言列不为空则调用WriteSheet函数。
		if( CP != L"")
		{
			std::string Lang = CStringA( a.GetValue(4,jj) );
			a.WriteSheet( Content , Lang , Device );//将Content字符串中的内容输出。
		}
	}
}//对应InsertTemp命令所执行的过程。
	void string_replace(std::string & strBig, const std::string & strsrc, 
		const std::string &strdst);
};
