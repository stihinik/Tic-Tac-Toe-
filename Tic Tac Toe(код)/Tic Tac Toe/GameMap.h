#pragma once
#include<vector>
#include<algorithm>
struct Vector2 {
	int x, y;
};
class GameMap
{
	int** map;
	Vector2 size;
	int lengthWin;
public:
	GameMap();
	~GameMap();

	bool SetPosition(Vector2, int);
	bool IsEmpty(Vector2);
	void SetMap(Vector2);
	void ClearMap();
	int GetValue(Vector2);
	int GetLength() { return lengthWin; }
	Vector2 GetSize() { return size; }
	int CheckList(std::vector<int> a);
	int CheckingWin();
	bool CanMove();
};

