#include "SocketIo.hpp"

int SocketIo::m_Size = 1024;

void SocketIo::SetBlockSize(int size)
{
	SocketIo::m_Size = size;
}

int SocketIo::GetBlockSize()
{
	return SocketIo::m_Size;
}

SocketIo::SocketIo(bool isblock)
{
	this->m_sock = NULL;
	this->m_sockType = Cus::SocketStatus::None;
	this->m_block = isblock;
	this->m_protocolType = SOCK_STREAM;

	this->m_size = m_Size;
	this->m_buf = new char[m_size +1];
	memset(this->m_buf, NULL, m_size + 1);
	this->m_ipaddr.clear();
}

SocketIo::~SocketIo()
{
	this->close();
}

bool SocketIo::bind(std::string & ip, short int port)
{
	if (this->m_sockType != Cus::SocketStatus::None) {
		DebugLog("===WRONG= can not bind,sockType is not None");
		return false;
	}

	int ret = 0;
	SOCKADDR_IN sockadr;

	this->m_sockType = Cus::SocketStatus::IsBind;
	this->m_sock = ::socket(AF_INET, this->m_protocolType, 0);
	if (this->m_sock <= 0) {
		DebugLog("===WRONG= socket create is wrong,maybe socket list is full");
		goto end;
	}

	if (this->m_block) {
		
	}

	sockadr.sin_family = AF_INET;
	sockadr.sin_port = ::htons(port);
	sockadr.sin_addr.S_un.S_addr = inet_addr(ip.c_str());

	ret = ::bind(this->m_sock, (struct ::sockaddr *)&sockadr, sizeof(sockadr));
	if (ret != 0) {
		DebugLog("===WRONG= bind wrong check the network environment");
		goto end;
	}

	this->m_port = port;
	this->m_ipaddr.clear();
	this->m_ipaddr.append(ip);
	this->m_sockaddr = sockaddr;
	return true;

end:
	this->m_sockType = Cus::SocketStatus::None;
	closesocket(this->m_sock); this->m_sock = 0;
	this->m_port = 0;
	this->m_ipaddr.clear();
	return false;
}

SocketIo SocketIo::accept()
{

}

bool SocketIo::connect(std::string & ip, short int port)
{
	return false;
}

int SocketIo::send(std::string & buf)
{
	return 0;
}

int SocketIo::recv(std::string & buf)
{
	return 0;
}

void SocketIo::close()
{
}

void SocketIo::setProtocolType(int protocol)
{
	this->m_protocolType = protocol;
}

