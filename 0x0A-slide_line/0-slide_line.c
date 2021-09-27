#include "slide_line.h"

/**
 * slide_line - slides and merges an array of integers (2048 game)
 * @line: points to an array of integers...
 * @size: containing size elements...
 * @direction: that must be slided & merged to this direction
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	int i, pos = 0;

	if ((direction != SLIDE_RIGHT && direction != SLIDE_LEFT) || (size <= 0))
		return (0);
	if (direction == SLIDE_LEFT)
	{
		for (i = 1; i < (int)size; i++)
		{
			if (line[i] && line[i] == line[pos])
			{
				line[pos++] += line[i], line[i] = 0;
			}
			else if (line[i] && line[i] != line[pos])
			{
				if (line[pos] != 0)
					pos++;
				else
					line[pos] += line[i], line[i] = 0;
			}
		}
	}
	else if (direction == SLIDE_RIGHT)
	{
		pos = size - 1;
		for (i = size - 2; i >= 0; i--)
		{
			if (line[i] && line[i] == line[pos])
			{
				line[pos--] += line[i], line[i] = 0;
			}
			else if (line[i] && line[i] != line[pos])
			{
				if (line[pos] != 0)
					pos--;
				else
					line[pos] += line[i], line[i] = 0;
			}
		}
	}
	return (1);
}
