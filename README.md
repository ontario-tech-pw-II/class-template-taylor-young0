## Class Template

Learning outcomes highlights: 
- defining  a class template 
- understanding the syntax of member functions
- recognizing the flexibility of a class template 

**Problem:** The <code>DynamicArray</code> class is written to holds a list of integer. Change the class to a template class in order to work with other types as well. For example, the class can holds a list of string, double and etc.

```C++
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

class DynamicArray 
{
public:
  DynamicArray();
  ~DynamicArray();
  void addEntry(int newEntry);
  int getEntry(int index);
  int getSize();

private:
  int *dynamicArray;
  int size;
};

DynamicArray::DynamicArray()
{
  dynamicArray = nullptr;
  size = 0;
}


DynamicArray::~DynamicArray()
{
  if (dynamicArray != nullptr)
    delete[] dynamicArray;
}

int DynamicArray::getSize()
{
  return size;
}

// Adds an entry to the dynamic array. 
void DynamicArray::addEntry(int newEntry)
{
    // Create a new array, copy the contents of the old array, then delete it
    int *newArray = new int[size + 1];
    for (int i = 0; i < size; i++)
    {
    newArray[i] = dynamicArray[i];
    }
    
    delete[] dynamicArray;
    
    dynamicArray = newArray;
    
    // Add the new entry and increment the size
    newArray[size++] = newEntry;
}

// Retrieve the element at a given index
int DynamicArray::getEntry(int index)
{
  if ((index < 0) || (index >= size)){
    cout << "Out of the index !" << endl;
    return 0;

  }
  return dynamicArray[index];
}

int main()
{
  DynamicArray x;

  // Adding entries
  x.addEntry(7);
  x.addEntry(5);
  x.addEntry(4);
  x.addEntry(2);
  x.addEntry(8);

  // Output entries
  cout << "List:" << endl;
  
  for (int i = 0; i < x.getSize(); i++)
    cout << x.getEntry(i) << endl;
  
  return 0;
}
```
After changing the class definition to a class template, you can test your class using the following main:
```C++
int main()
{
  DynamicArray<string> x;

  // Adding entries
  x.addEntry("Frank");
  x.addEntry("Wiggum");
  x.addEntry("Nahasapeemapetilon");
  x.addEntry("Quimby");
  x.addEntry("Flanders");

  // Output entries
  cout << "List:" << endl;
  
  for (int i = 0; i < x.getSize(); i++)
    cout << x.getEntry(i) << endl;
  
  return 0;
}
```
