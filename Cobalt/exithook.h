#pragma once

#include <iostream>

#ifdef _WIN64
void (*RequestExitWithStatus)(bool Force, unsigned char Code);
void RequestExitWithStatusHook(bool Force, unsigned char Code)
{
	// printf("[VEH] RequestExitWithStatus Call Forced: %i ReturnCode: %u\n", Force, Code);
}
#else
void (*RequestExitWithStatus)(bool Force, unsigned char Code);
void RequestExitWithStatusHook(bool Force, unsigned char Code)
{
	// printf("[VEH] RequestExitWithStatus Call Forced: %i ReturnCode: %u\n", Force, Code);
}
#endif

void (*RequestExit)(int Code);
void RequestExitHook(int Code)
{
	std::cout << "REQUEST EXIT CODE: " << Code << '\n';
}

#ifdef _WIN64
void (*UnsafeEnvironmentPopup)(wchar_t** unknown1, unsigned __int8 _case, __int64 unknown2, char unknown3);
void UnsafeEnvironmentPopupHook(wchar_t** unknown1, unsigned __int8 _case, __int64 unknown2, char unknown3)
{
	// printf("[VEH] <UnsafeEnvironmentPopup Call with Case: %i\n", _case);
}
#else
void (*UnsafeEnvironmentPopup)(wchar_t** unknown1, unsigned __int8 _case, int unknown2, char unknown3);
void UnsafeEnvironmentPopupHook(wchar_t** unknown1, unsigned __int8 _case, int unknown2, char unknown3)
{
	// printf("[VEH] <UnsafeEnvironmentPopup Call with Case: %i\n", _case);
}
#endif