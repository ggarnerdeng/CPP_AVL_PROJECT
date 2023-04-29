/*=============================================================================
Driver.cpp
===============================================================================
Tests modules for AVL project.
=============================================================================*/

#include <iostream>
#include "CPersonInfo.h"
#include "PrecondViolatedExcept.h"
// #include "CBST.h"
// #include "CBinaryNode.h"
// #include "CBinaryNodeTree.h"
// #include "CBinaryTreeInterface.h"

using namespace std;

// SUCCESSFULLY TESTED:
void CPersonInfo_Test();
void PrecondViolatedExcept_Test();

// UNTESTED
void CBST_Test();
void CBinaryNode_Test();
void CBinaryNodeTree_Test();
void CBinaryTreeInterface_Test();

// HELPER FUNCTIONS
void Test_Exceptions(int value);

int main()
{
    CPersonInfo_Test();
    PrecondViolatedExcept_Test();
    CBST_Test();
    CBinaryNode_Test();
    CBinaryNodeTree_Test();
    CBinaryTreeInterface_Test();
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
void CBinaryNode_Test() {}
void CBinaryNodeTree_Test() {}
void CBinaryTreeInterface_Test() {}