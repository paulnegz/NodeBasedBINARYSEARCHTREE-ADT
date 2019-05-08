/* File Name: main.cpp
 * Author: Paul Negedu
 * EECS 268 - Lab 9
 * Description:  The main.cpp file that hands control to the Executive file
 * Last edited - April 28th, 2019
 *------------------------------------------------------------------------*/

#ifndef BNODEINTERFACE_H
#define BNODEINTERFACE_H
using namespace std;

template <typename ItemType>
class BNodeInterface
{
    public:
      virtual ~BNodeInterface(){}
      virtual ItemType getEntry() const = 0;
      virtual BNodeInterface<ItemType> *getLeft() const = 0;
      virtual BNodeInterface<ItemType> *getRight() const = 0;

      virtual void setEntry(ItemType entry) = 0;
      virtual void setLeft(BNodeInterface<ItemType> *left) = 0;
      virtual void setRight(BNodeInterface<ItemType> *right) = 0;

      virtual bool isLeaf() const = 0;
};
#endif