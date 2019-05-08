/* File Name: main.cpp
 * Author: Paul Negedu
 * EECS 268 - Lab 9
 * Description:  The main.cpp file that hands control to the Executive file
 * Last edited - April 28th, 2019
 *------------------------------------------------------------------------*/

template <typename ItemType>
bool BNode<ItemType>::isLeaf() const
{
    if (m_left == nullptr && m_right == nullptr)
    {
        return (true);
    }
    else
    {
        return (false);
    }
}

template <typename ItemType>
BNode<ItemType>::BNode(const ItemType entry)
{
    m_left = nullptr;
    m_right = nullptr;
    m_entry = entry;
}

template <typename ItemType>
BNode<ItemType>::~BNode()
{
  m_left = nullptr;
  m_right = nullptr;
}

template <typename ItemType>
BNode<ItemType>::BNode(const ItemType &entry, const ItemType &leftEntry, const ItemType &rightEntry)
{
  m_left = new BNode(leftEntry);
  m_right = new BNode(rightEntry);
  m_entry = entry;
}

template <typename ItemType>
ItemType BNode<ItemType>::getEntry() const
{
    return (m_entry);
}

template <typename ItemType>
BNodeInterface<ItemType> *BNode<ItemType>::getLeft() const
{
  return(m_left);
}

template <typename ItemType>
BNodeInterface<ItemType> *BNode<ItemType>::getRight() const
{
  return(m_right);
}



template <typename ItemType>
void BNode<ItemType>::setEntry(ItemType entry)
{
    m_entry = entry;
}
template <typename ItemType>
void BNode<ItemType>::setLeft(BNodeInterface<ItemType> *left)
{
  m_left = left;
}

template <typename ItemType>
void BNode<ItemType>::setRight(BNodeInterface<ItemType> *right)
{
  m_right = right;
}

