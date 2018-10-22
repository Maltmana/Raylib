#pragma once
struct CombatComponent
{
	CombatComponent();
	~CombatComponent();
	// flags
	bool _isDead = false;
	bool _deleteMe = false;
	// primitives
	float _attackRange = 10;
	int _attacksPerSec = 1;
	float _attackCooldownCounter = 0.f;
	int _attackDamage = 50;
	int _hp = 100;

};

