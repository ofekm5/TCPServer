#include "Server.h"

void main() {
    fd_set waitRecv, waitSend;
    int nfd;
    struct SocketState sockets[MAX_SOCKETS] = { 0 };
    int socketsCount = 0;

    importLib();

    SOCKET listenSocket = initiateSocket();

    bindSocket(&listenSocket);

    // Listen on the Socket for incoming connections.
    if (SOCKET_ERROR == listen(listenSocket, 5)) {
        cout << "Time Server: Error at listen(): " << WSAGetLastError() << endl;
        closesocket(listenSocket);
        WSACleanup();
        return;
    }
    addSocket(listenSocket, LISTEN,sockets,&socketsCount);

    while (true)
    {
        createSacks(&waitRecv, &waitSend,sockets);

        filterUpcomingEvents(&nfd, &waitRecv, &waitSend);

        handleEvents(&nfd, &waitRecv, &waitSend, sockets,&socketsCount);
    }


    finishingUp(listenSocket);
}