#pragma once
#include <windows.h>

class TimeManager
{
public:
    static void Initialize();
    static void Update();

    static float DeltaTime() { return mDeltaTime; }

private:
    static LARGE_INTEGER mCpuFrequency;
    static LARGE_INTEGER mPrevFrequency;
    static LARGE_INTEGER mCurrentFrequency;
    static float mDeltaTime;
};
