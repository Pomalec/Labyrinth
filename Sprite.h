#pragma once

#include "Image.h"
ref class Sprite : public imagen{
	
	short n_subimagesx;
	short n_subimagesy;
	short n_subimages;
	short indice;
	short dx, dy;
	short x, y;
	short ancho, alto;
public:
	Sprite(String^ ruta, System::Drawing::Rectangle a, short n_subimagesx,
		short n_subimagesy, short indice, short n_subimages) :imagen(ruta, a),
		n_subimagesx(n_subimagesx), n_subimagesy(n_subimagesy), indice(indice), n_subimages(n_subimages) {
		this->dx = 0;
		this->dy = 0;
		this->ancho = this->i->Width / this->n_subimagesx;
		this->alto = this->i->Height / this->n_subimagesy;
		this->x = this->indice % this->n_subimagesx * ancho;
		this->y = this->indice / this->n_subimagesx * alto;
		this->hacer_transparente();
	}
	void dibujar(Graphics^ graficador)override {
		System::Drawing::Rectangle a_recorte = System::Drawing::Rectangle(x, y, ancho, alto);
		graficador->DrawImage(this->i, this->a, a_recorte, GraphicsUnit::Pixel);
		
	}
	System::Drawing::Rectangle getpos() {
		return System::Drawing::Rectangle(x + dx, y + dy, ancho, alto);
	}
	short getx() { return x; }
	short gety() { return y; }
	short getdx() { return dx; }
	short getdy() { return dy; }
	void setx(short v) { this->x =v; }
	void sety(short v) { this->y =v; }
	void setdx(short v) { this->dx = v; }
	void setdy(short v) { this->dy = v; }
};

