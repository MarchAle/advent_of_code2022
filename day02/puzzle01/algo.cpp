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
			score += 1;
		}
		else if (line[0] == 'B' && line[2] == 'X')
		{
			score += 0;
			score += 1;
		}
		else if (line[0] == 'C' && line[2] == 'X')
		{
			score += 6;
			score += 1;
		}
		else if (line[0] == 'A' && line[2] == 'Y')
		{
			score += 6;
			score += 2;
		}
		else if (line[0] == 'B' && line[2] == 'Y')
		{
			score += 3;
			score += 2;
		}
		else if (line[0] == 'C' && line[2] == 'Y')
		{
			score += 0;
			score += 2;
		}
		else if (line[0] == 'A' && line[2] == 'Z')
		{
			score += 0;
			score += 3;
		}
		else if (line[0] == 'B' && line[2] == 'Z')
		{
			score += 6;
			score += 3;
		}
		else if (line[0] == 'C' && line[2] == 'Z')
		{
			score += 3;
			score += 3;
		}
	}

	std::cout << score << std::endl;
}