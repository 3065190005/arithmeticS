#include "SingleManager.hpp"

GlobalMemory * GlobalMemory::m_instance = nullptr;

GlobalMemory::GlobalMemory()
{
}

GlobalMemory::~GlobalMemory()
{
}

GlobalMemory * GlobalMemory::getInstance()
{
	static std::once_flag oc;

	if (m_instance == nullptr) {
		std::call_once(oc, [] {
			m_instance = new GlobalMemory();
		});
	}

	return m_instance;
}
