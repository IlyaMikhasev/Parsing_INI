#include "INI_Reader.h"
#include <string>
void INI_Reader::Reader(const std::string& name_file){
	std::ifstream in;
	in.open(name_file);
	std::string str, head;
	std::vector<std::pair<std::string, std::string>> _key_vars;
	if (in.is_open()) {		
		while (getline(in,str)) {
			bool varKey = true;
			std::pair<std::string, std::string> keyVar ;
			if (str[0] == '[') {
				head = str.substr(1, str.find(']') - 1);
				if (head != _head ) {
					if (_head != "") {
						_section[_head] = _key_vars;
					}
					_head = head;
					_key_vars.clear();
				}
			}
			if (str[0] != ';' && str[0] != '#' && str[0] != '[' && str[0] != '\0') {
				for (int i = 0; i < str.size(); i++) {
					if (str[i] == '=') {
						varKey = false;
						continue;
					}
					if (varKey) {
						keyVar.first += str[i];
					}
					else {
						if (str[i] != ';' && str[i] != '#') {
							keyVar.second += str[i];
						}
						else
							break;
					}
				}
			_key_vars.push_back(keyVar);
			}
		}
		_section[_head] = _key_vars;
	}
	else
		throw "Error open file";
	in.close();	
}

const std::string INI_Reader::SearchKeyToHeader(const std::string& key){	
	for ( auto [head, value] : _section) {
		for (auto it = value.begin(); it != value.end(); it ++) {
			if (it->first == key)
				return head;
		}
	}
}

bool INI_Reader::SearchSector(const std::string& header) const{
	for ( auto [head, value] : _section) {
		if (header == head)
			return true;
	}
	return false;
}

bool INI_Reader::SearchKey(const std::string& key) const{
	for ( auto [head, value] : _section) {
		for ( auto it = value.begin(); it != value.end(); it++) {
			if (it->first == key)
				return true;
		}
	}
	return false;
}

bool INI_Reader::SearchVariable(const std::string& var) const{
	for ( auto [head, value] : _section) {
		for ( auto it = value.begin(); it != value.end(); it++) {
			if (it->second == var)
				return true;
		}
	}
	return false;
}

const std::string INI_Reader::SearchVarToHeader(const std::string& head, const std::string& key){
	for (auto it = _section[head].begin(); it != _section[head].end(); it++) {
		if (it->first == key) {
			return it->second;
		}
	}
}

void INI_Reader::Replacement(const std::string& head, const std::string& key, const std::string& var){
	if (this->SearchSector(head) && this->SearchKey(key)) {
		for (auto it = _section[head].begin(); it != _section[head].end(); it ++) {
			if (it->first == key) {
				it->second = var;
				std::cout << "Çíà÷åíèå èçìåíåíî\n";
			}
		}
	}
	else {
		std::pair<std::string, std::string> keyVar = { key,var };
		_section[head].push_back(keyVar);
		std::cout << "Ñîçäàí íîâûé ðàçäåë ñî çíà÷åíèåì\n";
	}
}

const std::string INI_Reader::GetFile() const{
	std::string file;
	for ( auto [head, value] : _section) {
		file += ('['+head + "]\n");
		for ( auto it = value.begin(); it != value.end(); it++) {
			file += (it->first + '=' + it->second + '\n');
		}
		file += '\n';
	}
	return file;
}

