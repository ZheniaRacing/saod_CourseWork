#pragma once
#include <iostream>;
#include "Row.h";

class CompRows
{
public:
	CompRows(std::string _name);
	CompRows();
	~CompRows();
	void CreateRow();
	void SetName(std::string _name) { name = _name; }
	std::string GetName(){ return name; }
	bool PushRow(int _classR);
	int FindRow(int _nBuild);
	bool DeleteRow();

	bool CreateCell(int n, int _numbClassr, int _numbPlaces);
	int FindCell(int key);
	bool DeleteCell(int n);

	std::string GetString();
	void ShowRows();
private:
	std::string name;
	Row *rows;
};

CompRows::CompRows(std::string _name)
{
	name = _name;
}

CompRows::CompRows()
{
	
}

CompRows::~CompRows()
{
	delete rows;
}

//строки
void CompRows::CreateRow()
{
	rows = new Row();
}

std::string CompRows::GetString()
{
	std::string str = name + "\n" + rows->GetString();
	return str;
}

bool CompRows::PushRow(int _nBuild)
{
	
	return rows->Push(_nBuild);
}

int CompRows::FindRow(int _nBuild)
{
	int findRow = rows->Find(_nBuild);
	return findRow;
}

bool CompRows::DeleteRow()
{
	return rows->Pop();
}

//Ячейки
bool CompRows::CreateCell(int n_, int _numbClassr, int _numbPlaces)
{
	int n = rows->Find(n_);
	if (n != -1)
	{
		rows->GetCell(n)->Push(_numbClassr, _numbPlaces);
		return true;
	}
	else
		return false;
	
}

int CompRows::FindCell(int key)
{
	return rows->FindCell(key);
}

bool CompRows::DeleteCell(int n)
{
	n = rows->Find(n);
	if (n != -1)
		return rows->GetCell(n)->Pop();
	else
		return false;
}

void CompRows::ShowRows()
{
	rows->ShowRows();
}

