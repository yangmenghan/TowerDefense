#pragma once
#include "Attack.h"

class AreaAttack :
	public Attack
{
public:
	AreaAttack();
	~AreaAttack();

	float getRange();

	vector<Enemy*> getTarget();
	void resolve() override;


private:
	float range;
};

