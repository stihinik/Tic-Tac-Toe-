#pragma once

#include "GameMap.h"
#include "Gamer.h"

#include<Windows.h>
namespace TicTacToe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Ñâîäêà äëÿ GameForm
	/// </summary>
	public ref class GameForm : public System::Windows::Forms::Form
	{
	public:
		GameForm(void)
		{
			InitializeComponent();
			//
			//TODO: äîáàâüòå êîä êîíñòğóêòîğà
			//
		}

	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ğåñóğñû.
		/// </summary>
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ íîâàÿÈãğàToolStripMenuItem;

	private: System::Windows::Forms::StatusStrip^ status;
	private: System::Windows::Forms::ToolStripStatusLabel^ statusMove;


	private: System::Windows::Forms::ToolStripMenuItem^ îÏğîãğàììåToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^ dataGridView;


	private:
		/// <summary>
		/// Îáÿçàòåëüíàÿ ïåğåìåííàÿ êîíñòğóêòîğà.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Òğåáóåìûé ìåòîä äëÿ ïîääåğæêè êîíñòğóêòîğà — íå èçìåíÿéòå 
		/// ñîäåğæèìîå ıòîãî ìåòîäà ñ ïîìîùüş ğåäàêòîğà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GameForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->íîâàÿÈãğàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->îÏğîãğàììåToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûõîäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->status = (gcnew System::Windows::Forms::StatusStrip());
			this->statusMove = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip1->SuspendLayout();
			this->status->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->íîâàÿÈãğàToolStripMenuItem,
					this->îÏğîãğàììåToolStripMenuItem, this->âûõîäToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(354, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// íîâàÿÈãğàToolStripMenuItem
			// 
			this->íîâàÿÈãğàToolStripMenuItem->Name = L"íîâàÿÈãğàToolStripMenuItem";
			this->íîâàÿÈãğàToolStripMenuItem->Size = System::Drawing::Size(81, 20);
			this->íîâàÿÈãğàToolStripMenuItem->Text = L"Íîâàÿ èãğà";
			this->íîâàÿÈãğàToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::íîâàÿÈãğàToolStripMenuItem_Click);
			// 
			// îÏğîãğàììåToolStripMenuItem
			// 
			this->îÏğîãğàììåToolStripMenuItem->Name = L"îÏğîãğàììåToolStripMenuItem";
			this->îÏğîãğàììåToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->îÏğîãğàììåToolStripMenuItem->Text = L"Î ïğîãğàììå";
			this->îÏğîãğàììåToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::îÏğîãğàììåToolStripMenuItem_Click);
			// 
			// âûõîäToolStripMenuItem
			// 
			this->âûõîäToolStripMenuItem->Name = L"âûõîäToolStripMenuItem";
			this->âûõîäToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->âûõîäToolStripMenuItem->Text = L"Âûõîä";
			this->âûõîäToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::âûõîäToolStripMenuItem_Click);
			// 
			// status
			// 
			this->status->ImageScalingSize = System::Drawing::Size(20, 20);
			this->status->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->statusMove });
			this->status->Location = System::Drawing::Point(0, 361);
			this->status->Name = L"status";
			this->status->Size = System::Drawing::Size(354, 25);
			this->status->TabIndex = 1;
			this->status->Text = L"statusStrip1";
			// 
			// statusMove
			// 
			this->statusMove->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"statusMove.Image")));
			this->statusMove->Name = L"statusMove";
			this->statusMove->Size = System::Drawing::Size(88, 20);
			this->statusMove->Text = L"Õîä èãğîêà";
			// 
			// dataGridView
			// 
			this->dataGridView->AllowUserToAddRows = false;
			this->dataGridView->AllowUserToDeleteRows = false;
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView->Location = System::Drawing::Point(0, 24);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->RowHeadersWidth = 51;
			this->dataGridView->Size = System::Drawing::Size(354, 337);
			this->dataGridView->TabIndex = 2;
			this->dataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &GameForm::dataGridView_CellContentClick);
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(354, 386);
			this->Controls->Add(this->dataGridView);
			this->Controls->Add(this->status);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximumSize = System::Drawing::Size(370, 425);
			this->MinimumSize = System::Drawing::Size(370, 425);
			this->Name = L"GameForm";
			this->Text = L"Èãğà Êğåñòèêè-Íîëèêè";
			this->Load += gcnew System::EventHandler(this, &GameForm::GameForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->status->ResumeLayout(false);
			this->status->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: Random^ rand;

	private: void GameLogic();
	private: void Update();
	private: void NewGame();
	private: void StepAI();
	private: void UpdateGameGrid();
	private: void CreateGameGrid(Vector2);
	private: void SetPositionPlayer(Vector2);

	private: System::Void íîâàÿÈãğàToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void GameForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void îÏğîãğàììåToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void âûõîäToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
};
}
