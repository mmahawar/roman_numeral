#include <stdlib.h>
#include <check.h>
#include "../src/roman_number_calculator.h"

const size_t EXPECTED_SIZE = 16; 

START_TEST( given_NULL_and_NULL_produces_ERROR_upon_adding) {
	const char expected_result[] = "";

    char result[EXPECTED_SIZE];
	memset(result, 0, EXPECTED_SIZE);
	int returnType = add(NUL, NUL, result);

	ck_assert_str_eq(result, expected_result);
	ck_assert_int_eq(BAD_INPUT_PARAMETER, returnType);
}
END_TEST

START_TEST( given_MMMM_and_MMMM_produces_ERROR_upon_adding) {
	const char first_operand[] = "MMMM";
	const char second_operand[] = "MMMM";
	const char expected_result[] = "";

	char result[EXPECTED_SIZE];
	memset(result, 0, EXPECTED_SIZE);
	int returnType = add(first_operand, second_operand, result);

	ck_assert_str_eq(result, expected_result);
	ck_assert_int_eq(BAD_INPUT_PARAMETER, returnType);
}
END_TEST

START_TEST( given_I_and_I_produces_II_upon_adding) {
	const char first_operand[] = "I";
	const char second_operand[] = "I";
	const char expected_result[] = "II";

	char result[EXPECTED_SIZE];
	memset(result, 0, EXPECTED_SIZE);
	add(first_operand, second_operand, result);

	ck_assert_str_eq(result, expected_result);
}
END_TEST

START_TEST( given_II_and_I_produces_III_upon_adding) {
	const char first_operand[] = "II";
	const char second_operand[] = "I";
	const char expected_result[] = "III";

	char result[EXPECTED_SIZE];
	memset(result, 0, EXPECTED_SIZE);
	add(first_operand, second_operand, result);

	ck_assert_str_eq(result, expected_result);
}
END_TEST

START_TEST( given_II_and_II_produces_IV_upon_adding) {
	const char first_operand[] = "II";
	const char second_operand[] = "II";
	const char expected_result[] = "IV";

	char result[EXPECTED_SIZE];
	memset(result, 0, EXPECTED_SIZE);
	add(first_operand, second_operand, result);

	ck_assert_str_eq(result, expected_result);
}
END_TEST

START_TEST( given_V_and_V_produces_X_upon_adding) {
	const char first_operand[] = "V";
	const char second_operand[] = "V";
	const char expected_result[] = "X";

	char result[EXPECTED_SIZE];
	memset(result, 0, EXPECTED_SIZE);
	add(first_operand, second_operand, result);

	ck_assert_str_eq(result, expected_result);
}
END_TEST

START_TEST( given_IV_and_V_produces_IX_upon_adding) {
	const char first_operand[] = "IV";
	const char second_operand[] = "V";
	const char expected_result[] = "IX";

	char result[EXPECTED_SIZE];
	memset(result, 0, EXPECTED_SIZE);
	add(first_operand, second_operand, result);

	ck_assert_str_eq(result, expected_result);
}
END_TEST

START_TEST( given_MMM_and_CMXCIX_produces_MMMCMXCIX_upon_adding) {
	const char first_operand[] = "MMM";
	const char second_operand[] = "CMXCIX";
	const char expected_result[] = "MMMCMXCIX";

	char result[EXPECTED_SIZE];
	memset(result, 0, EXPECTED_SIZE);
	add(first_operand, second_operand, result);

	ck_assert_str_eq(result, expected_result);
}
END_TEST

START_TEST( given_D_and_D_produces_M_upon_adding) {
	const char first_operand[] = "D";
	const char second_operand[] = "D";
	const char expected_result[] = "M";

	char result[EXPECTED_SIZE];
	memset(result, 0, EXPECTED_SIZE);
	add(first_operand, second_operand, result);

	ck_assert_str_eq(result, expected_result);
}
END_TEST

START_TEST( given_II_and_I_produces_I_upon_substracting) {
	const char first_operand[] = "II";
	const char second_operand[] = "I";
	const char expected_result[] = "I";

	char result[EXPECTED_SIZE];
	memset(result, 0, EXPECTED_SIZE);
	substract(first_operand, second_operand, result);

	ck_assert_str_eq(result, expected_result);
}
END_TEST

START_TEST( given_X_and_V_produces_V_upon_substracting) {
	const char first_operand[] = "X";
	const char second_operand[] = "V";
	const char expected_result[] = "V";

	char result[EXPECTED_SIZE];
	memset(result, 0, EXPECTED_SIZE);
	substract(first_operand, second_operand, result);

	ck_assert_str_eq(result, expected_result);
}
END_TEST

START_TEST( given_X_and_VI_produces_IV_upon_substracting) {
	const char first_operand[] = "X";
	const char second_operand[] = "VI";
	const char expected_result[] = "IV";

	char result[EXPECTED_SIZE];
	memset(result, 0, EXPECTED_SIZE);
	substract(first_operand, second_operand, result);

	ck_assert_str_eq(result, expected_result);
}
END_TEST

START_TEST( given_MMMCMXCIX_and_MMM_produces_CMXCIX_upon_substracting) {
	const char first_operand[] = "MMMCMXCIX";
	const char second_operand[] = "MMM";
	const char expected_result[] = "CMXCIX";

	char result[EXPECTED_SIZE];
	memset(result, 0, EXPECTED_SIZE);
	substract(first_operand, second_operand, result);

	ck_assert_str_eq(result, expected_result);
}
END_TEST

START_TEST( given_M_and_D_produces_D_upon_substracting) {
	const char first_operand[] = "M";
	const char second_operand[] = "D";
	const char expected_result[] = "D";

	char result[EXPECTED_SIZE];
	memset(result, 0, EXPECTED_SIZE);
	substract(first_operand, second_operand, result);

	ck_assert_str_eq(result, expected_result);
}
END_TEST

START_TEST( given_MMM_and_MMMCMXCIX_produces_NEGATIVE_RESULT_upon_substracting) {
	const char first_operand[] = "MMM";
	const char second_operand[] = "MMMCMXCIX";
	const char expected_result[] = "";

	char result[EXPECTED_SIZE];
	memset(result, 0, EXPECTED_SIZE);
	int returnType = substract(first_operand, second_operand, result);

	ck_assert_str_eq(result, expected_result);
	ck_assert_int_eq(BAD_RESULT, returnType);
}
END_TEST

START_TEST( given_MM_and_MM_produces_ERROR_upon_adding) {
	const char first_operand[] = "MM";
	const char second_operand[] = "MM";
	const char expected_result[] = "";

	char result[EXPECTED_SIZE];
	memset(result, 0, EXPECTED_SIZE);
	int returnType = add(first_operand, second_operand, result);

	ck_assert_str_eq(result, expected_result);
	ck_assert_int_eq(BAD_RESULT, returnType);
}
END_TEST

Suite * numerals_suite(void) {
	Suite *s;
	TCase *tc_basic;

	s = suite_create("numerals");
	tc_basic = tcase_create("basic");

    // input Validation  
    tcase_add_test(tc_basic, given_NULL_and_NULL_produces_ERROR_upon_adding);
    tcase_add_test(tc_basic, given_MMMM_and_MMMM_produces_ERROR_upon_adding);

    // Addition
    tcase_add_test(tc_basic, given_I_and_I_produces_II_upon_adding);
	tcase_add_test(tc_basic, given_II_and_I_produces_III_upon_adding);
	tcase_add_test(tc_basic, given_II_and_II_produces_IV_upon_adding);
	tcase_add_test(tc_basic, given_V_and_V_produces_X_upon_adding);
	tcase_add_test(tc_basic, given_IV_and_V_produces_IX_upon_adding);
	tcase_add_test(tc_basic, given_D_and_D_produces_M_upon_adding);
	tcase_add_test(tc_basic,
			given_MMM_and_CMXCIX_produces_MMMCMXCIX_upon_adding);

    // Substraction
    tcase_add_test(tc_basic, given_II_and_I_produces_I_upon_substracting);
	tcase_add_test(tc_basic, given_X_and_V_produces_V_upon_substracting);
	tcase_add_test(tc_basic, given_X_and_VI_produces_IV_upon_substracting);
	tcase_add_test(tc_basic, given_M_and_D_produces_D_upon_substracting);
	tcase_add_test(tc_basic,
			given_MMMCMXCIX_and_MMM_produces_CMXCIX_upon_substracting);
    
    // Result Validation
	tcase_add_test(tc_basic, given_MMM_and_MMMCMXCIX_produces_NEGATIVE_RESULT_upon_substracting);
    tcase_add_test(tc_basic, given_MM_and_MM_produces_ERROR_upon_adding);


	suite_add_tcase(s, tc_basic);

	return s;
}

const int main(void) {
	int num_failed;
	Suite *s;
	SRunner *sr;

	s = numerals_suite();
	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	num_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (num_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
