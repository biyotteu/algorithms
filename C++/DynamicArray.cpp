#include "DynamicArray.h"
#include <stdexcept>

#include <iostream>
using namespace std;


void DynamicArray::checkValidIndex(int i) const
{
	if (i < 0 || mSize <= i)
	{
		throw std::out_of_range("The index is out of range.");
	}
	
}

int DynamicArray::Size() const
{
	return mSize;
}

int DynamicArray::Capacity() const
{
	return mCapacity;
}

bool DynamicArray::operator==(const DynamicArray& other) const
{
	if (mSize != other.Size())
	{
		return false;
	} 

	for (int i = 0; i < mSize; i++)
	{
		if (mData[i] != other[i])
			return false;
	}

	return true;
}

double& DynamicArray::operator[](const int i) const
{
	checkValidIndex(i);
	return mData[i];
}

DynamicArray::DynamicArray()
{
	mCapacity = 10;
	mSize = 0;
	mData = new double[mCapacity];
}

DynamicArray::DynamicArray(int sz, double val)
	: mSize(sz), mCapacity(2*sz)
{
	mSize = sz;
	mCapacity = (2 * sz);
	mData = new double[sz];
	for (int i = 0; i < sz; i++)
	{
		mData[i] = val;
	}

}

DynamicArray::DynamicArray(const DynamicArray& other)
{
	this->mSize = other.mSize;
	this->mCapacity = other.mCapacity;
	this->mData = new double[other.mSize];
	for (int i = 0; i < mSize; i++)
	{
		this->mData[i] = other.mData[i];
	}
}

DynamicArray::~DynamicArray()
{
	delete[] mData;
	int* mData = nullptr;

}
void DynamicArray::Reserve(int capacity)
{
	if (capacity <= 0)
	{
		throw std::out_of_range("The capacity should be greater than 0.");
	}

	if (mCapacity < capacity)
	{
		mCapacity = capacity;

		if (mData)  // if mData has a memory space for some elements
		{
			// [IMPLEMENT]
			// You should copy the existing elements after allocating a new memory space.
			double* tmp = new double[mSize];
			for (int i = 0; i < mSize; i++) tmp[i] = mData[i];
			mData = new double[mCapacity];
			for (int i = 0; i < mSize; i++){
				mData[i] = tmp[i];
			} 
			delete[] tmp;
		}
		else {  // if mData has no memory space (mData == nullptr)
			// [IMPLEMENT]
			// All you have to do is to allocate a new memory space.
			mData = new double[mCapacity];
		}
	}

}

void DynamicArray::Append(double data)
{
	// Reserve a memory space
	if (mCapacity == 0)
		Reserve(10);
	else if (mCapacity <= 2 * mSize)
		Reserve(2 * mCapacity);  // Reserve twice the existing capacity.
	mData[mSize++] = data;
}

void DynamicArray::Clear(bool bResizeCapacity)
{
	if (bResizeCapacity == false)
	{
		mSize = 0;
	}
	else
	{
		delete[] mData;
		mSize = 0;
		mCapacity = 0;
		mData = nullptr;
	}
	
}

int DynamicArray::Find(double data) const
{
	for (int i = 0; i < mSize; i++)
	{
		if (mData[i] == data)
		{
			return i;
		}
	}
	return -1;
}


void DynamicArray::Reverse()
{
    double* tmp = new double[mSize];
    for (int i = 0; i <mSize; i++) tmp[i] = mData[i];
    for(int i=0;i<mSize;i++) mData[i] = tmp[mSize-i-1];
    delete[] tmp;
}


void DynamicArray::Insert(int i, double data)
{
	if (mSize == 0 && i == 0) {
		Append(data);
		return;
	}

	checkValidIndex(i);  // Check the index;
	
	// Reserve a memory space
	// [!] Do not call Reserve() function to prevent redundant copy operations.
	if (mCapacity == 0)
		mCapacity = 10;
	else if (mCapacity <= 2 * mSize)
		mCapacity *= 2;  // Reserve twice the existing capacity.

	// [IMPLEMENT]
	
}

void DynamicArray::Remove(double data)
{	
	auto i = Find(data);
	if (i < 0)
		return;	
	// [IMPLEMENT]

}
