#include <check.h>
#include <stdio.h>
#include <string.h>
#include "s21_string.h"

int r1, r2;

START_TEST(test_s21_memchr) {
    char str1[] = "Hello world!", str2[] = "";
    ck_assert_ptr_eq(s21_memchr(str1, 'w', 13), memchr(str1, 'w', 13));
    ck_assert_ptr_eq(s21_memchr(str1, ' ', 13), memchr(str1, ' ', 13));
    ck_assert_ptr_eq(s21_memchr(str1, 111, 13), memchr(str1, 111, 13));
    ck_assert_ptr_eq(s21_memchr(str2, ' ', 1), memchr(str2, ' ', 1));
}
END_TEST

START_TEST(test_s21_memcmp) {
    char str1[] = "abcdefghj", str2[] = "abcdefghj", str3[] = "abcdefghjz",
         str4[] = "", str5[] = "\n";
    ck_assert_int_eq(s21_memcmp(str1, str2, 10), memcmp(str1, str2, 10));
    ck_assert_int_eq(s21_memcmp(str1, str3, 10), memcmp(str1, str3, 10));
    ck_assert_int_eq(s21_memcmp(str1, str4, 1), memcmp(str1, str4, 1));
    ck_assert_int_eq(s21_memcmp(str5, str4, 1), memcmp(str5, str4, 1));
}
END_TEST

START_TEST(test_s21_memcpy) {
    char str1[] = "abcd", str2[] = "efgh", str3[] = "efghi", str4[] = "",
         str5[] = "abcd", str6[] = "efgh", str7[] = "efghi", str8[] = "";

    s21_memcpy(str1, str2, 4);
    memcpy(str5, str6, 4);
    ck_assert_pstr_eq(str1, str5);

    s21_memcpy(str1, str3, 4);
    memcpy(str5, str7, 4);
    ck_assert_pstr_eq(str1, str5);

    s21_memcpy(str3, str1, 1);
    memcpy(str7, str5, 1);
    ck_assert_pstr_eq(str3, str7);

    s21_memcpy(str1, str4, 1);
    memcpy(str5, str8, 1);
    ck_assert_pstr_eq(str1, str5);
}
END_TEST

START_TEST(test_s21_memmove) {
    char str1[] = "abcd", str2[] = "efgh", str3[] = "iuytr", str4[] = "";
    char str5[] = "abcd", str6[] = "efgh", str7[] = "iuytr", str8[] = "";
    ck_assert_pstr_eq(s21_memmove(str1, str2, 5), memmove(str5, str6, 5));
    ck_assert_pstr_eq(s21_memmove(str1, str3, 4), memmove(str5, str7, 4));
    ck_assert_pstr_eq(s21_memmove(str3, str4, 1), memmove(str7, str8, 1));
    ck_assert_pstr_eq(s21_memmove(str1, str2, 5), memmove(str5, str6, 5));
    ck_assert_pstr_eq(s21_memmove(str1, str2, 5), memmove(str5, str6, 5));
    ck_assert_pstr_eq(s21_memmove(str1, str2, 5), memmove(str5, str6, 5));
}
END_TEST

START_TEST(test_s21_memset) {
    char str1[9] = "abcdefgh", str2[1] = "", str3[9] = "abcdefgh", str4[1] = "";

    s21_memset(str1, 'i', 8);
    memset(str3, 'i', 8);
    ck_assert_pstr_eq(str1, str3);

    s21_memset(str1, 'i', 5);
    memset(str3, 'i', 5);
    ck_assert_pstr_eq(str1, str3);

    s21_memset(str1, ' ', 5);
    memset(str3, ' ', 5);
    ck_assert_pstr_eq(str1, str3);

    s21_memset(str1, ' ', 8);
    memset(str3, ' ', 8);
    ck_assert_pstr_eq(str1, str3);

    s21_memset(str2, ' ', 1);
    memset(str4, ' ', 1);
    ck_assert_pstr_eq(str1, str3);

    s21_memset(str2, 'i', 1);
    memset(str4, 'i', 1);
    ck_assert_pstr_eq(str1, str3);
}
END_TEST

START_TEST(test_s21_strcat) {
    char str1[32] = "Hello world", str2[] = "qwe", str3[] = " \n\0",
         str4[] = "\0", str5[] = "abcde\0", str6[32] = "",
         str7[32] = "Hello world", str8[] = "qwe", str9[] = " \n\0",
         str10[] = "\0", str11[] = "abcde\0", str12[32] = "";

    s21_strcat(str1, str3);
    strcat(str7, str9);
    ck_assert_pstr_eq(str1, str7);

    s21_strcat(str2, str4);
    strcat(str8, str10);
    ck_assert_pstr_eq(str2, str8);

    s21_strcat(str5, str4);
    strcat(str11, str10);
    ck_assert_pstr_eq(str5, str11);

    s21_strcat(str3, str4);
    strcat(str9, str10);
    ck_assert_pstr_eq(str3, str9);

    s21_strcat(str6, str2);
    strcat(str12, str8);
    ck_assert_pstr_eq(str6, str12);
}
END_TEST

START_TEST(test_s21_strncat) {
    char str1[32] = "Hello world", str2[] = "qwe", str3[] = " \n\0",
         str4[] = "\0", str6[32] = "", str7[32] = "Hello world", str8[] = "qwe",
         str9[] = " \n\0", str10[] = "\0", str12[32] = "";

    s21_strncat(str1, str3, 4);
    strncat(str7, str9, 4);
    ck_assert_pstr_eq(str1, str7);

    s21_strncat(str2, str4, 3);
    strncat(str8, str10, 3);
    ck_assert_pstr_eq(str2, str8);

    s21_strncat(str6, str2, 4);
    strncat(str12, str8, 4);
    ck_assert_pstr_eq(str6, str12);
}
END_TEST

START_TEST(test_s21_strchr) {
    char str1[] = "Hello world!", str2[] = "";
    ck_assert_pstr_eq(s21_strchr(str2, 33), strchr(str2, 33));
    ck_assert_pstr_eq(s21_strchr(str1, 'w'), strchr(str1, 'w'));
    ck_assert_pstr_eq(s21_strchr(str1, 108), strchr(str1, 108));
    ck_assert_pstr_eq(s21_strchr(str1, ' '), strchr(str1, ' '));
    ck_assert_pstr_eq(s21_strchr(str1, 'a'), strchr(str1, 'a'));
}
END_TEST

START_TEST(test_s21_strcmp) {
    char str1[] = "abcd", str2[] = "abcd", str4[] = "efghi", str5[] = "";
    ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
    ck_assert_int_eq(s21_strcmp(str4, str1), strcmp(str4, str1));
    ck_assert_int_eq(s21_strcmp(str5, str1), strcmp(str5, str1));
    ck_assert_int_eq(s21_strcmp(str1, str5), strcmp(str1, str5));
}
END_TEST

START_TEST(test_s21_strncmp) {
    char str1[] = "abcd", str2[] = "abcd", str3[] = "efgh", str4[] = "efghi",
         str5[] = "";
    ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
    ck_assert_int_eq(s21_strncmp(str1, str3, 5), strncmp(str1, str3, 5));
    ck_assert_int_eq(s21_strncmp(str1, str3, 4), strncmp(str1, str3, 4));
    ck_assert_int_eq(s21_strncmp(str1, str4, 5), strncmp(str1, str4, 5));
    ck_assert_int_eq(s21_strncmp(str4, str1, 4), strncmp(str4, str1, 4));
    ck_assert_int_eq(s21_strncmp(str5, str1, 1), strncmp(str5, str1, 1));
    ck_assert_int_eq(s21_strncmp(str1, str5, 1), strncmp(str1, str5, 1));
}
END_TEST

START_TEST(test_s21_strcpy) {
    char str1[] = "Hello", str2[] = "World", str3[] = "", str4[32] = "",
         str5[] = "Hello", str6[] = "World", str7[] = "", str8[32] = "";

    s21_strcpy(str1, str2);
    strcpy(str5, str6);
    ck_assert_str_eq(str1, str5);

    s21_strcpy(str2, str1);
    strcpy(str6, str5);
    ck_assert_str_eq(str2, str6);

    s21_strcpy(str1, str3);
    strcpy(str5, str7);
    ck_assert_str_eq(str1, str5);

    s21_strcpy(str4, str1);
    strcpy(str8, str5);
    ck_assert_str_eq(str4, str8);

    s21_strcpy(str4, str3);
    strcpy(str8, str7);
    ck_assert_str_eq(str4, str8);
}
END_TEST

START_TEST(test_s21_strncpy) {
    char str1[] = "kjzxnvkjbsdfjhkbbds", str2[] = "jsdjsdfkjdsfjh", str3[] = "",
         str4[] = "kjzxnvkjbsdfjhkbbds", str5[] = "jsdjsdfkjdsfjh", str6[] = "";

    s21_strncpy(str1, str2, 5);
    strncpy(str4, str5, 5);
    ck_assert_str_eq(str1, str4);

    s21_strncpy(str1, str2, 20);
    strncpy(str4, str5, 20);
    ck_assert_str_eq(str1, str4);

    s21_strncpy(str1, str2, 15);
    strncpy(str4, str5, 15);
    ck_assert_str_eq(str1, str4);

    s21_strncpy(str2, str1, 8);
    strncpy(str5, str4, 8);
    ck_assert_str_eq(str1, str4);

    s21_strncpy(str2, str1, 15);
    strncpy(str5, str4, 15);
    ck_assert_str_eq(str1, str4);

    s21_strncpy(str1, str3, 8);
    strncpy(str4, str6, 8);
    ck_assert_str_eq(str1, str4);
}
END_TEST

START_TEST(test_s21_strcspn) {
    char str1[] = "jkflkfgdkhslkhgsdk", str2[] = "gd", str3[] = "";
    ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
    ck_assert_int_eq(s21_strcspn(str2, str1), strcspn(str2, str1));
    ck_assert_int_eq(s21_strcspn(str1, str3), strcspn(str1, str3));
    ck_assert_int_eq(s21_strcspn(str2, str3), strcspn(str2, str3));
    ck_assert_int_eq(s21_strcspn(str3, str1), strcspn(str3, str1));
    ck_assert_int_eq(s21_strcspn(str3, str2), strcspn(str3, str2));
}
END_TEST

START_TEST(test_s21_strerror) {
    for (int j = 0, err = -1; j < 3; j++) {
        char *errtest1 = s21_strerror(err);
        char *errtest2 = strerror(err);
        S21_SIZE_T i = 0, len1 = s21_strlen(errtest1),
                   len2 = s21_strlen(errtest2);
        while (i < len1 || i < len2) {
            ck_assert_str_eq(errtest1 + i, errtest2 + i);
            i++;
        }
        err += 1;
    }
}
END_TEST

START_TEST(test_s21_strlen) {
    char str1[] = "Hello world!", str2[] = "", str3[] = "!@IU@!*&$@1KWljD",
         str4[] = "Hello world!\n", str5[] = "123456";
    ck_assert_int_eq(s21_strlen(str1), strlen(str1));
    ck_assert_int_eq(s21_strlen(str2), strlen(str2));
    ck_assert_int_eq(s21_strlen(str3), strlen(str3));
    ck_assert_int_eq(s21_strlen(str4), strlen(str4));
    ck_assert_int_eq(s21_strlen(str5), strlen(str5));
}
END_TEST

START_TEST(test_s21_strpbrk) {
    char str1[] = "abcdefghijklmnop", str2[] = "pkh", str3[] = "";
    ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
    ck_assert_ptr_eq(s21_strpbrk(str2, str1), strpbrk(str2, str1));
    ck_assert_ptr_eq(s21_strpbrk(str1, str3), strpbrk(str1, str3));
    ck_assert_ptr_eq(s21_strpbrk(str2, str3), strpbrk(str2, str3));
    ck_assert_ptr_eq(s21_strpbrk(str3, str1), strpbrk(str3, str1));
    ck_assert_ptr_eq(s21_strpbrk(str3, str2), strpbrk(str3, str2));
}
END_TEST

START_TEST(test_s21_strrchr) {
    char str1[] = ";odsagjnpasdun 1242149215", str2[] = "";
    ck_assert_pstr_eq(s21_strrchr(str1, 'a'), strrchr(str1, 'a'));
    ck_assert_pstr_eq(s21_strrchr(str1, 100), strrchr(str1, 100));
    ck_assert_pstr_eq(s21_strrchr(str1, '/'), strrchr(str1, '/'));
    ck_assert_pstr_eq(s21_strrchr(str1, 98), strrchr(str1, 98));
    ck_assert_pstr_eq(s21_strrchr(str2, 'a'), strrchr(str2, 'a'));
    ck_assert_pstr_eq(s21_strrchr(str2, ' '), strrchr(str2, ' '));
    ck_assert_pstr_eq(s21_strrchr(str2, 56), strrchr(str2, 56));
}
END_TEST

START_TEST(test_s21_strspn) {
    char str1[] = "a;iuhgilsdugiaudhgiu2", str2[] = "gsdsgk", str3[] = "i2u",
         str4[] = "";
    ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
    ck_assert_int_eq(s21_strspn(str1, str3), strspn(str1, str3));
    ck_assert_int_eq(s21_strspn(str2, str1), strspn(str2, str1));
    ck_assert_int_eq(s21_strspn(str3, str1), strspn(str3, str1));
    ck_assert_int_eq(s21_strspn(str2, str3), strspn(str2, str3));
    ck_assert_int_eq(s21_strspn(str2, str4), strspn(str2, str4));
    ck_assert_int_eq(s21_strspn(str4, str1), strspn(str4, str1));
}
END_TEST

START_TEST(test_s21_strstr) {
    char str1[] = "abcdefghijklm", str2[] = "hij", str3[] = "", str4[] = "edc";
    ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
    ck_assert_pstr_eq(s21_strstr(str1, str4), strstr(str1, str4));
    ck_assert_pstr_eq(s21_strstr(str2, str1), strstr(str2, str1));
    ck_assert_pstr_eq(s21_strstr(str2, str4), strstr(str2, str4));
    ck_assert_pstr_eq(s21_strstr(str3, str1), strstr(str3, str1));
    ck_assert_pstr_eq(s21_strstr(str3, str2), strstr(str3, str2));
    ck_assert_pstr_eq(s21_strstr(str3, str4), strstr(str3, str4));
}
END_TEST

START_TEST(test_s21_strtok) {
    char arr1[100] = "My name is Root. Hello world!", *parr1 = arr1,
         arr2[100] = "My name is Root. Hello world!", *parr2 = arr2;

    s21_strtok(parr1, " .");
    strtok(parr2, " .");
    ck_assert_pstr_eq(parr1, parr2);

    parr1 = s21_strtok(NULL, " .");
    parr2 = strtok(NULL, " .");
    ck_assert_pstr_eq(parr1, parr2);

    parr1 = s21_strtok(parr1, "x");
    parr2 = strtok(parr2, "x");
    ck_assert_pstr_eq(parr1, parr2);
}
END_TEST

START_TEST(test_s21_to_upper) {
    char *res = s21_to_upper("test");
    ck_assert_str_eq(res, "TEST");
    if (res)
        free(res);

    res = s21_to_upper(" t e s t");
    ck_assert_str_eq(res, " T E S T");
    if (res)
        free(res);

    res = s21_to_upper("test001");
    ck_assert_str_eq(res, "TEST001");
    if (res)
        free(res);

    res = s21_to_upper("!test!");
    ck_assert_str_eq(res, "!TEST!");
    if (res)
        free(res);

    res = s21_to_upper(" ");
    ck_assert_str_eq(res, " ");
    if (res)
        free(res);

    res = s21_to_upper("!*_*!");
    ck_assert_str_eq(res, "!*_*!");
    if (res)
        free(res);
}
END_TEST

START_TEST(test_s21_to_lower) {
    char *res = s21_to_lower("TEST");
    ck_assert_str_eq(res, "test");
    if (res)
        free(res);

    res = s21_to_lower(" T E S T");
    ck_assert_str_eq(res, " t e s t");
    if (res)
        free(res);

    res = s21_to_lower("TEST001");
    ck_assert_str_eq(res, "test001");
    if (res)
        free(res);

    res = s21_to_lower("!TEST!");
    ck_assert_str_eq(res, "!test!");
    if (res)
        free(res);

    res = s21_to_lower(" ");
    ck_assert_str_eq(res, " ");
    if (res)
        free(res);

    res = s21_to_lower("!*_*!");
    ck_assert_str_eq(res, "!*_*!");
    if (res)
        free(res);
}
END_TEST

START_TEST(test_s21_insert) {
    char *str1 = "Test";
    char *str2 = "quest";
    char *res = NULL;

    res = s21_insert(str1, str2, 2);
    ck_assert_str_eq(res, "Tequestst");
    if (res)
        free(res);

    str1 = "The test";
    str2 = " perfect";
    res = s21_insert(str1, str2, 3);
    ck_assert_str_eq(res, "The perfect test");
    if (res)
        free(res);

    str1 = "Insert in";
    str2 = " end";
    res = s21_insert(str1, str2, 9);
    ck_assert_str_eq(res, "Insert in end");
    if (res)
        free(res);

    str1 = " with insert";
    str2 = "Start";
    res = s21_insert(str1, str2, 0);
    ck_assert_str_eq(res, "Start with insert");
    if (res)
        free(res);

    str1 = "Newspace";
    str2 = " ";
    res = s21_insert(str1, str2, 3);
    ck_assert_str_eq(res, "New space");
    if (res)
        free(res);

    str1 = "";
    str2 = " ";
    res = s21_insert(str1, str2, 0);
    ck_assert_str_eq(res, " ");
    if (res)
        free(res);
}
END_TEST

START_TEST(test_s21_trim) {
    char *res = s21_trim("testc", "c");
    ck_assert_str_eq(res, "test");
    if (res)
        free(res);

    res = s21_trim(" test ", " ");
    ck_assert_str_eq(res, "test");
    if (res)
        free(res);

    res = s21_trim(" ", " ");
    ck_assert_str_eq(res, "");
    if (res)
        free(res);

    res = s21_trim("*te*st*", "*");
    ck_assert_str_eq(res, "te*st");
    if (res)
        free(res);

    res = s21_trim(" te st001", " ");
    ck_assert_str_eq(res, "te st001");
    if (res)
        free(res);

    res = s21_trim(" /*()", ")(/ *");
    ck_assert_str_eq(res, "");
    if (res)
        free(res);
}
END_TEST

    int main() {
    Suite *suite = suite_create("S21_Debuger");
    SRunner *srunner = srunner_create(suite);

    TCase *s21_memchrCase = tcase_create("s21_memchrCase");
    suite_add_tcase(suite, s21_memchrCase);
    tcase_add_test(s21_memchrCase, test_s21_memchr);

    TCase *s21_memcmpCase = tcase_create("s21_memcmpCase");
    suite_add_tcase(suite, s21_memcmpCase);
    tcase_add_test(s21_memcmpCase, test_s21_memcmp);

    TCase *s21_memcpyCase = tcase_create("s21_memcpyCase");
    suite_add_tcase(suite, s21_memcpyCase);
    tcase_add_test(s21_memcpyCase, test_s21_memcpy);

    TCase *s21_memmoveCase = tcase_create("s21_memmoveCase");
    suite_add_tcase(suite, s21_memmoveCase);
    tcase_add_test(s21_memmoveCase, test_s21_memmove);

    TCase *s21_memsetCase = tcase_create("s21_memsetCase");
    suite_add_tcase(suite, s21_memsetCase);
    tcase_add_test(s21_memsetCase, test_s21_memset);

    TCase *s21_strcatCase = tcase_create("s21_strcatCase");
    suite_add_tcase(suite, s21_strcatCase);
    tcase_add_test(s21_strcatCase, test_s21_strcat);

    TCase *s21_strncatCase = tcase_create("s21_strncatCase");
    suite_add_tcase(suite, s21_strncatCase);
    tcase_add_test(s21_strncatCase, test_s21_strncat);

    TCase *s21_strchrCase = tcase_create("s21_strchrCase");
    suite_add_tcase(suite, s21_strchrCase);
    tcase_add_test(s21_strchrCase, test_s21_strchr);

    TCase *s21_strcmpCase = tcase_create("s21_strcmpCase");
    suite_add_tcase(suite, s21_strcmpCase);
    tcase_add_test(s21_strcmpCase, test_s21_strcmp);

    TCase *s21_strncmpCase = tcase_create("s21_strncmpCase");
    suite_add_tcase(suite, s21_strncmpCase);
    tcase_add_test(s21_strncmpCase, test_s21_strncmp);

    TCase *s21_strcpyCase = tcase_create("s21_strcpyCase");
    suite_add_tcase(suite, s21_strcpyCase);
    tcase_add_test(s21_strcpyCase, test_s21_strcpy);

    TCase *s21_strncpyCase = tcase_create("s21_strncpyCase");
    suite_add_tcase(suite, s21_strncpyCase);
    tcase_add_test(s21_strncpyCase, test_s21_strncpy);

    TCase *s21_strcspnCase = tcase_create("s21_strcspnCase");
    suite_add_tcase(suite, s21_strcspnCase);
    tcase_add_test(s21_strcspnCase, test_s21_strcspn);

    TCase *s21_strerrorCase = tcase_create("s21_strerrorCase");
    suite_add_tcase(suite, s21_strerrorCase);
    tcase_add_test(s21_strerrorCase, test_s21_strerror);

    TCase *s21_strlenCase = tcase_create("s21_strlenCase");
    suite_add_tcase(suite, s21_strlenCase);
    tcase_add_test(s21_strlenCase, test_s21_strlen);

    TCase *s21_strpbrkCase = tcase_create("s21_strpbrkCase");
    suite_add_tcase(suite, s21_strpbrkCase);
    tcase_add_test(s21_strpbrkCase, test_s21_strpbrk);

    TCase *s21_strrchrCase = tcase_create("s21_strrchrCase");
    suite_add_tcase(suite, s21_strrchrCase);
    tcase_add_test(s21_strrchrCase, test_s21_strrchr);

    TCase *s21_strspnCase = tcase_create("s21_strspnCase");
    suite_add_tcase(suite, s21_strspnCase);
    tcase_add_test(s21_strspnCase, test_s21_strspn);

    TCase *s21_strstrCase = tcase_create("s21_strstrCase");
    suite_add_tcase(suite, s21_strstrCase);
    tcase_add_test(s21_strstrCase, test_s21_strstr);

    TCase *s21_strtokCase = tcase_create("s21_strtokCase");
    suite_add_tcase(suite, s21_strtokCase);
    tcase_add_test(s21_strtokCase, test_s21_strtok);

    TCase *s21_to_upperCase = tcase_create("s21_to_upperCase");
    suite_add_tcase(suite, s21_to_upperCase);
    tcase_add_test(s21_to_upperCase, test_s21_to_upper);

    TCase *s21_to_lowerCase = tcase_create("s21_to_lowerCase");
    suite_add_tcase(suite, s21_to_lowerCase);
    tcase_add_test(s21_to_lowerCase, test_s21_to_lower);

    TCase *s21_insertCase = tcase_create("s21_insertCase");
    suite_add_tcase(suite, s21_insertCase);
    tcase_add_test(s21_insertCase, test_s21_insert);

    TCase *s21_trimCase = tcase_create("s21_trimCase");
    suite_add_tcase(suite, s21_trimCase);
    tcase_add_test(s21_trimCase, test_s21_trim);

    srunner_run_all(srunner, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(srunner);
    srunner_free(srunner);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
