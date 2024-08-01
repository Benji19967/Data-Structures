#include "../src/hashmap.h"
#include "../unity/src/unity.h"

void setUp(void) {
  // set stuff up here
}

void tearDown(void) {
  // clean stuff up here
}

void test_new_hashmap() {
  int num_buckets = 1000;
  Hashmap* map = hashmap_new(num_buckets);

  TEST_ASSERT_EQUAL_INT(0, map->num_elements);
  TEST_ASSERT_EQUAL_INT(num_buckets, map->num_buckets);
  TEST_ASSERT_EACH_EQUAL_PTR(NULL, map->buckets, num_buckets);
}

void test_hash_function() {
  int num_buckets = 1000;

  int key1 = 999;
  int hashed_key1 = hashmap_hash(key1, num_buckets);
  TEST_ASSERT_EQUAL_INT(999, hashed_key1);

  int key2 = 1000;
  int hashed_key2 = hashmap_hash(key2, num_buckets);
  TEST_ASSERT_EQUAL_INT(0, hashed_key2);
}

// void test_hashmap_insert() {
//   int num_buckets = 10;
//   Hashmap* map = hashmap_new(num_buckets);
//
//   int key = 1;
//   int value = 11;
//   hashmap_insert(map, kev, value);
//
//   TEST_ASSERT_EQUAL_INT(1, map->num_elements);
//   TEST_ASSERT_EQUAL_INT(num_buckets, map->num_buckets);
// }

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_new_hashmap);
  RUN_TEST(test_hash_function);
  // RUN_TEST(test_hashmap_insert);

  UNITY_END();

  return 0;
}
