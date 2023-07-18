#pragma once
#include <iostream>
#include <chrono>

using namespace std::chrono;

class Timer
{
private:
	milliseconds globalGameTimer;
	nanoseconds frameTime;
	high_resolution_clock::time_point beforeTime;
	int frameCount;

public:
	void Init();	// �ʱ�ȭ + ������ �غ��۾���
	void Frame();	// Frame ���� �۾�
	void Render();	//������ ȭ�� ǥ��
	void Release();// �Ҹ� ~class
	inline int GetFPS();
	inline nanoseconds GetSecPerFrame() { return frameTime; };
	inline milliseconds GetGameTimer() { return globalGameTimer; };
};

