/* File Name: main.cpp
 * Author: Paul Negedu
 * EECS 268 - Lab 9
 * Description:  The main.cpp file that hands control to the Executive file
 * Last edited - April 28th, 2019
 *------------------------------------------------------------------------*/

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
using namespace std;
#include <functional>
#include "BNode.h"
#include "BinarySearchTreeInterface.h"

template <typename ItemType, typename KeyType>
class BinarySearchTree : public BinarySearchTreeInterface<ItemType, KeyType>
{
  private:
    BNodeInterface<ItemType> *m_root;
    ItemType recSearch(KeyType key, BNodeInterface<ItemType> *curSubTree) const;
    void recAdd(BNodeInterface<ItemType>* temp, BNodeInterface<ItemType> *curSubTree);//throws
    void destroyTree(BNodeInterface<ItemType> *subTreePtr);
    void operator=(const BinarySearchTree &rhs);
    BNodeInterface<ItemType>* copyTree(const BNodeInterface<ItemType> *treePtr) const;
    bool isEmpty() const;
    BNodeInterface<ItemType> *removeValue(BNodeInterface<ItemType> *subTreePtr, KeyType key, bool &success);
    BNodeInterface<ItemType> *removeNode(BNodeInterface<ItemType> *nodePtr);
    BNodeInterface<ItemType> *removeLeftmostNode(BNodeInterface<ItemType> *subTreePtr, ItemType &inorderSuccessor);

    void preorder(function<void(ItemType)> visit, BNodeInterface<ItemType> *treePtr) const; //Visits each node in pre order
    void inorder(function<void(ItemType)> visit, BNodeInterface<ItemType> *treePtr) const;  //Visits each node in in order
    void postorder(function<void(ItemType)> visit, BNodeInterface<ItemType> *treePtr) const; //Visits each node in post order

  public:
    BinarySearchTree();
    BinarySearchTree(const ItemType &rootItem);
    BinarySearchTree(const BinarySearchTree<ItemType, KeyType> &treePtr);
    ~BinarySearchTree();
    void add(const ItemType& entry);//throws
    ItemType search(KeyType key) const;//throws
    void clear();
    //More methods to come in next lab
    void remove(KeyType key);  //throws std::runtime_error if not in tree
    void visitPreOrder(function<void(ItemType)> visit) const;  //Visits each node in pre order
    void visitInOrder(function<void(ItemType)> visit) const;   //Visits each node in in order
    void visitPostOrder(function<void(ItemType)> visit) const; //Visits each node in post order
};
#include "BinarySearchTree.hpp"
#endif
