/*5. Модель компьютера характеризуется кодом и названием марки компьютера, типом процессора, частотой работы процессора, 
объемом оперативной памяти, объемом жесткого диска, объемом памяти видеокарты, ценностью компьютера и количеством экземпляров. 
Поиск по типу процессора, объему ОЗУ, памяти видеокарты и объему жесткого диска.

Реализовать виртуальный магазин ПК. Магазин должен иметь два режима работы — клиент и сотрудник (выбирается в меню). 
Сотрудник имеет возможность управления магазином: добавление, редактирование, удаление моделей ПК. 
Предусмотреть вывод списка моделей ПК с сортировкой и/или фильтрацией по выбранному полю. 
Пользователь имеет возможность поиска ПК по заданному критерию 
(любое поле, для полей типа ценности и объема памяти — предусмотреть ввод диапазона) и покупки выбранного ПК. 
Предусмотреть хранение истории покупок и просмотр истории сотрудником.
Горлищева Лидия, 2 курс 9 группа*/

#include "stdafx.h"
#include "Computer.h"
#include "Template.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	ContainerComp cont = ContainerComp();
	ContainerComp subset = ContainerComp();
	std::vector<Computer>::iterator it;
	std::string str;
	int choice, lower, higher;
	std::fstream f;
	std::string fStorage = "input.txt";
	std::string fHistory = "history.txt";

	cont.getFromFile(std::fstream(fStorage, std::ios::in));

	while (true)
	{
		printMenuMode();
		choice = getInt(0,2);

		if (choice == 1)
		{
			while (true)
			{
				printMenuManager();
				choice = getInt(0, 4);
				if (choice == 0) break;
				switch (choice)
				{
				//добавление
				case 1:
					try
					{
						cont.add(inputComputer());
						cont.printToFile(std::fstream(fStorage, std::ios::out));
					}
					catch (const char*)
					{
					}
					break;
				//вывод
				case 2:
					printMenuPrint();
					choice = getInt(0, 3);
					switch (choice)
					{
					//список
					case 1:
						printToConsole(cont);
						break;
					//отсортированный по...
					case 2:
						printMenuFind();
						choice = getInt(0, 9);
						switch (choice)
						{
						case 1:
							cont.sort(CodeComparator());
							printToConsole(cont);
							break;
						case 2:
							cont.sort(MarkComparator());
							printToConsole(cont);
							break;
						case 3:
							cont.sort(ProcessorComparator());
							printToConsole(cont);
							break;
						case 4:
							cont.sort(FrequencyComparator());
							printToConsole(cont);
							break;
						case 5:
							cont.sort(RAMComparator());
							printToConsole(cont);
							break;
						case 6:
							cont.sort(HDDComparator());
							printToConsole(cont);
							break;
						case 7:
							cont.sort(VideoComparator());
							printToConsole(cont);
							break;
						case 8:
							cont.sort(ValueComparator());
							printToConsole(cont);
							break;
						case 9:
							cont.sort(CountComparator());
							printToConsole(cont);
							break;
						case 0:
							break;
						}
						break;
					//подмножество 
					case 3:
						printMenuFind();
						choice = getInt(0, 9);
						switch (choice)
						{
						case 1:
							std::cout << "\nВведите код: ";
							subset = cont.findCodeSet(getInt(1));
							printToConsole(subset);
							break;
						case 2:
							std::cout << "\nВведите марку: ";
							std::cin >> str;
							subset = cont.findMarkSet(str);
							printToConsole(subset);
							break;
						case 3:
							std::cout << "\nВведите тип процессора: ";
							std::cin >> str;
							subset = cont.findProcessorSet(str);
							printToConsole(subset);
							break;
						case 4:
							std::cout << "\nВведите частоту: ";
							subset = cont.findFrequencySet(getInt(1));
							printToConsole(subset);
							break;
						case 5:
							std::cout << "\nВведите объем оперативной памяти: ";
							subset = cont.findRAMSet(getInt(1));
							printToConsole(subset);
							break;
						case 6:
							std::cout << "\nВведите объем жесткого диска: ";
							subset = cont.findHDDSet(getInt(1));
							printToConsole(subset);
							break;
						case 7:
							std::cout << "\nВведите объем памяти видеокарты: ";
							subset = cont.findVideoSet(getInt(1));
							printToConsole(subset);
							break;
						case 8:
							std::cout << "\nВведите ценность: ";
							subset = cont.findValueSet(getInt(1));
							printToConsole(subset);
							break;
						case 9:
							std::cout << "\nВведите количество: ";
							subset = cont.findCountSet(getInt(1));
							printToConsole(subset);
							break;
						case 0:
							break;
						}

						break;
					}
					break;
				//редактирование
				case 3:
					printMenuFind();
					choice = getInt(0, 9);
					//критерий поиска
					switch (choice)
					{
					case 1:
						std::cout << "\nВведите код: ";
						subset = cont.findCodeSet(getInt(1));
						break;
					case 2:
						std::cout << "\nВведите марку: ";
						std::cin >> str;
						subset = cont.findMarkSet(str);
						break;
					case 3:
						std::cout << "\nВведите тип процессора: ";
						std::cin >> str;
						subset = cont.findProcessorSet(str);
						break;
					case 4:
						std::cout << "\nВведите частоту: ";
						subset = cont.findFrequencySet(getInt(1));
						break;
					case 5:
						std::cout << "\nВведите объем оперативной памяти: ";
						subset = cont.findRAMSet(getInt(1));
						break;
					case 6:
						std::cout << "\nВведите объем жесткого диска: ";
						subset = cont.findHDDSet(getInt(1));
						break;
					case 7:
						std::cout << "\nВведите объем памяти видеокарты: ";
						subset = cont.findVideoSet(getInt(1));
						break;
					case 8:
						std::cout << "\nВведите ценность: ";
						subset = cont.findValueSet(getInt(1));
						break;
					case 9:
						std::cout << "\nВведите количество: ";
						subset = cont.findCountSet(getInt(1));
						break;
					case 0:
						break;
					}
					if (subset.vectSize() != 0)
					{
						printToConsole(subset);
						printMenuEdit(subset.vectSize() + 1);
						choice = getInt(0, subset.vectSize() + 1);
						if (choice == 0) break;
						it = cont.findit(subset.getElem(choice - 1));
						while (true)
						{
							std::cout << "\nДействия с найденной записью:\n";
							printMenuAction();
							choice = getInt(0, 3);
							if (choice == 0) break;
							switch (choice)
							{
							//вывод
							case 1:
								std::cout << *(it);
								break;
							//редактирование
							case 2:
								try
								{
									editComputer(*it);
									cont.printToFile(std::fstream(fStorage, std::ios::out));
									break;
								}
								catch (const char*)
								{
									if (str == "stop")
										break;
								}
							//удаление
							case 3:
								cont.remove(it);
								cont.printToFile(std::fstream(fStorage, std::ios::out));
								break;
							}
							if (choice == 3) break;
						}
					}
					else
						std::cout << "\nЗапись не найдена\n";
					break;
				//просмотр истории
				case 4:
					f.open(fHistory, std::ios::in);
					if (!f.is_open())
					{
						break;
					}
					while (std::getline(f, str))
					{
						std::cout << str << std::endl;
					}
					f.close();
					break;
				}
			}
		}
		//клиент
		else if (choice == 2)
			while (true)
			{
				printMenuFind();
				choice = getInt(0, 9);
				if (choice == 0)
				{
					break;
				}
				//критерий поиска
				switch (choice)
				{
				case 1:
					std::cout << "\nВведите код: ";
					subset = cont.findCodeSet(getInt(1));
					break;
				case 2:
					std::cout << "\nВведите марку: ";
					std::cin >> str;
					subset = cont.findMarkSet(str);
					break;
				case 3:
					std::cout << "\nВведите тип процессора: ";
					std::cin >> str;
					subset = cont.findProcessorSet(str);
					break;
				case 4:
					std::cout << "\nВведите частоту: ";
					subset = cont.findFrequencySet(getInt(1));
					break;
				case 5:
					std::cout << "\nВведите нижнюю границу дапазона: ";
					lower = getInt(1);
					std::cout << "\nВведите верхнюю границу дапазона: ";
					higher = getInt(lower + 1);
					subset = cont.findRAMSetRange(lower, higher);
					break;
				case 6:
					std::cout << "\nВведите объем жесткого диска: ";
					subset = cont.findHDDSet(getInt(1));
					break;
				case 7:
					std::cout << "\nВведите объем памяти видеокарты: ";
					subset = cont.findVideoSet(getInt(1));
					break;
				case 8:
					std::cout << "\nВведите нижнюю границу дапазона: ";
					lower = getInt(1);
					std::cout << "\nВведите верхнюю границу дапазона: ";
					higher = getInt(lower + 1);
					subset = cont.findValueSetRange(lower, higher);
					break;
				case 9:
					std::cout << "\nВведите количество: ";
					subset = cont.findCountSet(getInt(1));
					break;
				}
				if (subset.vectSize() != 0)
				{
					printToConsole(subset);
					printMenuBuy(subset.vectSize() + 1);
					choice = getInt(0, subset.vectSize() + 1);
					if (choice == 0)
						continue;

					it = cont.findit(subset.getElem(choice - 1));
					if (!(*it).count == 0)
					{
						(*it).count--;
						f.open(fHistory, std::ios_base::app);
						f << "Компьютер с кодом " + std::to_string((*it).code) + " продан\n";
						f.close();
					}
					else
						std::cout << "\nНет в наличии\n";
					cont.printToFile(std::fstream(fStorage, std::ios::out));
				}
				else
					std::cout << "\nНет подходящих компьютеров\n";
			}
		//выход
		else
			return 0;
	}
}

