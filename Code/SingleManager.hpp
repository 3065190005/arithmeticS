#pragma once
#ifndef __SINGLEMANAGER_H_
#define __SINGLEMANAGER_H_

#include "include.h"

class GlobalMemory
{
private:
	GlobalMemory();
	~GlobalMemory();

	static GlobalMemory * m_instance;

public:
	GlobalMemory * getInstance();

private:
	class GC {
		~GC() {
			delete m_instance;
			m_instance = nullptr;
		}
	};
};


#endif // !__SINGLEMANAGER_H_
