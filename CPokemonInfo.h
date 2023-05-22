// CPokemonInfo.h
#ifndef CPOKEMONINFO_H
#define CPOKEMONINFO_H

#include <iostream>
#include <string>

class CPokemonInfo {
private:
    int m_id;
    std::string m_name;

public:
    CPokemonInfo();
    CPokemonInfo(int id, const std::string& name);

    void SetId(int id);
    void SetName(const std::string& name);

    int GetId() const;
    std::string GetName() const;

    bool operator==(const CPokemonInfo& rhs) const;
    bool operator>(const CPokemonInfo& rhs) const;
    bool operator<(const CPokemonInfo& rhs) const;

    friend std::istream& operator>>(std::istream& ins, CPokemonInfo& pokemon);
    friend std::ostream& operator<<(std::ostream& outs, const CPokemonInfo& pokemon);
};

#endif