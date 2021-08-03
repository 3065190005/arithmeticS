#pragma once
#ifndef __DEFINE_H_
#define __DEFINE_H_

#ifndef _DEBUG
#define DebugLog(...)
#define RowDebugLog(...)
#else
#define DebugLog(...) printf(__VA_ARGS__)
#define RowDebugLog(...) printf(__VA_ARGS__); throw(__VA_ARGS__)
#endif

namespace Cus {
	
	extern enum class SocketStatus {
		None = 0,
		IsBind,
		IsConnect,
	};
}

#endif // !__DEFINE_H_
