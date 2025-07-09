#include "decoder.h"

char *rot_13_decoder(const char *encoded_msg) {
  if (!encoded_msg) {
    return NULL;
  }
  size_t length = strlen(encoded_msg);
  char *decode_msg = malloc(length + 1);

  if (!decode_msg) {
    return NULL;
  }

  for (size_t i = 0; i < length; i++) {
    unsigned char ch = encoded_msg[i];
    if (ch >= 'a' && ch <= 'z') {
      decode_msg[i] = ((ch - 'a' + 13) % 26) + 'a';
    } else if (ch >= 'A' && ch <= 'Z') {
      decode_msg[i] = ((ch - 'A' + 13) % 26) + 'A';
    } else {
      decode_msg[i] = ch;
    }
  }
  decode_msg[length] = '\0';
  return decode_msg;
}

