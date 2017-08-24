#ifndef _PARSEXML_H__
#define _PARSEXML_H__

#include<iostream>
#include <map>
using namespace std;
class ParseXml
{
private:
    string file_name;
    map<string,string> m_map;
public:
    ParseXml(string path);
    ParseXml();
    void setXmlFile(string path);
    bool parse();
    string getValue(string name);//key value
    void setValue(string name,string value);
    void save();
};

#endif // _PARSEXML_H__
