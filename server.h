#ifdef _WIN32
#include <windows.h>

void run_win_server();
DWORD WINAPI win_server_socket_thread(void * data);
#endif

void run_server();
