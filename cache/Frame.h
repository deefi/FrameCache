#pragma once
template <typename des> 
class CFrame
{
public:
	CFrame(void);
	~CFrame(void);
	bool write(void* mypData,unsigned int mylData,des &myDescription);
	unsigned long getSize();
	bool read(void* mypData,des &myDescription);
	void setNext(CFrame*);
	CFrame* getNext();
	void setBefore(CFrame*);
	CFrame* getBefore();
	//CFrame* stepNext();
private:
	CFrame* pNext;
	CFrame* pBefore;
	void* pData;
	unsigned long lData;
	des Description;
	int iOverWrite;
};
