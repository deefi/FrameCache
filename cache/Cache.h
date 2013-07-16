#pragma once
#include "Frame.cpp"
template <typename des> 
class CCache
{
public:
	CCache(unsigned int n=24);
	CCache(CCache& cache);
	~CCache();
	unsigned int getLongth();
	unsigned int getDataSize();
	bool write(void* pData,unsigned int lData,des &Description);
	bool read(void* mypData,des &myDescription);
private:
	unsigned int longth;
	CFrame<des>* pRead;
	CFrame<des>* pWrite;
};

