#include "Frame.h"
template <typename des>
CFrame<des>::CFrame(void)
{
	pData=new char('\n');
	lData=1;
	//std::cout<<"buid"<<endl;
}
template <typename des>
CFrame<des>::~CFrame(void)
{
	delete pData;
	lData=0;
	//std::cout<<"destroy"<<endl;
}

template <typename des>
void CFrame<des>::setNext(CFrame* next)
{
	pNext=next;
}
template <typename des>
void CFrame<des>::setBefore(CFrame* before)
{
	pBefore=before;
}
template <typename des>
CFrame<des>* CFrame<des>::getNext()
{
	return pNext;
}
template <typename des>
CFrame<des>* CFrame<des>::getBefore()
{
	return pBefore;
}


//д�뺯��
template <typename des>
bool CFrame<des>::write(void* mypData,unsigned int mylData,des &myDescription)
{
	memcpy(&Description,&myDescription,sizeof(des));
	lData=mylData;
	delete pData;
	pData=new char[lData];
	memcpy(pData,mypData,lData);
	iOverWrite++;
	return true;
}
//��ȡ���������ȣ�Ϊ�����ڴ���׼��
template <typename des>
unsigned long CFrame<des>::getSize()
{
	return lData;
}
//��ȡ����
template <typename des>
bool CFrame<des>::read(void* mypData,des &myDescription)
{
	memcpy(&myDescription,&Description,sizeof(des));
	memcpy(mypData,pData,lData);
	return true;
}