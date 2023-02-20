#include "Program_reader.h"
#include <Windows.h>
Program_reader::Program_reader(const std::string& path):_path(path){}

void Program_reader::StartRead(std::shared_ptr<INI_Reader>& obj){
	obj->Reader(_path);
}

void Program_reader::Work(std::shared_ptr<INI_Reader>& obj){
	obj->Reader(_path);
	bool exit = true;
	std::string variable,key,head;
	int num;
	while (exit)	{
		system("CLS");		
			std::cout << "Программа для работы с INI_files:\n";
			std::cout << "1.Найти в каком разделе находится ключ\n";
			std::cout << "2.Проверить существование заголовка\n";
			std::cout << "3.Проверить существование ключа\n";
			std::cout << "4.Проверить существование значения\n";
			std::cout << "5.Найти значение ключа в зоголовке\n";
			std::cout << "6.Присвоение значение в зоголовке по ключу\n";
			std::cout << "7.Сохранить файл\n";
			std::cout << "Введите номер нужной функции ->";
			std::cin >> variable;
			num = std::stoi(variable);
			std::cin.ignore();
			switch (num) {
			case 1:
				std::cout << "Введите ключ-> ";
				getline(std::cin, key);
				if (obj->SearchKey(key))
					std::cout << obj->SearchKeyToHeader(key) << '\n';
				else
					std::cout << "Введеного ключа не существует\n";
				break;
			case 2:
				std::cout << "Введите название заголовка ->";
				getline(std::cin, head);
				if (obj->SearchSector(head))
					std::cout << "Такой заголовок существует\n";
				else {
					std::cout << "Заданного заголовка несуществует\n";
				}
				break;
			case 3:
				std::cout << "Введите ключ-> ";
				getline(std::cin, key);
				if (obj->SearchKey(key))
					std::cout << "Запрашиваемый ключ есть в файле\n";
				else {
					std::cout << "Введеного ключа не существует\n";
				}
				break;
			case 4:
				std::cout << "Введите значение-> ";
				getline(std::cin, variable);
				if (obj->SearchVariable(variable))
					std::cout << "Введеное значение есть в файле\n";
				else {
					std::cout << "Запрашиваемого значения не существует\n";
				}
				break;
			case 5:
				std::cout << "Введите ключ-> ";
				getline(std::cin, key);
				std::cout << "Введите заголовок-> ";
				getline(std::cin, head);
				if (obj->SearchKey(key) && obj->SearchSector(head))
					std::cout << obj->SearchVarToHeader(head, key) << '\n';
				else
					std::cout << "Неверные параметры\n";
				break;
			case 6:
				std::cout << "Введите ключ-> ";
				getline(std::cin, key);
				std::cout << "Введите заголовок-> ";
				getline(std::cin, head);
				std::cout << "Введите новое значение-> ";
				getline(std::cin, variable);
				obj->Replacement(head, key, variable);
				break;
			case 7:
				std::cout << "Введите название нового файла ->";
				getline(std::cin, variable);
				SaveFile(variable, obj->GetFile());
				exit = false;
			default: continue;
			}
		system("Pause");		
	}

}

void Program_reader::SaveFile(const std::string& newPath, const std::string& file){
	std::ofstream out{newPath+".txt"};
	out << file;	
	out.close();
}
