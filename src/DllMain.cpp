#include <windows.h>
#include "mind3d8.h"
#include "Direct3D8Wrapper.h"

HINSTANCE g_hinstD3D8 = NULL;

BOOL WINAPI DllMain(
	HINSTANCE hinstDLL,
	DWORD     fdwReason,
	LPVOID    lpvReserved
)
{
	switch (fdwReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			DisableThreadLibraryCalls(hinstDLL);
			return TRUE;
		}
		case DLL_PROCESS_DETACH:
			if (g_hinstD3D8)
			{
				FreeLibrary(g_hinstD3D8);
				g_hinstD3D8 = NULL;
			}
			return TRUE;
		default:
			return TRUE;
	}
}

extern "C" __declspec(dllexport) IDirect3D8 *WINAPI Direct3DCreate8(UINT SDKVersion)
{
	if (!g_hinstD3D8)
	{
		WCHAR szDllPath[MAX_PATH];
		ExpandEnvironmentStringsW(L"%WINDIR%\\system32\\d3d8.dll", szDllPath, ARRAYSIZE(szDllPath));

		g_hinstD3D8 = LoadLibraryW(szDllPath);
		if (!g_hinstD3D8)
		{
			MessageBoxW(NULL, L"Failed to load original d3d8.dll", L"th06_hitbox_and_enemy", MB_ICONERROR);
			ExitProcess(-1);
		}
	}

	auto pfnDirect3DCreate8 = (IDirect3D8 *(WINAPI *)(UINT))GetProcAddress(
		g_hinstD3D8, "Direct3DCreate8"
	);

	IDirect3D8 *pOrigD3D8 = pfnDirect3DCreate8(SDKVersion);
	if (pOrigD3D8)
	{
		return new CDirect3D8Wrapper(pOrigD3D8);
	}
	return nullptr;
}