//*****************************************************************************************************
//
//		File:					DLList.h
//
//		Student:				Cadence Seim
//
//		Assignment:				Program #12
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-Z1
//
//		Due:					4/31/2025
//
//
//		This is the system program for a node.
//	
//		Other files required:
//		1. node.h
//			
//			
//*****************************************************************************************************

#ifndef LIST_H
#define LIST_H

#include "node.h" 

//*****************************************************************************************************

template <typename TYPE>
class LList
{
private:
	Node<TYPE>* front;
	Node<TYPE>* rear;

public:
	LList();
	~LList();
	bool insert(const TYPE& dataIn);
	bool remove(TYPE& dataOut);
	bool retrieve(TYPE& dataIo) const;
	bool viewFront(TYPE& dataOut) const;
	bool viewRear(TYPE& dataOut) const;
	void displayReverse() const;
	void display() const;
	int getNumValues() const;
	bool isEmpty() const;
	bool isFull() const;
};

//*****************************************************************************************************

template <typename TYPE>
LList <TYPE>::LList()
{
	front = nullptr;
	rear = nullptr;
}

//*****************************************************************************************************

template <typename TYPE>
LList <TYPE>::~LList()
{
	Node<TYPE>* pTemp;

	while (front)
	{
		pTemp = front;
		front = front->next;
		delete pTemp;
	}

	rear = nullptr;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList <TYPE>::insert(const TYPE& dataIn)
{
	bool success = false; 
	Node<TYPE>* pAfter = front; 
	Node<TYPE>* pBefore = nullptr;
	Node<TYPE>* pNew;

	while ((pAfter) && (pAfter->data < dataIn))
	{
		pBefore = pAfter;
		pAfter = pAfter->next;
	}

	pNew = new(nothrow) Node<TYPE>(dataIn);

	if (pNew)
	{
		pNew->next = pAfter;
		pNew->prev = pBefore;

		if (pBefore)
		{
			pBefore->next = pNew;
		}
		else
		{
			front = pNew;
		}

		if (pAfter)
		{
			pAfter->prev = pNew;
		}
		else
		{
			rear = pNew;
		}
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList <TYPE>::remove(TYPE& dataOut)
{
	bool success = false;
	Node<TYPE>* pDel = front;

	while (pDel && pDel->data < dataOut)
	{
		pDel = pDel->next;
	}

	if (pDel && pDel->data == dataOut)
	{
		if (pDel->prev)
		{
			pDel->prev->next = pDel->next;
		}
		else
		{
			front = pDel->next;
		}

		if (pDel->next)
		{
			pDel->next->prev = pDel->prev;
		}
		else
		{
			rear = pDel->prev;
		}

		dataOut = pDel->data;
		delete pDel;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList <TYPE>::retrieve(TYPE& dataIo) const
{
	bool success = false; 
	Node<TYPE>* pTemp = front;

	while ((pTemp) && (pTemp->data < dataIo))
	{
		pTemp = pTemp->next;
	}

	if((pTemp) && (pTemp->data == dataIo))
	{
		dataIo = pTemp->data;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList <TYPE>::viewFront(TYPE& dataOut) const
{
	bool success = false; 

	if (front)
	{
		dataOut = front->data;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList <TYPE>::viewRear(TYPE& dataOut) const
{
	bool success = false;

	if (rear)
	{
		dataOut = rear->data;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
void LList <TYPE>::display() const
{
	Node<TYPE>* pTemp = front;

	while (pTemp != nullptr)
	{
		cout << pTemp->data << endl;
		pTemp = pTemp->next;
	}
}

//*****************************************************************************************************

template <typename TYPE>
void LList<TYPE>::displayReverse() const
{
	Node<TYPE>* pTemp = rear;

	while (pTemp != nullptr)
	{
		cout << pTemp->data << endl;
		pTemp = pTemp->prev;
	}
}

//*****************************************************************************************************

template <typename TYPE>
int LList <TYPE>::getNumValues() const
{
	int numValues;
	numValues = 0;
	Node<TYPE>* pTemp = front;

	while (pTemp != nullptr)
	{
		numValues++;
		pTemp = pTemp->next;
	}

	return numValues;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList <TYPE>::isEmpty() const
{
	return(front == nullptr);
}

//*****************************************************************************************************

template <typename TYPE>
bool LList <TYPE>::isFull() const
{
	bool full = true; 
	Node<TYPE>* pTemp;

	pTemp = new (nothrow) Node<TYPE>;

	if (pTemp)
	{
		full = false; 
		delete pTemp;
	}

	return full;
}

//*****************************************************************************************************
#endif