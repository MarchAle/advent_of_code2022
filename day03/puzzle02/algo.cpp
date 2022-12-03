#include <fstream>
#include <iostream>
#include <set>

int main()
{
	int 			index = 0;
	int				sum = 0;
	std::string 	s1;
	std::string 	s2;
	std::string 	s3;
 
	std::string		line;
	std::ifstream	input("input.txt");
	while (std::getline(input, line))
	{
		if (index == 0)
			s1 = line;
		if (index == 1)
			s2 = line;
		if (index == 2)
		{
			s3 = line;
			for (int i = 0; i < s1.length(); i++)
			{
				int stop = 0;
				for (int j = 0; j < s2.length(); j++)
				{
					if (s1[i] == s2[j])
					{
						for (int k = 0; k < s3.length(); k++)
						{
							if (s2[j] == s3[k])
							{
								if ((int)s1[i] >= 97)
									sum += (int)s1[i] - 96;
								else
									sum += (int)s1[i] - 38;
								stop = 1;
								break;
							}
						}
					}
					if (stop)
						break;
				}
				if (stop)
					break;
			}
			index = -1;
		}
		index++;
	}

	std::cout << sum << std::endl;
}