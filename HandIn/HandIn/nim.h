#pragma once
#include <string>

class Nim {
public:
	void Play();

private:
	bool MoveIsLegal(int move);
	void DrawSticks();
	int remaining_sticks{ 24 };
	int current_player{ 0 };
	const std::string rules{ 
		"- 2 Players \n"
		"- 24 matches on the table \n"
		"- players take turns to draw matches \n"
		"- may draw 1, 2 or 3 matches(not more, not less) \n"
		"- player who has to take last match loses(alternatively: wins)\n\n" 
	};
};