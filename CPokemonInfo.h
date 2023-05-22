// ============================================================================
// File: CPokemonInfo.h
// ============================================================================
// Header file for the class CPokemonInfo
// ============================================================================
// Programmer: Garner Deng
// Date: 4/29/23

#ifndef CPOKEMONINFO_H
#define CPOKEMONINFO_H

#include <string>

class CPokemonInfo
{
public:
    CPokemonInfo();
    CPokemonInfo(int id, const std::string& name);

    void SetID(int id);
    void SetName(const std::string& name);

    int GetID() const;
    std::string GetName() const;

    friend std::istream& operator>>(std::istream& ins, CPokemonInfo& pokemon);
    friend std::ostream& operator<<(std::ostream& outs, const CPokemonInfo& pokemon);

private:
    int m_id;
    std::string m_name;
};

#endif // CPOKEMONINFO_H