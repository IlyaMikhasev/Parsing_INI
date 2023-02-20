#include <iostream>
#include "INI_Reader.h"
#include "Program_reader.h"
int main(int args, char** argv) {
	setlocale(LC_ALL, "Russian");
	std::shared_ptr<INI_Reader> ini = std::make_shared<INI_Reader>();
	try {
		if (args > 1) {
			Program_reader prog(argv[0]);
			prog.Work(ini);
		}
		else {
			std::cout << "Не указан путь файла.\nВведити адрес файла->";
			std::string path;
			std::cin >> path;
			Program_reader prog1(path);
			prog1.Work(ini);
		}
	}
	catch(const char* ex){
		std::cout << ex << std::endl;
		std::cout << "\nВведити адрес файла->";
		std::string path;
		std::cin >> path;
		Program_reader prog1(path);
		prog1.Work(ini);
	}
	return 0;
}