#pragma once
#include "Menu.h"

template <class T>
class Container
{
protected:

	std::vector<T> vect;

public:
	typedef std::_Vector_iterator<std::_Vector_val<std::_Simple_types<T>>> iter;
	typedef std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<T>>> constIter;

	int vectSize()
	{
		return vect.size();
	}

	void vectClear()
	{
		vect.clear();
	}

	constIter vectBegin()
	{
		return vect.cbegin();
	}

	constIter vectEnd()
	{
		return vect.cend();
	}

	Container(int size)
	{
		vect = std::vector<T>(size);
	}

	Container()
	{
		vect = std::vector<T>();
	}

	~Container() 
	{
	}

	void add(T el)
	{
		vect.push_back(el);
	}

	void remove(iter &it) {
		vect.erase(it);
	}

	bool find(T el)
	{
		return std::find(vect.begin(), vect.end(), el) != vect.end();
	}

	bool find(T el, iter &it)
	{
		iter itit;
		itit = std::find(vect.begin(), vect.end(), el);
		if (itit == vect.end())
			return false;
		it = itit;
		return true;
	}

	template<class Predicate>
	bool find(Predicate &pred, iter &it)
	{
		iter tmp = std::find_if(vect.begin(), vect.end(), pred);
		if (tmp == vect.end()) return false;
		it = tmp;
		return true;
	}

	template<class Comparator>
	bool find(T el, Comparator &comp, iter &it)
	{
		std::sort(vect.begin(), vect.end(), comp);
		iter tmp = std::lower_bound(vect.begin(), vect.end(), el, comp);
		if (tmp == vect.end() || comp(el, *tmp))
			return false;
		it = tmp;
		return true;
	}

	template<class Set>
	std::vector<T> findSubSet(Set subset)
	{
		std::for_each(vect.begin(), vect.end(), subset);
		return subset.getSet();
	}

	iter findit(T el)
	{
		return std::find(vect.begin(), vect.end(), el);
	}

	T getElem(int i)
	{ 
		return vect[i];
	}

	template <class Comparator>
	void sort(Comparator comp)
	{
		std::sort(vect.begin(), vect.end(), comp);
	}
};

class ContainerComp : public Container<Computer>
{
public:

	ContainerComp()
	{
	}

	ContainerComp(std::vector<Computer> Avect)
	{
		vect = Avect;
	}

	bool findCode(int code, iter &it)
	{
		return find(CodePredicate(code), it);
	}

	bool findMark(std::string mark, iter &it)
	{
		return find(MarkPredicate(mark), it);
	}

	bool findFrequency(int frequency, iter &it)
	{
		return find(FrequencyPredicate(frequency), it);
	}

	bool findValue(int value, iter &it)
	{
		return find(ValuePredicate(value), it);
	}

	bool findValueRange(int lower, int higher, iter &it)
	{
		iter itit = vect.begin();
		while (itit++ != vect.end())
		{
			if ((*itit).value >= lower && (*itit).value <= higher)
			{
				it = itit;
				return true;
			}
		}
		return false;
	}

	bool findCount(int count, iter &it)
	{
		return find(CountPredicate(count), it);
	}

	bool findProcessor(std::string processor, iter &it)
	{
		return find(ProcessorPredicate(processor), it);
	}

	bool findRAM(int RAM, iter &it)
	{
		return find(RAMPredicate(RAM), it);
	}

	bool findRAMRange(int lower, int higher, iter &it)
	{
		iter itit = vect.begin();
		while (itit++ != vect.end())
		{
			if ((*itit).RAM >= lower && (*itit).RAM <= higher)
			{
				it = itit;
				return true;
			}
		}
		return false;
	}

	bool findVideo(int VideoCard, iter &it)
	{
		return find(VideoPredicate(VideoCard), it);
	}

	bool findHDD(int HDD, iter &it)
	{
		return find(HDDPredicate(HDD), it);
	}


	bool findCodeBinary(int ram, iter &it)
	{
		return find(Computer(ram, "", "", 0, 0, 0, 0, 0, 0), CodeComparator(), it);
	}

	bool findMarkBinary(std::string m, iter &it)
	{
		return find(Computer(0, m, "", 0, 0, 0, 0, 0, 0), MarkComparator(), it);
	}

	bool findFrequencyBinary(int vm, iter &it)
	{
		return find(Computer(0, "", "", vm, 0, 0, 0, 0, 0), FrequencyComparator(), it);
	}

	bool findValueBinary(int hdd, iter &it)
	{
		return find(Computer(0, "", "", 0, 0, 0, 0, 0, hdd), ValueComparator(), it);
	}

	bool findCountBinary(int vm, iter &it)
	{
		return find(Computer(0, "", "", 0, 0, 0, 0, 0, vm), CountComparator(), it);
	}

	bool findProcessorBinary(std::string processor, iter &it)
	{
		return find(Computer(0, "", processor, 0, 0, 0, 0, 0, 0), ProcessorComparator(), it);
	}

	bool findRAMBinary(int RAM, iter &it)
	{
		return find(Computer(0, "", "", 0, RAM, 0, 0, 0, 0), RAMComparator(), it);
	}

	bool findVideoBinary(int VideoCard, iter &it)
	{
		return find(Computer(0, "", "", 0, 0, 0, VideoCard, 0, 0), VideoComparator(), it);
	}

	bool findHDDBinary(int HDD, iter &it)
	{
		return find(Computer(0, "", "", 0, 0, HDD, 0, 0, 0), HDDComparator(), it);
	}


	ContainerComp findCodeSet(int code)
	{
		return ContainerComp(findSubSet(CodeSet(code)));
	}

	ContainerComp findMarkSet(std::string mark)
	{
		return ContainerComp(findSubSet(MarkSet(mark)));
	}

	ContainerComp findFrequencySet(int frequency)
	{
		return ContainerComp(findSubSet(FrequencySet(frequency)));
	}

	ContainerComp findValueSet(int value)
	{
		return ContainerComp(findSubSet(ValueSet(value)));
	}

	ContainerComp findValueSetRange(int lower, int higher)
	{
		return ContainerComp(findSubSet(ValueSetRange(lower, higher)));
	}

	ContainerComp findCountSet(int count)
	{
		return ContainerComp(findSubSet(CountSet(count)));
	}

	ContainerComp findProcessorSet(std::string processor)
	{
		return ContainerComp(findSubSet(ProcessorSet(processor)));
	}

	ContainerComp findRAMSet(int RAM)
	{
		return ContainerComp(findSubSet(RAMSet(RAM)));
	}

	ContainerComp findRAMSetRange(int lower, int higher)
	{
		return ContainerComp(findSubSet(RAMSetRange(lower, higher)));
	}

	ContainerComp findVideoSet(int VideoCard)
	{
		ContainerComp set;
		set.vect = findSubSet(VideoSet(VideoCard));
		return set;
	}

	ContainerComp findHDDSet(int HDD)
	{
		ContainerComp set;
		set.vect = findSubSet(HDDSet(HDD));
		return set;
	}

	void getFromFile(std::fstream fin)
	{
		if (fin.is_open())
		{
			std::istream_iterator<Computer> is(fin);
			vect.clear();
			if (fin.eof()) return;
			Computer comp = *is;
			while (!fin.fail() && !fin.eof())
			{
				comp = *is++;
				add(comp);
			}
			fin.close();
		}
		else
			std::cout << "Невозможно открыть файл" << std::endl;
	}

	void printToFile(std::fstream fout)
	{
		if (fout.is_open())
		{
			copy(vect.begin(), vect.end(), std::ostream_iterator<Computer>(fout, "\n"));
			fout.close();
		}
		else
		{
			std::cout << "Невозможно открыть файл";
		}
	}
};

void getFromConsole(ContainerComp &cont)
{
	cont.vectClear();
	Computer comp;
	while (true)
	{
		try
		{
			comp = inputComputer();
		}
		catch (const char*)
		{
			return;
		}
		cont.add(comp);
	}
}

void printToConsole(ContainerComp &cont)
{
	if (cont.vectSize() == 0)
		std::cout << std::endl << "Записи отсутствуют\n" << std::endl;
	else
	{
		std::cout << "код\tмарка\tтип\tчастота\tram\thdd\tвидео\tцена\tколичество\n\n";
		copy(cont.vectBegin(), cont.vectEnd(), std::ostream_iterator<Computer>(std::cout, "\n"));
	}
}

const int maxLevel = 2;

void Recursion(ContainerComp &cont, int level)
{
	int choice;
	std::string str;

	if (cont.vectSize() <= 1 || level == maxLevel)
		return;

	if (cont.vectSize() > 0)
		printToConsole(cont);

	printMenuFindIndex();
	choice = getInt(0, 10);
	if (choice == 0) throw "exit";
	switch (choice)
	{
	case 1:
		std::cout << "\nВведите код: ";
		cont = cont.findCodeSet(getInt(1));
		break;
	case 2:
		std::cout << "\nВведите марку: ";
		std::cin >> str;
		cont = cont.findMarkSet(str);
		break;
	case 3:
		std::cout << "\nВведите тип процессора: ";
		std::cin >> str;
		cont = cont.findProcessorSet(str);
		break;
	case 4:
		std::cout << "\nВведите частоту: ";
		cont = cont.findFrequencySet(getInt(1));
		break;
	case 5:
		std::cout << "\nВведите объем оперативной памяти: ";
		cont = cont.findRAMSet(getInt(1));
		break;
	case 6:
		std::cout << "\nВведите объем жесткого диска: ";
		cont = cont.findHDDSet(getInt(1));
		break;
	case 7:
		std::cout << "\nВведите объем памяти видеокарты: ";
		cont = cont.findVideoSet(getInt(1));
		break;
	case 8:
		std::cout << "\nВведите ценность: ";
		cont = cont.findValueSet(getInt(1));
		break;
	case 9:
		std::cout << "\nВведите количество: ";
		cont = cont.findCountSet(getInt(0));
		break;
	case 10:
		return;
	}

	Recursion(cont, level + 1);
}