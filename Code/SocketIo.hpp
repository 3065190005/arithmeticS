#pragma once
#ifndef __SOCKETIO_H_
#define __SOCKETIO_H_

#include "include.h"
#include "define.hpp"

class SocketIo {
public:
	static void SetBlockSize(int size);
	static int GetBlockSize();

private:
	static int m_Size;

public:
	SocketIo(bool isblock = true);
	~SocketIo();

	bool bind(std::string & ip, short int port);
	SocketIo accept();
	bool connect(std::string & ip, short int port);

	int send(std::string & buf);
	int recv(std::string & buf);

	void close();

public:
	void setProtocolType(int protocol);
private:

	int m_sock;
	short int m_port;
	std::string m_ipaddr;
	::SOCKADDR_IN m_sockaddr;
	Cus::SocketStatus m_sockType;
	
	bool m_block;
	int m_protocolType;

	int m_size;
	char * m_buf;
};

#endif // !__SOCKETIO_H_
