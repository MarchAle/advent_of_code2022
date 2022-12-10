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

void	move_tail(t_coord &head_current, t_coord &tail_current)
{
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (head_current.x + i == tail_current.x && head_current.y + j == tail_current.y)
				return ;
		}
	}
	if (head_current.y == tail_current.y)
	{
		if (head_current.x < tail_current.x)
			tail_current.x--;
		else if (head_current.x > tail_current.x)
			tail_current.x++;
	}
	else if (head_current.x == tail_current.x)
	{
		if (head_current.y < tail_current.y)
			tail_current.y--;
		else if (head_current.y > tail_current.y)
			tail_current.y++;
	}
	else if (head_current.y > tail_current.y)
	{
		if (head_current.x < tail_current.x)
			tail_current.x--;
		else if (head_current.x > tail_current.x)
			tail_current.x++;
		tail_current.y++;
	}
	else if (head_current.y < tail_current.y)
	{
		if (head_current.x < tail_current.x)
			tail_current.x--;
		else if (head_current.x > tail_current.x)
			tail_current.x++;
		tail_current.y--;
	}
}

void	move_head(std::vector<t_coord> &tail_pos, t_coord &head_current, t_coord &tail_current, std::string &dir, int step)
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
		move_tail(head_current, tail_current);
		add_tail_pos(tail_pos, tail_current);
		step_count++;
	}
}

int main()
{
	std::vector<t_coord> 		tail_pos;
	t_coord						head_current;
	t_coord						tail_current;
	std::vector<std::string>	command;
	std::string					dir;
	int							step;

	head_current.x = 0;
	head_current.y = 0;
	tail_current.x = 0;
	tail_current.y = 0;
	add_tail_pos(tail_pos, tail_current);

	std::string		line;
	std::ifstream	fd("input.txt");
	while (std::getline(fd, line))
	{
		command = split(line);
		dir = command.at(0);
		step = std::stoi(command.at(1));
		move_head(tail_pos, head_current, tail_current, dir, step);
	}
	std::cout << tail_pos.size() <<std::endl;
}