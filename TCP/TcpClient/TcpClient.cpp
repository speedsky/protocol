#include <winsock2.h>  
#include <WS2tcpip.h>
#include<stdio.h>
#include<iostream>
#include<cstring>

using namespace std;
#pragma comment(lib, "ws2_32.lib")

int main()
{
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA data;
	if (WSAStartup(sockVersion, &data) != 0)
	{
		return 0;
	}
	sockaddr_in serAddr;
	serAddr.sin_family = AF_INET;
	serAddr.sin_port = htons(8888);
	inet_pton(AF_INET, "127.0.0.1", &serAddr.sin_addr);

	while (true)
	{
		SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (sclient == INVALID_SOCKET)
		{
			printf("invalid socket!");
			return 0;
		}
		if (connect(sclient, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
		{  //Á¬½ÓÊ§°Ü 
			printf("connect error !");
			closesocket(sclient);
			return 0;
		}
		char * strData = { "Hello Server£¡\n" };
		send(sclient, strData, strlen(strData), 0);
		char recData[255];
		int ret = recv(sclient, recData, 255, 0);
		if (ret > 0) {
			recData[ret] = 0x00;
			printf(recData);
		}

		closesocket(sclient);
		Sleep(2000);
	}
	WSACleanup();
	return 0;
}
