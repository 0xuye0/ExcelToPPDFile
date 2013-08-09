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
	a.ReadSheet( JumpSheet );//���Ӳ���ȡInsertTemp����para1����Ӧ��sheet��
	CString StartFlag;//ͨ���˱�־�ж���InsertTempҳ�ж�ȡ��ҳ��Ŀ�ʼ�ͽ�����
	int TempRow=0;
	do
	{
		TempRow++;  
		StartFlag = a.GetValue(TempRow,1);
	}while( StartFlag.MakeUpper() != Para1.MakeUpper() );//�ӵ�1�п�ʼ�ж�ÿ�е�һ���Ƿ�Ϊ����ȡ�Ŀ�ʼ��־��
														 //��������ʼ��־��ֹͣѭ����
	std::string temp1;//������ƥ������е�ģ��
	std::string temp2;//������ƥ������б��޸ģ�����ֵ�ӵ�Content�ַ���ĩβ��
	std::string Content="";
	do
	{
		temp1 = CStringA(a.GetValue(TempRow,2));//�õ���ʼ��־�����еĵڶ��е��ַ�����
		temp2 = temp1;//����temp1��temp2��
		std::string::const_iterator it=temp1.begin();
		std::string::const_iterator end=temp1.end();
		boost::regex reg("\\$\\(.*?\\)");//������ʽ������ƥ�䡰$(�κ��ַ�)"ģʽ��
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
			it=m[0].second;//it������ָ��ƥ���ַ������λ�á�
		}//��ѭ�������ҵ�temp2�����з���������ʽģʽ�����ַ������������滻��

		Content = Content + temp2 + "\n";//���޸ĺ��temp2�ӵ�Content�ַ����󣬲���ӻ��з���
		StartFlag = a.GetValue(TempRow,1);
		TempRow++;//��ȡ��һ��
	}while( StartFlag.MakeUpper() != L"END");//����һ�еĵ�һ���ǽ�����־"END"�������ִ�Сд��������ѭ����
	a.ReadSheet(L"Base");
	CString device = a.GetValue(4,j);
	device.Replace ('/','_');
	std::string Device = CStringA( device );//�õ������ļ������豸���ƣ����ݸ�WriteSheet������
	for (int jj=11;jj<21;jj++)
	{
		CString CP = a.GetValue(i,jj);//�õ����ڱȽϵ��ַ����������ַ�����ĳ�����в�Ϊ�������WriteSheet������
		if( CP != L"")
		{
			std::string Lang = CStringA( a.GetValue(4,jj) );
			a.WriteSheet( Content , Lang , Device );//��Content�ַ����е����������
		}
	}
}//��ӦInsertTemp������ִ�еĹ��̡�
	void string_replace(std::string & strBig, const std::string & strsrc, 
		const std::string &strdst);
};
