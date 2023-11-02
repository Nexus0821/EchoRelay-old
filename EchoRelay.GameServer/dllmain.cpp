// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "echovr.h"
#include "gameserver.h"

// The initialized ServerLib which Echo VR will call upon to communicate with central services.
EchoVR::IServerLib* g_ServerLib;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

HRESULT RadPluginInit() 
{
	return ERROR_SUCCESS;
}

HRESULT RadPluginInitMemoryStatics(HMODULE hModule) {
	return ERROR_SUCCESS;
}

HRESULT RadPluginInitNonMemoryStatics(HMODULE hModule) {
	return ERROR_SUCCESS;
}

HRESULT RadPluginMain(CHAR* x) {
	return ERROR_SUCCESS;
}

HRESULT RadPluginSetAllocator(VOID* x) {
	return ERROR_SUCCESS;
}

HRESULT RadPluginSetEnvironment(VOID* x) {
	return ERROR_SUCCESS;
}

HRESULT RadPluginSetEnvironmentMethods(VOID* x, VOID* y) {
	return ERROR_SUCCESS;
}

HRESULT RadPluginSetFileTypes(VOID* x) {
	return ERROR_SUCCESS;
}

HRESULT RadPluginSetPresenceFactory(VOID* x) {
	return ERROR_SUCCESS;
}

HRESULT RadPluginSetSymbolDebugMethodsMethod(VOID* a, VOID* b, VOID* c, VOID* d) {
	return ERROR_SUCCESS;
}

HRESULT RadPluginShutdown() {
	// TODO: This is ugly, but for now the platform provider can panic from the server hacks + no ovr, etc.
	// There is some state transition confusion to rectify.
	// 
	// As a temporary quick fix for panics which hang the app on close, we just force exit the whole process 
	// when we detect shutdown.
	delete g_ServerLib;
	exit(1);
	return ERROR_SUCCESS;
}

EchoVR::IServerLib* ServerLib() {

#ifdef _DEBUG
	// Set a debug breakpoint on startup if we're debugging.
	//DebugBreak();
#endif

	// If the server library hasn't been initialized, set it now.
	if (g_ServerLib == NULL) {
		g_ServerLib = new GameServerLib();
	}
	return g_ServerLib;
}
