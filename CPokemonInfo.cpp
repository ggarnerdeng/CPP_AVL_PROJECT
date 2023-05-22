// ============================================================================
// File: CPokemonInfo.cpp
// ============================================================================
// Implementation file for the class CPokemonInfo
// ============================================================================
// Programmer: Garner Deng
// Date: 4/29/23

#include <iostream>
#include <string>
#include <iomanip>
#include "CPokemonInfo.h"

using namespace std;

// ==== CPokemonInfo::CPokemonInfo =============================================
//
// This is the CPokemonInfo constructor. It sets the ID and Name to default
// values.
//
// Input:
//       void
//
// Output:
//       Nothing
//
// =============================================================================
CPokemonInfo::CPokemonInfo()
{
    m_id = 0;
    m_name = "";
}

// ==== CPokemonInfo::CPokemonInfo =============================================
//
// This is the CPokemonInfo constructor. It initializes the private data members
// to the arguments passed.
//
// Input:
//       id        [IN]    - An int for the Pokémon's ID.
//       name      [IN]    - A string for the Pokémon's name.
//
// Output:
//       void
//
// =============================================================================
CPokemonInfo::CPokemonInfo(int id, const string& name)
{
    m_id = id;
    m_name = name;
}

// ==== CPokemonInfo::SetID ====================================================
//
// This function assigns the ID to m_id.
//
// Input:
//       id        [IN]    - An int for the Pokémon's ID.
//
// Output:
//       void
//
// =============================================================================
void CPokemonInfo::SetID(int id)
{
    m_id = id;
}

// ==== CPokemonInfo::SetName ==================================================
//
// This function assigns the name to m_name.
//
// Input:
//       name      [IN]    - A string for the Pokémon's name.
//
// Output:
//       void
//
// =============================================================================
void CPokemonInfo::SetName(const string& name)
{
    m_name = name;
}

// ==== CPokemonInfo::GetID ====================================================
//
// This function returns the Pokémon's ID.
//
// Input:
//       void
//
// Output:
//       An int that represents the Pokémon's ID.
//
// =============================================================================
int CPokemonInfo::GetID() const
{
    return m_id;
}

// ==== CPokemonInfo::GetName ==================================================
//
// This function returns the Pokémon's name.
//
// Input:
//       void
//
// Output:
//       A string that represents the Pokémon's name.
//
// =============================================================================
string CPokemonInfo::GetName() const
{
    return m_name;
}

// ==== operator>> =============================================================
//
// The function overloads the extraction operator. Its objective is to read the
// ID and name of a Pokémon from the object ins.
//
// Input:
//       ins      [IN]    - An istream reference to read from.
//       pokemon  [IN/OUT] - A CPokemonInfo reference object to store what is
//                          read from ins.
//
// Output:
//       An istream reference.
//
// =============================================================================
istream& operator>>(istream& ins, CPokemonInfo& pokemon)
{
    if (!(ins >> pokemon.m_id >> pokemon.m_name))
    {
        // Failed to read all the required fields
        ins.setstate(ios::failbit);
    }
    return ins;
}

// ==== operator<< =============================================================
//
// This is the overloaded insertion operator. Its objective is to nicely display
// the Pokémon's information to the object outs.
//
// Input:
//       outs     [IN]    - An ostream reference to display to.
//       pokemon  [IN/OUT] - A const CPokemonInfo reference object to display.
//
// Output:
//       An ostream reference.
//
// =============================================================================
ostream& operator<<(ostream& outs, const CPokemonInfo& pokemon)
{
    outs << setw(5) << pokemon.m_id << " | " << pokemon.m_name;
    return outs;
}