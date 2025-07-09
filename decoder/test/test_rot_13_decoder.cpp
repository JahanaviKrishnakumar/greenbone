#include <gtest/gtest.h>
extern "C" {
#include "decoder.h"
#include <stdlib.h>
}

TEST(rot_13_test, rot_13_basic) {
  char *out = rot_13_decoder("Hello");
  ASSERT_STREQ(out, "Uryyb");
  free(out);
}

TEST(rot_13_test, rot_13_null_input) {
  ASSERT_EQ(rot_13_decoder(NULL), nullptr);
}

TEST(rot_13_test, rot_13_lowercase_hello) {
  char *out = rot_13_decoder("hello");
  ASSERT_STREQ(out, "uryyb");
  free(out);
}

TEST(rot_13_test, rot_13_uppercase_hello) {
  char *out = rot_13_decoder("HELLO");
  ASSERT_STREQ(out, "URYYB");
  free(out);
}

TEST(rot_13_test, rot_13_mixed_hello_world) {
  char *out = rot_13_decoder("HelloWorld");
  ASSERT_STREQ(out, "UryybJbeyq");
  free(out);
}

TEST(rot_13_test, rot_13_empty_string) {
  char *out = rot_13_decoder("");
  ASSERT_STREQ(out, "");
  free(out);
}

TEST(rot_13_test, rot_13_special_characters) {
  const char *input = "1234! @# $%^&*()_+";
  char *out = rot_13_decoder(input);
  ASSERT_STREQ(out, input);
  free(out);
}
