#ifndef GENERAL_TEMPLATE_INFO_H
#define GENERAL_TEMPLATE_INFO_H

#include <string>
#include <map>
#include <iostream>

class GeneralTemplateInfo
{
public:
    GeneralTemplateInfo();
    GeneralTemplateInfo(const std::map<std::string, std::string>& attributes);

    void SetAttribute(const std::string& attributeName, const std::string& attributeValue);
    std::string GetAttribute(const std::string& attributeName) const;

    bool operator==(const GeneralTemplateInfo& rhs) const;
    bool operator>(const GeneralTemplateInfo& rhs) const;
    bool operator<(const GeneralTemplateInfo& rhs) const;

    friend std::istream& operator>>(std::istream& ins, GeneralTemplateInfo& person);
    friend std::ostream& operator<<(std::ostream& outs, const GeneralTemplateInfo& person);

private:
    std::map<std::string, std::string> m_attributes;
};

#endif