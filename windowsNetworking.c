#include "windowsNetworking.h"
#include "logger.h"
#include <winsock2.h>
#include <stdio.h>

void _networking_init(WSADATA * wsa) {
    printf("\nInitialising Winsock...\n");
	if (WSAStartup(MAKEWORD(2, 2), wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		exit(-1);
	}
	
	printf("Initialised.\n");
}

void _networking_create_socket_(SOCKET * s) {
    if((*s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Could not create socket : %d\n", WSAGetLastError());
        exit(-1);
    }

    printf("Socket Created\n");
}

void _networking_socket_bind(SOCKET * s, struct sockaddr_in * server) {
    if(bind(*s, (struct sockaddr *) server, sizeof(*server)) == SOCKET_ERROR) {
        printf("Bind failed with error code : %d", WSAGetLastError());
        exit(-1);
    }

    puts("bind done");
}