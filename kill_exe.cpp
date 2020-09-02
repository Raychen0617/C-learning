void AMyActor::killProcessByName(const char *filename)
{
	HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
	PROCESSENTRY32 pEntry;
	pEntry.dwSize = sizeof(pEntry);
	BOOL hRes = Process32First(hSnapShot, &pEntry);
	BOOL check = false;
	while (hRes)
	{
		if (strcmp(UnicodeToAnsixx(pEntry.szExeFile), filename) == 0)
		{
			check = true;
			break;
		}
		hRes = Process32Next(hSnapShot, &pEntry);
	}
	if (!check)
	{
		GetWorld()->GetFirstLocalPlayerFromController()->ConsoleCommand("quit");
		FGenericPlatformMisc::RequestExit(false);
	}
	else
	{
		initBasic();
	}
	CloseHandle(hSnapShot);
}
