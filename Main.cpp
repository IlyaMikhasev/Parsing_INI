#include <iostream>
#include "INI_Reader.h"
#include "Program_reader.h"
int main(int args, char** argv) {
	setlocale(LC_ALL, "Russian");
	std::shared_ptr<IReader> in_r = std::make_shared<INI_Reader>();
	if (args > 1) {
		Program_reader prog(argv[1]);
		prog.Work(in_r);
	}
	else {
		std::cout << "Не указан путь файла.\nВведити адрес файла->";
		std::string path;
		std::cin >> path;
		Program_reader prog1(path);
		prog1.Work(in_r);
	}
	return 0;
}