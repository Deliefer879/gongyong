#pragma once

#include "Std.h"

enum FSMState
{
	State_None,
	State_Idle,
	State_Move,
	State_Jump,
	State_Attack,
	State_Damaged,
	State_Die,
	State_Fall,
};
enum FSMEvent
{
	Event_Idle,
	Event_Move,
	Event_Jump,
	Event_Attack,
	Event_Damaged,
	Event_Die,
	Event_Fall,
};
class FiniteState
{
private:
	std::unordered_map<FSMEvent, FSMState> m_FSMStateMap;
	FSMState currentState; // is this necessary?
public:
	void AddState(FSMEvent event, FSMState outputState)
	{
		m_FSMStateMap.insert(std::make_pair(event, outputState));
	}

	FSMState GetState(FSMEvent event)
	{
		auto iter = m_FSMStateMap.find(event);

		if (iter != m_FSMStateMap.end())
			return iter->second;

		return State_None;
	}

public:
	FiniteState(FSMState state) { currentState = state; }
	virtual ~FiniteState() {}
};

