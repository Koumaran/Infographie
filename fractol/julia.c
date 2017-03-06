#include "fractol.h"

void julia(t_var *var)
{
  double tmp;
  int     i;

  X1 = (!X1) ? -2.5 : X1;
  X2 = 2.5;
  Y1 = (!Y1) ? -1.2 : Y1;
  Y2 = 1.2;
  if (PLAY)
  	{
  		I_MAX = (I_MAX) ? I_MAX + 1: 20;
  		I_MAX = (I_MAX > 200) ? 20 : I_MAX;
  	}
  I_MAX = (!PLAY) ? 100 : I_MAX;
  ZOOM_X = (X2 - X1 + ZOOM);
  ZOOM_Y = (Y2 - Y1 + ZOOM);
  X = -1;
  while (++X < WIDTH_WIN)
  {
    Y = -1;
    while (++Y < HEIGHT_WIN)
    {
      CR = 0.285;
      CI = 0.01;
      ZR = X / ZOOM + X1;
      ZI = Y / ZOOM + Y1;
      i = -1;
      while ((ZR * ZR + ZI * ZI) < 4 && ++i < I_MAX)
      {
        tmp = ZR;
        ZR = ZR * ZR - ZI * ZI + CR;
        ZI = 2 * ZI * tmp + CI;
      }
      if (i == I_MAX)
      {
        if (COLOR)
          put_pixel(var, BLACK);
        else
          put_pixel(var, WHITE);
      }
      else
        put_pixel(var, i * COLOR);
    }
  }
}
