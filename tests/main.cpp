#include <iostream>
#include "tests.h"
int main(int argc, char* argv[]) {
	std::cout << "preparing to run test 1 => get ip addresses and bind to host\n";
	auto test_1_results = assert_utilities_get_ip_address();
	std::cout << "preparing to run test 2 => parse URL into request\n";
	auto test_2_results = assert_request_parses("HTTPs://www.google.com:443");
	std::cout << "preparing to run test 3 => parse fetch into request\n";
	auto test_3_results = assert_client_fetch("HTTP://www.google.com");
}