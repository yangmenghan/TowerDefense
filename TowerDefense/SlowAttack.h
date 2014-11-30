#pragma once
#include "Attack.h"

class SlowAttack :
	public Attack
{
public:
	SlowAttack();
	virtual ~SlowAttack(){};

	void resolve() override;
};

