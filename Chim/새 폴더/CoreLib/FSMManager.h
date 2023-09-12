#pragma once

#include "FiniteState.hpp"
#include "Singleton.hpp"

using StateMap = std::unordered_map<FSMState, std::unique_ptr<FiniteState>>;

class FSMManager : public Singleton<FSMManager>
{
private:
	friend class Singleton<FSMManager>;
	FSMManager() = default;
	~FSMManager() = default;

private:
	std::unordered_map<std::wstring, std::unique_ptr<StateMap>> fsmMap;
public:
	void AddTransition(std::wstring type,FSMState state, FSMEvent event, FSMState outputState);
	
	StateMap* GetStateMap(std::wstring type)
	{
		auto iter = fsmMap.find(type);
		if (iter != fsmMap.end())
			return iter->second.get();

		return nullptr;
	}
};

