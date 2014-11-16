#include "NormalAttack.h"



NormalAttack::NormalAttack()
{
}


NormalAttack::~NormalAttack()
{
}

void Attack::resolve()
{
	//TODO:¼õÑª£¬¶¯»­
	Enemy enemy = getTarget();
	enemy.takeDamage(damage);

	//????Timer?????

}