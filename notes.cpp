/*
VIRTUAL FUNCTIONS
// ============================================================================
// CBinaryTreeInterface 13 + 1 destructor
// ============================================================================
   virtual bool IsEmpty() const = 0;
   virtual int GetHeight() const = 0;
   virtual int GetNumberOfNodes() const = 0;
   virtual ItemType GetRootData() const = 0;
   virtual void SetRootData(const ItemType& newData) = 0;
   virtual bool Add(const ItemType& newData) = 0;
   virtual bool Remove(const ItemType& data) = 0;
   virtual void Clear() = 0;
   virtual bool Contains(const ItemType& anEntry) const = 0;
   virtual void PreorderTraverse(void Visit(const ItemType &item)) const = 0;
   virtual void InorderTraverse(void Visit(const ItemType &item)) const = 0;
   virtual void PostorderTraverse(void Visit(const ItemType &item)) const = 0;
   virtual void LevelorderTraverse(void Visit(const ItemType &item)) const = 0;
   
   virtual ~CBinaryTreeInterface() {  }


// ============================================================================
// CBinaryNodeTree      15 + 1 destructor, last 2 are new
// ============================================================================
   virtual bool IsEmpty() const;
   virtual int GetHeight() const;
   virtual int GetNumberOfNodes() const;
   virtual ItemType GetRootData() const throw(PrecondViolatedExcept);
   virtual void SetRootData(const ItemType &newData);
   virtual bool Add(const ItemType &newData) = 0;
   virtual bool Remove(const ItemType &data) = 0;
   virtual void Clear();
   virtual bool Contains(const ItemType &anEntry) const;
   virtual void PreorderTraverse(void Visit(const ItemType &item)) const;
   virtual void InorderTraverse(void Visit(const ItemType &item)) const;
   virtual void PostorderTraverse(void Visit(const ItemType &item)) const;
   virtual void LevelorderTraverse(void Visit(const ItemType &item)) const;

   virtual CBinaryNode<ItemType> *RemoveValue(CBinaryNode<ItemType> *subTreePtr,
                                               const ItemType &target, bool &success) = 0;
   virtual CBinaryNode<ItemType> *FindNode(CBinaryNode<ItemType> *treePtr,
                                            const ItemType &target,
                                            bool &success) const = 0;
   virtual ~CBinaryNodeTree();

// ============================================================================
// CBST 4 + 1 destructor
// ============================================================================

   virtual bool Add(const ItemType &newEntry);
   virtual bool Remove(const ItemType &anEntry);

   virtual CBinaryNode<ItemType> *RemoveValue(CBinaryNode<ItemType> *subTreePtr,
                                               const ItemType &target, bool &success);
   virtual CBinaryNode<ItemType> *FindNode(CBinaryNode<ItemType> *treePtr,
                                            const ItemType &target,
                                            bool &success) const;
   virtual ~CBST();







                                            NON VIRTUAL


// ============================================================================
// CBinaryTreeInterface 
// ============================================================================
   ALL VIRTUAL?????????????
// ============================================================================
// CBinaryNodeTree      
// ============================================================================
   CBinaryNodeTree();
   CBinaryNodeTree(const ItemType &rootItem);
   CBinaryNodeTree(const ItemType &rootItem,
                    const CBinaryNodeTree<ItemType> *leftTreePtr,
                    const CBinaryNodeTree<ItemType> *rightTreePtr);
   CBinaryNodeTree(const CBinaryNodeTree<ItemType> &tree);

   CBinaryNode<ItemType> *GetRootPtr() const;
   void SetRootPtr(CBinaryNode<ItemType> *rootPtr);
   CBinaryNode<ItemType> *GetParentNode(CBinaryNode<ItemType> *subTreePtr,
                                         CBinaryNode<ItemType> *nodePtr) const;
   int GetHeightHelper(CBinaryNode<ItemType> *subTreePtr) const;
   int GetNumberOfNodesHelper(CBinaryNode<ItemType> *subTreePtr) const;
   CBinaryNode<ItemType> *FindMinNode(CBinaryNode<ItemType> *subTreePtr);
   CBinaryNode<ItemType> *FindMaxNode(CBinaryNode<ItemType> *subTreePtr);

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
// ============================================================================
// CBST
// ============================================================================

CBST();
CBST(const ItemType &rootItem);
CBST(const CBST<ItemType> &tree);
CBST<ItemType> &operator=(const CBST<ItemType> &rhs);
CBinaryNode<ItemType> *LeftRotate(CBinaryNode<ItemType> *subTreePtr);
CBinaryNode<ItemType> *RightRotate(CBinaryNode<ItemType> *subTreePtr);
CBinaryNode<ItemType> *LeftRightRotate(CBinaryNode<ItemType> *subTreePtr);
CBinaryNode<ItemType> *RightLeftRotate(CBinaryNode<ItemType> *subTreePtr);
CBinaryNode<ItemType> *PlaceNode(CBinaryNode<ItemType> *subTreePtr,
                                     CBinaryNode<ItemType> *newNode);





*/