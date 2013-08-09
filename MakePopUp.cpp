#include "StdAfx.h"
#include "MakePopUp.h"
#include <string>
CMakePopUp::CMakePopUp(void)
{
}

CMakePopUp::~CMakePopUp(void)
{
}

void CMakePopUp::excute(CExcel &a,int i,int j)
{
	int tempi = i;//存入makepopup命令所在的行，以便修改i的值之后还能重新找回。
	std::string one = CStringA( a.GetValue(i,3) );//value of 1
	std::string two = CStringA( a.GetValue(i,4) );//value of 2
	std::string three = CStringA( a.GetValue(i,5) );//value of 3
	CString t11 = a.GetValue(i,11);
	if( t11 != "" )
	{
		std::string four = CStringA(a.GetValue(i,6));//value of 4
		std::string Content = "*OpenUI *" + one + "/" + four + ": PickOne\n";//output the first sentence
		if( two != "" )
		{
			Content += "*OrderDependency: "+two+" AnySetup *"+one+"\n";//output the second if necessary
		}
		CString Flag;
		do
		{
			CString Rp = a.GetValue(i,j);
			if(Rp != L"*")
			{
				three = CStringA(a.GetValue(i,3));
				break;
			}
			i++;
			Flag = a.GetValue(i,2);	
		}while(Flag.MakeUpper() != L"END") ;
		Content += "*Default" +one+": "+three+"\n";//output the third sentence after having corrected
		tempi++;//tempi表示MakePopUp命令所在行的下一行
		std::string five,six,seven;
		Flag = a.GetValue(tempi,2);
		while( Flag.MakeUpper() != L"END" )
		{
			five = CStringA(a.GetValue(tempi,3));
			six = CStringA(a.GetValue(tempi,6));
			seven = CStringA(a.GetValue(tempi,10));
			Content += "*"+one+" "+five+"/"+six+": \""+seven+"\"\n";
			if(seven.find("\n")!=seven.npos)
				Content += "*End\n";
			tempi++;
			Flag = a.GetValue(tempi,2);	
		}
		Content += "*CloseUI: *"+one+"\n";
		CString device = a.GetValue(4,j);
		device.Replace ('/','_');
		std::string Device = CStringA( device );//得到可做文件名的设备名称，传递给WriteSheet函数。
		std::string Lang = CStringA( a.GetValue(4,11) );
		a.WriteSheet(Content,Lang,Device);
	}
}