#include "FSMManager.h"

void FSMManager::AddTransition(std::wstring type, FSMState state, FSMEvent event, FSMState outputState)
{
	// find StateMap by type
	StateMap* pStateMap = nullptr;
	auto iter1 = fsmMap.find(type);

	if (iter1 != fsmMap.end())
	{
		pStateMap = iter1->second.get();
	}
	else
	{
		pStateMap = new StateMap();
		fsmMap.insert(std::make_pair(type, std::unique_ptr<StateMap>(pStateMap)));
	}


	//find FiniteState by state
	FiniteState* pState = nullptr;
	auto iter2 = pStateMap->find(state);

	if (iter2 != pStateMap->end())
	{
		pState = iter2->second.get();
		pState->AddState(event, outputState);
	}
	else
	{
		pState = new FiniteState(state);

		pState->AddState(event, outputState);
		pStateMap->insert(std::make_pair(state, std::unique_ptr<FiniteState>(pState)));
	}
}

