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

void	flush_val(int &x, int &cycle, std::vector<t_val> pending_val)
{
	for (std::vector<t_val>::iterator it = pending_val.begin(); it != pending_val.end(); it++)
	{
		if ((*it).cycle == cycle)
			x += (*it).val;
	}
}

void	add_strengh(std::set<int> &strengh, int &x, int &cycle)
{
	static int nb_cycle = 20;

	if (cycle == nb_cycle && cycle <= 220)
	{
		strengh.insert(cycle * x);
		nb_cycle += 40;
	}
}

int main()
{
	std::vector<std::string>			command;
	std::string							instruc;
	std::vector<t_val> 					pending_val;
	std::set<int>						strengh;
	int									x = 1;
	int									cycle = 1;

	std::string		line;
	std::ifstream	fd("input.txt");
	while (std::getline(fd, line))
	{
		command = split(line);
		instruc = command.at(0);
		if (instruc == "addx")
		{
			t_val	 pair;

			pair.val = std::stoi(command.at(1));
			pair.cycle = cycle + 2;
			pending_val.push_back(pair);
			cycle++;
			flush_val(x, cycle, pending_val);
			add_strengh(strengh, x, cycle);
		}
		cycle++;
		flush_val(x, cycle, pending_val);
		add_strengh(strengh, x, cycle);
	}
	int sum = 0;
	for (std::set<int>::iterator it = strengh.begin(); it != strengh.end(); it++)
		sum += (*it);
	std::cout << sum << std::endl;
}