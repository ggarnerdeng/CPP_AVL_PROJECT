// ============================================================================
// File: CBST.tpp
// ============================================================================
// Implementation file for the class CBST
// ============================================================================
// Programmer: Garner Deng
// Date: 5/18/2023

// Macro definitions.
#define GetHeightHelper CBinaryNodeTree<ItemType>::GetHeightHelper
#define SetRootPtr CBinaryNodeTree<ItemType>::SetRootPtr
#define GetRootPtr CBinaryNodeTree<ItemType>::GetRootPtr
#define CopyTree CBinaryNodeTree<ItemType>::CopyTree
#define Clear CBinaryNodeTree<ItemType>::Clear
#define Contains CBinaryNodeTree<ItemType>::Contains
#define DestroyTree CBinaryNodeTree<ItemType>::DestroyTree

// ==== CBST<ItemType>::CBST ===================================================
//
// This is the default constructor for CBST<ItemType>. It sets the root to
// nullptr.
//
// Input:
//       void
// Output:
//       Nothing
// =============================================================================
template <class ItemType>
CBST<ItemType>::
    CBST()
{
    SetRootPtr(nullptr);
}

// ==== CBST<ItemType>::CBST ===================================================
//
// This is the type constructor for CBST<ItemType>.  It allocates a space for a
// CBinaryNode and sets it equal to m_rootPtr.  The new node will have it's
// right and left child pointers set to nullptr.
//
// Input:
//       rootItem   [IN]    - A const reference ItemType.
// Output:
//       Nothing
// =============================================================================
template <class ItemType>
CBST<ItemType>::CBST(const ItemType &rootItem)
{
    SetRootPtr(new CBinaryNode<ItemType>(rootItem, nullptr, nullptr));
}

// ==== CBST<ItemType>::CBST ===================================================
//
// This is the copy constructor for CBST<ItemType>. It creates a deep copy of
// "tree."
//
// Input:
//       tree   [IN]    - A const templated CBST that will be copied.
// Output:
//       Nothing
// =============================================================================
template <class ItemType>
CBST<ItemType>::CBST(const CBST<ItemType> &tree)
{
    SetRootPtr(CopyTree(tree.GetRootPtr()));
}

// ==== CBST<ItemType>::~CBST ==================================================
//
// This is the destructor for CBST<ItemType>.  It will release all the nodes
// from the heap.
//
// Input:
//       void
// Output:
//       Nothing
// =============================================================================
template <class ItemType>
CBST<ItemType>::~CBST()
{
    Clear();
}

// ==== CBST<ItemType>::Add ====================================================
//
// This function adds an item to a tree.  Calls the PlaceNode function to add
// the node to the tree to make sure it is balanced using AVL.
//
// Input:
//       newEntry   [IN]    - A const ItemType reference to the new entry to be
//                              added to the tree.
// Output:
//       Returns true if successful, otherwise false.
// =============================================================================
template <class ItemType>
bool CBST<ItemType>::Add(const ItemType &newEntry)
{
    if (this->Contains(newEntry))
    {
        std::cout << "Denied attempt to add duplicate" << std::endl;
        return false;
    }
    CBinaryNode<ItemType> *newNodePtr = new CBinaryNode<ItemType>(newEntry);
    this->SetRootPtr(PlaceNode(this->GetRootPtr(), newNodePtr));

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
        DestroyTree(this->GetRootPtr());
        this->SetRootPtr(CopyTree(rhs.GetRootPtr()));
    }
    return *this;
}

// ==== CBST<ItemType>::PlaceNode ==============================================
//
// This function adds a node in the tree. It makes sure that the same node value
// is not added twice in its predecessor Add function. Furthermore, as soon as
// it adds a node, it makes sure the tree is still AVL balanced.
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
// ============================================================================
template <class ItemType>
CBinaryNode<ItemType> *CBST<ItemType>::
    PlaceNode(CBinaryNode<ItemType> *subTreePtr, CBinaryNode<ItemType> *newNode)
{
    if (subTreePtr == nullptr)
    {
        return newNode;
    }
    else if (subTreePtr->GetItem() > newNode->GetItem())
    {
        CBinaryNode<ItemType> *tempPtr =
            PlaceNode(subTreePtr->GetLeftChildPtr(), newNode);
        subTreePtr->SetLeftChildPtr(tempPtr);

        if (GetHeightHelper(subTreePtr->GetLeftChildPtr()) -
                GetHeightHelper(subTreePtr->GetRightChildPtr()) >
            1)
        {
            if (newNode->GetItem() < subTreePtr->GetLeftChildPtr()->GetItem())
            { // Single right rotation
                subTreePtr = RightRotate(subTreePtr);
            }
            else
            { // Left-Right rotation
                subTreePtr = LeftRightRotate(subTreePtr);
            }
        }
    }
    else
    {
        CBinaryNode<ItemType> *tempPtr =
            PlaceNode(subTreePtr->GetRightChildPtr(), newNode);
        subTreePtr->SetRightChildPtr(tempPtr);

        if (this->GetHeightHelper(subTreePtr->GetLeftChildPtr()) -
                GetHeightHelper(subTreePtr->GetRightChildPtr()) <
            -1)
        {
            if (newNode->GetItem() > subTreePtr->GetRightChildPtr()->GetItem())
            { // Single left rotation
                subTreePtr = LeftRotate(subTreePtr);
            }
            else
            { // Right-Left rotation
                subTreePtr = RightLeftRotate(subTreePtr);
            }
        }
    }
    return subTreePtr;
}

// ==== CBST<ItemType>::LeftRotate ============================================
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
// ============================================================================
template <class ItemType>
CBinaryNode<ItemType> *CBST<ItemType>::
    LeftRotate(CBinaryNode<ItemType> *subTreePtr)
{
    CBinaryNode<ItemType> *ptr_A = subTreePtr->GetRightChildPtr();
    CBinaryNode<ItemType> *ptr_B = ptr_A->GetLeftChildPtr();
    ptr_A->SetLeftChildPtr(subTreePtr);
    subTreePtr->SetRightChildPtr(ptr_B);

    return ptr_A;
}

// ==== CBST<ItemType>::RightRotate ===========================================
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
// ============================================================================
template <class ItemType>
CBinaryNode<ItemType> *CBST<ItemType>::
    RightRotate(CBinaryNode<ItemType> *subTreePtr)
{
    CBinaryNode<ItemType> *ptr_A = subTreePtr->GetLeftChildPtr();
    CBinaryNode<ItemType> *ptr_B = ptr_A->GetRightChildPtr();
    ptr_A->SetRightChildPtr(subTreePtr);
    subTreePtr->SetLeftChildPtr(ptr_B);

    return ptr_A;
}

// ==== CBST<ItemType>::LeftRightRotate =======================================
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
// ============================================================================
template <class ItemType>
CBinaryNode<ItemType> *CBST<ItemType>::
    LeftRightRotate(CBinaryNode<ItemType> *subTreePtr)
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
CBinaryNode<ItemType> *CBST<ItemType>::
    RightLeftRotate(CBinaryNode<ItemType> *subTreePtr)
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
CBinaryNode<ItemType> *CBST<ItemType>::
    FindNode(CBinaryNode<ItemType> *treePtr, const ItemType &target,
             bool &success) const
{
    if (treePtr == nullptr)
    {
        success = false;
        return nullptr;
    }

    if (target == treePtr->GetItem())
    { // Node found
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

// ==== CBST<ItemType>::RemoveValueHelper =====================================
//
// This function removes a node from the tree while maintaining AVL balance.
// Covers leaf nodes, and nodes that have only one child.
// Calls RVH_2Children for nodes that have two children.
//
// Input:
//      nodePtr     [IN]    - A CBinaryNode pointer to the node to remove.
//
// Output:
//      An updated CBinaryNode<ItemType> templated pointer that is the new
//          "nodePtr" after the removal.
//
// ============================================================================
template <class ItemType>
CBinaryNode<ItemType> *CBST<ItemType>::
    RemoveValueHelper(CBinaryNode<ItemType> *nodePtr)
{
    if (nodePtr->IsLeaf()) // Node is a leaf (no children).
    {
        if (nodePtr != nullptr)
        {
            delete nodePtr;
            nodePtr = nullptr;
            return nodePtr;
        }
    }
    else if (nodePtr->GetLeftChildPtr() == nullptr) // Only a right child.
    {
        CBinaryNode<ItemType> *nodeToConnectPtr = nodePtr->GetRightChildPtr();
        if (nodePtr != nullptr)
        {
            delete nodePtr;
            nodePtr = nullptr;
            return nodeToConnectPtr;
        }
    }
    else if (nodePtr->GetRightChildPtr() == nullptr) // Only a left child.
    {
        CBinaryNode<ItemType> *nodeToConnectPtr = nodePtr->GetLeftChildPtr();
        if (nodePtr != nullptr)
        {
            delete nodePtr;
            nodePtr = nullptr;
            return nodeToConnectPtr;
        }
    }
    else // Node has two children. Call RVH_2Children
    {
        ItemType newNodeValue;
        CBinaryNode<ItemType> *tempPtr =
            RVH_2Children(nodePtr->GetRightChildPtr(), newNodeValue);
        nodePtr->SetRightChildPtr(tempPtr);
        nodePtr->SetItem(newNodeValue);
        return nodePtr;
    }
}

// ==== CBST<ItemType>::RVH_2Children =========================================
//
// This function covers cases where the removed node has two children.
//
// Input:
//      nodePtr      [IN]    - A CBinaryNode pointer to the node from which
//                                      to remove the leftmost node.
//      successor    [OUT]   - Reference to an ItemType object to store
//                                      the value of the inorder successor.
// Output:
//      A pointer that is the new "nodePtr" after the removal is finished.
//
// ============================================================================
template <class ItemType>
CBinaryNode<ItemType> *CBST<ItemType>::
    RVH_2Children(CBinaryNode<ItemType> *nodePtr, ItemType &successor)
{
    if (nodePtr->GetLeftChildPtr() == nullptr)
    {
        successor = nodePtr->GetItem();
        return RemoveValueHelper(nodePtr);
    }
    else
    {
        CBinaryNode<ItemType> *tempPtr =
            RVH_2Children(nodePtr->GetLeftChildPtr(), successor);
        nodePtr->SetLeftChildPtr(tempPtr);
        return nodePtr;
    }
}

// ==== CBST<ItemType>::RemoveValue ===========================================
// This function removes a value from the tree.  It also keeps the tree AVL
// balanced after each removal. Uses RemoveValueHelper for leaf nodes or nodes
// that have a single child. RemoveValueHelper calls RVH_2Children for nodes
// that have two children. The actual removal is performed in RemoveValueHelper
//
// Input:
//      subTreePtr  [IN]    - A CBinaryNode pointer to start the
//                              search of the node to remove.
//      target      [IN]    - A const ItemType value to remove from
//                              the tree.
//      success     [OUT]   - A bool value that is marked true if sucessful,
//                              false otherwise.
// Output:
//       An updated CBinaryNode<ItemType> templated pointer that is the new
//          "subTreePtr" after the removal.
// ============================================================================
template <class ItemType>
CBinaryNode<ItemType> *CBST<ItemType>::
    RemoveValue(CBinaryNode<ItemType> *subTreePtr, const ItemType &target,
                bool &success)
{
    if (subTreePtr == nullptr)
    {
        success = false;
        return nullptr;
    }
    else if (target < subTreePtr->GetItem()) // Target is in left subtree
    {
        /*  Recursively call RemoveValue on the left child of the current node
            and update the left child pointer with the result.
            Then check if the difference in height between the right child and
            left child of the current node is greater than 1.
            The choice of rotation (left or right-left rotation)
            depends on the relative heights of the
            right-right child and right-left child.*/
        CBinaryNode<ItemType> *tempPtr =
            RemoveValue(subTreePtr->GetLeftChildPtr(), target, success);
        subTreePtr->SetLeftChildPtr(tempPtr);

        if (GetHeightHelper(subTreePtr->GetRightChildPtr()) -
                GetHeightHelper(subTreePtr->GetLeftChildPtr()) >
            1)
        {
            int RRHeight =
                GetHeightHelper(subTreePtr->GetRightChildPtr()->GetRightChildPtr());
            int RLHeight =
                GetHeightHelper(subTreePtr->GetRightChildPtr()->GetLeftChildPtr());

            if (RRHeight >= RLHeight)
                subTreePtr = LeftRotate(subTreePtr);
            else
                subTreePtr = RightLeftRotate(subTreePtr);
        }
    }
    else if (target > subTreePtr->GetItem()) // Target in right subtree
    {
        /*  Inverse of "Target is in left subtree" case. Right or left-right
            rotation depends on the relative heights of the
            left-left child and left-right child.*/
        CBinaryNode<ItemType> *tempPtr =
            RemoveValue(subTreePtr->GetRightChildPtr(), target, success);
        subTreePtr->SetRightChildPtr(tempPtr);
        if (GetHeightHelper(subTreePtr->GetLeftChildPtr()) -
                GetHeightHelper(subTreePtr->GetRightChildPtr()) >
            1)
        {
            if (GetHeightHelper(subTreePtr->GetLeftChildPtr()->GetLeftChildPtr()) >=
                GetHeightHelper(subTreePtr->GetLeftChildPtr()->GetRightChildPtr()))
                subTreePtr = RightRotate(subTreePtr);
            else
                subTreePtr = LeftRightRotate(subTreePtr);
        }
    }
    else // Target is found. Call RemoveValueHelper to remove the node.
    {
        subTreePtr = RemoveValueHelper(subTreePtr);
        success = true;
    }

    return subTreePtr;
}

// ==== CBST<ItemType>::Remove =================================================
// This function removes an entry (a node), if it exists, from the tree.
//
// Input:
//       anEntry    [IN]    - A const ItemType reference to the new entry to be
//                              REMOVED FROM the tree.
// Output:
//       Returns true if successful, otherwise false.
// =============================================================================
template <class ItemType>
bool CBST<ItemType>::Remove(const ItemType &anEntry)
{
    bool success = false;

    if (Contains(anEntry))
    {
        SetRootPtr(RemoveValue(GetRootPtr(), anEntry, success));
    }
    else
    {
        std::cout << "Entry does not exist in the tree." << std::endl;
    }

    return success;
}