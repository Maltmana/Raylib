#pragma once
// std
// libs
// non-sys
// sys

class CombatComponent
{
public:
	CombatComponent();
	~CombatComponent();
	CombatComponent(const CombatComponent& other) = delete; // copy constructor
	CombatComponent(CombatComponent&& other) = delete; // move constructor
	CombatComponent & operator=(const CombatComponent & other) = delete; // copy assignment
	CombatComponent & operator=(CombatComponent&& other) noexcept = delete; // move assignment
public:
private:
public:
private:
};

