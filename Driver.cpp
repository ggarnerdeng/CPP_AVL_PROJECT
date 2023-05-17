/*=============================================================================
Driver.cpp
===============================================================================
Tests modules for AVL project.

NOTES:
    4/28/2023: Successfully tested CPersonInfo and PrecondViolatedExcept.
=============================================================================*/

#include <iostream>
#include "CPersonInfo.h"
#include "PrecondViolatedExcept.h"
// #include "CBinaryTreeInterface.h"
#include "CBinaryNode.h"

// #include "CBST.h"
// #include "CBinaryNodeTree.h"

using namespace std;

// SUCCESSFULLY TESTED:
void CPersonInfo_Test();
void PrecondViolatedExcept_Test();
void CBinaryNode_Test();

// UNTESTED
// void CBST_Test();
// void CBinaryNodeTree_Test();
// void CBinaryTreeInterface_Test();

// HELPER FUNCTIONS
void Test_Exceptions(int value);

int main()
{
    CPersonInfo_Test();
    PrecondViolatedExcept_Test();
    // CBST_Test();
    CBinaryNode_Test();
#ifdef BINARYTREE
    CBinaryNodeTree_Test();
    CBinaryTreeInterface_Test();
#endif
    return 0;
}

void CPersonInfo_Test()
{
    // Test default constructor
    CPersonInfo person1;
    cout << "Default constructor:" << endl;
    cout << person1 << endl;

    // Test parameterized constructor
    CPersonInfo person2("John", "Doe", 30, 1000, 5000);
    cout << "Parameterized constructor:" << endl;
    cout << person2 << endl;

    // Test setters
    person1.SetFirstName("Jane");
    person1.SetLastName("Doe");
    person1.SetAge(25);
    person1.SetChecking(2000);
    person1.SetSavings(10000);
    cout << "Setters:" << endl;
    cout << person1 << endl;

    // Test getters
    cout << "Getters:" << endl;
    cout << "First name: " << person2.GetFirstName() << endl;
    cout << "Last name: " << person2.GetLastName() << endl;
    cout << "Age: " << person2.GetAge() << endl;
    cout << "Checking: " << person2.GetChecking() << endl;
    cout << "Savings: " << person2.GetSavings() << endl;

    // Test comparison operators
    cout << "Comparison operators:" << endl;
    if (person1 == person2)
        cout << "person1 is the same as person2" << endl;
    if (person1 > person2)
        cout << "person1 is older than person2" << endl;
    if (person1 < person2)
        cout << "person1 is younger than person2" << endl
             << endl;
}
void PrecondViolatedExcept_Test()
{
    try
    {
        Test_Exceptions(-1);
    }
    catch (PrecondViolatedExcept &e)
    {
        cout << "Caught an exception: " << e.GetMsg() << endl;
    }

    try
    {
        Test_Exceptions(1);
    }
    catch (PrecondViolatedExcept &e)
    {
        cout << "Caught an exception: " << e.GetMsg() << endl;
    }
}
void Test_Exceptions(int value)
{
    if (value < 0)
    {
        throw PrecondViolatedExcept("Value cannot be negative.");
    }
    else
    {
        cout << "Value is positive." << endl;
    }
}

void CBST_Test() {}
void CBinaryNode_Test()
{
    CBinaryNode<int> *node = new CBinaryNode<int>(10);

    // Test GetItem and SetItem functions
    node->SetItem(20);
    cout << "Item value: " << node->GetItem() << endl;

    // Test GetLeftChildPtr and SetLeftChildPtr functions
    CBinaryNode<int> *leftNode = new CBinaryNode<int>(5);
    node->SetLeftChildPtr(leftNode);
    cout << "Left child value: " << node->GetLeftChildPtr()->GetItem() << endl;

    // Test GetRightChildPtr and SetRightChildPtr functions
    CBinaryNode<int> *rightNode = new CBinaryNode<int>(15);
    node->SetRightChildPtr(rightNode);
    cout << "Right child value: " << node->GetRightChildPtr()->GetItem() << endl;

    // Test IsLeaf function
    cout << "Is leaf node: " << node->IsLeaf() << endl;

    // Clean up memory

    delete node;
    delete leftNode;
    delete rightNode;

    cout << "END NODE TEST" << endl;
}

#ifdef BINARYTREE
void CBinaryNodeTree_Test()
{
    // Test default constructor
    CBinaryNodeTree<int> tree1;
    std::cout << "tree1 created with default constructor.\n";

    // Test type constructor
    CBinaryNodeTree<int> tree2(5);
    std::cout << "tree2 created with type constructor. Root value: " << tree2.getRootData() << "\n";

    // Test copy constructor
    CBinaryNodeTree<int> tree3(tree2);
    std::cout << "tree3 created with copy constructor. Root value: " << tree3.getRootData() << "\n";

    // Test destructor
    tree1.add(1);
    tree1.add(2);
    tree1.add(3);
    std::cout << "tree1 before destruction:\n";
    tree1.displayInOrder();
    std::cout << "Destroying tree1...\n";
    tree1.~CBinaryNodeTree();
    std::cout << "tree1 after destruction:\n";
    tree1.displayInOrder();
}
void CBinaryTreeInterface_Test() {}
#endif