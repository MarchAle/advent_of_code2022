#include "./algo.hpp"

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
	std::vector<std::vector<std::pair<int, bool> > > forest;
	int	trees = 0;

	std::string		line;
	std::ifstream	fd("input.txt");
	while (std::getline(fd, line))
	{
		std::vector<std::pair<int, bool> > row;
		int i = 0;
		while (i < line.size())
		{
			std::pair<int, bool> tree;
			tree = std::make_pair (line[i] - 48, false);
			row.push_back(tree);
			i++;
		}
		forest.push_back(row);
	}
	for (std::vector<std::vector<std::pair<int, bool> > >::iterator row = ++forest.begin(); row != --forest.end(); row++)
	{
		int col = 0;
		int mem_size = (*row).at(col).first;
		while (col <= (*row).size() - 1)
		{
			if ((*row).at(col).first > mem_size && (*row).at(col).second == false)
			{
				trees++;
				mem_size = (*row).at(col).first;
				(*row).at(col).second = true;
			}
			else if ((*row).at(col).first > mem_size)
				mem_size = (*row).at(col).first;
			col++;
		}
		col = (*row).size() - 1;
		mem_size = (*row).at(col).first;
		while (col >= 1)
		{
			if ((*row).at(col).first > mem_size && (*row).at(col).second == false)
			{
				trees++;
				mem_size = (*row).at(col).first;
				(*row).at(col).second = true;
			}
			else if ((*row).at(col).first > mem_size)
				mem_size = (*row).at(col).first;
			col--;
		}
	}
	int col = forest.at(0).size() - 2;
	while (col >= 1)
	{
		int mem_size = forest.at(0).at(col).first;
		for (std::vector<std::vector<std::pair<int, bool> > >::iterator row = ++forest.begin(); row != --forest.end(); row++)
		{
			if ((*row).at(col).first > mem_size && (*row).at(col).second == false)
			{
				trees++;
				mem_size = (*row).at(col).first;
				(*row).at(col).second = true;
			}
			else if ((*row).at(col).first > mem_size)
				mem_size = (*row).at(col).first;
		}
		mem_size = forest.back().at(col).first;
		for (std::vector<std::vector<std::pair<int, bool> > >::iterator row = --forest.end(); row != ++forest.begin(); row--)
		{
			if ((*row).at(col).first > mem_size && (*row).at(col).second == false)
			{
				trees++;
				mem_size = (*row).at(col).first;
				(*row).at(col).second = true;
			}
			else if ((*row).at(col).first > mem_size)
				mem_size = (*row).at(col).first;
		}
		col--;
	}

	for (std::vector<std::vector<std::pair<int, bool> > >::iterator row = forest.begin(); row != forest.end(); row++)
	{
		for (std::vector<std::pair<int, bool> >::iterator col = (*row).begin(); col != (*row).end(); col++)
		{
			if ((*col).second == true)
				std::cout << "\x1B[32m" << (*col).first << "\033[0m";
			else
				std::cout << "\x1B[31m" << (*col).first << "\033[0m";
		}
		std::cout << std::endl;
	}

	trees += 2 * (forest.size() - 1) + 2 * (forest.at(0).size() - 1);

	std::cout << trees << std::endl;
}