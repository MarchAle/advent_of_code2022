#include "./algo.hpp"

typedef std::vector<std::vector<int> > grid;

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
	int 	i = 0;
	grid	map;

	std::string		line;
	std::ifstream	fd("input.txt");
	while (std::getline(fd, line))
	{
		std::vector<int> map_line;
		map.push_back(map_line);
		for (int j = 0; j < line.size(); j++)
			map[i].push_back(line[j]);
		i++;
	}
	std::cout << (char)map[10][10];
}