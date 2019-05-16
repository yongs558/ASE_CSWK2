#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include "../N0778285-ASE-CWK2/headers/rational.h"

using namespace ExactArithmetic;


/*
*
* Function add, subtract, multi and division
*
*/
Rational add(Rational x, Rational y) {
	return x + y;
}
Rational subtract(Rational x, Rational y) {
	return x - y;
}
Rational multi(Rational x, Rational y) {
	return x * y;
}
Rational division(Rational x, Rational y) {
	return x / y;
}



/*
*
* Test case
*
*/
BOOST_AUTO_TEST_SUITE(maths_function)

	//check input in int addition
	BOOST_AUTO_TEST_CASE(check_addition_int) {

		//input as int
		Rational result = Rational(2, 3);
		BOOST_CHECK_EQUAL(Rational(1,3) + Rational(1, 3), result);

		//input as string
		Rational x;
		std::istringstream iss("1/3");
		iss >> x;
		BOOST_CHECK_EQUAL(add(x, x), result);

	}
	BOOST_AUTO_TEST_CASE(check_subtraction_int) {
		//input as int
		Rational result = Rational(-1, 3);
		BOOST_CHECK_EQUAL(Rational(1, 3) - Rational(2, 3), result);

		//input as string
		Rational x;
		Rational y;
		std::istringstream iss("1/3");
		std::istringstream iss2("2/3");
		iss >> x;
		iss2 >> y;
		BOOST_CHECK_EQUAL(subtract(x, y), result);
	}
	BOOST_AUTO_TEST_CASE(check_multiplication_int) {
		Rational result = Rational(1, 9);
		BOOST_CHECK_EQUAL(Rational(1, 3) * Rational(1, 3), result);
	}
	BOOST_AUTO_TEST_CASE(check_division_int) {
		Rational result = Rational(1);
		BOOST_CHECK_EQUAL(Rational(1, 3) / Rational(1, 3), result);
	}



	//check input in double changed in fraction
	BOOST_AUTO_TEST_CASE(check_addition_double) {

		Rational result = Rational(7, 2);
		BOOST_CHECK_EQUAL(add(2.25, 1.25), result);
	}
	BOOST_AUTO_TEST_CASE(check_subtraction_double) {

		Rational result = Rational(1, 1);
		BOOST_CHECK_EQUAL(subtract(2.25, 1.25), result);
	}
	BOOST_AUTO_TEST_CASE(check_multiplication_double) {

		Rational result = Rational(45, 16);
		BOOST_CHECK_EQUAL(multi(2.25, 1.25), result);
	}
	BOOST_AUTO_TEST_CASE(check_division_double) {

		Rational result = Rational(9, 5);
		BOOST_CHECK_EQUAL(division(2.25, 1.25), result);
	}

	
	//check value bigger or smaller
	BOOST_AUTO_TEST_CASE(check_smaller_than)
	{
		Rational x = Rational(4, 3);
		Rational y = Rational(2, 1);
		BOOST_CHECK_EQUAL(x <= y, false);
	}

	BOOST_AUTO_TEST_CASE(check_bigger_than)
	{
		Rational x = Rational(4, 3);
		Rational y = Rational(2, 1);
		BOOST_CHECK_EQUAL(x >= y, true);
	}



	//check fraction in lowest terms
	BOOST_AUTO_TEST_CASE(lowest_terms) {

		BOOST_CHECK_EQUAL(Rational(2000000, 1000000), Rational(2));
		BOOST_CHECK_EQUAL(Rational(3,3), Rational(1));
		BOOST_CHECK_EQUAL(Rational(900000, 900000), Rational(1));
		BOOST_CHECK_EQUAL(Rational(300000000, 100000000), Rational(3));
	}



	//check invalid string
	BOOST_AUTO_TEST_CASE(check_string_invalid)
	{
		BOOST_CHECK_THROW(Rational("qwerty"), std::invalid_argument);
	}
	//check in string valid
	BOOST_AUTO_TEST_CASE(check_iss)
	{
		Rational x;
		std::istringstream iss("2/3");
		iss >> x;
		BOOST_CHECK_EQUAL(x, Rational(2, 3));
	}



	//check negate function with negative and position value
	BOOST_AUTO_TEST_CASE(check_negate_negative)
	{
		BOOST_CHECK_EQUAL(Rational::negate(Rational(-4, 5)), Rational(-4, 5));
	}
	BOOST_AUTO_TEST_CASE(check_positive_negative)
	{
		BOOST_CHECK_EQUAL(Rational::negate(Rational(4, 5)), Rational(4, 5));
	}



	//check abs function with negative and position value
	BOOST_AUTO_TEST_CASE(check_abs_negative)
	{
		BOOST_CHECK_EQUAL(Rational::abs(Rational(-2, 3)), Rational(-2, 3));
	}
	BOOST_AUTO_TEST_CASE(check_abs_positive)
	{
		BOOST_CHECK_EQUAL(Rational::abs(Rational(1, 2)), Rational(1, 2));
	}


	//end test case
BOOST_AUTO_TEST_SUITE_END()