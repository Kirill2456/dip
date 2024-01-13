#include "target.h"
#include <math.h>
#define PI 3.1415

Target::Target()
{

}
float Target :: degrees_peleng(struct main_target* ptar, struct  carrier_ship* pship)
{
 float dx1 = ptar->x - pship->x;
 float dy1 = ptar->y - pship->y;
 float arctan = (atan(dx1 / dy1) * 180 / PI);
 if (arctan < 0)
 {
  if (dx1 > 0 && dy1 < 0)
   return (180 + arctan);
  if (dx1 < 0 && dy1 < 0)
   return (270 + arctan);
  if (dx1 < 0 && dy1>0)
   return (360 + arctan);
  else
   return (90 + arctan);
 }
 if (dx1 < 0 && dy1 < 0)
  return (180 + arctan);
 return (arctan);
}

float Target :: calcelation_distance_ship_to_target(struct main_target* ptar, struct  carrier_ship* pship, int var, int j)
{
 float a = sqrt (((ptar[var].x[j] - pship->x) * (ptar[var].x[j] - pship->x)) - ((ptar[var].y[j] - pship->y) * (ptar[var].y[j] - pship->y)));
 return a;
}

float Target :: ku_degrees(struct  carrier_ship* pship, float peling)
{
 float ku = peling - pship->K;
 if (ku >= 180)
 {
  ku = peling - pship->K;
  return ku;
 }
 if (ku <= -180)
 {
  return ku + 360;
 }
 else
  return ku;
}

void Target :: getting_x (struct main_target ptar)
{
 float temp = (ptar.K) * PI / 180;
 float x = ptar.Dist * sin(temp);
 ptar.x = x;
}

void Target :: getting_y (struct main_target ptar)
{
 float temp = (ptar.K) * PI / 180;
 float y = ptar.Dist * cos(temp);
 ptar.y = y;
}

void Target :: change(struct main_target* ptar, int var, int j)
{
 float change_x;
 float change_y;
 float rad = (90 - ptar[var].K) * PI / 180;
 change_x = ptar->V * cos(rad) * 1;
 change_y = ptar->V * sin(rad) * 1;
 if (j == 0)
 {
  ptar[var].x[j] += change_x;
  ptar[var].y[j] += change_y;
 }
 else
 {
  ptar[var].x[j] = ptar[var].x[j - 1] + change_x;
  ptar[var].y[j] = ptar[var].y[j - 1] + change_y;
 }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
void Target :: getting_x_carrier_ship(struct  carrier_ship* pship)
{
 float rad = (180 - pship->K) * PI / 180;
 float x = pship->Dist * sin(rad);
 pship->x = x;
};

void Target :: getting_y_carrier_ship(struct  carrier_ship* pship)
{
 float rad = (180 - pship->K) * PI / 180;
 float y = pship->Dist * cos(rad);
 pship->y = y;
};

void Target :: change_carrier_ship(struct  carrier_ship* pship)
{
 float change_x;
 float change_y;
 float rad = (90 - pship->K) * PI / 180;
 change_x = pship->V * cos(rad) * 1;
 change_y = pship->V * sin(rad) * 1;

 pship->x += change_x;
 pship->y += change_y;
}
