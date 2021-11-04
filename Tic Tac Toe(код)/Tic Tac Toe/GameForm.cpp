#include "GameForm.h"

GameMap map;
Gamer player1;
Gamer player2;
GamerStatus currentPlayer;
Vector2 selectedCellPlayer;

bool canPlay;
bool endGame;

std::vector<Vector2> allMoves;
int currentMoves;

void TicTacToe::GameForm::GameLogic()
{
	if (currentPlayer == Computer) {
		StepAI();
	}
	Update();
}

void TicTacToe::GameForm::Update()
{
	if (endGame)
		return;

	int state_game = map.CheckingWin();

	if (state_game == 1) {
		MessageBox::Show("���������� ������ � �������!!!", "������!");
		UpdateGameGrid();
		endGame = true;
	}else if (state_game == 2) {
		MessageBox::Show("���������� ��������� � �������!!!", "������!");
		UpdateGameGrid();
		endGame = true;
	}else if (state_game == 3) {
		MessageBox::Show("�������� ������!!!", "�����!");
		UpdateGameGrid();
		endGame = true;
	}
	if (endGame) {
		if (MessageBox::Show("��������� ����� ����?","��������!",MessageBoxButtons::YesNo)==Windows::Forms::DialogResult::Yes) {
			NewGame();
		}
		return;
	}

	if (currentPlayer == Computer) {
		statusMove->Text = "���: ������!";
		currentPlayer = Player;
		return;
	}
	else {
		statusMove->Text = "���: ����������!";
		currentPlayer = Computer;
		GameLogic();
		UpdateGameGrid();
		return;
	}

	GameLogic();
	UpdateGameGrid();
}

void TicTacToe::GameForm::NewGame()
{
	rand=gcnew Random();
	endGame = false;

	CreateGameGrid(map.GetSize());

	currentMoves = 0;
	allMoves.clear();
	map.ClearMap();

	Vector2 buf;

	for (int i = 0; i < map.GetSize().x; ++i) {
		for (int j = 0; j < map.GetSize().y; ++j) {
			buf.x = i;
			buf.y = j;

			allMoves.push_back(buf);
		}
	}

	int num_mixing = rand->Next(2, 10);

	for (int i = 0; i < num_mixing; ++i)
		std::random_shuffle(allMoves.begin(), allMoves.end());

	int state_gamer = rand->Next(1, 3);

	player1.SetField(Player, 1);
	player2.SetField(Computer, 2);

	if (state_gamer == 1) {
		MessageBox::Show("������ ����� �����!!!", "����������!");
		statusMove->Text = "���: ������!";

		currentPlayer = Player;
	}
	else if (state_gamer == 2) {
		MessageBox::Show("������ ����� ���������!!!", "����������!");

		statusMove->Text = "���: ����������!";
		currentPlayer = Computer;
		GameLogic();
		UpdateGameGrid();
		
	}
	else {
		MessageBox::Show("������ ��������� ������������� ������ ������!", "������!");
		return;
	}
}

void TicTacToe::GameForm::StepAI()
{
	if (currentMoves < allMoves.size()) {
		if (map.IsEmpty(allMoves[currentMoves])) {
			map.SetPosition(allMoves[currentMoves], player2.GetMark());
			currentMoves++;
		}
		else {
			currentMoves++;
			StepAI();
		}

	}
}

void TicTacToe::GameForm::UpdateGameGrid()
{
	for (int i = 0; i < map.GetSize().x; ++i) {
		for (int j = 0; j < map.GetSize().y; ++j) {
			Vector2 cellUpdate;
			cellUpdate.x = i;
			cellUpdate.y = j;

			if (!map.IsEmpty(cellUpdate)) {
				if (map.GetValue(cellUpdate) == 1) {
					dataGridView->Rows[i]->Cells[j]->Value = "X";
				}
				else {
					dataGridView->Rows[i]->Cells[j]->Value = "0";
				}
			}

		}
	}
}

void TicTacToe::GameForm::CreateGameGrid(Vector2 size)
{
	dataGridView->Rows->Clear();
	dataGridView->Columns->Clear();

	System::Drawing::Font^ font = gcnew System::Drawing::Font("Microsoft Sans Serif", 14);
	dataGridView->DefaultCellStyle->Font = font;
	dataGridView->ColumnHeadersDefaultCellStyle->Font = font;
	dataGridView->RowHeadersDefaultCellStyle->Font = font;

	for (int i = 0; i < size.x; i++) {
		DataGridViewButtonColumn^ column = gcnew DataGridViewButtonColumn();
		column->HeaderCell->Value = Convert::ToString(i + 1);
		column->Name = "column" + i;
		column->Width = 100;
		dataGridView->Columns->Add(column);
	}
	for (int i = 0; i < size.y; i++) {
		dataGridView->Rows->Add();
		dataGridView->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
		dataGridView->Rows[i]->Height = 100;
	}

}

void TicTacToe::GameForm::SetPositionPlayer(Vector2 cell)
{
	if (currentPlayer == Player) {
		if (!map.SetPosition(cell, player1.GetMark())) {
			MessageBox::Show("������ ������� ������!", "��������!");
			return;
		}
	}
	else {
		MessageBox::Show("��� �� ���� �������!", "��������!");
		return;
	}
	Update();
}

System::Void TicTacToe::GameForm::���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("����������?", "��������!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
		NewGame();
	}
}

System::Void TicTacToe::GameForm::GameForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	NewGame();
}

System::Void TicTacToe::GameForm::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("������, ���� ����� ����, � �������� �� ������ � �����������. ������ ������ ���������� ����������� ���, ������ ������� ������ Unity,"+
		" ���� ����� ������ ��������� ������, ���� �������. ���� � ���� ������� � �++, ����� 3 ��� ������������ ����������. �� �� ����� ����, � �� ����� ������ ���� ����"+
		" ������, ������ ��� � � �������� ��������� ������������� � ����� ��������. ����� � ������� �� ����. �� ���������� ������, � ������ ������� ��������� �������."+
		"������� �������� ������ �� �++, ��� � ��������� ��� ������ �������. ��� � ������� ���� � ���� � �������� ��������, ������� �����������."+
		"� ��� ������������ ������������� � ����� �������. � ����� ��������, � ������� �������� ���� ������ � ������� � ����������� ���, ��� ������������,"+
		"� �� ��� ��������.��� �� ���� �������� � ������������)) �� ������� ������, ����� � �������� ����� ���������� � ���������, � ������ ���������� � ������ �����"+
		" ��� �� ������������.������� �� �������� � �������� ���!", "� ���������");
}

System::Void TicTacToe::GameForm::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("����������?", "��������!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
		Application::Exit();
	}
}

System::Void TicTacToe::GameForm::dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	auto senderGrid = (DataGridView^)sender;
	selectedCellPlayer.x = e->RowIndex;
	selectedCellPlayer.y = e->ColumnIndex;

	SetPositionPlayer(selectedCellPlayer);
}
