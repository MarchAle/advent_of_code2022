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

void	routine_m0(std::vector<std::vector<int> > &monkeys, std::vector<int> &counts)
{
	for (std::vector<int>::iterator item = monkeys.at(0).begin(); item != monkeys.at(0).end(); item++)
	{
		int new_item = (*item) * 17;
		new_item %= 9699690;
		if (new_item % 13 == 0)
			monkeys.at(6).push_back(new_item);
		else
			monkeys.at(7).push_back(new_item);
		counts.at(0)++;
	}
	monkeys.at(0).clear();
}

void	routine_m1(std::vector<std::vector<int> > &monkeys, std::vector<int> &counts)
{
	for (std::vector<int>::iterator item = monkeys.at(1).begin(); item != monkeys.at(1).end(); item++)
	{
		int new_item = (*item) + 8;
		new_item %= 9699690;
		if (new_item % 7 == 0)
			monkeys.at(0).push_back(new_item);
		else
			monkeys.at(7).push_back(new_item);
		counts.at(1)++;
	}
	monkeys.at(1).clear();
}

void	routine_m2(std::vector<std::vector<int> > &monkeys, std::vector<int> &counts)
{
	for (std::vector<int>::iterator item = monkeys.at(2).begin(); item != monkeys.at(2).end(); item++)
	{
		int new_item = (*item) + 6;
		new_item %= 9699690;
		if (new_item % 19 == 0)
			monkeys.at(5).push_back(new_item);
		else
			monkeys.at(3).push_back(new_item);
		counts.at(2)++;
	}
	monkeys.at(2).clear();
}

void	routine_m3(std::vector<std::vector<int> > &monkeys, std::vector<int> &counts)
{
	for (std::vector<int>::iterator item = monkeys.at(3).begin(); item != monkeys.at(3).end(); item++)
	{
		int new_item = (*item) * 19;
		new_item %= 9699690;
		if (new_item % 2 == 0)
			monkeys.at(4).push_back(new_item);
		else
			monkeys.at(1).push_back(new_item);
		counts.at(3)++;
	}
	monkeys.at(3).clear();
}

void	routine_m4(std::vector<std::vector<int> > &monkeys, std::vector<int> &counts)
{
	for (std::vector<int>::iterator item = monkeys.at(4).begin(); item != monkeys.at(4).end(); item++)
	{
		int new_item = (*item) + 7;
		new_item %= 9699690;
		if (new_item % 5 == 0)
			monkeys.at(1).push_back(new_item);
		else
			monkeys.at(0).push_back(new_item);
		counts.at(4)++;
	}
	monkeys.at(4).clear();
}

void	routine_m5(std::vector<std::vector<int> > &monkeys, std::vector<int> &counts)
{
	for (std::vector<int>::iterator item = monkeys.at(5).begin(); item != monkeys.at(5).end(); item++)
	{
		int new_item = (*item) * (*item);
		new_item %= 9699690;
		if (new_item % 3 == 0)
			monkeys.at(3).push_back(new_item);
		else
			monkeys.at(4).push_back(new_item);
		counts.at(5)++;
	}
	monkeys.at(5).clear();
}

void	routine_m6(std::vector<std::vector<int> > &monkeys, std::vector<int> &counts)
{
	for (std::vector<int>::iterator item = monkeys.at(6).begin(); item != monkeys.at(6).end(); item++)
	{
		int new_item = (*item) + 1;
		new_item %= 9699690;
		if (new_item % 11 == 0)
			monkeys.at(5).push_back(new_item);
		else
			monkeys.at(2).push_back(new_item);
		counts.at(6)++;
	}
	monkeys.at(6).clear();
}

void	routine_m7(std::vector<std::vector<int> > &monkeys, std::vector<int> &counts)
{
	for (std::vector<int>::iterator item = monkeys.at(7).begin(); item != monkeys.at(7).end(); item++)
	{
		int new_item = (*item) + 2;
		new_item %= 9699690;
		if (new_item % 17 == 0)
			monkeys.at(6).push_back(new_item);
		else
			monkeys.at(2).push_back(new_item);
		counts.at(7)++;
	}
	monkeys.at(7).clear();
}

int main(int ac, char **av)
{
	std::vector<int> counts(8, 0);
	std::vector<std::vector<int> > monkeys {	{52, 60, 85, 69, 75, 75},
												{96, 82, 61, 99, 82, 84, 85},
												{95, 79},
												{88, 50, 82, 65, 77},
												{66, 90, 59, 90, 87, 63, 53, 88},
												{92, 75, 62},
												{94, 86, 76, 67},
												{57}};
	for (int i = 0; i < atoi(av[1]); i++)
	{
		routine_m0(monkeys, counts);
		routine_m1(monkeys, counts);
		routine_m2(monkeys, counts);
		routine_m3(monkeys, counts);
		routine_m4(monkeys, counts);
		routine_m5(monkeys, counts);
		routine_m6(monkeys, counts);
		routine_m7(monkeys, counts);
	}
	int most = 0;
	int second_most = 0;
	for (std::vector<int>::iterator count = counts.begin(); count != counts.end(); count++)
	{
		if ((*count) > most)
		{
			second_most = most;
			most = (*count);
		}
		else if ((*count) > second_most)
			second_most = (*count);
	}
	std::cout << most << " " << second_most << " " << most * second_most << std::endl;
}