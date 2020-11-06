#pragma once
#include "Sprite.h"
ref class Mc:public Sprite
{
	short vidas;

public:
	Mc():Sprite("images\\mcmov.png", System::Drawing::Rectangle(200, 490, 150, 150),9, 4,
			18, 40) {
	}
	bool perdervida() {
		return --this->vidas == 0;
	}
	void mover() {
		
		setx(getx() + getdx());
	
		sety(gety() + getdy());
	}
	void stand(char i) {
		switch (i)
		{
		default:
			break;
		}
	}
	
};

