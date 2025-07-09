#ifndef UTILS_H
#define UTILS_H

#include <assert.h>
#include <stdlib.h>
#include <gvm/util/jsonpull.h>
#include "decoder.h"


void init_json_pull_parser(gvm_json_pull_parser_t *parser,
                           gvm_json_pull_event_t *event, FILE *file);
void cleanup_json_pull_parser(gvm_json_pull_parser_t *parser,
                              gvm_json_pull_event_t *event, FILE *file);
void parse_decode_json(gvm_json_pull_parser_t *parser,
                       gvm_json_pull_event_t *event);

#endif
