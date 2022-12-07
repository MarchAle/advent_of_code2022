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
		std::cout << "OUI " << (*it)->name << " " << name << std::endl;
		if ((*it)->name == name)
			return ((*it));
	}
	return (NULL);
}

int main()
{
	int				i = 0;
	s_list			*home;

	home = (s_list *)malloc(sizeof(s_list));
	home->name = "home";

	// std::vector<struct s_list *> 	test;
	// std::cout << "TEST : " << test.size() << std::endl;
	// home->dir = test;
	home->dir.resize(1);
	std::cout << "nb sous dir " << home->dir.size() << std::endl;
	// std::cout << "ICI" << std::endl;
	s_list			*current = home;

	std::vector<std::string> output;

	std::string		line;
	std::ifstream	input("input.txt");
	while (std::getline(input, line))
	{
		std::cout << line << std::endl;
		output = split(line);
		if (i > 1)
		{
			if (output.at(0) == "$" && output.at(1) == "cd")
			{
				if (output.at(2) == "..")
					current = current->parent;
				else
				{
					current = get_child(current->dir, output.at(2));
				}
			}
			else if (output.at(0) == "dir")
			{
				s_list *new_dir;
				new_dir = (s_list *)malloc(sizeof(s_list));
				current->dir.push_back(new_dir);
				// new_dir->name = output.at(1);
				// new_dir->parent = current;
				std::cout << "nb sous dir " << current->dir.size() << std::endl;
			}
			else if (output.at(0) != "$")
			{
				current->files.insert(current->files.begin(), std::stoi(output.at(0)));
			}
		}
		i++;
	}
}