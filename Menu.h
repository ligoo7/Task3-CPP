#pragma once

#include <iostream>
#include <string>

//���� ��� �������
void printMenuWay()
{
	std::cout << "\n1. �������\n";
	std::cout << "2. ����\n";
	std::cout << "0. ������\n\n";
}

//�������� ������
void printMenuFind()
{
	std::cout << "\n����� ��:\n";
	std::cout << "1. ����\n";
	std::cout << "2. �����\n";
	std::cout << "3. ���� ����������\n";
	std::cout << "4. �������\n";
	std::cout << "5. ������ ���\n";
	std::cout << "6. ������ �������� �����\n";
	std::cout << "7. ������ ����������\n";
	std::cout << "8. ��������\n";
	std::cout << "9. ����������\n";
	std::cout << "0. ������\n\n";
}

//�������� ������
void printMenuFindIndex()
{
	std::cout << "\n����� ��:\n";
	std::cout << "1. ����\n";
	std::cout << "2. �����\n";
	std::cout << "3. ���� ����������\n";
	std::cout << "4. �������\n";
	std::cout << "5. ������ ���\n";
	std::cout << "6. ������ �������� �����\n";
	std::cout << "7. ������ ����������\n";
	std::cout << "8. ��������\n";
	std::cout << "9. ����������\n";
	std::cout << "10. �� �������\n";
	std::cout << "0. ������\n\n";
}

//�������� � �������
void printMenuAction()
{
	std::cout << "\n1. �������\n";
	std::cout << "2. ��������\n";
	std::cout << "3. �������\n";
	std::cout << "0. �����\n\n";
}

//�����
void printMenuMode()
{
	std::cout << "\n1. ��������\n"; 
	std::cout << "2. �����\n\n";
	std::cout << "0. �����\n\n";
}

//�������� ���������
void printMenuManager()
{
	std::cout << "\n1. ��������\n";
	std::cout << "2. ������� ������\n";
	std::cout << "3. ������������� ������\n";
	std::cout << "4. ����������� �������\n";
	std::cout << "0. ������\n\n";
}

//����� �������
void printMenuBuy(int count)
{
	for (int i = 1; i < count; i++) 
		std::cout << "\n" + std::to_string(i) + ". ������ ��������� � " + std::to_string(i);
	std::cout << "\n0. ������\n";
}

//����� ������ ��� ��������������
void printMenuEdit(int count)
{
	for (int i = 1; i < count; i++)
		std::cout << "\n" + std::to_string(i) + ". ������������� ������ � " + std::to_string(i);
	std::cout << "\n0. ������\n";
}

//�����
void printMenuPrint()
{
	std::cout << "\n1. ������\n";
	std::cout << "2. ��������������� ������\n";
	std::cout << "3. ���������\n";
	std::cout << "0. �����\n\n";
}