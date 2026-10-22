#include <gtest/gtest.h>

#include "string.hpp"

TEST(StringFunction, strlen) {
    EXPECT_EQ(String::strlen(""), 0);
    EXPECT_EQ(String::strlen("foo"), 3);
}

TEST(StringFunction, strcpy) {
    char result[10];
    EXPECT_EQ(String::strcpy(result, "foo"), result);
    EXPECT_STREQ(result, "foo");

    EXPECT_EQ(String::strcpy(result, "a"), result);
    EXPECT_STREQ(result, "a");

    EXPECT_EQ(String::strcpy(result, ""), result);
    EXPECT_STREQ(result, "");
}

TEST(StringFunction, strncpy) {
    char result[10];
    EXPECT_EQ(String::strncpy(result, "hello", 3), result);
    EXPECT_STREQ(result, "hel");

    EXPECT_EQ(String::strncpy(result, "hello", 5), result);
    EXPECT_STREQ(result, "hello");

    EXPECT_EQ(String::strncpy(result, "hi", 10), result);
    EXPECT_STREQ(result, "hi");

    EXPECT_EQ(String::strncpy(result, "hello", 0), result);
    EXPECT_STREQ(result, "");

    EXPECT_EQ(String::strncpy(result, "", 3), result);
    EXPECT_STREQ(result, "");

    EXPECT_EQ(String::strncpy(result, "a", 1), result);
    EXPECT_STREQ(result, "a");
}

TEST(StringFunction, strcat) {
    // normal case
    char r1[20] = "ab";
    EXPECT_EQ(String::strcat(r1, "cd"), r1);
    EXPECT_STREQ(r1, "abcd");

    // empty dest
    char r2[20] = "";
    EXPECT_EQ(String::strcat(r2, "cd"), r2);
    EXPECT_STREQ(r2, "cd");

    // empty src
    char r3[20] = "ab";
    EXPECT_EQ(String::strcat(r3, ""), r3);
    EXPECT_STREQ(r3, "ab");

    // both empty
    char r4[20] = "";
    EXPECT_EQ(String::strcat(r4, ""), r4);
    EXPECT_STREQ(r4, "");

    // one char each
    char r5[20] = "a";
    EXPECT_EQ(String::strcat(r5, "b"), r5);
    EXPECT_STREQ(r5, "ab");

    // punctuation
    char r6[20] = "hi";
    EXPECT_EQ(String::strcat(r6, ", there!"), r6);
    EXPECT_STREQ(r6, "hi, there!");
}

TEST(StringFunction, strncat) {
    // n smaller than src
    char r1[20] = "ab";
    EXPECT_EQ(String::strncat(r1, "cdef", 2), r1);
    EXPECT_STREQ(r1, "abcd");

    // n equal to src length
    char r2[20] = "ab";
    EXPECT_EQ(String::strncat(r2, "cdef", 4), r2);
    EXPECT_STREQ(r2, "abcdef");

    // n bigger than src
    char r3[20] = "ab";
    EXPECT_EQ(String::strncat(r3, "cdef", 10), r3);
    EXPECT_STREQ(r3, "abcdef");

    // n = 0
    char r4[20] = "ab";
    EXPECT_EQ(String::strncat(r4, "cdef", 0), r4);
    EXPECT_STREQ(r4, "ab");

    // n = 1
    char r5[20] = "ab";
    EXPECT_EQ(String::strncat(r5, "cdef", 1), r5);
    EXPECT_STREQ(r5, "abc");

    // empty dest
    char r6[20] = "";
    EXPECT_EQ(String::strncat(r6, "cdef", 2), r6);
    EXPECT_STREQ(r6, "cd");

    // empty src
    char r7[20] = "ab";
    EXPECT_EQ(String::strncat(r7, "", 3), r7);
    EXPECT_STREQ(r7, "ab");
}

TEST(StringFunction, strcmp) {
       EXPECT_EQ(String::strncmp("abcx", "abcy", 3), 0);
       EXPECT_LT(String::strncmp("abcx", "abcy", 4), 0);
       EXPECT_GT(String::strncmp("abcy", "abcx", 4), 0);
       EXPECT_EQ(String::strncmp("abc", "xyz", 0), 0);
       EXPECT_LT(String::strncmp("a", "b", 1), 0);
       EXPECT_EQ(String::strncmp("abc", "abc", 10), 0);
       EXPECT_LT(String::strncmp("ab", "abc", 10), 0);
       EXPECT_EQ(String::strncmp("", "", 5), 0);
       EXPECT_GT(String::strncmp("a", "", 5), 0);
}

TEST(StringFunction, strncmp) {
    EXPECT_EQ(String::strcmp("abc", "abc"), 0);
    EXPECT_EQ(String::strcmp("a", "a"), 0);
    EXPECT_EQ(String::strcmp("", ""), 0);

   
    EXPECT_LT(String::strcmp("abc", "abd"), 0);
    EXPECT_LT(String::strcmp("a", "b"), 0);
    EXPECT_LT(String::strcmp("abc", "bbc"), 0);   

   
    EXPECT_GT(String::strcmp("abd", "abc"), 0);
    EXPECT_GT(String::strcmp("b", "a"), 0);
    EXPECT_GT(String::strcmp("bbc", "abc"), 0);

  
    EXPECT_LT(String::strcmp("ab", "abc"), 0);
    EXPECT_GT(String::strcmp("abc", "ab"), 0);

   
    EXPECT_LT(String::strcmp("", "a"), 0);
    EXPECT_GT(String::strcmp("a", ""), 0);

   
    EXPECT_LT(String::strcmp("a!", "a?"), 0);     
    EXPECT_LT(String::strcmp("A", "a"), 0);  
}

TEST(StringFunction, reverse_cpy){
    char r1[20];
    String::reverse_cpy(r1, "abc");
    EXPECT_STREQ(r1, "cba");

    char r2[20];
    String::reverse_cpy(r2, "");
    EXPECT_STREQ(r2, "");

    char r3[20];
    String::reverse_cpy(r3, "a");
    EXPECT_STREQ(r3, "a");

    char r4[20];
    String::reverse_cpy(r4, "ab");
    EXPECT_STREQ(r4, "ba");

    char r5[20];
    String::reverse_cpy(r5, "racecar");
    EXPECT_STREQ(r5, "racecar");

    char r6[20];
    String::reverse_cpy(r6, "hi, you!");
    EXPECT_STREQ(r6, "!uoy ,ih");
}

TEST(StringFunction, strchr) {
    const char *s = "hello";
    EXPECT_EQ(String::strchr(s, 'h'), s);        // first char
    EXPECT_EQ(String::strchr(s, 'l'), s + 2);    // first of repeated char
    EXPECT_EQ(String::strchr(s, 'o'), s + 4);    // last char
    EXPECT_EQ(String::strchr(s, 'z'), nullptr);  // not found
    EXPECT_EQ(String::strchr(s, '\0'), s + 5);   // finds the terminator

    const char *e = "";
    EXPECT_EQ(String::strchr(e, 'a'), nullptr);  // empty string
    EXPECT_EQ(String::strchr(e, '\0'), e);

    const char *p = "a,b!";
    EXPECT_EQ(String::strchr(p, '!'), p + 3);    // punctuation
}

TEST(StringFunction, strstr) {
    const char *h = "hello world";
    EXPECT_EQ(String::strstr(h, "hello"), h);        // at the start
    EXPECT_EQ(String::strstr(h, "world"), h + 6);    // at the end
    EXPECT_EQ(String::strstr(h, "o"), h + 4);        // first of repeats
    EXPECT_EQ(String::strstr(h, "lo w"), h + 3);     // middle, with space
    EXPECT_EQ(String::strstr(h, "hello world"), h);  // whole string
    EXPECT_EQ(String::strstr(h, "xyz"), nullptr);    // not found
    EXPECT_EQ(String::strstr(h, "worlds"), nullptr); // runs past the end
    EXPECT_EQ(String::strstr(h, ""), h);             // empty needle

    const char *e = "";
    EXPECT_EQ(String::strstr(e, "a"), nullptr);      // empty haystack
    EXPECT_EQ(String::strstr(e, ""), e);             // both empty

    const char *p = "aab";
    EXPECT_EQ(String::strstr(p, "ab"), p + 1);       // partial match, then retry

    const char *q = "a,b!c";
    EXPECT_EQ(String::strstr(q, "b!"), q + 2);       // punctuation
}
