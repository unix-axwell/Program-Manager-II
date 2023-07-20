/* * * * * * * *\
	SHELLINT.C -
		Copyright (c) 2023 freedom7341, Freedom Desktop
	DESCRIPTION -
		Program Manager's shell interface functions.
	LICENSE INFORMATION -
		MIT License, see LICENSE.txt in the root folder
\* * * * * * * */

/* Headers */
#include "progmgr.h"
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

/* Functions */
/* * * *\
	RunFile -
		Produces a Run dialog window.
	RETURNS -
		True if successful, false if unsuccessful.
\* * * */
BOOL RunFile(HWND hWndOwner,
	HICON	hIcon,
	LPWSTR	lpszDir,
	LPWSTR	lpszTitle,
	LPWSTR	lpszDesc,
	DWORD	dwFlags)
{
	HMODULE hLib = LoadLibrary(L"shell32.dll");

	if (hLib) {
		FARPROC fLib = GetProcAddress(hLib, MAKEINTRESOURCEA(61));
		if (fLib(hWndOwner, hIcon, lpszDir, lpszTitle, lpszDesc, dwFlags))
			FreeLibrary(hLib);
			return TRUE;
	}

	return 0;
}

/* * * *\
	ShutdownDlg -
		Produces a Shutdown dialog window.
	RETURNS -
		True if successful, false if unsuccessful.
\* * * */
BOOL ShutdownDlg(HWND hWndOwner)
{
	HMODULE hLib = LoadLibrary(L"shell32.dll");

	if (hLib) {
		FARPROC fLib = GetProcAddress(hLib, MAKEINTRESOURCEA(60));
		if (fLib(hWndOwner))
			FreeLibrary(hLib);
			return TRUE;
	}

	return 0;
}