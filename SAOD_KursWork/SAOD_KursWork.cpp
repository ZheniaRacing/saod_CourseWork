// SAOD_KursWork.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <iostream>
#include "CompRows.h";
#include "FileStorage.h";
CompRows *tbl = NULL;
Storage storage("storage.txt");

int nBuild, nClass, nPlaces;
std::string name;

void MainMenu();
void Init();
void InitFromStorage();

int main()
{
	setlocale(LC_ALL, "");
	InitFromStorage();
	MainMenu();
}

void InitFromStorage()
{
	tbl = new CompRows();
	if (!storage.InputData(tbl))
	{
		std::cout << "Ошибка закгрузки данных\n";
		std::cout << "Введите название таблицы (учебного учреждения):\n";
		std::cin >> name;
		tbl->SetName(name);
		tbl->CreateRow();

	}
	else
		std::cout << "Таблица "<<tbl->GetName()<<" успешно загружена из файла.\n";
	system("pause");
	system("cls");
}

void Init()
{
	tbl = new CompRows();
	std::cout << "Введите название таблицы (учебного учреждения):\n";
	std::cin >> name;
	tbl->SetName(name);
	tbl->CreateRow();
}

void MainMenu()
{
	int sw;
	while (true)
	{
		std::cout <<"Учебное учреждение: "<<tbl->GetName()<<"\n";
		tbl->ShowRows();
		std::cout << "________________________________________________________________\n\n";
		std::cout << "=Главное меню=\n";
		std::cout << "1 - Добавить здание | 10 - Удалить здание   | 100 - Найти здание\n2 - Добавить класс  | 20 - Удалить класс    | 200 - Найти класс\n";
		std::cout << "________________________________________________________________\n\n";
		std::cout << "3 - Показать        | 9 - Очистить структуру| 0 - Выход\n";
		std::cin >> sw;
		switch (sw)
		{
		case 1:
			std::cout << "Введите номер здания: \n";
			std::cin >> nBuild;
			if (tbl->PushRow(nBuild))
				std::cout << "Учебное здание успешно добавлено.\n";
			else
				std::cout << "Ошибка добавления.\n";
			system("pause");
			break;
		case 10:
			if (tbl->DeleteRow())
				std::cout << "Здание успешно удалено.\n";
			else
				std::cout << "Невозможно удалить здание.\n";
			system("pause");
			break;
		case 100:
			std::cout << "Введите номер здания: \n";
			std::cin >> nBuild;
			if (tbl->FindRow(nBuild) != -1)
				std::cout << "Здание успешно найдено.\n";
			else
				std::cout << "Не удалось найти здание. Проверьте введённую информацию.\n";
			system("pause");
			break;
		case 2:
			std::cout << "Введите номер здания: \n";
			std::cin >> nBuild;
			std::cout << "Введите номер класса: \n";
			std::cin >> nClass;
			std::cout << "Введите количество мест: \n";
			std::cin >> nPlaces;
			if (tbl->CreateCell(nBuild, nClass, nPlaces))
				std::cout << "Класс успешно добавлен.\n";
			else
				std::cout << "Не удалось добавить класс. Проверьте введённую информацию.\n";
			system("pause");
			break;
		case 20:
			std::cout << "Введите номер здания: \n";
			std::cin >> nBuild;
			if (tbl->DeleteCell(nBuild))
			{
				std::cout << "Класс успешно удален.\n";
			}
			else
				std::cout << "Невозможно удалить класс.\n";
			system("pause");
			break;
		case 200:
			std::cout << "Введите номер класса: \n";
			std::cin >> nClass;
			nBuild = tbl->FindCell(nClass);
			if (nBuild != -1)
				std::cout << "Класс успешно найдено. Он находится в "<< nBuild <<" здании.\n";
			else
				std::cout << "Не удалось найти класс. Проверьте введённую информацию.\n";
			system("pause");
			break;
		case 3:
			std::cout << "Учебное учреждение:" << tbl->GetName() << "\n";
			tbl->ShowRows();
			system("pause");
			break;
		case 9:
			delete tbl;
			std::cout << "Структура очищена\n";
			system("pause");
			system("cls");
			Init();
			break;
		case 0:
			std::cout << "Сохранить изменения?\n1 - Да | 2 - Нет\n";
			std::cin >> sw;
			if (sw == 1)
			{
				if (storage.OutputData(tbl))
					std::cout << "Сохранение прошло успеш\n";
				else
					std::cout << "Ошибка сохранения\n";
				delete tbl;
				system("pause");
				exit(0);
			}
			else if (sw == 2)
			{
				delete tbl;
				exit(0);
			}
			else
			{
				std::cout << "Ошибка ввода\n";
				break;
			}
		}
		system("cls");
	}
	
	
}