/* File Name: main.cpp
 * Author: Paul Negedu
 * EECS 268 - Lab 9
 * Description:  The main.cpp file that hands control to the Executive file
 * Last edited - April 28th, 2019
 *------------------------------------------------------------------------*/

#ifndef BINARYSEARCHTREEINTERFACE_H
#define BINARYSEARCHTREEINTERFACE_H
#include <functional>
using namespace std;

template<typename ItemType, typename KeyType>
class BinarySearchTreeInterface
{
public:
  virtual ~BinarySearchTreeInterface() {}
  virtual void add(const ItemType& entry) = 0;
  virtual ItemType search(KeyType key) const = 0;
  virtual void clear() = 0;
  //new
  virtual void remove(KeyType key) = 0;                                   //throws std::runtime_error if not in tree
  virtual void visitPreOrder(function<void(ItemType)> visit) const = 0;  //Visits each node in pre order
  virtual void visitInOrder(function<void(ItemType)> visit) const = 0;   //Visits each node in in order
  virtual void visitPostOrder(function<void(ItemType)> visit) const = 0; //Visits each node in post order

};
#endif
