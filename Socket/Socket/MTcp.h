#ifndef MTcp_H
#define MTcp_H

#ifdef WIN32
#ifdef SOCKET_EXPORTS
#define XSOCKET_API __declspec(dllexport)
#else
#define XSOCKET_API __declspec(dllimport)
#endif
#else
#define XSOCKET_API
#endif



#include <string>
XSOCKET_API std::string GetIpByHost(std::string host);

class XSOCKET_API MTcp
{
public:
	MTcp();
	virtual ~MTcp();
	bool Bind(unsigned short port);
	MTcp Accept();
	void Close();
	int Recv(char *buf,int bufsize);
	int Send(const char *buf,int sendsize);
	bool Connect(const char *ip,unsigned short port,int timeoutms=1000);
	bool SetBlock(bool isblock);

	int sock = 0;
	unsigned short port = 0;
	char ip[16];

};

#endif