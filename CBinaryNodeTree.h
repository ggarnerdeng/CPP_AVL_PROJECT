// ============================================================================
// File: CBinaryNodeTree.h
// ============================================================================
// Header file for the class CBinaryNodeTree
// ============================================================================

#ifndef CBINARYNODETREE_HEADER
#define CBINARYNODETREE_HEADER

#include "CBinaryTreeInterface.h"
#include "CBinaryNode.h"
#include "PrecondViolatedExcept.h"

template <class ItemType>
class CBinaryNodeTree : public CBinaryTreeInterface<ItemType>
{
public:
    // =========================================================================
    //      Constructors and Destructor
    // =========================================================================

  
    CBinaryNodeTree();

    CBinaryNodeTree(const ItemType &rootItem);

    
    CBinaryNodeTree(const ItemType &rootItem,
                    const CBinaryNodeTree<ItemType> *leftTreePtr,
                    const CBinaryNodeTree<ItemType> *rightTreePtr);

    
    CBinaryNodeTree(const CBinaryNodeTree<ItemType> &tree);

    virtual ~CBinaryNodeTree();

    // =========================================================================
    //      Member Functions
    // =========================================================================


    virtual bool IsEmpty() const;
    virtual int GetHeight() const;
    virtual int GetNumberOfNodes() const;
    virtual ItemType GetRootData() const throw(PrecondViolatedExcept);
    virtual void SetRootData(const ItemType &newData);
    virtual bool Add(const ItemType &newData)= 0;
    virtual bool Remove(const ItemType &data)= 0;
    virtual void Clear();
    virtual bool Contains(const ItemType &anEntry) const;
    virtual void PreorderTraverse(void Visit(const ItemType &item)) const;
    virtual void InorderTraverse(void Visit(const ItemType &item)) const;
    virtual void PostorderTraverse(void Visit(const ItemType &item)) const;
    virtual void LevelorderTraverse(void Visit(const ItemType &item)) const;
    CBinaryNodeTree<ItemType> &operator=(const CBinaryNodeTree<ItemType> &rhs);

protected:
    // =========================================================================
    //      Protected Member Functions
    // =========================================================================
    CBinaryNode<ItemType> *GetRootPtr() const;
    void SetRootPtr(CBinaryNode<ItemType> *rootPtr);
    CBinaryNode<ItemType> *GetParentNode(CBinaryNode<ItemType> *subTreePtr,
                                         CBinaryNode<ItemType> *nodePtr) const;
    int GetHeightHelper(CBinaryNode<ItemType> *subTreePtr) const;
    int GetNumberOfNodesHelper(CBinaryNode<ItemType> *subTreePtr) const;
    CBinaryNode<ItemType> *FindMinNode(CBinaryNode<ItemType> *subTreePtr);
    CBinaryNode<ItemType> *FindMaxNode(CBinaryNode<ItemType> *subTreePtr);
    virtual CBinaryNode<ItemType> *RemoveValue(CBinaryNode<ItemType> *subTreePtr,
                                               const ItemType &target, bool &success) = 0;
    virtual CBinaryNode<ItemType> *FindNode(CBinaryNode<ItemType> *treePtr,
                                            const ItemType &target,
                                            bool &success) const = 0;
    
    CBinaryNode<ItemType> *CopyTree(const CBinaryNode<ItemType> *oldTreeRootPtr)
        const;
    void DestroyTree(CBinaryNode<ItemType> *subTreePtr);
    
    void Preorder(void Visit(const ItemType &item),
                  CBinaryNode<ItemType> *treePtr) const;
    void Inorder(void Visit(const ItemType &item),
                 CBinaryNode<ItemType> *treePtr) const;
    void Postorder(void Visit(const ItemType &item),
                   CBinaryNode<ItemType> *treePtr) const;
    void Levelorder(void Visit(const ItemType &item),
                    CBinaryNode<ItemType> *treePtr,
                    int level) const;
    

private:
    // =========================================================================
    //      Data Member
    // =========================================================================

    CBinaryNode<ItemType> *m_rootPtr;
};

#include "CBinaryNodeTree.tpp"

#endif // CBINARYNODETREE_HEADER
