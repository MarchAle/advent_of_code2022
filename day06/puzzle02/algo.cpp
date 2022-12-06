#include <fstream>
#include <iostream>
#include <sstream>
#include <set>
#include <vector>

int main()
{
	char			tab[14];
	int				index;
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
			index = 0;
			while (index < 14)
			{
				tab[index] = line[i + index];
				index++;
			}
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
		std::cout << i + 13 << std::endl;
	}
}