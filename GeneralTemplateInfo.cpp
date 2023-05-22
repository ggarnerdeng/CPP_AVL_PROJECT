#include "GeneralTemplateInfo.h"
#include <iomanip>

GeneralTemplateInfo::GeneralTemplateInfo()
{
}

GeneralTemplateInfo::GeneralTemplateInfo(const std::map<std::string, std::string>& attributes)
    : m_attributes(attributes)
{
}

void GeneralTemplateInfo::SetAttribute(const std::string& attributeName, const std::string& attributeValue)
{
    m_attributes[attributeName] = attributeValue;
}

std::string GeneralTemplateInfo::GetAttribute(const std::string& attributeName) const
{
    auto it = m_attributes.find(attributeName);
    if (it != m_attributes.end()) {
        return it->second;
    }
    return "";
}

bool GeneralTemplateInfo::operator==(const GeneralTemplateInfo& rhs) const
{
    return m_attributes == rhs.m_attributes;
}

bool GeneralTemplateInfo::operator>(const GeneralTemplateInfo& rhs) const
{
    auto lhsAgeStr = GetAttribute("Age");
    auto rhsAgeStr = rhs.GetAttribute("Age");

    if (!lhsAgeStr.empty() && !rhsAgeStr.empty()) {
        return lhsAgeStr > rhsAgeStr;
    }
    // Fallback to lexicographic comparison of other attributes if "Age" is not available
    return m_attributes > rhs.m_attributes;
}

bool GeneralTemplateInfo::operator<(const GeneralTemplateInfo& rhs) const
{
    auto lhsAgeStr = GetAttribute("Age");
    auto rhsAgeStr = rhs.GetAttribute("Age");

    if (!lhsAgeStr.empty() && !rhsAgeStr.empty()) {
        return lhsAgeStr < rhsAgeStr;
    }
    // Fallback to lexicographic comparison of other attributes if "Age" is not available
    return m_attributes < rhs.m_attributes;
}

std::istream& operator>>(std::istream& ins, GeneralTemplateInfo& person)
{
    std::map<std::string, std::string> attributes;
    std::string attributeName, attributeValue;

    while (ins >> attributeName >> attributeValue)
    {
        attributes[attributeName] = attributeValue;
    }

    person = GeneralTemplateInfo(attributes);
    return ins;
}

std::ostream& operator<<(std::ostream& outs, const GeneralTemplateInfo& person)
{
    for (const auto& attribute : person.m_attributes)
    {
        outs << std::left << std::setw(15) << attribute.first
             << std::right << std::setw(15) << attribute.second
             << "\n";
    }
    return outs;
}