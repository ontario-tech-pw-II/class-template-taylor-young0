#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

template<class T>
class DynamicArray {
public:
  DynamicArray();
  ~DynamicArray();
  void addEntry(T newEntry);
  T getEntry(int index);
  int getSize();

private:
  T *dynamicArray;
  int size;
};

template<class T>
DynamicArray<T>::DynamicArray() {
  dynamicArray = nullptr;
  size = 0;
}

template<class T>
DynamicArray<T>::~DynamicArray() {
  if (dynamicArray != nullptr)
    delete[] dynamicArray;
}

template<class T>
int DynamicArray<T>::getSize() {
  return size;
}

// Adds an entry to the dynamic array.
template<class T>
void DynamicArray<T>::addEntry(T newEntry) {
    // Create a new array, copy the contents of the old array, then delete it
    T *newArray = new T[size + 1];
    for (int i = 0; i < size; i++) {
      newArray[i] = dynamicArray[i];
    }

    delete[] dynamicArray;

    dynamicArray = newArray;

    // Add the new entry and increment the size
    newArray[size++] = newEntry;
}



// Retrieve the element at a given index
template<class T>
T DynamicArray<T>::getEntry(int index) {
  if ((index < 0) || (index >= size)){
    cout << "Out of the index !" << endl;
    return 0;

  }
  return dynamicArray[index];
}


int main() {
  DynamicArray<int> x;

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

  DynamicArray<string> y;

  // Adding entries
  y.addEntry("Frank");
  y.addEntry("Wiggum");
  y.addEntry("Nahasapeemapetilon");
  y.addEntry("Quimby");
  y.addEntry("Flanders");

  // Output entries
  cout << "String List:" << endl;

  for (int i = 0; i < y.getSize(); i++)
    cout << y.getEntry(i) << endl;

  return 0;
}
