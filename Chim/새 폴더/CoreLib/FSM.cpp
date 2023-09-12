#include "FSM.h"
#include "FSMManager.h"

void FSM::Init(std::wstring fsmType)
{
	stateMap = FSMManager::GetInstance().GetStateMap(fsmType);

	auto iter = stateList.find(FSMState::State_Idle);

	if (iter != stateList.end())
	{
		currentObjState = iter->second;
		currentObjState->Enter();
		return;
	}

	currentObjState = nullptr;
}

void FSM::Execute(Object* other)
{
	currentObjState->Execute(other);
}

void FSM::Release()
{
	for (auto& iter : stateList)
		delete iter.second;
}

void FSM::AddState(FSMState state, ObjectState* statePtr)
{
	stateList.insert(std::make_pair(state, statePtr));
}
void FSM::SetState(FSMState currentState, FSMEvent fsmEvent)
{
	auto iter = stateMap->find(currentState);

	if (iter != stateMap->end())
	{
		FSMState nextState = iter->second->GetState(fsmEvent);
		currentObjState->Exit();
		
		currentObjState = stateList[nextState];
		currentObjState->Enter();
	}

}