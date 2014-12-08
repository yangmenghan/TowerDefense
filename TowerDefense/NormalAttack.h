#pragma once
#include "Attack.h"

class NormalAttack :
	public Attack
{
public:
	NormalAttack();
	virtual ~NormalAttack(){};

	bool hasTarget();
	void setTarget(shared_ptr<Enemy>);
	void resolve() override;
private:
	shared_ptr<Enemy> target;
};

