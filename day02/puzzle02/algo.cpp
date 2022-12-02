#include <fstream>
#include <iostream>
#include <set>

int main()
{
	int				score = 0;
 
	std::string		line;
	std::ifstream	input("input.txt");
	while (std::getline(input, line))
	{
		if (line[0] == 'A' && line[2] == 'X')
		{
			score += 3;
			score += 0;
		}
		else if (line[0] == 'B' && line[2] == 'X')
		{
			score += 1;
			score += 0;
		}
		else if (line[0] == 'C' && line[2] == 'X')
		{
			score += 2;
			score += 0;
		}
		else if (line[0] == 'A' && line[2] == 'Y')
		{
			score += 1;
			score += 3;
		}
		else if (line[0] == 'B' && line[2] == 'Y')
		{
			score += 2;
			score += 3;
		}
		else if (line[0] == 'C' && line[2] == 'Y')
		{
			score += 3;
			score += 3;
		}
		else if (line[0] == 'A' && line[2] == 'Z')
		{
			score += 2;
			score += 6;
		}
		else if (line[0] == 'B' && line[2] == 'Z')
		{
			score += 3;
			score += 6;
		}
		else if (line[0] == 'C' && line[2] == 'Z')
		{
			score += 1;
			score += 6;
		}
	}

	std::cout << score << std::endl;
}