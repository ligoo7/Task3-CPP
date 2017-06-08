#pragma once

#include <iostream>
#include <string>

//файл или консоль
void printMenuWay()
{
	std::cout << "\n1. Консоль\n";
	std::cout << "2. Файл\n";
	std::cout << "0. Отмена\n\n";
}

//критерий поиска
void printMenuFind()
{
	std::cout << "\nНайти по:\n";
	std::cout << "1. Коду\n";
	std::cout << "2. Марке\n";
	std::cout << "3. Типу процессора\n";
	std::cout << "4. Частоте\n";
	std::cout << "5. Объему ОЗУ\n";
	std::cout << "6. Объему жесткого диска\n";
	std::cout << "7. Памяти видеокарты\n";
	std::cout << "8. Ценности\n";
	std::cout << "9. Количеству\n";
	std::cout << "0. Отмена\n\n";
}

//критерий поиска
void printMenuFindIndex()
{
	std::cout << "\nНайти по:\n";
	std::cout << "1. Коду\n";
	std::cout << "2. Марке\n";
	std::cout << "3. Типу процессора\n";
	std::cout << "4. Частоте\n";
	std::cout << "5. Объему ОЗУ\n";
	std::cout << "6. Объему жесткого диска\n";
	std::cout << "7. Памяти видеокарты\n";
	std::cout << "8. Ценности\n";
	std::cout << "9. Количеству\n";
	std::cout << "10. По индексу\n";
	std::cout << "0. Отмена\n\n";
}

//действия с записью
void printMenuAction()
{
	std::cout << "\n1. Вывести\n";
	std::cout << "2. Изменить\n";
	std::cout << "3. Удалить\n";
	std::cout << "0. Назад\n\n";
}

//режим
void printMenuMode()
{
	std::cout << "\n1. Менеджер\n"; 
	std::cout << "2. Клент\n\n";
	std::cout << "0. Выход\n\n";
}

//действия менеджера
void printMenuManager()
{
	std::cout << "\n1. Добавить\n";
	std::cout << "2. Вывести список\n";
	std::cout << "3. Редактировать запись\n";
	std::cout << "4. Просмотреть историю\n";
	std::cout << "0. Отмена\n\n";
}

//выбор покупки
void printMenuBuy(int count)
{
	for (int i = 1; i < count; i++) 
		std::cout << "\n" + std::to_string(i) + ". Купить компьютер № " + std::to_string(i);
	std::cout << "\n0. Отмена\n";
}

//выбор записи для редактирования
void printMenuEdit(int count)
{
	for (int i = 1; i < count; i++)
		std::cout << "\n" + std::to_string(i) + ". Редактировать запись № " + std::to_string(i);
	std::cout << "\n0. Отмена\n";
}

//вывод
void printMenuPrint()
{
	std::cout << "\n1. Список\n";
	std::cout << "2. Отсортированный список\n";
	std::cout << "3. Подсписок\n";
	std::cout << "0. Назад\n\n";
}