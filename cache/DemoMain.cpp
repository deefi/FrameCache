#include <iostream>
#include "Cache.cpp"
using namespace std;

int main()
{
	unsigned int size=1,choose;
	char str[100];
	char desp[100];
	cout<<"请输入缓存块大小：";
	while(!(cin>>size))
	{	cin.clear();
		cin.sync();
		cout<<"输入有误，请重新输入:";
	}
	CCache<char[100]>* pCache=new CCache<char[100]>(size);
	cout<<"建立缓存完成"<<endl;
	do
	{
		cout<<"0.退出。\t 1.输入。\t 2.读出。\t 3.重置缓存大小。"<<endl<<"请输入选择动作：";
		while(!(cin>>choose))
		{	cin.clear();
			cin.sync();
			cout<<"输入有误，请重新输入:";
		}	
		switch(choose)
		{
		case 0:
			break;
		case 1:
			cout<<"将输入的字符串存入缓存，输入两次，第一次是数据，第二次是描述"<<endl;
			cout<<"数据：";
			cin>>str;
			cout<<"描述：";
			cin>>desp;
			pCache->write(str,100,desp);
			break;
		case 2:
			cout<<"将读出存入缓存的字符串"<<endl;
			pCache->read(str,desp);
			cout<<"数据"<<str<<endl;
			cout<<"描述"<<desp<<endl;
			break;
		case 3:			
			cout<<"请输入缓存块大小：";
			while(!(cin>>size))
			{	cin.clear();
				cin.sync();
				cout<<"输入有误，请重新输入:";
			};
			delete pCache;
			pCache=new CCache<char[100]>(size);
			cout<<"建立缓存完成"<<endl;
			break;
		default:
			cout<<"输入超出范围，还没有该功能，请重新输入"<<endl;
		}
		cout<<"再来一次"<<endl;
	}while(choose>0);
	delete pCache;
}