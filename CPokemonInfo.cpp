// CPokemonInfo.cpp
#include "CPokemonInfo.h"
#include <iomanip>

CPokemonInfo::CPokemonInfo() : m_id(0), m_name("") {}

CPokemonInfo::CPokemonInfo(int id, const std::string& name) : m_id(id), m_name(name) {}

void CPokemonInfo::SetId(int id) {
    m_id = id;
}

void CPokemonInfo::SetName(const std::string& name) {
    m_name = name;
}

int CPokemonInfo::GetId() const {
    return m_id;
}

std::string CPokemonInfo::GetName() const {
    return m_name;
}

bool CPokemonInfo::operator==(const CPokemonInfo& rhs) const {
    return (m_id == rhs.m_id) && (m_name == rhs.m_name);
}

bool CPokemonInfo::operator>(const CPokemonInfo& rhs) const {
    return m_id > rhs.m_id;
}

bool CPokemonInfo::operator<(const CPokemonInfo& rhs) const {
    return m_id < rhs.m_id;
}

std::istream& operator>>(std::istream& ins, CPokemonInfo& pokemon) {
    if (!(ins >> pokemon.m_id >> pokemon.m_name)) {
        // Failed to read the required fields
        return ins;
    }
    return ins;
}

std::ostream& operator<<(std::ostream& outs, const CPokemonInfo& pokemon) {
    outs << std::setw(5) << std::left << pokemon.m_id
         << std::setw(15) << std::left << pokemon.m_name << "\n";
    return outs;
}