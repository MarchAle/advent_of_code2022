#include <fstream>
#include <iostream>
#include <set>

int main()
{
	int				max_cal = 0;
	int				total = 0;
	std::set<int>	mem_max_cal;
	std::string		line;
	std::ifstream	input("input.txt");
	while (std::getline(input, line))
	{
		if (line.length() != 0)
		{
			max_cal += std::stoi(line);
		}
		else
		{
			if (mem_max_cal.size() < 3)
				mem_max_cal.insert(max_cal);
			else if (max_cal > *mem_max_cal.begin())
			{
				mem_max_cal.erase(mem_max_cal.begin());
				mem_max_cal.insert(max_cal);
			}
			max_cal = 0;
		}
	}
	for (std::set<int>::iterator it = mem_max_cal.begin(); it != mem_max_cal.end(); it++)
		total += *it;
	std::cout << total << std::endl;
}