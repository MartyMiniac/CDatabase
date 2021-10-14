#include <windows.h>
#include <stdio.h>

#include "main.h"
#include "server.h"
#include "datahandler.h"

int main() {
    datahandler_init();
    run_server();
    return 0;
}