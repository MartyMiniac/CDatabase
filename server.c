#include "server.h"
#include <stdio.h>

#ifdef _WIN32
#include "windowsNetworking.h"
#include <winsock2.h>

void run_server() {
    run_win_server();
}

#endif

#include "messageProcessing.h"

void run_win_server() {    
    WSADATA wsa;
	SOCKET s, new_socket;
    int c;

    _networking_init(&wsa);
    _networking_create_socket_(&s);

    struct sockaddr_in server, client;

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8001);

    _networking_socket_bind(&s, &server);

    listen(s, 3);

    puts("Waiting for incoming connections...");

    c = sizeof(struct sockaddr_in);
    while((new_socket = accept(s, (struct sockaddr *) &client, &c)) != INVALID_SOCKET) {
        puts("Connection accepted");
        CreateThread(NULL, 0, win_server_socket_thread, (void *)&new_socket, 0, NULL);
    }

    if(new_socket == INVALID_SOCKET) {
        printf("accept failed with error code : %d", WSAGetLastError());
        exit(-1);
    }

    closesocket(s);
    WSACleanup();
}

DWORD WINAPI win_server_socket_thread(void * data) {
    SOCKET new_socket = *(SOCKET *) data;
    char msg[1024]="";
    while(recv(new_socket, msg, 1024, 0)) {
        char command[10]="";
        char value[10]="";
        char message[100]="";
        stringTokenize(&msg, &command, &value);
        performOperation(&command, &value, &message);
        send(new_socket, message, strlen(message), 0);
    }
    closesocket(new_socket);
    puts("Client Disconnected from Server");
    return 0;
}