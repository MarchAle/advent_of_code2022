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

void	add_tail_pos(std::vector<t_coord> &tail_pos, t_coord &tail_current)
{
	for (std::vector<t_coord>::iterator it = tail_pos.begin(); it != tail_pos.end(); it++)
	{
		if (tail_current.x == (*it).x && tail_current.y == (*it).y)
			return ;
	}
	tail_pos.push_back(tail_current);
}

void	move_nodes(t_coord &head_current, std::vector<t_coord> &nodes)
{
	t_coord		previous = head_current;

	for (std::vector<t_coord>::iterator node = nodes.begin(); node != nodes.end(); node++)
	{
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				if (previous.x + i == (*node).x && previous.y + j == (*node).y)
					return ;
			}
		}
		if (previous.y == (*node).y)
		{
			if (previous.x < (*node).x)
				(*node).x--;
			else if (previous.x > (*node).x)
				(*node).x++;
		}
		else if (previous.x == (*node).x)
		{
			if (previous.y < (*node).y)
				(*node).y--;
			else if (previous.y > (*node).y)
				(*node).y++;
		}
		else if (previous.y > (*node).y)
		{
			if (previous.x < (*node).x)
				(*node).x--;
			else if (previous.x > (*node).x)
				(*node).x++;
			(*node).y++;
		}
		else if (previous.y < (*node).y)
		{
			if (previous.x < (*node).x)
				(*node).x--;
			else if (previous.x > (*node).x)
				(*node).x++;
			(*node).y--;
		}
		previous = (*node);
	}
}

void	move_head(std::vector<t_coord> &tail_pos, t_coord &head_current, std::vector<t_coord> &nodes, std::string &dir, int step)
{
	int	step_count = 0;
	while (step_count < step)
	{
		switch (dir.at(0))
		{
		case 'R':
			head_current.x++;
			break;
		case 'L':
			head_current.x--;
			break;
		case 'U':
			head_current.y++;
			break;
		case 'D':
			head_current.y--;
			break;
		default:
			break;
		}
		move_nodes(head_current, nodes);
		add_tail_pos(tail_pos, nodes.at(8));
		step_count++;
	}
}

int main()
{
	std::vector<t_coord> 		tail_pos;
	t_coord						head_current;
	std::vector<t_coord>		nodes;
	std::vector<std::string>	command;
	std::string					dir;
	int							step;

	head_current.x = 0;
	head_current.y = 0;
	for (int i = 0; i < 9; i++)
	{
		t_coord		new_node;

		new_node.x = 0;
		new_node.y = 0;
		nodes.push_back(new_node);
	}
	add_tail_pos(tail_pos, nodes.at(0));

	std::string		line;
	std::ifstream	fd("input.txt");
	while (std::getline(fd, line))
	{
		command = split(line);
		dir = command.at(0);
		step = std::stoi(command.at(1));
		move_head(tail_pos, head_current, nodes, dir, step);
	}
	std::cout << tail_pos.size() <<std::endl;
}