
/* File Name: main.cpp
 * Author: Paul Negedu
 * EECS 268 - Lab 9
 * Description:  The main.cpp file that hands control to the Executive file
 * Last edited - April 28th, 2019
 *------------------------------------------------------------------------*/
#ifndef BNODE_H
#define BNODE_H
#include "BNodeInterface.h"
#include <stdexcept>
#include <string>


#include <iostream>
using namespace std;

template <typename ItemType>
class BNode : public BNodeInterface<ItemType>
{
  private:
    ItemType m_entry;                      // Data portion
    BNodeInterface<ItemType> *m_left;      // Pointer to left child
    BNodeInterface<ItemType> *m_right;     // Pointer to right child

  public:
    bool isLeaf() const;
    //creating node with leaf
    BNode(const ItemType entry);

    //without leaf
    BNode(const ItemType &entry, const ItemType &leftEntry, const ItemType &rightEntry);

    ~BNode();

    ItemType getEntry() const;
    BNodeInterface<ItemType> *getLeft() const;
    BNodeInterface<ItemType> *getRight() const;

    void setEntry(ItemType entry);
    void setLeft(BNodeInterface<ItemType> *left);
    void setRight(BNodeInterface<ItemType> *right);

  
};
#include "BNode.hpp"
#endif