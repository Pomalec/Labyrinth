#pragma once
#include <iostream>
using namespace System::Drawing;
 ref class Map
{
private:
	int** map;
	Bitmap^ floor;
	Bitmap^ wall;
	
public: 
	Map() {
		map = new int* [50];
		for (short i = 0; i < 50; i++)
		{
			map[i] = new int[50];
			for (short j = 0; j < 50; j++)
			{
				if (i==0||j==0||i==15||j==15||rand()%10==0)
				{
					map[i][j] == 1;
				}
				else
				{
					map[i][j] == 0;
				}
			}
		}
		floor = gcnew Bitmap("images\\floor.png");
		wall = gcnew Bitmap("images\\wall.png");
	 }
	 void dibujar(Graphics^ g) {
		 for (short i = 0; i < 50; i++)
		 {
			 for (short j = 0; j < 50; j++)
			 {
				 if (map[i][j]==0)
				 {
					 g->DrawImage(floor, j * 50, i * 50, 50, 50);
				 }
				 else
				 {
					 g->DrawImage(wall, j * 50, i * 50, 50, 50);
				 }
			 }
		 }
	 }
	 bool validarmov(System::Drawing::Rectangle r) {
		 return map[(r.Y + 1) / 50][(r.X + 1) / 50] == 1 ||
			 map[(r.Y + 1) / 50][(r.X + r.Width - 1) / 50] == 1 ||
			 map[(r.Y + r.Height - 1) / 50][(r.X + r.Width - 1) / 50] == 1 ||
			 map[(r.Y + r.Height - 1) / 50][(r.X + 1) / 50] == 1;
	 }
};

