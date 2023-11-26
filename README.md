# V1.1

Dll that should grab the Version of ue4 that a game is running based on a sig.
Only posting this on github because I think it will be easier for people to find it on here.

**ALL CREDITS GOES TO RussellJerome, the original author of this code** I am just a lazy paster, thanks for the source <3
⠀

I just reworked some stuff
⠀
> | 1.0 Added title to cmd, and added a prompt to copy-paste engine version faster for lazy ppl like me
> | 1.1 Lowered file size 

# Lowered dll size, a lot.

⠀
⠀
```
        File size         Ratio      Format      Name
   --------------------   ------   -----------   -----------
    113152 ->     25600   22.62%    win64/pe     EngineVersionGrabber.dll     
```


# anti cheat and anti virus detections

⠀
Mostly depends on injection method, make sure that u use kernel / driver injection or payload because normal LoadLibraryW is detected on most games.

Basically any anticheat that detects dll injection will detect it if use without bypass, however it's prove to work on some EAC games that I won't name 😊 (if bypassed proprely)

***And concerning av mostly shit av get false positive for it**(*who tf use Bkav pro*)

**[3/71 detections](https://www.virustotal.com/gui/file/8e2919c3967b5aa7e462f2a4973714ea2bd60179351e58c3f80a3b986fc11318?nocache=1)**


⠀
⠀

| Antivirus Software                  | Detection Status             |
| ----------------------------------- | ---------------------------- |
| Bkav Pro                            | ❌ W64.AIDetectMalware          |
| DeepInstinct                        | ❌ MALICIOUS                    |
| MaxSecure                           | ❌ Trojan.Malware.300983.susgen |
| Acronis (Static ML)                | ✅ Undetected                   |
| AhnLab-V3                           | ✅ Undetected                   |
| Alibaba                             | ✅ Undetected                   |
| ALYac                               | ✅ Undetected                   |
| Antiy-AVL                           | ✅ Undetected                   |
| Arcabit                             | ✅ Undetected                   |
| Avast                               | ✅ Undetected                   |
| AVG                                 | ✅ Undetected                   |
| Avira (no cloud)                    | ✅ Undetected                   |
| Baidu                               | ✅ Undetected                   |
| BitDefender                         | ✅ Undetected                   |
| BitDefenderTheta                    | ✅ Undetected                   |
| ClamAV                              | ✅ Undetected                   |
| CMC                                 | ✅ Undetected                   |
| CrowdStrike Falcon                  | ✅ Undetected                   |
| Cylance                             | ✅ Undetected                   |
| Cynet                               | ✅ Undetected                   |
| DrWeb                               | ✅ Undetected                   |
| Elastic                             | ✅ Undetected                   |
| Emsisoft                            | ✅ Undetected                   |
| eScan                               | ✅ Undetected                   |
| ESET-NOD32                          | ✅ Undetected                   |
| F-Secure                            | ✅ Undetected                   |
| Fortinet                            | ✅ Undetected                   |
| GData                               | ✅ Undetected                   |
| Google                              | ✅ Undetected                   |
| Gridinsoft (no cloud)               | ✅ Undetected                   |
| Ikarus                              | ✅ Undetected                   |
| Jiangmin                            | ✅ Undetected                   |
| K7AntiVirus                         | ✅ Undetected                   |
| K7GW                                | ✅ Undetected                   |
| Kaspersky                           | ✅ Undetected                   |
| Kingsoft                            | ✅ Undetected                   |
| Lionic                              | ✅ Undetected                   |
| Malwarebytes                        | ✅ Undetected                   |
| MAX                                 | ✅ Undetected                   |
| McAfee                              | ✅ Undetected                   |
| Microsoft                           | ✅ Undetected                   |
| NANO-Antivirus                      | ✅ Undetected                   |
| Palo Alto Networks                  | ✅ Undetected                   |
| Panda                               | ✅ Undetected                   |
| QuickHeal                           | ✅ Undetected                   |
| Rising                              | ✅ Undetected                   |
| Sangfor Engine Zero                 | ✅ Undetected                   |
| SecureAge                           | ✅ Undetected                   |
| SentinelOne (Static ML)            | ✅ Undetected                   |
| Skyhigh (SWG)                       | ✅ Undetected                   |
| Sophos                              | ✅ Undetected                   |
| SUPERAntiSpyware                    | ✅ Undetected                   |
| Symantec                            | ✅ Undetected                   |
| TACHYON                             | ✅ Undetected                   |
| TEHTRIS                             | ✅ Undetected                   |
| Tencent                             | ✅ Undetected                   |
| Trapmine                            | ✅ Undetected                   |
| Trellix (FireEye)                   | ✅ Undetected                   |
| TrendMicro                          | ✅ Undetected                   |
| TrendMicro-HouseCall                | ✅ Undetected                   |
| Varist                              | ✅ Undetected                   |
| VBA32                               | ✅ Undetected                   |
| VIPRE                               | ✅ Undetected                   |
| VirIT                               | ✅ Undetected                   |
| ViRobot                             | ✅ Undetected                   |
| Webroot                             | ✅ Undetected                   |
| Xcitium                             | ✅ Undetected                   |
| Yandex                              | ✅ Undetected                   |
| Zillya                              | ✅ Undetected                   |
| ZoneAlarm by Check Point            | ✅ Undetected                   |
| Zoner                               | ✅ Undetected                   |
| Avast-Mobile                        | ✅ Unable to process file type  |
| BitDefenderFalx                     | ✅ Unable to process file type  |
| Cybereason                          | ✅ Unable to process file type  |
| Symantec Mobile Insight             | ✅ Unable to process file type  |
| Trustlook                           | ✅ Unable to process file type  |




# Most of the source

```c++
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
```

