
#include <iostream>
#include "diplom.h"
#include <math.h>
#include <time.h>
#include <QApplication>

using namespace std;

#define PI 3.14159
#define AMOUNT 10
int var = 0, j = 0;
float pealing = 0;
bool flag;


void coordinates_carrier_ship(struct carrier_ship* pship)
{
 float k, v;
 cout << "Print spead value carrier ship\n";
 cin >> v;
 pship->V = v;
 //pship->V = (float)(rand()) / RAND_MAX * 10;

 cout << "Print angle value carrier ship\n";
 cin >> k;
 pship->K = k;
 //pship->V = (float)(rand()) / RAND_MAX * 360;

 //if (flag == 1)
 //{
  pship->Dist = 0;
  //flag = 0;
 //}
}

void getting_x_carrier_ship(struct  carrier_ship* pship)
{
 float rad = (180 - pship->K) * PI / 180;
 float x = pship->Dist * sin(rad);
 pship->x = x;
};

void getting_y_carrier_ship(struct  carrier_ship* pship)
{
 float rad = (180 - pship->K) * PI / 180;
 float y = pship->Dist * cos(rad);
 pship->y = y;
};

void change_carrier_ship(struct  carrier_ship* pship)
{
 float change_x;
 float change_y;
 float rad = (90 - pship->K) * PI / 180;
 change_x = pship->V * cos(rad) * 1;
 change_y = pship->V * sin(rad) * 1;

 pship->x += change_x;
 pship->y += change_y;
}

void coordinates(struct main_target ptar[], int var, int j)
{
 float k, v, dist;
 cout << "Print speed value target\n";
 cin >> v;
 //ptar->V = v;
 ptar->V = (float)(rand()) / RAND_MAX * 360;

 cout << "Print angle value target\n";
 cin >> k;
 //ptar[var].K = k;
 ptar->K = (float)(rand()) / RAND_MAX * 360;

 cout << "Print distance value target\n";
 cin >> dist;
 //ptar[var].Dist = dist;
 ptar[var].Dist = (float)(rand()) / RAND_MAX * 1000;
}

void getting_x (struct main_target ptar[], int var, int j)
{
 float temp = (ptar[var].K) * PI / 180;
 float x = ptar[var].Dist * sin(temp);
 ptar[var].x[j] = x;
}

void getting_y (struct main_target ptar[], int var, int j)
{
 float temp = (ptar[var].K) * PI / 180;
 float y = ptar[var].Dist * cos(temp);
 ptar[var].y[j] = y;
}

float degrees_peleng(struct main_target* ptar, struct  carrier_ship* pship, int var, int j)
{
 float dx1 = ptar[var].x[j] - pship->x;
 float dy1 = ptar[var].y[j] - pship->y;
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

void change(struct main_target* ptar, int var, int j)
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

float calcelation_distance_ship_to_target(struct main_target* ptar, struct  carrier_ship* pship, int var, int j)
{
 float a = sqrt (((ptar[var].x[j] - pship->x) * (ptar[var].x[j] - pship->x)) - ((ptar[var].y[j] - pship->y) * (ptar[var].y[j] - pship->y)));
 return a;
}

float ku_degrees(struct  carrier_ship* pship, float peling)
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

int main(int argc, char *argv[])
{
 int vibor = 1;
 srand(time(NULL));
// struct  main_target tar[AMOUNT];
 //struct  carrier_ship ship;
 coordinates_carrier_ship(&ship);
 getting_x_carrier_ship(&ship);
 getting_y_carrier_ship(&ship);

 for (; var < AMOUNT; ++var)
 {
  if (vibor == 1)
  {
   coordinates(tar, var, j);
   getting_x(tar, var, j);
   getting_y(tar, var, j);
   pealing = degrees_peleng(tar, &ship, var, j);
   cout << "X: " << tar[var].x[j] << "\t" << "Y: " << tar[var].y[j] << endl;
   cout << "Distance: " << calcelation_distance_ship_to_target(tar, &ship, var, j) << "\t" << "Peleng: " << degrees_peleng(tar, &ship, var, j) << endl;   cout << "Kurs_degree: " << ku_degrees(&ship, pealing) << endl;
      j++;
     for (; j < AMOUNT; ++j)
     {
      change_carrier_ship(&ship);   change(tar, var, j);
      cout << "Carrier_ship X: " << ship.x << "\t" << "Carrier_ship Y: " << ship.y << endl;
      cout << "Distance_to_target: " << calcelation_distance_ship_to_target(tar, &ship, var, j) << endl;
      tar[var].Dist = calcelation_distance_ship_to_target(tar, &ship, var, j);
      cout << "X: " << tar[var].x[j] << "\t" << "Y: " << tar[var].y[j] << endl;
      cout << "Pealing: " << degrees_peleng(tar, &ship, var, j) << endl;
      pealing = degrees_peleng(tar, &ship, var, j);
      cout << "Kurs_degrees: " << ku_degrees(&ship, pealing) << endl;
     }
     cout << "Create more target\t 1 - Yes  0 - No\n";  cin >> vibor;
     j = 0; }
     else  {
      break;  }
    }
 QApplication a(argc, argv);
 diplom w;
 w.show();
 return a.exec();
   }
/*
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    diplom w;
    w.show();
    return a.exec();
}
*/
