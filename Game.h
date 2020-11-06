#pragma once
#include "Sprite.h"
#include "Mc.h"
#include "Map.h"
ref class Game
{
	Map^ mapa;
	Mc^ king;
public:
	Game() {
		mapa = gcnew Map();
		king = gcnew Mc();
	}

	void play(Graphics^ g) {
		
		mapa->dibujar(g);
		if (!mapa->validarmov(king->getpos()))
		{
			king->mover();
		}
		king->dibujar(g);
	}
	void tecla(short dx, short dy) {
		king->setdx(dx);
		king->setdy(dy);

	}
private:
	void renderizar(Graphics^ g) {

		this->king->animar(g);


	}
};

