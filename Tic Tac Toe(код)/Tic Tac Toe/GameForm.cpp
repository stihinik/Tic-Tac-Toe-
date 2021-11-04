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
		MessageBox::Show("Поздравляю Игрока с победой!!!", "Победа!");
		UpdateGameGrid();
		endGame = true;
	}else if (state_game == 2) {
		MessageBox::Show("Поздравляю Компьютер с победой!!!", "Победа!");
		UpdateGameGrid();
		endGame = true;
	}else if (state_game == 3) {
		MessageBox::Show("Победила дружба!!!", "Ничья!");
		UpdateGameGrid();
		endGame = true;
	}
	if (endGame) {
		if (MessageBox::Show("Запустить Новую игру?","Внимание!",MessageBoxButtons::YesNo)==Windows::Forms::DialogResult::Yes) {
			NewGame();
		}
		return;
	}

	if (currentPlayer == Computer) {
		statusMove->Text = "Ход: Игрока!";
		currentPlayer = Player;
		return;
	}
	else {
		statusMove->Text = "Ход: Компьютера!";
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
		MessageBox::Show("Первым ходит Игрок!!!", "Объявление!");
		statusMove->Text = "Ход: Игрока!";

		currentPlayer = Player;
	}
	else if (state_gamer == 2) {
		MessageBox::Show("Первым ходит Компьютер!!!", "Объявление!");

		statusMove->Text = "Ход: Компьютера!";
		currentPlayer = Computer;
		GameLogic();
		UpdateGameGrid();
		
	}
	else {
		MessageBox::Show("Ошибка генерации первонального выбора игрока!", "Ошибка!");
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
			MessageBox::Show("Данная позиция занята!", "Внимание!");
			return;
		}
	}
	else {
		MessageBox::Show("Еще не ваша очередь!", "Внимание!");
		return;
	}
	Update();
}

System::Void TicTacToe::GameForm::новаяИграToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("Продолжить?", "Внимание!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
		NewGame();
	}
}

System::Void TicTacToe::GameForm::GameForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	NewGame();
}

System::Void TicTacToe::GameForm::оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Привет, меня зовут Паша, я переехал из Питера в Калининград. Всегда мечтал заниматься разработкой игр, сейчас активно изучаю Unity,"+
		" даже начал делать небольшой проект, могу скинуть. Опыт у меня большой в С++, около 3 лет коммерческой разработки. Но на самом деле, я бы слабо назвал себя даже"+
		" мидлом, потому что я в основном занимался самообучением и решал проблемы. Опыта в команде не было. На предыдущей работе, я всегда находил решешение проблем."+
		"Сказали написать сервер на С++, ищу в интернете как писать серверы. Там я работал один и хоть в трудовой написано, старший программист."+
		"Я был единственным программистом в своей команде. В вашей компании, я надеюсь получить опыт работы в команде и развиваться уже, как профессионал,"+
		"а не как самоучка.Так же умею общаться с менедежерами)) На прошлой работе, когда я создавал новый функционал в программе, я обучал менеджеров и других людей"+
		" как ей пользоваться.Спасибо за внимание и удачного дня!", "О программе");
}

System::Void TicTacToe::GameForm::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("Продолжить?", "Внимание!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
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
