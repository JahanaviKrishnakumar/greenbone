#include "utils.h"


void init_json_pull_parser(gvm_json_pull_parser_t *parser,
                           gvm_json_pull_event_t *event, FILE *file) {
  gvm_json_pull_event_init(event);
  gvm_json_pull_parser_init(parser, file);
}

void cleanup_json_pull_parser(gvm_json_pull_parser_t *parser,
                              gvm_json_pull_event_t *event, FILE *file) {
  gvm_json_pull_event_cleanup(event);
  gvm_json_pull_parser_cleanup(parser);
  if (file) {
    fclose(file);
  }
}


void parse_decode_json(gvm_json_pull_parser_t *parser,
                       gvm_json_pull_event_t *event) {
  // Expect start of array
  gvm_json_pull_parser_next(parser, event);
  assert(event->type == GVM_JSON_PULL_EVENT_ARRAY_START);
  // To point to the first element in the array
  gvm_json_pull_parser_next(parser, event);   
  
  // Loop through the json array
  while (!(event->type == GVM_JSON_PULL_EVENT_ARRAY_END)) {
      assert(event->type == GVM_JSON_PULL_EVENT_STRING);
    printf("Encoded message: %s\n", event->value->valuestring);
    char *decoded_msg = rot_13_decoder(event->value->valuestring);
    if (decoded_msg) {
      printf("Decoded message: %s\n", decoded_msg);
      free(decoded_msg);
    } else {
      fprintf(stderr, "Failed to allocate memory for ROT13 decoding\n");
    }
    gvm_json_pull_parser_next(parser, event); 
  }
}