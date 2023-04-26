// =============================================================================
// File: CBinaryNodeTree.tpp
// =============================================================================
// Implementation file for the class CBinaryNodeTree.tpp
// =============================================================================

#include <iostream>



// ==== CBinaryNodeTree<ItemType>::CBinaryNodeTree =============================
//
// This is the default constructor for CBinaryNodeTree.  It sets the root to
// nullptr.
//
// Input:
//       void
//       
// Output:
//       Nothing
//
// =============================================================================





// ==== CBinaryNodeTree<ItemType>::CBinaryNodeTree =============================
//
// This is the type constructor for CBinaryNodeTree.  It allocates a space for a
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





// ==== CBinaryNodeTree<ItemType>::CBinaryNodeTree =============================
//
// This is the type constructor for CBinaryNodeTree.  It allocates a space for a
// CBinaryNode and sets it equal to m_rootPtr.  The new node will have it's
// right and left child pointers set to rightTreePtr and leftTreePtr,
// respectively.
//
// Input:
//       rootItem      [IN]    - A const ItemType reference to initialize the
//                                  new node.
//       leftTreePtr   [IN]    - A const CBinaryNode<ItemType> pointer that
//                                  points to the left child.
//       rightTreePtr  [IN]    - A const CBinaryNode<ItemType> pointer that
//                                  points to the right child.
//       
// Output:
//       Nothing
//
// =============================================================================





// ==== CBinaryNodeTree<ItemType>::CBinaryNodeTree =============================
//
// This is the copy constructor for CBinaryNodeTree. It creates a deep copy of
// "tree."
//
// Input:
//       tree   [IN]    - A const templated CBinaryNodeTree that will be copied.
//       
// Output:
//       Nothing
//
// =============================================================================





// ==== CBinaryNodeTree<ItemType>::~CBinaryNodeTree ============================
//
// This is the destructor for CBinaryNodeTree.  It will release all the nodes
// from the heap.
//
// Input:
//       void
//       
// Output:
//       Nothing
//
// =============================================================================





// ==== CBinaryNodeTree<ItemType>::IsEmpty =====================================
//
// This function checks if the tree is empty or not.
//
// Input:
//       void
//
// Output:
//       Returns true if the tree is empty, otherwise false.
//
// =============================================================================





// ==== CBinaryNodeTree<ItemType>::GetHeight ===================================
//
// This function returns the height of the tree.  It calls the protected member
// function GetHeightHelper to get the height from the root of the tree.
//
// Input:
//       void
//
// Output:
//       Returns an integer for the height of the tree.
//
// =============================================================================





// ==== CBinaryNodeTree<ItemType>::GetNumberOfNodes ============================
//
// This function returns the number of nodes in the tree.  It calls the
// protected member function GetNumberOfNodesHelper to get the number of nodes
// from the root of the tree.
//
// Input:
//       void
//
// Output:
//       Returns an integer for the number of nodes in the tree.
//
// =============================================================================





// ==== CBinaryNodeTree<ItemType>::GetRootData =================================
//
// This function returns the data item in the root of the tree.
//
// Throws a PrecondViolatedExcept if the root of the tree is empty (nullptr).
//
// Input:
//       void
//
// Output:
//       Returns an ItemType, which is the item in the root of the tree.
//
// =============================================================================





// ==== CBinaryNodeTree<ItemType>::SetRootData =================================
//
// This function sets the data item in the root of the tree.
//
// Input:
//       newData    [IN]    - A const ItemType reference that has the new data
//                              value.
//       
// Output:
//       void
//
// =============================================================================






// ==== CBinaryNodeTree<ItemType>::Clear =======================================
//
// This function removes all nodes from the heap and sets the root pointer to
// nullptr.  To make things easier, this function can call the member function
// DestroyTree.
//
// Input:
//       void
//       
// Output:
//       void
//
// =============================================================================





// ==== CBinaryNodeTree<ItemType>::Contains ====================================
//
// This function checks if a particular entry exists in the tree.
//
// Input:
//       anEntry    [IN]    - A const ItemType reference to check of its
//                              existence.
//
// Output:
//       Returns true if the entry is already in the tree, false otherwise.
//
// =============================================================================





// ==== CBinaryNodeTree<ItemType>::PreorderTraverse ============================
//
// This function traverses in pre-order by calling the protected member function
// Preorder.
//
// Input:
//       void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
//
// Output:
//       void
//
// =============================================================================





// ==== CBinaryNodeTree<ItemType>::InorderTraverse =============================
//
// This function traverses in in-order by calling the protected member function
// Inorder.
//
// Input:
//       void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
// Output:
//       void
//
// =============================================================================





// ==== CBinaryNodeTree<ItemType>::PostorderTraverse ===========================
//
// This function traverses in post-order by calling the protected member
// function Postorder.
//
// Input:
//       void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
// Output:
//       void
//
// =============================================================================





// ==== CBinaryNodeTree<ItemType>::LevelorderTraverse ==========================
//
// This function traverses in level-order by calling the protected member
// function Levelorder for each level to process.
//
// Input:
//       void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
// Output:
//       void
//
// =============================================================================





// ==== CBinaryNodeTree<ItemType>::operator= ==================================
//
// This function assigns the right-hand side CBinaryNodeTree to the left-hand
// side CBinaryNodeTree.  Make sure to protect against assignment to self!
//
// Input:
//       rhs    [IN]    - A const templated CBinaryNodeTree to copy from.
//
// Output:
//       A templated CBinaryNodeTree reference object (the left-hand side of the
//          tree.
//
// =============================================================================





// ==== CBinaryNodeTree<ItemType>::GetRootPtr ==================================
//
// This function returns m_rootPtr
//
// Input:
//       Nothing
//
// Output:
//       A CBinaryNode<ItemType> templated pointer that is the address of the
//          root pointer.
//
// =============================================================================





// ==== CBinaryNodeTree<ItemType>::SetRootPtr ==================================
//
// This function sets m_rootPtr
//
// Input:
//       rootPtr    [IN]    - A CBinaryNode<ItemType> pointer.
// Output:
//       Nothing
//
// =============================================================================





// ==== CBinaryNodeTree<ItemType>::GetParentNode ===============================
//
// This function searches for the parent node of any node in the tree.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to start the
//                              search of the parent node.
//      nodePtr     [IN]    - A templated CBinaryNode pointer to find the parent
//                              of.
//
// Output:
//       A CBinaryNode<ItemType> templated pointer that is the address of the
//          parent node pointer.
//
// =============================================================================





// ==== CBinaryNodeTree<ItemType>::GetHeightHelper =============================
//
// This function finds the height starting at subTreePtr (this could be root or
// any other node within the tree).
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to find the height
//                              from.
//
// Output:
//       An int that is the height from subTreePtr.
//
// =============================================================================





// ==== CBinaryNodeTree<ItemType>::GetNumberOfNodesHelper ======================
//
// This function finds the number of nodes starting at subTreePtr (this could be
// root or any other node within the tree).
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to find the number
//                              of nodes from.
//
// Output:
//       An int that represents the number of nodes from subTreePtr.
//
// =============================================================================





// ==== CBinaryNodeTree<ItemType>::FindMinNode =================================
//
// This function finds the minimum ItemType Node in the tree starting from
// subTreePtr. If there is no minimum ItemType Node found, the function returns
// nullptr.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to find the
//                              minimum node from.
//
// Output:
//       A templated CBinaryNode<ItemType> pointer that points to the minimum
//          node.
//
// =============================================================================





// ==== CBinaryNodeTree<ItemType>::FindMaxNode =================================
//
// This function finds the maximum ItemType Node in the tree starting from
// subTreePtr. If there is no maximum ItemType Node found, the function returns
// nullptr.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to find the
//                              maximum node from.
//
// Output:
//       A templated CBinaryNode<ItemType> pointer that points to the maximum
//          node.
//
// =============================================================================





// ==== CBinaryNodeTree<ItemType>::CopyTree ====================================
//
// This function copies a tree using a deep copy.
//
// Input:
//      oldTreeRootPtr  [IN]    - A templated CBinaryNode pointer to copy from.
//
// Output:
//       A templated CBinaryNode<ItemType> pointer that points to the new root.
//
// =============================================================================





// ==== CBinaryNodeTree<ItemType>::DestroyTree =================================
//
// This function destroys a tree.  In other words, it releases the memory from
// the heap.
//
// Input:
//       CBinaryNode<ItemType> *subTreePtr [IN/OUT] - The tree to destroy.
//       
// Output:
//       void
//
// =============================================================================





// ==== CBinaryNodeTree<ItemType>::Preorder ====================================
//
// This function traverses the tree in pre-order.
//
// Input:
//      void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
//      treePtr                    [IN]    - The tree to process.
//
// Output:
//       void
//
// =============================================================================





// ==== CBinaryNodeTree<ItemType>::Inorder ====================================
//
// This function traverses the tree in in-order.
//
// Input:
//      void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
//      treePtr                    [IN]    - The tree to process.
//
// Output:
//       void
//
// =============================================================================





// ==== CBinaryNodeTree<ItemType>::Postorder ===================================
//
// This function traverses the tree in post-order.
//
// Input:
//      void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
//      treePtr                    [IN]    - The tree to process.
//
// Output:
//       void
//
// =============================================================================





// ==== CBinaryNodeTree<ItemType>::Levelorder ==================================
//
// This function traverses the tree in level-order.
//
// Input:
//      void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
//      treePtr                    [IN]    - The tree to process.
//		level                      [IN]    - The height of the tree (total
//                                              levels to process).
//
// Output:
//       void
//
// =============================================================================


