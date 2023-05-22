// ============================================================================
// File: main.cpp
// ============================================================================
// Programmer: Garner Deng
// Date: 4/26/23
// Class: CSCI 133 ("Data Structures Using C++")
// Time: ONLINE
// Instructor: Dr. Rodriguez
// Project: Project CBST
//
// Description:
//  This program works with the ADT CBST.  It allows the user to remove
//  and insert items (nodes) in the tree and keep it balanced using AVL.
// ============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "CBST.h"

#include "CPersonInfo.h"
#include "CPokemonInfo.h"
#include "GeneralTemplateInfo.h"

using namespace std;

// global constants
const int MAX_ITEMS = 151;

// function prototype
template <typename P>
void Visit(const P &item);

// ==== main ==================================================================
//
// ============================================================================

// Preprocessor Directives:
//#define txtName "PersonBankInfo.txt" // Text file to analyze/organize
//#define GeneralTemplateInfo CPersonInfo

#define txtName "151pokemon.txt" // Text file to analyze/organize
#define GeneralTemplateInfo CPokemonInfo
//#define DEBUG                        // DEBUG flag

int main()
{
    CBST<GeneralTemplateInfo> treeList;    // create a tree list
    GeneralTemplateInfo people[MAX_ITEMS]; // allocate an array of 

    ifstream inFile(txtName);

    char header[256];
    int index;

    if (inFile.fail())
    {
        cerr << "Error opening " << txtName << " ...\n\n";
        exit(EXIT_FAILURE);
    }

    // Get rid of the header in the file ("First", "Last", ... , "Savings")
    inFile.getline(header, 256);

    // Read all the items in the file and store in a CPersonInfo array
    for (index = 0; index < MAX_ITEMS; ++index)
    {
        inFile >> people[index]; // usage of overloaded stream operator
    }
    // Add 20 items (CPersonInfo) to the treeList and remove them to test it.
    cout << "\n\nAdding First 151 items\n\n";
    for (index = 0; index < 151; ++index)
    {
        treeList.Add(people[index]);
    }

    // Display the treeList in inorder
    cout << "\n\nDisplaying treeList in in-order\n\n";
    treeList.InorderTraverse(Visit);
    cout << endl;

#ifdef DEBUG
    CBST<CPersonInfo> treeList;    // create a tree list
    CPersonInfo people[MAX_ITEMS]; // allocate an array of CPersonInfo
    ifstream inFile(txtName);

    char header[256];
    int index;

    if (inFile.fail())
    {
        cerr << "Error opening " << txtName << " ...\n\n";
        exit(EXIT_FAILURE);
    }

    // Get rid of the header in the file ("First", "Last", ... , "Savings")
    inFile.getline(header, 256);

    // Read all the items in the file and store in a CPersonInfo array
    for (index = 0; index < MAX_ITEMS; ++index)
    {
        inFile >> people[index]; // usage of overloaded stream operator
    }

    // Add 20 items (CPersonInfo) to the treeList and remove them to test it.
    cout << "\n\nAdding First 20 items\n\n";
    for (index = 0; index < 20; ++index)
    {
        treeList.Add(people[index]);
    }

    // Display the treeList in pre-order
    cout << "\n\nDisplaying treeList in pre-order\n\n";
    treeList.PreorderTraverse(Visit);
    cout << endl;

    // Display the treeList in post-order
    cout << "\n\nDisplaying treeList in post-order\n\n";
    treeList.PostorderTraverse(Visit);
    cout << endl;

    // Display the treeList in inorder
    cout << "\n\nDisplaying treeList in in-order\n\n";
    treeList.InorderTraverse(Visit);
    cout << endl;

    // Display the treeList in level-order
    cout << "\n\nDisplaying treeList in level-order\n\n";
    treeList.LevelorderTraverse(Visit);
    cout << endl;

    // Remove the first 10 items
    cout << "\n\nRemoving first 10 items.\n\n";
    for (index = 0; index < 10; ++index)
    {
        treeList.Remove(people[index]);
    }
    cout << "\n\nFinished Removal.\n\n";

    // Add 10 more items (CPersonInfo) to the treeList
    cout << "\n\nAdding last 10 items.\n\n";
    for (index = 20; index < MAX_ITEMS; ++index)
    {
        treeList.Add(people[index]);
    }

    // Create more CBST objects to test the type and copy CTORs
    CBST<CPersonInfo> treeList2(treeList);  // Copy CTOR
    CBST<CPersonInfo> treeList3(people[0]); // Type CTOR

    // Check for assignment to self.
    treeList2 = treeList2;

    // Test the overloaded assignment operator
    treeList3 = treeList2;

    // Display the treeList3 in pre-order
    cout << "\n\nDisplaying treeList3 in pre-order\n\n";
    treeList3.PreorderTraverse(Visit);
    cout << endl;

    // Display the treeList3 in post-order
    cout << "\n\nDisplaying treeList3 in post-order\n\n";
    treeList3.PostorderTraverse(Visit);
    cout << endl;

    // Display the treeList3 in inorder
    cout << "\n\nDisplaying treeList3 in in-order\n\n";
    treeList3.InorderTraverse(Visit);
    cout << endl;

    // Display the treeList3 in level-order
    cout << "\n\nDisplaying treeList3 in level-order\n\n";
    treeList3.LevelorderTraverse(Visit);
    cout << endl;
#endif
    return 0;

} // end of "main"

// ==== Visit ================================================================
//
// This function displays an object of type T using the overloaded stream operator.
//
// Input:
//      item [in]   -- A pass by reference object of type T.
//
// Output:
//      void
//
// ============================================================================
template <typename P>
void Visit(const P &item)
{
    std::cout << item << std::endl; // usage of overloaded stream operator
}