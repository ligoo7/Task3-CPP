#pragma once

#include <fstream>
#include <algorithm> 
#include <vector>
#include <iterator>
#include "Helper.h"

class Computer
{
public:

	int code;
	std::string mark;
	std::string processor;
	int frequency;
	int RAM;
	int HDD;
	int VideoCard;
	int value;
	int count;

	Computer(int Acode, std::string Amark, std::string Aprocessor, int Afrequency, int ARAM, int AHDD, int AVideoCard, int Avalue, int Acount)
	{
		code = Acode;
		mark = Amark;
		processor = Aprocessor;
		frequency = Afrequency;
		RAM = ARAM;
		HDD = AHDD;
		VideoCard = AVideoCard;
		value = Avalue;
		count = Acount;
	}

	Computer()
	{
		code = 0;
		mark = "";
		processor = "";
		frequency = 0;
		RAM = 0;
		HDD = 0;
		VideoCard = 0;
		value = 0;
		count = 0;
	}

	~Computer()
	{
	}

	bool operator==(const Computer& comp) const
	{
		return	this->code == comp.code;
	}
};

//����� ������
std::ostream& operator<<(std::ostream &os, const Computer &comp) {
	os << std::to_string(comp.code) + "\t" + comp.mark + "\t" +	comp.processor + "\t" +
		std::to_string(comp.frequency) + "\t" +	std::to_string(comp.RAM) + "\t" + std::to_string(comp.HDD) + "\t" +
		std::to_string(comp.VideoCard) + "\t" +	std::to_string(comp.value) + "\t" + std::to_string(comp.count) + "\n";

	return os;
}

//����� �����
std::istream& operator>>(std::istream& is, Computer &comp)
{
	is >> comp.code;
	is >> comp.mark;
	is >> comp.processor;
	is >> comp.frequency;
	is >> comp.RAM;
	is >> comp.HDD;
	is >> comp.VideoCard;
	is >> comp.value;
	is >> comp.count;

	return is;
}

//Predicates

class CodePredicate
{
protected:
	int code;

public:
	CodePredicate(int Acode)
	{
		code = Acode;
	}

	bool operator() (Computer comp)
	{
		return comp.code == code;
	}

};

class MarkPredicate
{
protected:
	std::string mark;

public:
	MarkPredicate(std::string Amark)
	{
		mark = Amark;
	}

	bool operator() (Computer comp)
	{
		return comp.mark == mark;
	}

};

class FrequencyPredicate
{
protected:
	int frequency;

public:
	FrequencyPredicate(int Afrequency)
	{
		frequency = Afrequency;
	}

	bool operator() (Computer comp)
	{
		return comp.frequency == frequency;
	}

};

class ValuePredicate
{
protected:
	int value;

public:
	ValuePredicate(int Avalue)
	{
		value = Avalue;
	}

	bool operator() (Computer comp)
	{
		return comp.value == value;
	}

};

class CountPredicate
{
protected:
	int count;

public:
	CountPredicate(int Acount)
	{
		count = Acount;
	}

	bool operator() (Computer comp)
	{
		return comp.count == count;
	}

};

class ProcessorPredicate
{
protected:
	std::string processor;

public:
	ProcessorPredicate(std::string Aprocessor)
	{
		processor = Aprocessor;
	}

	bool operator() (Computer comp)
	{
		return comp.processor == processor;
	}
};

class RAMPredicate
{
protected:
	int RAM;

public:
	RAMPredicate(int ARAM)
	{
		RAM = ARAM;
	}

	bool operator() (Computer comp)
	{
		return comp.RAM == RAM;
	}
};

class VideoPredicate
{
protected:
	int VideoCard;

public:
	VideoPredicate(int AVideoCard)
	{
		VideoCard = AVideoCard;
	}

	bool operator() (Computer comp)
	{
		return comp.VideoCard == VideoCard;
	}
};

class HDDPredicate
{
protected:
	int HDD;

public:
	HDDPredicate(int AHDD)
	{
		HDD = AHDD;
	}

	bool operator() (Computer comp)
	{
		return comp.HDD == HDD;
	}
};

//Comparators

class CodeComparator
{
public:
	bool operator() (Computer comp1, Computer comp2)
	{
		return comp1.code < comp2.code;
	}
};

class MarkComparator
{
public:
	bool operator() (Computer comp1, Computer comp2)
	{
		return comp1.mark < comp2.mark;
	}
};

class FrequencyComparator
{
public:
	bool operator() (Computer comp1, Computer comp2)
	{
		return comp1.frequency < comp2.frequency;
	}
};

class ValueComparator
{
public:
	bool operator() (Computer comp1, Computer comp2)
	{
		return comp1.value < comp2.value;
	}
};

class CountComparator
{
public:
	bool operator() (Computer comp1, Computer comp2)
	{
		return comp1.count < comp2.count;
	}
};

class ProcessorComparator
{
public:
	bool operator() (Computer comp1, Computer comp2)
	{
		return comp1.processor < comp2.processor;
	}
};

class RAMComparator
{
public:
	bool operator() (Computer comp1, Computer comp2)
	{
		return comp1.RAM < comp2.RAM;
	}
};

class VideoComparator
{
public:
	bool operator() (Computer comp1, Computer comp2)
	{
		return comp1.VideoCard < comp2.VideoCard;
	}
};

class HDDComparator
{
public:
	bool operator() (Computer comp1, Computer comp2)
	{
		return comp1.HDD < comp2.HDD;
	}
};

//Sets

class CodeSet
{
protected:
	int code;
	std::vector<Computer>* vect;

public:
	CodeSet(int Acode)
	{
		code = Acode;
		vect = new std::vector<Computer>();
	}

	std::vector<Computer> getSet()
	{
		return *vect;
	}

	void operator() (Computer comp)
	{
		if (comp.code == code)
			(*vect).push_back(comp);
	}
};

class MarkSet
{
protected:
	std::string mark;
	std::vector<Computer>* vect;

public:
	MarkSet(std::string Amark)
	{
		mark = Amark;
		vect = new std::vector<Computer>();
	}

	std::vector<Computer> getSet()
	{
		return *vect;
	}

	void operator() (Computer comp)
	{
		if (comp.mark == mark)
			(*vect).push_back(comp);
	}
};

class FrequencySet
{
protected:
	int frequency;
	std::vector<Computer>* vect;

public:
	FrequencySet(int Afrequency)
	{
		frequency = Afrequency;
		vect = new std::vector<Computer>();
	}

	std::vector<Computer> getSet()
	{
		return *vect;
	}

	void operator() (Computer comp)
	{
		if (comp.frequency == frequency)
			(*vect).push_back(comp);
	}
};

class ValueSet
{
protected:
	int value;
	std::vector<Computer>* vect;

public:
	ValueSet(int Avalue)
	{
		value = Avalue;
		vect = new std::vector<Computer>();
	}

	std::vector<Computer> getSet()
	{
		return *vect;
	}

	void operator() (Computer comp)
	{
		if (comp.value == value)
			(*vect).push_back(comp);
	}
};

class ValueSetRange
{
protected:
	int lower; int higher;
	std::vector<Computer>* vect;

public:
	ValueSetRange(int Alower, int Ahigher)
	{
		lower = Alower;
		higher = Ahigher;
		vect = new std::vector<Computer>();
	}

	std::vector<Computer> getSet()
	{
		return *vect;
	}

	void operator() (Computer comp)
	{
		if (comp.value <= higher && comp.value >= lower)
			(*vect).push_back(comp);
	}
};

class CountSet
{
protected:
	int count;
	std::vector<Computer>* vect;

public:
	CountSet(int ACount)
	{
		count = ACount;
		vect = new std::vector<Computer>();
	}

	std::vector<Computer> getSet()
	{
		return *vect;
	}

	void operator() (Computer comp)
	{
		if (comp.count == count)
			(*vect).push_back(comp);
	}
};

class ProcessorSet
{
protected:
	std::string processor;
	std::vector<Computer>* vect;

public:
	ProcessorSet(std::string Aprocessor)
	{
		processor = Aprocessor;
		vect = new std::vector<Computer>();
	}

	std::vector<Computer> getSet()
	{
		return *vect;
	}

	void operator() (Computer comp)
	{
		if (comp.processor == processor)
			(*vect).push_back(comp);
	}
};

class RAMSet
{
protected:
	int RAM;
	std::vector<Computer>* vect;

public:
	RAMSet(int ARAM)
	{
		RAM = ARAM;
		vect = new std::vector<Computer>();
	}

	std::vector<Computer> getSet()
	{
		return *vect;
	}

	void operator() (Computer comp)
	{
		if (comp.RAM == RAM)
			(*vect).push_back(comp);
	}
};

class RAMSetRange
{
protected:
	int lower; int higher;
	std::vector<Computer>* vect;

public:
	RAMSetRange(int Alower, int Ahigher)
	{
		lower = Alower;
		higher = Ahigher;
		vect = new std::vector<Computer>();
	}

	std::vector<Computer> getSet()
	{
		return *vect;
	}

	void operator() (Computer comp)
	{
		if (comp.RAM <= higher && comp.RAM >= lower)
			(*vect).push_back(comp);
	}
};

class VideoSet
{
protected:
	int VideoCard;
	std::vector<Computer>* vect;

public:
	VideoSet(int AVideoCard)
	{
		VideoCard = AVideoCard;
		vect = new std::vector<Computer>();
	}

	std::vector<Computer> getSet()
	{
		return *vect;
	}

	void operator() (Computer comp)
	{
		if (comp.VideoCard == VideoCard)
			(*vect).push_back(comp);
	}
};

class HDDSet
{
protected:
	int HDD;
	std::vector<Computer>* vect;

public:
	HDDSet(int AHDD)
	{
		HDD = AHDD;
		vect = new std::vector<Computer>();
	}

	std::vector<Computer> getSet()
	{
		return *vect;
	}

	void operator() (Computer comp)
	{
		if (comp.HDD == HDD)
			(*vect).push_back(comp);
	}
};

//���� ������
Computer inputComputer()
{
	int code, frequency, RAM, HDD, VideoCard, value, count;
	std::string mark, processor;

	std::cout << "\n��� ��������� ������� 'stop'\n";
	std::cout << "\n������� ���: ";
	code = getInt(1);
	std::cout << "\n������� �������� �����: ";
	std::cin >> mark;
	if (mark == "stop") throw "stop";
	std::cout << "\n������� ��� ����������: ";
	std::cin >> processor;
	if (processor == "stop") throw "stop";
	std::cout << "\n������� ������� ������ ����������: ";
	frequency = getInt(1);
	std::cout << "\n������� ����� ����������� ������: ";
	RAM = getInt(1); 
	std::cout << "\n������� ����� �������� �����: ";
	HDD = getInt(1);
	std::cout << "\n������� ����� ������ ����������: ";
	VideoCard = getInt(1);
	std::cout << "\n������� ��������: ";
	value = getInt(1);
	std::cout << "\n������� ���������� �����������: ";
	count = getInt(1);
	std::cout << std::endl;
	
	return Computer(code, mark, processor, frequency, RAM, HDD, VideoCard, value, count);
}

int max = 999999;

//��������������
void editComputer(Computer &comp)
{
	int ACode, Afrequency, ARAM, AHDD, AVideoCard, Avalue, ACount;
	std::string AMark, Aprocessor;

	std::cout << "\n��� ������ ������� 'stop', ��� �������� ���� - 'skip'\n";
	std::cout << "\n������� ���(������� = " + std::to_string(comp.code) + "): ";
	ACode = getInt(1, max, true);
	if (ACode != -1) comp.code = ACode;

	std::cout << "\n������� �������� �����(������� = " + comp.mark + "): ";
	std::cin >> AMark;
	if (AMark == "stop") throw "stop";
	if (AMark != "skip")  comp.mark = AMark; 

	std::cout << "\n������� ��� ����������(������� = " + comp.processor + "): ";
	std::cin >> Aprocessor;
	if (Aprocessor == "stop") throw "stop";
	if (Aprocessor != "skip") comp.processor = Aprocessor;

	std::cout << "\n������� ������� ������ ����������(������� = " + std::to_string(comp.frequency) + "): ";
	Afrequency = getInt(1, max, true);
	if (Afrequency != -1) comp.frequency = Afrequency;

	std::cout << "\n������� ����� ����������� ������(������� = " + std::to_string(comp.RAM) + "): ";
	ARAM = getInt(1, max, true);
	if (ARAM != -1) comp.RAM = ARAM;

	std::cout << "\n������� ����� �������� �����(������� = " + std::to_string(comp.HDD) + "): ";
	AHDD = getInt(1, max, true);
	if (AHDD != -1) comp.HDD = AHDD;

	std::cout << "\n������� ����� ������ ����������(������� = " + std::to_string(comp.VideoCard) + "): ";
	 AVideoCard = getInt(1, max, true);
	if (AVideoCard != -1) comp.VideoCard = AVideoCard;

	std::cout << "\n������� ��������(������� = " + std::to_string(comp.value) + "): ";
	Avalue = getInt(1, max, true);
	if (Avalue != -1) comp.value = Avalue;

	std::cout << "\n������� ���������� �����������(������� = " + std::to_string(comp.count) + "): ";
	ACount = getInt(1, max, true);
	if (ACount != -1) comp.count = ACount;
}