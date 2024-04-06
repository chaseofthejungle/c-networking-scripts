const char * get_error_text() {
  #if defined(_WIN32)

  static char msg[256] = {0};
  FormatMessage(
    FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
    0, WSAGetLastError(), 0, msg, 256, 0);
  char * nl = strrchr(msg, '\n');
  if (nl) * nl = 0;
  return msg;

  #else
  return strerror(errno);
  #endif
}

int main() {
  #if defined(_WIN32)
  WSADATA data;
  if (WSAStartup(MAKEWORD(2, 2), & data)) {
    fprintf(stderr, "Process failed to initialize...\n");
    return 1;
  }
  #endif

  printf("Invalid parameters passed to socket function...\n");
  socket(0, 0, 0);
  printf("Most Recent Error: %s\n", get_error_text());
  return 0;
}
