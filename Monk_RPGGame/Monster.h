#pragma once
#include "Entity.h"

class Monster : public Entity {
private:
	string* artModel;
	int artHeight;
	int artWidth;

	int attack_chance;
public:
	Monster();

	string* getArtModel();
	int getArtHeight();
	int getArtWidth();

	void setArtModel(string* artModel);
	void setArtHeight(int artHeight);
	void setArtWidth(int artWidth);
	void setAttackChance(int attack_chance);

	int actionToPerform();
};