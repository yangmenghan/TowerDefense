#pragma once
#include "Attack.h"

class NormalAttack :
	public Attack
{
public:
	NormalAttack();
	~NormalAttack();

	void resolve() override;
};

