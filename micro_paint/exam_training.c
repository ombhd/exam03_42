#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define is_vld(l) (l > 0 && l <= 300)

typedef struct s_bgd
{
	int		w;
	int		h;
	char	c;
}			   t_bgd;

typedef struct	s_mp
{
	t_bgd	bg;
	char	spec;
	float	xt;
	float	yt;
	float	xb;
	float	yb;
	float	w;
	float	h;
	char	c;
	char	**rec;
}				t_mp;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
		ft_putchar(*s++);
}

void	print_arr(char **arr)
{
	while (*arr)
	{
		ft_putstr(*arr++);
		ft_putchar('\n');
	}
}

int		corrupted(void)
{
	ft_putstr("Error: Operation file corrupted\n");
	return (1);
}

void