#pragma once
#include <iostream>
#include "INI_Reader.h"
class Program_reader
{
public:
	Program_reader(const std::string& path);
	void StartRead(std::shared_ptr<INI_Reader>& obj);
	void Work(std::shared_ptr<INI_Reader>& obj);
	void SaveFile(const std::string& newPath,const std::string& file);
private:
	std::string _path;
};

