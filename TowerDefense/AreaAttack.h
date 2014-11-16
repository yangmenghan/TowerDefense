#pragma once
#include "Attack.h"

class AreaAttack :
	public Attack
{
public:
	AreaAttack();
	~AreaAttack();

	float getRange();

	void setRange();

	vector<Enemy*> getTarget();


private:
	float range;
};

