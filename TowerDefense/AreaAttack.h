#pragma once
#include "Attack.h"

class AreaAttack :
	public Attack
{
public:
	AreaAttack();
	virtual ~AreaAttack();

	vector<shared_ptr<Enemy>> getTarget();
	void resolve() override;
};

