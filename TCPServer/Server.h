/******************************************** server side, Ofek ****************************************/
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE

#include <iostream>
using namespace std;
#pragma comment(lib, "Ws2_32.lib")
#include <winsock2.h>
#include <string.h>
#include "HTTP.h"
#include <fstream>


bool addSocket(SOCKET id, int what, struct SocketState* sockets, int* socketsCount);
void removeSocket(int index, struct SocketState* sockets, int* socketsCount);
void acceptConnection(int index, struct SocketState* sockets, int* socketsCount);
void receiveMessage(int index, struct SocketState* sockets, int* socketsCount);
void sendMessage(int index, struct SocketState* sockets, int* socketsCount);
void importLib();
void finishingUp(SOCKET connSocket);
SOCKET initiateSocket(void);
void bindSocket(SOCKET* m_socket);
void filterUpcomingEvents(int* nfd, fd_set* waitRecv, fd_set* waitSend);
void createSacks(fd_set* waitRecv, fd_set* waitSend, struct SocketState* sockets);
void handleEvents(int* nfd, fd_set* waitRecv, fd_set* waitSend, struct SocketState* sockets, int* socketsCount);
void GetFile(struct Request* req);
