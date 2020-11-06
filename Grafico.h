#pragma once
#include <Windows.h> 
#include <MMSystem.h>
using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;
ref class Grafico abstract
{
protected:
	short dx, dy;
	System::Drawing::Rectangle a;
public:
	Grafico(System::Drawing::Rectangle a)
		: a(a), dx(0), dy(0) { }
	void animar(Graphics^ g) {
		this->dibujar(g);
		this->mover();
	}
protected:
	virtual void dibujar(Graphics^ graficador) abstract;
	void mover() {
		this->a.X += this->dx;
		this->a.Y += this->dy;
	}
};

