#pragma once
#include "Global.h"

static std::string wtm(const std::wstring& wstr)
{
    if (wstr.empty()) 
        return std::string();

    int sizeNeeded = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), nullptr, 0, nullptr, nullptr);
    std::string str(sizeNeeded, 0);
    WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &str[0], sizeNeeded, nullptr, nullptr);
    return str;
}

static std::wstring mtw(const std::string& str)
{
    if (str.empty()) 
        return std::wstring();

    int sizeNeeded = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), nullptr, 0);
    std::wstring wstr(sizeNeeded, 0);
    MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstr[0], sizeNeeded);
    return wstr;
}

static void T_Debug(const WCHAR* msg)
{
#ifdef _DEBUG
    OutputDebugString(msg);
#endif
}
