#include <openssl/ssl.h>

int main(int argc, char *argv[]) {
    printf("Current OpenSSL Version is: %s\n", OpenSSL_version(SSLEAY_VERSION));
    return 0;
}
