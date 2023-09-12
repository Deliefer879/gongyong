#pragma once

#include "Std.h"
#include "ObjectState.h"
#include "FSMManager.h"

class FSM
{
private:
	StateMap* stateMap = nullptr;
	
	std::unordered_map<FSMState, ObjectState*> stateList;
	ObjectState* currentObjState = nullptr;
public:
	void Init(std::wstring fsmType);
	void Execute(Object* other);
	void Release();

	void AddState(FSMState state, ObjectState* statePtr);
	void SetState(FSMState currentState, FSMEvent fsmEvent);
public:
	FSM() {};
	~FSM() {};
};

