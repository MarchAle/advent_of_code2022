#include <fstream>
#include <iostream>
#include <sstream>
#include <set>
#include <vector>

int main()
{
	char			tab[4];
	int				stop = 0;
	std::string		line;
	std::ifstream	input("input.txt");
	while (std::getline(input, line))
	{
		int	i = 0;
		while (line[i + 3] && stop == 0)
		{
			int a = 0;
			stop = 1;
			tab[0] = line[i];
			tab[1] = line[i + 1];
			tab[2] = line[i + 2];
			tab[3] = line[i + 3];
			while (tab[a])
			{
				int b = a + 1;
				while (tab[b])
				{
					if (tab[a] == tab[b])
					{
						stop = 0;
						break;
					}
					b++;
				}
				a++;
			}
			i++;
		}
		std::cout << i + 3 << std::endl;
	}
}