#include "parsexml.h"


ParseXml::ParseXml(string path)
{
	file_name = path;
}

ParseXml::ParseXml(){}

void ParseXml::setXmlFile(string path)
{
	file_name = path;
}

bool ParseXml::parse()
{
	fstream fout;
	fout.open(file_name);
	if(fout)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

string ParseXml::getValue(string name)
{

}

void ParseXml::setValue(string name,string value)
{

}

void ParseXml::save()
{

}
