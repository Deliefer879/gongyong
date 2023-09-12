#pragma once

template <typename T>
class Singleton
{
protected:
	Singleton() {  };
	Singleton(const Singleton&) {  };
	Singleton& operator=(const Singleton&) {  };
	~Singleton() {  };
public:
	static T& GetInstance()
	{
		static T instance;

		return instance;
	}
}; 