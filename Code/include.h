#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>

#ifdef WIN32
#include <WinSock2.h>
#else
#include <socket.h>
#endif