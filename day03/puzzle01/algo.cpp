#include <fstream>
#include <iostream>
#include <set>

int main()
{
	int				sum = 0;
	std::string 	s1;
	std::string 	s2;
 
	std::string		line;
	std::ifstream	input("input.txt");
	while (std::getline(input, line))
	{
		s1 = line.substr(0, line.length() / 2);
		s2 = line.substr(line.length() / 2, line.length());
		for (int i = 0; i < s1.length(); i++)
		{
			int stop = 0;
			for (int j = 0; j < s2.length(); j++)
			{
				if (s1[i] == s2[j])
				{
					if ((int)s1[i] >= 97)
						sum += (int)s1[i] - 96;
					else
						sum += (int)s1[i] - 38;
					stop = 1;
					break;
				}
			}
			if (stop)
				break;
		}
	}

	std::cout << sum << std::endl;
}