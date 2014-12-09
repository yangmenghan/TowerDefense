#pragma once
#include "Attack.h"

class NormalAttack :
	public Attack
{
public:
	NormalAttack();
	virtual ~NormalAttack(){};

	void resolve() override;
};

