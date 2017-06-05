#pragma once

#include <iostream>
#include <string>

//�������� ����� �� ���������� ���������
int getInt(int min = 0, int max = 999999, bool edit = false)
{
	std::string str;
	int res; 

	while (true)
	{
		try
		{
			std::cin >> str;
			if (str == "stop") throw "stop";
			if (str == "skip" && edit) return -1;
			res = std::stoi(str);
			while (res < min || res > max)
			{
				std::cout << "������� ����� �� " << min << " �� " << max << std::endl;
				std::cin >> str;
				if (str == "stop") throw "stop";
				if (str == "skip" && edit) return -1;
				res = std::stoi(str);
			}
			return res;
		}
		catch (std::exception)
		{
			std::cout << "�������� ������! ��������� ����:\n";
		}
	}
}

//�������� ����� �����
std::string fileIn()
{
	std::fstream file;
	std::string res;
	std::cout << "������� ��� �����: ";
	std::cin >> res;
	std::cout << std::endl;
	file.open(res + ".txt");
	while (!file.is_open()) 
	{
		std::cout << "���������� ������� ����, ��������� ����: ";
		std::cin >> res;
		file.open(res + ".txt");
	};
	file.close();
	return res + ".txt";
}

//��� ����� ��� ������
std::string fileOut()
{
	std::string fout;
	std::cout << "������� ��� �����: ";
	std::cin >> fout;
	std::cout << std::endl;
	return fout + ".txt";
}