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

void	resolve(std::vector<std::vector<std::pair<int, bool> > > forest, int row, int col, int &scenic)
{
	int	tree = forest.at(row).at(col).first;
	int row2 = row + 1;
	int col2 = col + 1;
	int N = 0;
	int S = 0;
	int E = 0;
	int O = 0;
	while (row2 < forest.size())
	{
		S++;
		if (forest.at(row2).at(col).first >= tree)
			break ;
		row2++;
	}
	row2 = row - 1;
	while (row2 >= 0)
	{
		N++;
		if (forest.at(row2).at(col).first >= tree)
			break ;
		row2--;
	}
	while (col2 < forest.at(0).size())
	{
		E++;
		if (forest.at(row).at(col2).first >= tree)
			break ;
		col2++;
	}
	col2 = col - 1;
	while (col2 >= 0)
	{
		O++;
		if (forest.at(row).at(col2).first >= tree)
			break ;
		col2--;
	}
	if (N * S * O * E > scenic)
		scenic = N * S * O * E;
}

int main()
{
	std::vector<std::vector<std::pair<int, bool> > > forest;
	int	scenic = 0;

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

	for (int row = 0; row != forest.size(); row++)
	{
		for (int col = 0; col != forest.at(row).size(); col++)
		{
			resolve(forest, row, col, scenic);
		}
	}
	std::cout << scenic << std::endl;
}