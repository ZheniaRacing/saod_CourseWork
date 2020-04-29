#pragma once
#include <iostream>
#include "Cell.h"
#include <string> 

const int ARR_SIZE = 3;

class Row
{
private:
	struct EduBuild
	{
		Cell *classRooms[ARR_SIZE];
		int head, tail, count;
	}*queue;
public:
	Row();
	~Row();
	bool Pop();
	int Find(int _nBuild);
	bool Push(int _nBuild);
	Cell * GetCell(int n);
	int FindCell(int key);
	bool IsFull();
	bool IsEmpty();
	void ShowRows();

	std::string GetString();
};

Row::Row()
{
	queue = new EduBuild();
	queue->count = queue->head = queue->tail = 0;
}

Cell * Row::GetCell(int n)
{
	return queue->classRooms[n];
}

std::string Row::GetString()
{
	std::string str = "";
	if (!IsEmpty())
	{
		int n = queue->head;
		int i = 0;
		do
		{
			str += std::to_string(queue->classRooms[n]->GetNumb()) + " ";
			str += queue->classRooms[n]->GetString() + "\n";
			if (n == ARR_SIZE - 1)
				n = 0;
			else
				n++;
		} while (n != queue->tail);
		return str;
	}
	else
		return "";
}

int Row::FindCell(int key)
{
	if (!IsEmpty())
	{
		int n = queue->head;
		int i = 0;
		do
		{
			if (queue->classRooms[n]->FindCell(key) == key)
			{
				return queue->classRooms[n]->GetNumb();
			}
			else if(queue->classRooms[n]->FindCell(key) == -1)
			{
				if (n == ARR_SIZE - 1)
					n = 0;
				else
					n++;
			}
		} while (n != queue->tail);
		return -1;
	}
	else
		return -1;
}

bool Row::IsEmpty()
{
	if (queue->count == 0)
		return true;
	else
		return false;
}

bool Row::IsFull()
{
	if (queue->count == ARR_SIZE)
		return true;
	else
		return false;
}

bool Row::Push(int _nBuild)
{
	if (IsFull())
	{
		return false;
	}
	else
	{
		Cell * classR = new Cell(_nBuild);
		queue->classRooms[queue->tail] = classR;
		if (queue->tail == ARR_SIZE - 1)
			queue->tail = 0;
		else
			queue->tail++;
		queue->count++;
		return true;
	}
}

bool Row::Pop()
{
	if (IsEmpty())
		return false;
	else
	{
		delete queue->classRooms[queue->head];
		if (queue->head == ARR_SIZE - 1)
			queue->head = 0;
		else
			queue->head++;
		queue->count--;
		return true;
	}
}

int Row::Find(int _nBuild)
{
	if (!IsEmpty())
	{
		bool isFind = false;
		int n = queue->head;
		int i = 0;
		do
		{
			if (queue->classRooms[n]->GetNumb() == _nBuild)
			{
				isFind = true;
				break;
			}
			if (n == ARR_SIZE - 1)
				n = 0;
			else
				n++;
			
		} while (n != queue->tail);
		if (isFind)
			return n;
		else
			return -1;
	}
	else
		return -1;
}

void Row::ShowRows()
{
	if (!IsEmpty())
	{
		int n = queue->head;
		int i = 0;
		do
		{
			std::cout << "Здание № " << queue->classRooms[n]->GetNumb() << "\n";
			queue->classRooms[n]->ShowCell();
			if (n == ARR_SIZE - 1)
				n = 0;
			else
				n++;
		} while (n != queue->tail);
	}
	else
		std::cout << "Структура пуста\n";
}

Row::~Row()
{
	if (!IsEmpty())
	{
		while (queue->count != 0)
			Pop();
	}
	delete queue;
}