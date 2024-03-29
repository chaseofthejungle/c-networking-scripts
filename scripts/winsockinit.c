#pragma comment(lib, "ws2_32.lib")
#include <stdio.h>
#include <winsock2.h>

int main() {
    WSADATA data;

    if (WSAStartup(MAKEWORD(2, 2), &data)) {
        printf("Winsock failed to initialize.\n");
        return -1;
    }

    WSACleanup();
    printf("Winsock successfully initialized.\n");
    return 0;
}
