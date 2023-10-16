#include <windows.h>
#include <iostream>
#include <psapi.h>
#include <string>   
#include <locale> 
namespace PAT
{
    static bool DataCompare(PBYTE pData, PBYTE bSig, const char* szMask)
    {
        for (; *szMask; ++szMask, ++pData, ++bSig)
        {
            if (*szMask == 'x' && *pData != *bSig)
                return false;
        }
        return (*szMask) == 0;
    }

    static DWORD_PTR FindPattern(DWORD_PTR dwAddress, DWORD dwSize, const char* pbSig, const char* szMask, long offset)
    {
        size_t length = strlen(szMask);
        for (size_t i = NULL; i < dwSize - length; i++)
        {
            if (DataCompare((PBYTE)dwAddress + i, (PBYTE)pbSig, szMask))
                return dwAddress + i + offset;
        }
        return 0;
    }
}

template<class T>
class TArray
{
public:
    T* Data;
    int Count;
    int Max;
};

class FString : public TArray<wchar_t>
{
public:

    inline const wchar_t* c_str() const
    {
        return Data;
    }

    std::string ToString() const
    {
        const auto length = std::wcslen(Data);

        std::string str(length, '\0');

        std::use_facet<std::ctype<wchar_t>>(std::locale()).narrow(Data, Data + length, '?', &str[0]);

        return str;
    }
};

void* Result;
DWORD_PTR addr_GetEngineVersion;
FString* GetEngineVersion(void* Result)
{
    return reinterpret_cast<FString * (__fastcall*)(void*)>(addr_GetEngineVersion)(Result);
}

void CopyToClipboard(const std::string& text)
{
    if (OpenClipboard(nullptr))
    {
        EmptyClipboard();
        HGLOBAL hClipboardData = GlobalAlloc(GMEM_DDESHARE, text.size() + 1);
        if (hClipboardData)
        {
            char* pchData = static_cast<char*>(GlobalLock(hClipboardData));
            if (pchData)
            {
                strcpy_s(pchData, text.size() + 1, text.c_str());
                GlobalUnlock(hClipboardData);
                SetClipboardData(CF_TEXT, hClipboardData);
            }
        }
        CloseClipboard();
    }
}

DWORD _stdcall InitEngineVersion(LPVOID)
{
    DWORD_PTR BaseAddress = (DWORD_PTR)GetModuleHandle(NULL);
    MODULEINFO ModuleInfo;
    GetModuleInformation(GetCurrentProcess(), (HMODULE)BaseAddress, &ModuleInfo, sizeof(ModuleInfo));
    addr_GetEngineVersion = PAT::FindPattern(BaseAddress, ModuleInfo.SizeOfImage, "\x40\x53\x48\x83\xEC\x20\x48\x8B\xD9\xE8\x00\x00\x00\x00\x48\x8B\xC8\x41\xB8\x04\x00\x00\x00\x48\x8B\xD3", "xxxxxxxxxx????xxxxxxxxxxxx", 0);
    if (addr_GetEngineVersion)
    {
        FString* Engine = GetEngineVersion(&Result);
        std::cout << "EngineVer: " << Engine->ToString().c_str() << std::endl;

        // Ask the user if they want to copy the engine version to the clipboard
        std::cout << "Do you want to copy the engine version to the clipboard? (Y/N): ";

        char choice;
        std::cin >> choice;

        if (choice == 'Y' || choice == 'y')
        {
            std::string engineVersionStr = Engine->ToString();
            CopyToClipboard(engineVersionStr);
            std::cout << "Engine version copied to clipboard." << std::endl;
        }
    }
    else
    {
        std::cout << "Pattern Not Found" << std::endl;
    }
    return NULL;
}

BOOL __stdcall DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID lpReserved)
{
    switch (dwReason)
    {
    case DLL_PROCESS_ATTACH:
    {
        DisableThreadLibraryCalls(hModule);

        AllocConsole();
        ShowWindow(GetConsoleWindow(), SW_SHOW);
        FILE* fp;
        freopen_s(&fp, "CONIN$", "r", stdin);
        freopen_s(&fp, "CONOUT$", "w", stdout);
        freopen_s(&fp, "CONOUT$", "w", stderr);
        std::cout << "DLL Attached" << std::endl;
        CreateThread(0, 0, InitEngineVersion, 0, 0, 0);
        break;
    }
    case DLL_PROCESS_DETACH:
    {
        break;
    }
    }

    return TRUE;
}
