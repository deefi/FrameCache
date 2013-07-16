#include "Cache.h"
template <typename des> 
CCache<des>::CCache(unsigned int n)
{
	longth=n;
	if(n<1)
	{
		pWrite=0;
	}
	else
	{
		pWrite=new CFrame<des>;
		CFrame<des>* pTail=pWrite;
		CFrame<des>* pHead=pWrite;
		n--;
		while(n--)
		{
			pWrite=new CFrame<des>;
			pWrite->setBefore(pTail);
			pTail->setNext(pWrite);
			pTail=pWrite;
		}
		pWrite->setNext(pHead);
		pHead->setBefore(pWrite);
	}
	pRead=pWrite;
}

template <typename des>
CCache<des>::~CCache()
{
	if(pWrite!=0)
	{
		pWrite->getBefore()->setNext(0);
		while(pWrite->getNext())
		{
			pWrite=pWrite->getNext();
			delete pWrite->getBefore();
		}		
	}
	delete pWrite;
	pWrite=0;
}

template <typename des>
unsigned int CCache<des>::getLongth()
{
	return longth;
}

template <typename des> 
bool CCache<des>::write(void* pData,unsigned int lData,des &Description)
{
	pWrite->write(pData,lData,Description);
	pWrite=pWrite->getNext();
	return true;
}
template <typename des> 
bool CCache<des>::read(void* mypData,des &myDescription)
{
	pRead->read(mypData,myDescription);
	pRead=pRead->getNext();
	return true;
}
template <typename des> 
unsigned int CCache<des>::getDataSize()
{
	return pRead->getSize();
}