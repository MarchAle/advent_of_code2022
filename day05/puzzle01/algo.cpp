#include <fstream>
#include <iostream>
#include <sstream>
#include <set>
#include <vector>

void	print_vector(std::vector<char> v)
{
	for (std::vector<char>::iterator it = v.begin(); it != v.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
}

std::vector<std::string> split(std::string &names)
{
	std::string tmp = names;
	std::stringstream ss(names);
	std::vector<std::string> result;
	while (getline(ss, tmp, ' '))
		result.push_back(tmp);
	return (result);
}

int main()
{
	std::vector<char> stacks[9];
 
	std::string		line;
	std::ifstream	input("input.txt");
	while (std::getline(input, line))
	{
		if (line[0] == '[')
		{
			int index = 1;
			int rank = 0;
			while (index <= line.length())
			{
				if (line[index] != ' ')
					stacks[rank].insert(stacks[rank].begin(), line[index]);
				index += 4;
				rank++;
			}
		}
		else if (line[0] == 'm')
		{
			std::vector<std::string>	cmd = split(line);

			int nb_move = std::stoi(cmd.at(1));
			int stack1 = std::stoi(cmd.at(3)) - 1;
			int stack2 = std::stoi(cmd.at(5)) - 1;
			std::cout << nb_move << " " << stack1 << " " << stack2 << std::endl;
			while (nb_move > 0)
			{
				stacks[stack2].push_back(stacks[stack1].back());
				if (!stacks[stack1].empty())
					stacks[stack1].pop_back();
				nb_move--;
			}
		}
	}
	std::cout << stacks[0].back() << " " << stacks[1].back() << " " << stacks[2].back() << " " << stacks[3].back() << " " << stacks[4].back() << " " << stacks[5].back() << " " << stacks[6].back() << " " << stacks[7].back() << " " << stacks[8].back() << " "  << std::endl;
}