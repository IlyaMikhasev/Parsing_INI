#pragma once
#include <string>
class IReader
{
public:
	virtual void Reader(const std::string& name_file)= 0;
	virtual const std::string GetFile()const = 0;	
	virtual bool SearchKey(const std::string& key)const = 0;
	virtual bool SearchVariable(const std::string& var)const = 0;
	virtual bool SearchSector(const std::string& header)const = 0;
	virtual void Replacement(const std::string& head, const std::string& key, const std::string& var) = 0;
	virtual ~IReader() {}
};
