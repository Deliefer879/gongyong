#pragma once

#include "Singleton.hpp"
#include "Std.h"

template <typename T, typename S>
class ResourceManager : public Singleton<S>
{
protected:
	friend class Singleton<S>;

	ID3D11Device* pDevice = nullptr;
	ID3D11DeviceContext* pContext = nullptr;
public:
	std::unordered_map<std::wstring, std::unique_ptr<T>> resList;

	std::wstring fileName;
	std::wstring path;
private:
	bool isLoaded(std::wstring key)
	{
		auto iter = resList.find(key);

		if (iter == resList.end())
			return false;

		return true;
	}
public:
	void Set(ID3D11Device* pDevice, ID3D11DeviceContext* pContext)
	{
		this->pDevice = pDevice;
		this->pContext = pContext;
	}

	T& Load(std::wstring fileName)
	{
		std::size_t found = fileName.find_last_of(L"/");
		path = fileName.substr(0, found + 1);
		this->fileName = fileName.substr(found + 1);

		if(isLoaded(this->fileName))
			return *(resList[this->fileName]);

		auto res = std::make_unique<T>() ;

		if (res->Load(fileName, pDevice))
		{
			resList.insert(std::make_pair(this->fileName, std::move(res)));
			return *(resList[this->fileName]);
		}

		res.reset();
		return *(res);
	}

	bool Release()
	{
		for (auto& res : resList)
		{
			res.second->Release();
			res.second.reset();
		}
		resList.clear();

		return true;
	}

	~ResourceManager()
	{
		Release();
	}

protected:
	ResourceManager() {};
};

