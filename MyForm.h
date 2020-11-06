#pragma once
#include <Windows.h> 
#include <MMSystem.h>
#include "Game.h"
namespace Labyrinth {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	public ref class MyForm : public System::Windows::Forms::Form
	{
		Graphics^ g;
		BufferedGraphics^ buffer;
		Game^ game;
	public:
		MyForm(void)
		{
			InitializeComponent();
			this-> g = this->CreateGraphics();
			this-> buffer = BufferedGraphicsManager::Current->Allocate(this->g, this->ClientRectangle);
			game = gcnew Game();
		}

	protected:
		
		~MyForm()
		{
			if (components)
			{
				delete game;

				delete components;
			}
		}

	private:
	
	private: System::ComponentModel::IContainer^ components;



#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(834, 516);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		
		
		this->game->play(this->buffer->Graphics);
		this->buffer->Render();
	}

	
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
			case Keys::W:game->tecla(0,-5);break;
			case Keys::A:game->tecla(-5,0);break;
			case Keys::S:game->tecla(0,5);break;
			case Keys::D:game->tecla(5,0);break;
		default:
			break;
		}
	}
	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		game->tecla(0, 0);

	}
	};
}
