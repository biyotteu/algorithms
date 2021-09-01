#include <iostream>
#include <stdexcept>
#include <cassert>

#include "DynamicArray.cpp"

using namespace std;

int main()
{
	DynamicArray arr0;  // Check default constructor
	DynamicArray arr1(10, 1.0);
	DynamicArray arr2(arr0);

	cout << "<Size of arr0>" << endl;
	cout << arr0.Size() << endl << endl;
	assert(arr0.Size() == 0);

	cout << "<Capacity of arr0>" << endl;
	cout << arr0.Capacity() << endl << endl;
	assert(arr0.Capacity() == 10);

	cout << "<Size of arr1>" << endl;
	cout << arr1.Size() << endl << endl;
	assert(arr1.Size() == 10);

	cout << "<Capacity of arr1>" << endl;
	cout << arr1.Capacity() << endl << endl;
	assert(arr1.Capacity() == 20);

	cout << "<Size of arr2>" << endl;
	cout << arr2.Size() << endl << endl;
	assert(arr2.Size() == 0);

	cout << "<Capacity of arr2>" << endl;
	cout << arr2.Capacity() << endl << endl;
	assert(arr2.Capacity() == 10);

	cout << "<Size & capacity of arr1 after reserving 20>" << endl;
	arr1.Reserve(20);
	cout << "Size:" << arr1.Size() << endl;
	cout << "Capacity:" << arr1.Capacity() << endl << endl;
	assert(arr1.Size() == 10);
	assert(arr1.Capacity() == 20);


	cout << "<Contents of arr1>" << endl;
	for (int i = 0; i < arr1.Size(); i++)
	{
		cout << arr1[i] << " ";
		assert(arr1[i] == 1.0);
	}
	cout << endl << endl;

	cout << "<Contents of arr1 after assigning>" << endl;
	for (int i = 0; i < arr1.Size(); i++) {
		auto val = i + 1.0;
		arr1[i] = val;
		cout << arr1[i] << " ";
		assert(arr1[i] == val);
	}
	cout << endl << endl;
		
	cout << "<Comparison between two arrays>" << endl;
	DynamicArray arr3(arr1);
	cout << std::boolalpha;
	cout << (arr1 == arr3) << endl << endl;
	assert(arr1 == arr3);


	cout << "<Contents of arr0 after appending some data>" << endl;
	arr0.Append(-1);
	arr0.Append(-2);
	arr0.Append(-3);
	arr0.Append(-4);
	arr0.Append(-5);
	assert(arr0[0] == -1);
	assert(arr0[1] == -2);
	assert(arr0[2] == -3);
	assert(arr0[3] == -4);
	assert(arr0[4] == -5);
	for (int i = 0; i < arr0.Size(); i++) {
		cout << arr0[i] << " ";
	}
	cout << endl << endl;
	cout << "<Size of arr0 after appending some data>" << endl;
	cout << arr0.Size() << endl << endl;
	assert(arr0.Size() == 5);

	cout << "<Contents of arr1 after appending some data>" << endl;
	arr1.Append(101);
	arr1.Append(102);
	arr1.Append(103);
	assert(arr1[arr1.Size() - 3] == 101);
	assert(arr1[arr1.Size() - 2] == 102);
	assert(arr1[arr1.Size() - 1] == 103);
	for (int i = 0; i < arr1.Size(); i++) {
		cout << arr1[i] << " ";
	}
	cout << endl << endl;

	cout << "<Size of arr1 after appending some data>" << endl;
	cout << arr1.Size() << endl << endl;
	assert(arr1.Size() == 13);

	cout << "<Find the index of an element in arr1>" << endl;
	int ix;
	ix = arr1.Find(101);
	cout << ix << endl;
	assert(ix == 10);

	ix = arr1.Find(102);
	cout << ix << endl;
	assert(ix == 11);

	ix = arr1.Find(103);
	cout << ix << endl << endl;
	assert(ix == 12);

	cout << "<Contents of arr0 after reversing>" << endl;
	arr0.Reverse();
	assert(arr0[0] == -5);
	assert(arr0[1] == -4);
	assert(arr0[2] == -3);
	assert(arr0[3] == -2);
	assert(arr0[4] == -1);
	for (int i = 0; i < arr0.Size(); i++) {
		cout << arr0[i] << " ";
	}
	cout << endl << endl;

	cout << "<Contents of arr1 after reversing>" << endl;
	arr1.Reverse();
	assert(arr0[0] == -5);
	for (int i = 0; i < arr1.Size(); i++) {
		cout << arr1[i] << " ";
	}
	cout << endl << endl;
		 
	cout << "<Contents of arr1 after clearing>" << endl;
	arr1.Clear(); // bool bResizeCapacity = false);
	for (int i = 0; i < arr1.Size(); i++) {
		cout << arr1[i] << " ";
	}
	cout << endl << endl;

	cout << "<Size & Capacity of arr1 after calling Clear()>" << endl;
	cout << "Size: " << arr1.Size() << endl;
	cout << "Capacity: " << arr1.Capacity() << endl << endl;
	assert(arr1.Size() == 0);
	assert(arr1.Capacity() == 40);

	cout << "<Size & Capacity of arr1 after calling Clear(true)>" << endl;
	arr1.Clear(true);
	cout << "Size: " << arr1.Size() << endl;
	cout << "Capacity: " << arr1.Capacity() << endl << endl;
	assert(arr1.Size() == 0);
	assert(arr1.Capacity() == 0);

	cout << "<Contents of arr1 after inserting 10 data>" << endl;
	for (int i = 0; i < 10; i++)
		arr1.Insert(0, i + 1);

	for (int i = 0; i < arr1.Size(); i++)
		assert(arr1[i] == arr1.Size() - i);

	for (int i = 0; i < arr1.Size(); i++) {
		cout << arr1[i] << " ";
	}
	cout << endl << endl;

	cout << "<Contents of arr1 after removing some data>" << endl;	
	arr1.Remove(10);
	arr1.Remove(9);
	arr1.Remove(8);	
	assert(arr1[0] == 7);
	assert(arr1[1] == 6);
	assert(arr1[2] == 5);
	assert(arr1[3] == 4);
	assert(arr1[4] == 3);
	assert(arr1[5] == 2);
	assert(arr1[6] == 1);
	for (int i = 0; i < arr1.Size(); i++) {
		cout << arr1[i] << " ";
	}
	cout << endl << endl;

	cout << "<Size & Capacity of arr1 after removing some data>" << endl;
	cout << "Size: " << arr1.Size() << endl;
	cout << "Capacity: " << arr1.Capacity() << endl << endl;
	assert(arr1.Size() == 7);
	assert(arr1.Capacity() == 20);

	cout << "<Handling the index-out-of-rage exception>" << endl;
	try {
		arr1[100] = 999;
	}
	catch (const std::out_of_range& oor) {
		cout << oor.what() << endl;
	}
	cout << endl;

	cout << "<Handling the capacity-out-of-rage exception>" << endl;
	try {
		arr1.Reserve(-1);
	}
	catch (const std::out_of_range& oor) {
		cout << oor.what() << endl;
	}
	cout << endl;

	return 0;
}