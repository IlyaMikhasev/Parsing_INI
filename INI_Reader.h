#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <map>
#include <list>
#include "IReader.h"
class INI_Reader: public IReader{
public:
	void Reader(const std::string& name_file) override;
	const std::string SearchKeyToHeader(const std::string& key);
	bool SearchSector(const std::string& header)const override;
	bool SearchKey(const std::string& key)const override;
	bool SearchVariable(const std::string& var)const override;
	const std::string SearchVarToHeader(const std::string& head, const std::string& key);
	void Replacement(const std::string& head, const std::string& key, const std::string& var)override;
	const std::string GetFile()const override;
private:
	std::unordered_map<std::string, std::vector<std::pair<std::string, std::string>>> _section;	
	std::string _head;
};

