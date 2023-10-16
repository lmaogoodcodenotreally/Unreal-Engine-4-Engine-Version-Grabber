# Unreal-Engine-4-Engine-Version-Grabber

Dll that should grab the Version of ue4 that a game is running based on a sig.
Only posting this on github because I think it will be easier for people to find it on here.

# Reworked some stuff

Added title to cmd, and added a prompt to copy-paste engine version faster for lazy ppl like me

Lowered dll size

```
        File size         Ratio      Format      Name
   --------------------   ------   -----------   -----------
    113152 ->     25600   22.62%    win64/pe     EngineVersionGrabber.dll     
```
# anti cheat and anti virus detections

Basically any anticheat that detects dll injection

and for av mostly shit av get false positive for it (who tf use Bkav pro)
[3/71 detections](https://www.virustotal.com/gui/file/b51ccb9a1d09a455b2e6fe858814ea148c534e506faab89ddebaa319451e8299?nocache=1)



| Antivirus Software                  | Detection Status             |
| ----------------------------------- | ---------------------------- |
| Bkav Pro                            | W64.AIDetectMalware          |
| DeepInstinct                        | MALICIOUS                    |
| MaxSecure                           | Trojan.Malware.300983.susgen |
| Acronis (Static ML)                | Undetected                   |
| AhnLab-V3                           | Undetected                   |
| Alibaba                             | Undetected                   |
| ALYac                               | Undetected                   |
| Antiy-AVL                           | Undetected                   |
| Arcabit                             | Undetected                   |
| Avast                               | Undetected                   |
| AVG                                 | Undetected                   |
| Avira (no cloud)                    | Undetected                   |
| Baidu                               | Undetected                   |
| BitDefender                         | Undetected                   |
| BitDefenderTheta                    | Undetected                   |
| ClamAV                              | Undetected                   |
| CMC                                 | Undetected                   |
| CrowdStrike Falcon                  | Undetected                   |
| Cylance                             | Undetected                   |
| Cynet                               | Undetected                   |
| DrWeb                               | Undetected                   |
| Elastic                             | Undetected                   |
| Emsisoft                            | Undetected                   |
| eScan                               | Undetected                   |
| ESET-NOD32                          | Undetected                   |
| F-Secure                            | Undetected                   |
| Fortinet                            | Undetected                   |
| GData                               | Undetected                   |
| Google                              | Undetected                   |
| Gridinsoft (no cloud)               | Undetected                   |
| Ikarus                              | Undetected                   |
| Jiangmin                            | Undetected                   |
| K7AntiVirus                         | Undetected                   |
| K7GW                                | Undetected                   |
| Kaspersky                           | Undetected                   |
| Kingsoft                            | Undetected                   |
| Lionic                              | Undetected                   |
| Malwarebytes                        | Undetected                   |
| MAX                                 | Undetected                   |
| McAfee                              | Undetected                   |
| Microsoft                           | Undetected                   |
| NANO-Antivirus                      | Undetected                   |
| Palo Alto Networks                  | Undetected                   |
| Panda                               | Undetected                   |
| QuickHeal                           | Undetected                   |
| Rising                              | Undetected                   |
| Sangfor Engine Zero                 | Undetected                   |
| SecureAge                           | Undetected                   |
| SentinelOne (Static ML)            | Undetected                   |
| Skyhigh (SWG)                       | Undetected                   |
| Sophos                              | Undetected                   |
| SUPERAntiSpyware                    | Undetected                   |
| Symantec                            | Undetected                   |
| TACHYON                             | Undetected                   |
| TEHTRIS                             | Undetected                   |
| Tencent                             | Undetected                   |
| Trapmine                            | Undetected                   |
| Trellix (FireEye)                   | Undetected                   |
| TrendMicro                          | Undetected                   |
| TrendMicro-HouseCall                | Undetected                   |
| Varist                              | Undetected                   |
| VBA32                               | Undetected                   |
| VIPRE                               | Undetected                   |
| VirIT                               | Undetected                   |
| ViRobot                             | Undetected                   |
| Webroot                             | Undetected                   |
| Xcitium                             | Undetected                   |
| Yandex                              | Undetected                   |
| Zillya                              | Undetected                   |
| ZoneAlarm by Check Point            | Undetected                   |
| Zoner                               | Undetected                   |
| Avast-Mobile                        | Unable to process file type  |
| BitDefenderFalx                     | Unable to process file type  |
| Cybereason                          | Unable to process file type  |
| Symantec Mobile Insight             | Unable to process file type  |
| Trustlook                           | Unable to process file type  |
