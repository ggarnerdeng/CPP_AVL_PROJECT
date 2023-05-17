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
CBST<ItemType>::CBST()
{
    CBinaryNodeTree<ItemType>::SetRootPtr(nullptr);
}

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
    CBinaryNodeTree<ItemType>::Clear();
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
        cout << "attempted to add duplicate";
        return false;
    }
    CBinaryNode<ItemType> *newNodePtr = new CBinaryNode<ItemType>(newEntry);
    this->CBinaryNodeTree<ItemType>::SetRootPtr(PlaceNode(this->CBinaryNodeTree<ItemType>::GetRootPtr(), newNodePtr));

    return true;
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
        CBinaryNodeTree<ItemType>::DestroyTree(this->GetRootPtr());
        this->SetRootPtr(CBinaryNodeTree<ItemType>::CopyTree(rhs.GetRootPtr()));
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
    {
        CBinaryNode<ItemType> *tempPtr = PlaceNode(subTreePtr->GetLeftChildPtr(), newNode);
        subTreePtr->SetLeftChildPtr(tempPtr);

        if (CBinaryNodeTree<ItemType>::GetHeightHelper(subTreePtr->GetLeftChildPtr()) - CBinaryNodeTree<ItemType>::GetHeightHelper(subTreePtr->GetRightChildPtr()) > 1)
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

        if (this->CBinaryNodeTree<ItemType>::GetHeightHelper(subTreePtr->GetLeftChildPtr()) - CBinaryNodeTree<ItemType>::GetHeightHelper(subTreePtr->GetRightChildPtr()) < -1)
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
template <class ItemType>
CBinaryNode<ItemType> *CBST<ItemType>::RemoveValue(CBinaryNode<ItemType> *subTreePtr,
                                                   const ItemType &target, bool &success)
{
    if (subTreePtr == nullptr)
    {
        success = false;
        return nullptr;
    }
    else if (target == subTreePtr->GetItem())
    {
        // Node found
        CBinaryNode<ItemType> *nodeToRemove = subTreePtr;
        if (subTreePtr->IsLeaf())
        {
            subTreePtr = nullptr;
        }
        else if (subTreePtr->GetLeftChildPtr() == nullptr)
        {
            subTreePtr = subTreePtr->GetRightChildPtr();
        }
        else if (subTreePtr->GetRightChildPtr() == nullptr)
        {
            subTreePtr = subTreePtr->GetLeftChildPtr();
        }
        else
        {
            // Node has two children
            CBinaryNode<ItemType> *predecessorNode = subTreePtr->GetLeftChildPtr();
            while (predecessorNode->GetRightChildPtr() != nullptr)
            {
                predecessorNode = predecessorNode->GetRightChildPtr();
            }
            subTreePtr->SetItem(predecessorNode->GetItem());
            subTreePtr->SetLeftChildPtr(RemoveValue(subTreePtr->GetLeftChildPtr(), predecessorNode->GetItem(), success));
        }

        delete nodeToRemove;
        success = true;
    }
    else if (target < subTreePtr->GetItem())
    {
        subTreePtr->SetLeftChildPtr(RemoveValue(subTreePtr->GetLeftChildPtr(), target, success));
        // Perform AVL tree rebalancing if necessary
        if (CBinaryNodeTree<ItemType>::GetHeightHelper(subTreePtr->GetRightChildPtr()) - CBinaryNodeTree<ItemType>::GetHeightHelper(subTreePtr->GetLeftChildPtr()) == 2)
        {
            if (target < subTreePtr->GetLeftChildPtr()->GetItem())
                subTreePtr = RightRotate(subTreePtr);
            else
                subTreePtr = LeftRightRotate(subTreePtr);
        }
    }
    else
    {
        subTreePtr->SetRightChildPtr(RemoveValue(subTreePtr->GetRightChildPtr(), target, success));
        // Perform AVL tree rebalancing if necessary
        if (CBinaryNodeTree<ItemType>::GetHeightHelper(subTreePtr->GetLeftChildPtr()) - CBinaryNodeTree<ItemType>::GetHeightHelper(subTreePtr->GetRightChildPtr()) == 2)
        {
            if (target > subTreePtr->GetRightChildPtr()->GetItem())
                subTreePtr = LeftRotate(subTreePtr);
            else
                subTreePtr = RightLeftRotate(subTreePtr);
        }
    }
    return subTreePtr;
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
        this->CBinaryNodeTree<ItemType>::SetRootPtr(CBST<ItemType>::RemoveValue(this->CBinaryNodeTree<ItemType>::GetRootPtr(), anEntry, success));
    }
    return success;
}
