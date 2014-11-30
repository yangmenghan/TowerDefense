#pragma once
#include "Attack.h"

class AreaAttack :
	public Attack
{
public:
	AreaAttack();
	virtual ~AreaAttack();

	float getRange();

	vector<shared_ptr<Enemy>> getTarget();
	void resolve() override;


private:
	float range;
};

