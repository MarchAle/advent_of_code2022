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

void	print_pxl(std::set<int> &strengh, int &x, int &cycle)
{
	static int nb_cycle = 1;

	if (cycle - nb_cycle  == x - 1 || cycle - nb_cycle  == x || cycle - nb_cycle  == x + 1)
		std::cout << '#';
	else
		std::cout << ' ';

	if (cycle % 40 == 0)
	{
		std::cout << std::endl;
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
			print_pxl(strengh, x, cycle);
		}
		cycle++;
		flush_val(x, cycle, pending_val);
		print_pxl(strengh, x, cycle);
	}
}