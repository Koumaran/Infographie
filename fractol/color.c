#include "fractol.h"

int     *create_color()
{
  int     *color;

  color = ft_memalloc(8);
  color[0] = BLACK;
  color[1] = WHITE;
  color[2] = RED;
  color[3] = GREEN;
  color[4] = BLUE;
  color[5] = YELLOW;
  color[6] = PURPLE;
  color[7] = SKY;
  return (color);
}

void   get_color(int *color_tab, int *color, char sign)
{
  int   i;

  i = -1;
  while (++i < 8)
    if (*color == color_tab[i])
      break;
  if (sign == '+')
    i = (i >= 7) ? 0 : i + 1;
  else
    i = (i == 0 || i == 8) ? 7 : i - 1;
  *color = color_tab[i];
}
