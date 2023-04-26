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


