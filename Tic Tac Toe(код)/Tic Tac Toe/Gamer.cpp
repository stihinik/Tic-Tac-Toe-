#include "Gamer.h"
void Gamer::SetField(GamerStatus mode, int m)
{
	if (mode == 0)
		status = Computer;
	else if (mode == 1)
		status = Player;
	this->mark = m;
}
