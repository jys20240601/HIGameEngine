#include "TimeManager.h"

// 정적 멤버 변수 정의
LARGE_INTEGER TimeManager::mCpuFrequency = {};
LARGE_INTEGER TimeManager::mPrevFrequency = {};
LARGE_INTEGER TimeManager::mCurrentFrequency = {};
float TimeManager::mDeltaTime = 0.0f;

void TimeManager::Initialize()
{
    QueryPerformanceFrequency(&mCpuFrequency);
    QueryPerformanceCounter(&mPrevFrequency);
}

void TimeManager::Update()
{
    QueryPerformanceCounter(&mCurrentFrequency);

    float differenceFrequency =
        static_cast<float>(mCurrentFrequency.QuadPart - mPrevFrequency.QuadPart);

    mDeltaTime = differenceFrequency / static_cast<float>(mCpuFrequency.QuadPart);

    mPrevFrequency.QuadPart = mCurrentFrequency.QuadPart;
}
