/* File Name: main.cpp
 * Author: Paul Negedu
 * EECS 268 - Lab 9
 * Description:  The main.cpp file that hands control to the Executive file
 * Last edited - April 28th, 2019
 *------------------------------------------------------------------------*/

template <typename ItemType, typename keyType>
BinarySearchTree<ItemType, keyType>::BinarySearchTree()
{
    m_root = nullptr;
}
template <typename ItemType, typename keyType>
BinarySearchTree<ItemType, keyType>::BinarySearchTree(const ItemType &rootItem)
{
    m_root = nullptr;
    m_root->add(rootItem);
}

template <typename ItemType, typename keyType>
BinarySearchTree<ItemType, keyType>::BinarySearchTree(const BinarySearchTree<ItemType, keyType> &treePtr)
{
    m_root = copyTree(treePtr.m_root);
}

template <typename ItemType, typename keyType>
BinarySearchTree<ItemType, keyType>::~BinarySearchTree()
{
    clear();
    m_root=nullptr;
}

template <typename ItemType, typename keyType>
ItemType BinarySearchTree<ItemType, keyType>::search(keyType key) const
{
    return (recSearch(key,m_root));
}

template <typename ItemType, typename keyType>
ItemType BinarySearchTree<ItemType, keyType>::recSearch(keyType key, BNodeInterface<ItemType> *curSubTree) const
{
    if (curSubTree==nullptr)
    {
        throw(runtime_error("entry is not in tree"));
    }
    else if (curSubTree->getEntry() == key)
    {
        return (curSubTree->getEntry());
    }
    else if (curSubTree->getEntry() > key)
    {
        return   recSearch(key,curSubTree->getLeft() )    ;
    }
    else 
    {
        return recSearch(   key,curSubTree->getRight() );
    }
}

template <typename ItemType, typename keyType>
void BinarySearchTree<ItemType, keyType>::add(const ItemType& entry)
{
    BNodeInterface<ItemType> *temp = new BNode<ItemType>(entry);
    (recAdd(temp, m_root));
}

template <typename ItemType, typename keyType>
void BinarySearchTree<ItemType, keyType>::recAdd(BNodeInterface<ItemType>* temp, BNodeInterface<ItemType> *curSubTree)
{
    if (m_root == nullptr)
    {
        m_root = temp;
        temp = nullptr;
    }
    else
    {
       
       if(  (temp->getEntry()) < (curSubTree->getEntry()) )
        {
            if (curSubTree->getLeft()!=nullptr)
                recAdd(temp, curSubTree->getLeft());
            else
            {
                curSubTree->setLeft(temp);
            }
            
        }
        else if (   (temp->getEntry()) > (curSubTree->getEntry())  )
        {
            if (curSubTree->getRight() != nullptr)
                recAdd(temp, curSubTree->getRight());
            else
            {
                curSubTree->setRight(temp);
            }
        }
        else    //attempting to add a duplicate
        throw(runtime_error("Attempting to add a dupplicate"));
    }
}

template <typename ItemType, typename keyType>
void BinarySearchTree<ItemType, keyType>::clear()
{
    destroyTree(m_root);
}

template <typename ItemType, typename keyType>
void BinarySearchTree<ItemType, keyType>::destroyTree(BNodeInterface<ItemType> *subTreePtr)
{
  if(subTreePtr== nullptr)
  {
    return;
  }
  else
  {
    destroyTree(subTreePtr->getLeft());
    destroyTree(subTreePtr->getRight());
    delete subTreePtr;
  }
}

template <typename ItemType, typename keyType>
void BinarySearchTree<ItemType, keyType>::operator=(const BinarySearchTree &rhs)
{
    clear();
    m_root = copyTree(rhs.m_root);
}

template <typename ItemType, typename keyType>
BNodeInterface<ItemType> *BinarySearchTree<ItemType, keyType>::copyTree(const BNodeInterface<ItemType> *treePtr) const
{
    BNodeInterface<ItemType> *newTreePtr = nullptr;
    // Copy tree nodes during a preorder traversal
    if (treePtr != nullptr)
    {
        // Copy node
        newTreePtr = new BNode<ItemType>(treePtr->getEntry());
        newTreePtr->setLeft(copyTree(treePtr->getLeft()));
        newTreePtr->setRight(copyTree(treePtr->getRight()));
    } // end if
    // Else tree is empty (newTreePtr is nullptr)
    return newTreePtr;
}

template <typename ItemType, typename keyType>
bool BinarySearchTree<ItemType, keyType>::isEmpty() const
{
    if (m_root == nullptr)
    {
        return true;
    }
    else 
    {
        return false; 
    }

}

template <typename ItemType, typename keyType>
void BinarySearchTree<ItemType, keyType>::remove(keyType key)
{
    bool checker = false;
    m_root = removeValue(m_root, key, checker);
    if(checker == false)
    {
        throw(runtime_error("The was no Pokemon with that name"));
    }
    
    
}

template <typename ItemType, typename keyType>
BNodeInterface<ItemType> *BinarySearchTree<ItemType, keyType>::removeValue(BNodeInterface<ItemType> *subTreePtr, keyType key, bool &success)
{
    BNodeInterface<ItemType> *temporary = nullptr;
    if (subTreePtr == nullptr)
    {
        success = false;
        return nullptr;
    }
    else if (subTreePtr->getEntry() == key)
    {
        subTreePtr = removeNode(subTreePtr);
        success = true;
        return subTreePtr;
    }
    else if (subTreePtr->getEntry() > key)
    {
        temporary = removeValue(subTreePtr->getLeft(), key, success);
        subTreePtr->setLeft(temporary);
        return subTreePtr;
    }
    else
    {
        temporary = removeValue(subTreePtr->getRight(), key, success);
        subTreePtr->setRight(temporary);
        return subTreePtr;
    }
}

template <typename ItemType, typename keyType>
BNodeInterface<ItemType> *BinarySearchTree<ItemType, keyType>::removeNode(BNodeInterface<ItemType> *nodePtr)
{
    BNodeInterface<ItemType> *temp = nullptr;
    BNodeInterface<ItemType> *temp2 = nullptr;
    // is leaf checker
    if (    nodePtr->isLeaf()   )
    {
        delete nodePtr;
        nodePtr = nullptr;
        return nodePtr;
    }
    else if ((nodePtr->getLeft() != nullptr && nodePtr->getRight() == nullptr) || (nodePtr->getRight() != nullptr && nodePtr->getLeft() == nullptr))
    {
        if (nodePtr->getLeft() != nullptr)//child is on the left
        {
            temp = nodePtr->getLeft();
            delete nodePtr;
            nodePtr = nullptr;
            return temp;
        }
        else //child is on the right
        {
            temp = nodePtr->getRight();
            delete nodePtr;
            nodePtr = nullptr;
            return temp;
        }
    }
    else // 2 child
    {
        ItemType value;
        temp2 = removeLeftmostNode(nodePtr->getRight(), value);
        nodePtr->setRight(temp2);
        nodePtr->setEntry(value);
        return nodePtr;
    }
}

template <typename ItemType, typename KeyType>
BNodeInterface<ItemType> *BinarySearchTree<ItemType, KeyType>::removeLeftmostNode(BNodeInterface<ItemType> *subTreePtr, ItemType &inorderSuccessor)
{
    if (subTreePtr->getLeft() == nullptr)
    {
        inorderSuccessor = subTreePtr->getEntry();
        return (removeNode(subTreePtr));
    }
    else
    {
        return removeLeftmostNode(subTreePtr->getLeft(), inorderSuccessor);
    }
}

template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::visitPreOrder(function<void(ItemType)> visit) const
{
    preorder(visit, m_root);
}

template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::visitInOrder(function<void(ItemType)> visit) const
{
    inorder(visit, m_root);
}

template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::visitPostOrder(function<void(ItemType)> visit) const
{
    postorder(visit, m_root);
}
////////////////////////////////////
template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::preorder(function<void(ItemType)> visit, BNodeInterface<ItemType> *treePtr) const
{
    if (treePtr != nullptr)
    {
        ItemType temp = treePtr->getEntry();
        visit(temp);
        preorder(visit, treePtr->getLeft());

        preorder(visit, treePtr->getRight());
    }
}

template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::inorder(function<void(ItemType)> visit, BNodeInterface<ItemType> *treePtr) const
{

    if (treePtr != nullptr)
    {

        inorder(visit, treePtr->getLeft());
        ItemType temp = treePtr->getEntry();
        visit(temp);
        inorder(visit, treePtr->getRight());
    }
}

template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::postorder(function<void(ItemType)> visit, BNodeInterface<ItemType> *treePtr) const
{
    if (treePtr != nullptr)
    {
        postorder(visit, treePtr->getLeft());
        postorder(visit, treePtr->getRight());
        ItemType temp = treePtr->getEntry();
        visit(temp);
    }
}

