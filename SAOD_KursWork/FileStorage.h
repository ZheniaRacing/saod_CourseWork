#pragma once
#include <fstream>
#include <iostream>
#include "CompRows.h"

class Storage
{
private:
	std::string addressFile;

public:
	Storage(std::string _addressFile);

	bool InputData(CompRows *_tbl);
	bool OutputData(CompRows *_tbl);

	~Storage();
};

bool Storage::InputData(CompRows *_tbl)
{
	int nBuild, nClass, nPlaces;
	std::string text;
	char buffer[100];
	char * f;

	std::ifstream file(addressFile);
	if (!file.is_open())
		return false;
	if (!file.eof()) {
		file.getline(buffer, 100); // Берем одну строку
		text = buffer;
		_tbl->CreateRow();
		_tbl->SetName(text);
	}
	else {
		std::cout << "Файл был пуст\n";
		return false;
	}
	while (!file.eof()) {
		file.getline(buffer, 100); // Берем одну строку
		f = strtok(buffer, " "); // Делим строку по пробелам
		if (f == NULL) continue;
		if (!(nBuild = atoi(f))) { // Если первый элемент - не целое (это ошибка), переходим на следующую строку
			//std::cout << "Замечена ошибка в файле, ввод данных был продолжен со следующей строки\n";
			continue;
		}
		_tbl->PushRow(nBuild); // Ошибки не было - создаем строку
		f = strtok(NULL, " "); // Переходим к следующему элементу

		while (f) { // Если не пусто
			if (!(nClass = atoi(f))) {
				//std::cout << "Замечена ошибка в файле, ввод данных был продолжен со следующей строки\n";
				break; // Если была ошибка, переходим на следующую строку
			}
			f = strtok(NULL, " ");

			if (f)
				nPlaces = atoi(f);
			_tbl->CreateCell(nBuild , nClass, nPlaces); // Создаем ячейку, если нашлись данные
			f = strtok(NULL, " ");
		}
	}
	file.close();
	return true;
}

bool Storage::OutputData(CompRows *_tbl)
{
	std::ofstream file(addressFile);
	if (!file.is_open())
		return false;
	file << _tbl->GetString();
	file.close();
	return true;
}

Storage::Storage(std::string _addressFile)
{
	addressFile = _addressFile;
}

Storage::~Storage()
{
}


