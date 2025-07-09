#include "decoder.h"
#include "utils.h"
#include <cjson/cJSON.h>
#include <ctype.h>
#include <stdio.h>

int main() {
  gvm_json_pull_parser_t parser;
  gvm_json_pull_event_t event;
  const char *file_name = "../test/config/decode_message.json";

  FILE *file = fopen(file_name, "rb");
  if (!file) {
    perror("File open failed");
    return EXIT_FAILURE;
  }

  init_json_pull_parser(&parser, &event, file);
  gvm_json_pull_parser_next(&parser, &event);
  parse_decode_json(&parser, &event);

  cleanup_json_pull_parser(&parser, &event, file);
  return EXIT_SUCCESS;
}
