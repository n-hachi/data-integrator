#include <gtest/gtest.h>

#include "my_funcs.h"

TEST(MAX, integer) {
  int max_val = my_max(1, 2);
  ASSERT_EQ(max_val, 2);
}

TEST(MIN, integer) {
  int max_val = my_min(1, 2);
  ASSERT_EQ(max_val, 1);
}
