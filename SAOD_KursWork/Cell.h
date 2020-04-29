#pragma once
#include <iostream>
#include <string> 

class Cell
{
private:
	struct ClassR
	{
		int numbClassR;
		int numbPlaces;
		ClassR *next;
	}*sp;
	int numbBuild;
public:
	Cell(int _numbBuild);
	void Push(int _numbClassR, int _numbPlaces);
	ClassR *GetNext() { return sp->next; }
	int GetNumb() { return numbBuild; }
	bool Pop();
	int FindCell(int key);
	bool IsEmpty();
	void ShowCell();
	~Cell();

	std::string GetString();
};

Cell::Cell(int _numbBuild)
{
	numbBuild = _numbBuild;
	sp = NULL;
}

void Cell::ShowCell()
{
	if (!IsEmpty())
	{
		ClassR * temp = sp;
		while (temp != NULL)
		{
			std::cout << "        Номер класса: " << temp->numbClassR << " Количество мест: " << temp->numbPlaces << "\n";
			temp = temp->next;
		}
	}
}

std::string Cell::GetString()
{
	if (!IsEmpty())
	{
		std::string str = "";
		std::string prob = " ";
		ClassR * temp = sp;
		while (temp != NULL)
		{
			str += std::to_string(temp->numbClassR) + prob + std::to_string(temp->numbPlaces) + prob;
			temp = temp->next;
		}
		return str;
	}
	else
		return "";
}

int Cell::FindCell(int key)
{
	ClassR *temp = sp;
	while (temp != NULL)
	{
		if (temp->numbClassR == key)
			return temp->numbClassR;
		else
			temp = temp->next;
	}
	return -1;
}

void Cell::Push(int _numbClassR, int _numbPlaces)
{
	ClassR *pTemp = new ClassR();
	pTemp->numbClassR = _numbClassR;
	pTemp->numbPlaces = _numbPlaces;
	pTemp->next = sp;
	sp = pTemp;
}

bool Cell::IsEmpty()
{
	if (sp == NULL)
		return true;
	else
		return false;
}

bool Cell::Pop()
{
	if (IsEmpty())
	{
		return false;
	}
	else
	{
		ClassR *pTemp = sp;
		sp = sp->next;
		delete pTemp;
		return true;
	}
}

Cell::~Cell()
{
	if (IsEmpty())
		std::cout << "Ячейка пуста\n";
	else
	{
		while (sp != NULL)
		{
			Pop();
		}
		delete sp;
	}
}