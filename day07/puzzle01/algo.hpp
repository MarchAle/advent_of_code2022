#include <fstream>
#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <cstdlib>

struct s_list
{
	std::string						name;
	std::vector<struct s_list *> 	dir;
	std::vector<int>				files;
	struct s_list					*parent;
};