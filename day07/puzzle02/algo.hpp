#include <fstream>
#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <cstdlib>
#include <string.h>

struct s_list
{
	char *							name;
	std::vector<struct s_list *> 	dir;
	int								sum;
	struct s_list					*parent;
};