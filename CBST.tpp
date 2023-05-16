// ============================================================================
// File: CBST.tpp
// ============================================================================
// Implementation file for the class CBST
// ============================================================================

// ==== CBST<ItemType>::CBST ===================================================
//
// This is the default constructor for CBST<ItemType>. It sets the root to
// nullptr.
//
// Input:
//       void
//
// Output:
//       Nothing
//
// =============================================================================
template <class ItemType>
CBST<ItemType>::CBST(){
    //CBinaryNodeTree<ItemType>(nullptr);
   CBinaryNodeTree<ItemType>::SetRootPtr(nullptr);
        //this->CBinaryNodeTree<ItemType>::SetRootPtr(nullptr);

}

//CBST<ItemType>::CBST(): CBNodeTree(), m_rootPtr(nullptr){}

// ==== CBST<ItemType>::CBST ===================================================
//
// This is the type constructor for CBST<ItemType>.  It allocates a space for a
// CBinaryNode and sets it equal to m_rootPtr.  The new node will have it's
// right and left child pointers set to nullptr.
//
// Input:
//       rootItem   [IN]    - A const reference ItemType.
//
// Output:
//       Nothing
//
// =============================================================================
template <class ItemType>
CBST<ItemType>::CBST(const ItemType &rootItem)
{
    CBinaryNodeTree<ItemType>::SetRootPtr(new CBinaryNode<ItemType>(rootItem, nullptr, nullptr));
    //m_rootPtr = new CBinaryNode<ItemType>(rootItem, nullptr, nullptr);
}

// ==== CBST<ItemType>::CBST ===================================================
//
// This is the copy constructor for CBST<ItemType>. It creates a deep copy of
// "tree."
//
// Input:
//       tree   [IN]    - A const templated CBST that will be copied.
//
// Output:
//       Nothing
//
// =============================================================================
template <class ItemType>
CBST<ItemType>::CBST(const CBST<ItemType> &tree)
{
    //this->CBinaryNodeTree<ItemType>::SetRootPtr(CBinaryNodeTree<ItemType>::CopyTree(tree.m_rootPtr));
    CBinaryNodeTree<ItemType>::SetRootPtr(CBinaryNodeTree<ItemType>::CopyTree(tree.CBinaryNodeTree<ItemType>::GetRootPtr()));

}

// ==== CBST<ItemType>::~CBST ==================================================
//
// This is the destructor for CBST<ItemType>.  It will release all the nodes
// from the heap.
//
// Input:
//       void
//
// Output:
//       Nothing
//
// =============================================================================
template <class ItemType>
CBST<ItemType>::~CBST()
{
        //CBinaryNodeTree<ItemType>::DestroyTree();
        CBinaryNodeTree<ItemType>::Clear();

   // this->CBinaryNodeTree<ItemType>::DestroyTree();
}

// ==== CBST<ItemType>::Add ====================================================
//
// This function adds an item to a tree.  Calls the PlaceNode function to add
// the node to the tree to make sure it is balanced using AVL.
//
// Input:
//       newEntry   [IN]    - A const ItemType reference to the new entry to be
//                              added to the tree.
//
// Output:
//       Returns true if successful, otherwise false.
//
// =============================================================================
template <class ItemType>
bool CBST<ItemType>::Add(const ItemType &newEntry)
{
    if (this->CBinaryNodeTree<ItemType>::Contains(newEntry))
    {
        return false;
    }
    CBinaryNode<ItemType> *newNodePtr = new CBinaryNode<ItemType>(newEntry);
    this->CBinaryNodeTree<ItemType>::SetRootPtr(PlaceNode(this->CBinaryNodeTree<ItemType>::GetRootPtr(), newNodePtr));
    return true;
}

// ==== CBST<ItemType>::Remove =================================================
//
// This function removes an entry (a node), if it exists, from the tree.
//
// Input:
//       anEntry    [IN]    - A const ItemType reference to the new entry to be
//                              added to the tree.
//
// Output:
//       Returns true if successful, otherwise false.
//
// =============================================================================
template <class ItemType>
bool CBST<ItemType>::Remove(const ItemType &anEntry)
{
    bool success = false;
    if (CBinaryNodeTree<ItemType>::Contains(anEntry))
    {
        this->CBinaryNodeTree<ItemType>::SetRootPtr(CBinaryNodeTree<ItemType>::RemoveValue(this->CBinaryNodeTree<ItemType>::GetRootPtr(), anEntry, success));

        //this->m_rootPtr = RemoveValue(this->m_rootPtr, anEntry, success);
        //RemoveValue(this->m_rootPtr, anEntry, success);
    }
    return success;
}

// ==== CBST<ItemType>::operator= ==============================================
//
// This function assigns the right-hand side CBST to the left-hand side CBST.
// Make sure to protect against assignment to self!
//
// Input:
//       rhs    [IN]    - A const templated CBST to copy from.
// Output:
//       A templated CBST reference object (the left-hand side of the tree.
//
// =============================================================================
template <class ItemType>
CBST<ItemType> &CBST<ItemType>::operator=(const CBST<ItemType> &rhs)
{
    if (this != &rhs)
    {
       // this->DestroyTree(this->GetRootPtr());
        //this->m_rootPtr = CBinaryNodeTree::CopyTree(rhs.GetRootPtr());
        CBinaryNodeTree<ItemType>::DestroyTree(this->CBinaryNodeTree<ItemType>::GetRootPtr());
        this->CBinaryNodeTree<ItemType>::SetRootPtr(CBinaryNodeTree<ItemType>::CopyTree(rhs.CBinaryNodeTree<ItemType>::GetRootPtr()));
    }
    return *this;
}

// ==== CBST<ItemType>::PlaceNode ==============================================
//
// This function adds a node in the tree. It makes sure that the same node value
// is not added twice.  Furthermore, as soon as it adds a node, it makes sure
// the tree is still AVL balanced.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to start the
//                              search of where to add the node.
//      nodePtr     [IN]    - A templated CBinaryNode pointer node that will be
//                              added to the tree.
// Output:
//       A CBinaryNode<ItemType> templated pointer that is the address of
//          the updated parent node pointer (after any shifts caused from AVL
//          balancing, parent node may need updating).
//
// =============================================================================
template <class ItemType>
CBinaryNode<ItemType> *CBST<ItemType>::PlaceNode(CBinaryNode<ItemType> *subTreePtr,
                                                 CBinaryNode<ItemType> *newNode)
{
    if (subTreePtr == nullptr)
    {
        return newNode;
    }
    else if (subTreePtr->GetItem() > newNode->GetItem())
    {//this->CBinaryNodeTree<ItemType>::GetRootPtr()
        CBinaryNode<ItemType> *tempPtr = PlaceNode(subTreePtr->GetLeftChildPtr(), newNode);
        subTreePtr->SetLeftChildPtr(tempPtr);

         // Balance check
        //if (getHeightDifference(subTreePtr) > 1)

        if(CBinaryNodeTree<ItemType>::GetHeightHelper(subTreePtr->GetLeftChildPtr()-CBinaryNodeTree<ItemType>::GetHeightHelper(subTreePtr->GetRightChildPtr()))>1)
        {
            if (newNode->GetItem() < subTreePtr->GetLeftChildPtr()->GetItem())
            {
                // Single right rotation 
                subTreePtr = RightRotate(subTreePtr);
            }
            else
            {
                subTreePtr = LeftRightRotate(subTreePtr);
            }
        }
    }
    else
    {
        CBinaryNode<ItemType> *tempPtr = PlaceNode(subTreePtr->GetRightChildPtr(), newNode);
        subTreePtr->SetRightChildPtr(tempPtr);
         // Balance check
        if (this->CBinaryNodeTree<ItemType>::GetHeightHelper(subTreePtr->GetLeftChildPtr()-CBinaryNodeTree<ItemType>::GetHeightHelper(subTreePtr->GetRightChildPtr())) < -1)
        {
            if (newNode->GetItem() > subTreePtr->GetRightChildPtr()->GetItem())
            {
                // Single left rotation
                subTreePtr = LeftRotate(subTreePtr);
            }
            else
            {
       
                subTreePtr = RightLeftRotate(subTreePtr);
            }
        }
    }

    return subTreePtr;
}

// ==== CBST<ItemType>::LeftRotate =============================================
//
// This function rotates the nodes to the left.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to start the
//                              rotation.
// Output:
//       An updated CBinaryNode<ItemType> templated pointer that is the new
//          "subTreePtr" after the rotation.
//
// =============================================================================
template <class ItemType>
CBinaryNode<ItemType> *CBST<ItemType>::LeftRotate(CBinaryNode<ItemType> *subTreePtr)
{
    CBinaryNode<ItemType> *ptr_A = subTreePtr->GetRightChildPtr();
    CBinaryNode<ItemType> *ptr_B = ptr_A->GetLeftChildPtr();
    ptr_A->SetLeftChildPtr(subTreePtr);
    subTreePtr->SetRightChildPtr(ptr_B); 
 
    return ptr_A;
}

// ==== CBST<ItemType>::RightRotate ============================================
//
// This function rotates the nodes to the right.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to start the
//                              rotation.
// Output:
//       An updated CBinaryNode<ItemType> templated pointer that is the new
//          "subTreePtr" after the rotation.
//
// =============================================================================
template <class ItemType>
CBinaryNode<ItemType> *CBST<ItemType>::RightRotate(CBinaryNode<ItemType> *subTreePtr)
{
    CBinaryNode<ItemType> *ptr_A = subTreePtr->GetLeftChildPtr();
    CBinaryNode<ItemType> *ptr_B = ptr_A->GetRightChildPtr();
    ptr_A->SetRightChildPtr(subTreePtr);
    subTreePtr->SetLeftChildPtr(ptr_B); 
 
    return ptr_A;
}

// ==== CBST<ItemType>::LeftRightRotate ========================================
//
// This function rotates the nodes to the left and then right.  In other words,
// it rotates the left child of subTreePtr to the left and then rotates
// subTreePtr to the right.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to start the
//                              rotation.
// Output:
//       An updated CBinaryNode<ItemType> templated pointer that is the new
//          "subTreePtr" after the rotation.
//
// =============================================================================
template <class ItemType>
CBinaryNode<ItemType> *CBST<ItemType>::LeftRightRotate(CBinaryNode<ItemType> *subTreePtr)
{
    CBinaryNode<ItemType> *leftChildPtr = subTreePtr->GetLeftChildPtr();
    subTreePtr->SetLeftChildPtr(LeftRotate(leftChildPtr));
    return RightRotate(subTreePtr);

}

// ==== CBST<ItemType>::RightLeftRotate ========================================
//
// This function rotates the nodes to the right and then left.  In other words,
// it rotates the right child of subTreePtr to the right and then rotates
// subTreePtr to the left.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to start the
//                              rotation.
// Output:
//       An updated CBinaryNode<ItemType> templated pointer that is the new
//          "subTreePtr" after the rotation.
//
// =============================================================================
template <class ItemType>
CBinaryNode<ItemType> *CBST<ItemType>::RightLeftRotate(CBinaryNode<ItemType> *subTreePtr)
{
    CBinaryNode<ItemType> *rightChildPtr = subTreePtr->GetRightChildPtr();
    subTreePtr->SetRightChildPtr(RightRotate(rightChildPtr));
    return LeftRotate(subTreePtr);
}

// ==== CBST<ItemType>::RemoveValue ============================================
//
// This function removes a value from the tree.  It also keeps the tree AVL
// balanced after each removal.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to start the
//                              search of the node to remove.
//      target      [IN]    - A const ItemType value that we want to remove from
//                              the tree.
//      success     [OUT]   - A bool value that is marked true if sucessful,
//                              false otherwise.
//
// Output:
//       An updated CBinaryNode<ItemType> templated pointer that is the new
//          "subTreePtr" after the removal.
//
// =============================================================================
/*virtual CBinaryNode<ItemType> *RemoveValue(CBinaryNode<ItemType> *subTreePtr,
                                               const ItemType &target, bool &success);*/
template <class ItemType>
CBinaryNode<ItemType> *CBST<ItemType>::RemoveValue(CBinaryNode<ItemType> *subTreePtr,
                                                   const ItemType &target, bool &success)
{
    if (subTreePtr == nullptr)
    {
        success = false;
    }
    else if (target == subTreePtr->GetItem())
    {
        // Node found
        // subTreePtr = RemoveNode(subTreePtr);
        if (subTreePtr->IsLeaf())
        {
            delete subTreePtr;
            subTreePtr = nullptr;
        }
      
    }
    else if (target < subTreePtr->GetItem())
    {
        subTreePtr->SetLeftChildPtr(RemoveValue(subTreePtr->GetLeftChildPtr(), target, success));
        //REBALANCE???
    }
    else
    {
        subTreePtr->SetRightChildPtr(RemoveValue(subTreePtr->GetRightChildPtr(), target, success));
    }

    return subTreePtr;
}

// ==== CBinaryNodeTree<ItemType>::FindNode ====================================
//
// This function finds a target node if it exists.
//
// Input:
//      treePtr     [IN]    - A templated CBinaryNode pointer to start the
//                              search of the node to find
//      target      [IN]    - A const ItemType value that we want to find from
//                              the tree.
//      success     [OUT]   - A bool value that is marked true if sucessful,
//                              false otherwise.
//
// Output:
//       An CBinaryNode<ItemType> templated pointer of the node found.  If not
//          found, a nullptr is returned.
//
// =============================================================================
template <class ItemType>
CBinaryNode<ItemType> *CBST<ItemType>::FindNode(CBinaryNode<ItemType> *treePtr,
                                                const ItemType &target,
                                                bool &success) const
{
    /*
    // Searches the binary search tree for a given target value.
search(bstTree: BinarySearchTree, target: ItemType)
{
 if (bstTree is empty)
 The desired item is not found
 else if (target == data item in the root of bstTree)
 The desired item is found
 else if (target < data item in the root of bstTree)
 search(Left subtree of bstTree, target)
 else
 search(Right subtree of bstTree, target)
}
*/
    if (treePtr == nullptr)
    {
        success = false;
        return nullptr;
    }

    if (target == treePtr->GetItem())
    {
        // Node found
        success = true;
        return treePtr;
    }

    if (target < treePtr->GetItem())
    {
        return FindNode(treePtr->GetLeftChildPtr(), target, success);
    }
    else
    {
        return FindNode(treePtr->GetRightChildPtr(), target, success);
    }
}
