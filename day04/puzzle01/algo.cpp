#include <fstream>
#include <iostream>
#include <set>

int main()
{
	int				total = 0;
	std::string 	s1;
	std::string 	s2;
	int				max1;
	int				max2;
	int				min1;
	int				min2;
 
	std::string		line;
	std::ifstream	input("input.txt");
	while (std::getline(input, line))
	{
		s1 = line.substr(0, line.find(","));
		s2 = line.substr(line.find(",") + 1, line.length());
		min1 = std::stoi(s1.substr(0, s1.find("-")));
		max1 = std::stoi(s1.substr(s1.find("-") + 1, s1.length()));
		min2 = std::stoi(s2.substr(0, s2.find("-")));
		max2 = std::stoi(s2.substr(s2.find("-") + 1, s2.length()));
		if (min2 >= min1 && max2 <= max1)
			total++;
		else if (min2 <= min1 && max2 >= max1)
			total++;
	}

	std::cout << total << std::endl;
}