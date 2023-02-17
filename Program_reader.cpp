#include "Program_reader.h"

Program_reader::Program_reader(const std::string& path):_path(path){}

void Program_reader::StartRead(std::shared_ptr<IReader> obj){
	obj->Reader(_path);
}

void Program_reader::Work(std::shared_ptr<IReader> obj){
	obj->Reader(_path);
	bool exit = true;
	std::string variable,key,head;
	int num;
	while (exit)	{
		try
		{
			std::cout << "��������� ��� ������ � INI_files:\n";
			std::cout << "1.����� � ����� ������� ��������� ����\n";
			std::cout << "2.��������� ������������� ���������\n";
			std::cout << "3.��������� ������������� �����\n";
			std::cout << "4.��������� ������������� ��������\n";
			std::cout << "5.����� �������� ����� � ���������\n";
			std::cout << "6.���������� �������� � ��������� �� �����\n";
			std::cout << "7.��������� ����\n";
			std::cin >> variable;
			num = std::stoi(variable);
			std::cin.ignore();
			switch (num) {
			case 1:
				std::cout << "������� ����-> ";
				std::cin >> key;
				std::cout<<obj->SearchKeyToHeader(key)<<'\n';
				break;
			case 2:
				std::cout << "������� �������� ��������� ->";
				std::cin.ignore();
				getline(std::cin, head);
				if (obj->SearchSector(head))
					std::cout << "����� ��������� ����������\n";
				else {
					std::cout << "��������� ��������� ������������\n";
				}
				break;
			case 3:
				std::cout << "������� ����-> ";
				std::cin >> key;
				if (obj->KeyIsFile(key))
					std::cout << "������������� ���� ���� � �����\n";
				else {
					std::cout << "��������� ����� �� ����������\n";
				}
				break;
			case 4:
				std::cout << "������� ��������-> ";
				std::cin >> variable;
				if(obj->VarIsFile(variable))
					std::cout <<"�������� �������� ���� � �����\n";
				else {
					std::cout << "�������������� �������� �� ����������\n";
				}
				break;
			case 5:
				std::cout << "������� ����-> ";
				std::cin >> key;
				std::cout << "������� ���������-> ";
				std::cin.ignore();
				getline(std::cin, head);
				std::cout<<obj->SearchVarToHeader(head, key)<<'\n';
				break;
			case 6:
				std::cout << "������� ����-> ";
				std::cin >> key;
				std::cout << "������� ���������-> ";
				std::cin.ignore();
				getline(std::cin, head);
				std::cout << "������� ����� ��������-> ";
				getline(std::cin, variable);
				obj->Replacement(head, key, variable);
				break;
			case 7:
				std::cout << "������� �������� ������ ����� ->";
				getline(std::cin, variable);
				SaveFile(variable, obj->GetFile());
				exit = false;
			default: continue;
			}

		}
		catch (const char** ch)
		{
			std::cout << ch<<'\n';
			continue;
		}
			
		
	}

}

void Program_reader::SaveFile(const std::string& newPath, const std::string& file){
	std::ofstream out{newPath+".txt"};
	out << file;	
	out.close();
}
