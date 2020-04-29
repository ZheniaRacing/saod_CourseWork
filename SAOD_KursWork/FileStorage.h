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
		file.getline(buffer, 100); // ����� ���� ������
		text = buffer;
		_tbl->CreateRow();
		_tbl->SetName(text);
	}
	else {
		std::cout << "���� ��� ����\n";
		return false;
	}
	while (!file.eof()) {
		file.getline(buffer, 100); // ����� ���� ������
		f = strtok(buffer, " "); // ����� ������ �� ��������
		if (f == NULL) continue;
		if (!(nBuild = atoi(f))) { // ���� ������ ������� - �� ����� (��� ������), ��������� �� ��������� ������
			//std::cout << "�������� ������ � �����, ���� ������ ��� ��������� �� ��������� ������\n";
			continue;
		}
		_tbl->PushRow(nBuild); // ������ �� ���� - ������� ������
		f = strtok(NULL, " "); // ��������� � ���������� ��������

		while (f) { // ���� �� �����
			if (!(nClass = atoi(f))) {
				//std::cout << "�������� ������ � �����, ���� ������ ��� ��������� �� ��������� ������\n";
				break; // ���� ���� ������, ��������� �� ��������� ������
			}
			f = strtok(NULL, " ");

			if (f)
				nPlaces = atoi(f);
			_tbl->CreateCell(nBuild , nClass, nPlaces); // ������� ������, ���� ������� ������
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


