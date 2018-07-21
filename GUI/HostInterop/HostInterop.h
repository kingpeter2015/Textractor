#pragma once
#include "../../texthook/hookman.h"
#include "../../texthook/textthread.h"
#include "../../texthook/host.h"

using namespace System;

namespace HostInterop
{
	public ref struct Host abstract sealed
	{
		void Open() { OpenHost(); }
		bool Start() { return StartHost(); }
		void Close() { CloseHost(); }
		void InitHookManager(HookManager uninit) { uninit.intern = GetHostHookManager(); }
		bool InjectProcessById(DWORD pid) { return ::InjectProcessById(pid); }
		bool DetachProcessById(DWORD pid) { return ::DetachProcessById(pid); }
		bool InsertHook(DWORD pid, HookParam hp, std::string name) { return ::InsertHook(pid, hp.GetNative()); };
		bool RemoveHook(DWORD pid, DWORD addr) { return ::RemoveHook(pid, addr); }
	};

	public ref struct HookManager
	{
	internal:
		::HookManager* intern;
	};

	public ref struct TextThread
	{

	internal:
		::TextThread* intern;
	};

	public ref struct HookParam
	{

	internal:
		::HookParam GetNative();
	};

	public ref struct ThreadParam
	{

	};
}
