#include "server.h"

#ifdef _WIN32
#include "windowsNetworking.h"
#include <winsock2.h>
#include <stdio.h>

void run_server() {
    run_win_server();
}

#endif

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
        
        char *message = "Hello Client , I have received your connection. But I have to go now, bye\n";        
        send(new_socket , message , strlen(message) , 0);
    }

    if(new_socket == INVALID_SOCKET) {
        printf("accept failed with error code : %d", WSAGetLastError());
        exit(-1);
    }

    closesocket(s);
    WSACleanup();
}