#include <iostream>
#include "Cache.cpp"
using namespace std;

int main()
{
	unsigned int size=1,choose;
	char str[100];
	char desp[100];
	cout<<"�����뻺����С��";
	while(!(cin>>size))
	{	cin.clear();
		cin.sync();
		cout<<"������������������:";
	}
	CCache<char[100]>* pCache=new CCache<char[100]>(size);
	cout<<"�����������"<<endl;
	do
	{
		cout<<"0.�˳���\t 1.���롣\t 2.������\t 3.���û����С��"<<endl<<"������ѡ������";
		while(!(cin>>choose))
		{	cin.clear();
			cin.sync();
			cout<<"������������������:";
		}	
		switch(choose)
		{
		case 0:
			break;
		case 1:
			cout<<"��������ַ������뻺�棬�������Σ���һ�������ݣ��ڶ���������"<<endl;
			cout<<"���ݣ�";
			cin>>str;
			cout<<"������";
			cin>>desp;
			pCache->write(str,100,desp);
			break;
		case 2:
			cout<<"���������뻺����ַ���"<<endl;
			pCache->read(str,desp);
			cout<<"����"<<str<<endl;
			cout<<"����"<<desp<<endl;
			break;
		case 3:			
			cout<<"�����뻺����С��";
			while(!(cin>>size))
			{	cin.clear();
				cin.sync();
				cout<<"������������������:";
			};
			delete pCache;
			pCache=new CCache<char[100]>(size);
			cout<<"�����������"<<endl;
			break;
		default:
			cout<<"���볬����Χ����û�иù��ܣ�����������"<<endl;
		}
		cout<<"����һ��"<<endl;
	}while(choose>0);
	delete pCache;
}