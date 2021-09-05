#include <winsock2.h>

void _networking_init(WSADATA * wsa);
void _networking_create_socket_(SOCKET * s);
void _networking_socket_bind(SOCKET * s, struct sockaddr_in * server);
