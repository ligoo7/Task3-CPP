/*5. ������ ���������� ��������������� ����� � ��������� ����� ����������, ����� ����������, �������� ������ ����������, 
������� ����������� ������, ������� �������� �����, ������� ������ ����������, ��������� ���������� � ����������� �����������. 
����� �� ���� ����������, ������ ���, ������ ���������� � ������ �������� �����.

����������� ����������� ������� ��. ������� ������ ����� ��� ������ ������ � ������ � ��������� (���������� � ����). 
��������� ����� ����������� ���������� ���������: ����������, ��������������, �������� ������� ��. 
������������� ����� ������ ������� �� � ����������� �/��� ����������� �� ���������� ����. 
������������ ����� ����������� ������ �� �� ��������� �������� 
(����� ����, ��� ����� ���� �������� � ������ ������ � ������������� ���� ���������) � ������� ���������� ��. 
������������� �������� ������� ������� � �������� ������� �����������.
��������� �����, 2 ���� 9 ������*/

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
				//����������
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
				//�����
				case 2:
					printMenuPrint();
					choice = getInt(0, 3);
					switch (choice)
					{
					//������
					case 1:
						printToConsole(cont);
						break;
					//��������������� ��...
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
					//������������ 
					case 3:
						printMenuFind();
						choice = getInt(0, 9);
						switch (choice)
						{
						case 1:
							std::cout << "\n������� ���: ";
							subset = cont.findCodeSet(getInt(1));
							printToConsole(subset);
							break;
						case 2:
							std::cout << "\n������� �����: ";
							std::cin >> str;
							subset = cont.findMarkSet(str);
							printToConsole(subset);
							break;
						case 3:
							std::cout << "\n������� ��� ����������: ";
							std::cin >> str;
							subset = cont.findProcessorSet(str);
							printToConsole(subset);
							break;
						case 4:
							std::cout << "\n������� �������: ";
							subset = cont.findFrequencySet(getInt(1));
							printToConsole(subset);
							break;
						case 5:
							std::cout << "\n������� ����� ����������� ������: ";
							subset = cont.findRAMSet(getInt(1));
							printToConsole(subset);
							break;
						case 6:
							std::cout << "\n������� ����� �������� �����: ";
							subset = cont.findHDDSet(getInt(1));
							printToConsole(subset);
							break;
						case 7:
							std::cout << "\n������� ����� ������ ����������: ";
							subset = cont.findVideoSet(getInt(1));
							printToConsole(subset);
							break;
						case 8:
							std::cout << "\n������� ��������: ";
							subset = cont.findValueSet(getInt(1));
							printToConsole(subset);
							break;
						case 9:
							std::cout << "\n������� ����������: ";
							subset = cont.findCountSet(getInt(1));
							printToConsole(subset);
							break;
						case 0:
							break;
						}

						break;
					}
					break;
				//��������������
				case 3:
					printMenuFind();
					choice = getInt(0, 9);
					//�������� ������
					switch (choice)
					{
					case 1:
						std::cout << "\n������� ���: ";
						subset = cont.findCodeSet(getInt(1));
						break;
					case 2:
						std::cout << "\n������� �����: ";
						std::cin >> str;
						subset = cont.findMarkSet(str);
						break;
					case 3:
						std::cout << "\n������� ��� ����������: ";
						std::cin >> str;
						subset = cont.findProcessorSet(str);
						break;
					case 4:
						std::cout << "\n������� �������: ";
						subset = cont.findFrequencySet(getInt(1));
						break;
					case 5:
						std::cout << "\n������� ����� ����������� ������: ";
						subset = cont.findRAMSet(getInt(1));
						break;
					case 6:
						std::cout << "\n������� ����� �������� �����: ";
						subset = cont.findHDDSet(getInt(1));
						break;
					case 7:
						std::cout << "\n������� ����� ������ ����������: ";
						subset = cont.findVideoSet(getInt(1));
						break;
					case 8:
						std::cout << "\n������� ��������: ";
						subset = cont.findValueSet(getInt(1));
						break;
					case 9:
						std::cout << "\n������� ����������: ";
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
							std::cout << "\n�������� � ��������� �������:\n";
							printMenuAction();
							choice = getInt(0, 3);
							if (choice == 0) break;
							switch (choice)
							{
							//�����
							case 1:
								std::cout << *(it);
								break;
							//��������������
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
							//��������
							case 3:
								cont.remove(it);
								cont.printToFile(std::fstream(fStorage, std::ios::out));
								break;
							}
							if (choice == 3) break;
						}
					}
					else
						std::cout << "\n������ �� �������\n";
					break;
				//�������� �������
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
		//������
		else if (choice == 2)
			while (true)
			{
				printMenuFind();
				choice = getInt(0, 9);
				if (choice == 0)
				{
					break;
				}
				//�������� ������
				switch (choice)
				{
				case 1:
					std::cout << "\n������� ���: ";
					subset = cont.findCodeSet(getInt(1));
					break;
				case 2:
					std::cout << "\n������� �����: ";
					std::cin >> str;
					subset = cont.findMarkSet(str);
					break;
				case 3:
					std::cout << "\n������� ��� ����������: ";
					std::cin >> str;
					subset = cont.findProcessorSet(str);
					break;
				case 4:
					std::cout << "\n������� �������: ";
					subset = cont.findFrequencySet(getInt(1));
					break;
				case 5:
					std::cout << "\n������� ������ ������� ��������: ";
					lower = getInt(1);
					std::cout << "\n������� ������� ������� ��������: ";
					higher = getInt(lower + 1);
					subset = cont.findRAMSetRange(lower, higher);
					break;
				case 6:
					std::cout << "\n������� ����� �������� �����: ";
					subset = cont.findHDDSet(getInt(1));
					break;
				case 7:
					std::cout << "\n������� ����� ������ ����������: ";
					subset = cont.findVideoSet(getInt(1));
					break;
				case 8:
					std::cout << "\n������� ������ ������� ��������: ";
					lower = getInt(1);
					std::cout << "\n������� ������� ������� ��������: ";
					higher = getInt(lower + 1);
					subset = cont.findValueSetRange(lower, higher);
					break;
				case 9:
					std::cout << "\n������� ����������: ";
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
						f << "��������� � ����� " + std::to_string((*it).code) + " ������\n";
						f.close();
					}
					else
						std::cout << "\n��� � �������\n";
					cont.printToFile(std::fstream(fStorage, std::ios::out));
				}
				else
					std::cout << "\n��� ���������� �����������\n";
			}
		//�����
		else
			return 0;
	}
}

