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

s_list	*get_child(std::vector<struct s_list *> &dir, std::string name)
{
	for (std::vector<struct s_list *>::iterator it = dir.begin(); it != dir.end(); it++)
	{
		if ((*it)->name == name)
			return ((*it));
	}
	return (NULL);
}

int	sum_dir(s_list *current, std::set<int> &spaces)
{
	int	sum = current->sum;
	for (std::vector<struct s_list *>::iterator it = current->dir.begin(); it != current->dir.end(); it++)
	{
		sum += sum_dir(*it, spaces);
	}
	spaces.insert(sum);
	return (sum);
}

int main()
{
	int				i = 0;
	s_list			*home;

	home = (s_list *)malloc(sizeof(s_list));
	home->name = "home";
	s_list			*current = home;

	std::vector<std::string> output;

	std::string		line;
	std::ifstream	input("input.txt");
	while (std::getline(input, line))
	{
		output = split(line);
		if (i > 1)
		{
			if (output.at(0) == "$" && output.at(1) == "cd")
			{
				if (output.at(2) == "..")
					current = current->parent;
				else
					current = get_child(current->dir, output.at(2));
			}
			else if (output.at(0) == "dir")
			{
				s_list *new_dir;
				new_dir = (s_list *)malloc(sizeof(s_list));
				new_dir->name = (char *)malloc(sizeof(char) * output.at(1).size());
				strcpy(new_dir->name, output.at(1).c_str());
				new_dir->parent = current;
				new_dir->sum = 0;
				current->dir.push_back(new_dir);
			}
			else if (output.at(0) != "$")
				current->sum += std::stoi(output.at(0));
		}
		i++;
	}
	std::set<int> spaces;
	int total_sum = sum_dir(home, spaces);
	int space_left = 70000000 - total_sum;
	int min_space = 30000000 - space_left;

	std::cout << total_sum << " " << space_left << " " << min_space << std::endl;

	for (std::set<int>::iterator it = spaces.begin(); it != spaces.end(); it++)
	{
		if ((*it) > min_space)
		{
			std::cout << *it << std::endl;
			break;
		}
	}
	exit(1);
}