#pragma once
#include "Grafico.h"
ref class imagen : public Grafico {
protected:
	Bitmap^ i;
	virtual void dibujar(Graphics^ graficador) override {
		graficador->DrawImage(this->i, this->a);
	}
public:
	imagen(String^ ruta, System::Drawing::Rectangle a)
		: Grafico(a) {
		this->i = gcnew Bitmap(ruta);
	}
	void hacer_transparente() {
		Color color = this->i->GetPixel(0, 0);
		this->i->MakeTransparent(color);
	}
	short get_ancho() { return this->a.Width; }
	short get_alto() { return this->a.Height; }
};

