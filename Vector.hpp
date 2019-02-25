//Vector: An array-based templated data structure that has various functions that make the
//structure more useful for inserting and removing data than an array

//I didn't cheat. (I neither recieved nor gave unauthorized assistance on this assignment)

//Programmer: Brady Siegel
#include <iostream>

#ifndef VECTOR_H
#define VECTOR_H

template<typename T>
class Vector
{
private:
  int size; //Capacity
  int count; //How many in the array
  T *storage; //Pointer to storage array
  void grow(); //Doubles size of array
  void make_hole(int location); //Makes a hole to insert
  void cover_up(int location); //Covers hole
public:
  Vector(); //Default constructor
  ~Vector(); //Destructor
  Vector(const Vector &v); //Copy constructor
  const Vector & operator= (const Vector &v); //= operator constructor
  bool contains(T find_me) const; //Checks to see if the variable is in the vector
  bool insert(T add_me); //Add item at the end of the vector
  bool insert_at(T add_me, int location); //Inserts item at specified location
  T remove_from(int location); //removes item from vector and returns the item
  T return_from(int location) const; //returns item from vector and does not remove
  int get_count() const; //returns how many items are in the vector
  void output(std::ostream &out) const; //prints vector
};

template<typename T>
Vector<T>::Vector() : size(10), count(0), storage(new T[size])
{
}
template<typename T>
Vector<T>::~Vector()
{
  delete [] storage;
  storage = nullptr;
}
template<typename T>
Vector<T>::Vector(const Vector &v)
{
  size = v.size;
  count = v.count;
  storage = new T[size];
  for (int c = 0; c < count; c++)
  {
    storage[c] = v.storage[c];
  }
}
template<typename T>
const Vector<T> &Vector<T>::operator= (const Vector<T> &v)
{
  if (this != &v) //Checks that the memory locations of the objects are different
  {
    delete [] storage;
    storage = nullptr;
    size = v.size;
    count = v.count;
    storage = new T[size];
    for (int c = 0; c < count; c++)
    {
      storage[c] = v.storage[c];
    }
  }
  return *this;
}
template<typename T>
bool Vector<T>::contains(T find_me) const
{
  for (int c = 0; c < count; c++)
  {
    if (storage[c] == find_me)
    {
      return true;
    }
  }
  return false;
}
template<typename T>
bool Vector<T>::insert(T add_me)
{
  if (size <= count)
  {
    grow();
  }
  storage[count] = add_me;
  count++;
  return true;
}
template<typename T>
bool Vector<T>::insert_at(T add_me, int location)
{
  if (size <= count)
  {
    grow();
  }
  if (location < 0)
  {
    location = 0;
  }
  else if(location >= count)
  {
    location = count;
  }
  make_hole(location);
  storage[location] = add_me;
  count++;
  return true;
}
template<typename T>
T Vector<T>::remove_from(int location)
{
  if (location >= count || location < 0) //Checks to make sure index is valid
  {
    return T();
  }
  T stuff = storage[location]; //Holds contents of vector at this index so it doesn't get lost when covered up
  cover_up(location);
  count--;
  return stuff;
}
template<typename T>
T Vector<T>::return_from(int location) const
{
  if (location >= count || location < 0) //Checks to make sure index is valid
  {
    return T();
  }
  return storage[location];
}
template<typename T>
int Vector<T>::get_count() const
{
  return count;
}
template<typename T>
void Vector<T>::grow()
{
  T *temp = storage;
  storage = new T[size*2];
  for (int c = 0; c < count; c++)
  {
    storage[c] = temp[c];
  }
  size *= 2;
  delete [] temp;
  temp = nullptr;
}
template<typename T>
void Vector<T>::make_hole(int location)
{
  //Starts from end of array and moves each index up one to make a space for the new value
  for (int c = count; c > location; c--)
  {
    storage[c] = storage[c - 1];
  }
}
template<typename T>
void Vector<T>::cover_up(int location)
{
  for (int c = location; c < count - 1; c++)
  {
      storage[c] = storage[c + 1];
  }
}
template<typename T>
void Vector<T>::output(std::ostream &out) const
{
  for (int c = 0; c < count; c++)
  {
    out << storage[c] << '\n';
  }
}
#endif
