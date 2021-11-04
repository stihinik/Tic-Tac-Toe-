#pragma once
enum GamerStatus {
	Computer=0,
	Player
};
class Gamer
{  
	GamerStatus status;
	int mark;
public:
	Gamer() {}
	~Gamer() {}

	void SetField(GamerStatus mode, int m);
	int GetMark() { return mark; }
	GamerStatus GetStatus() { return status; }

};

