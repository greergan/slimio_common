#include <cassert>
#include <iostream>
#include "tests.h"
#include <slimio/http/request.h>

bool assert_request_parses(std::string request_string) {
	std::cout << "preparing to run test 1\n";
	std::cout << "\trequest string => " << request_string << std::endl;
	slimio::http::Request request(request_string);
	std::cout << "\trequest protocol => " << request.protocol() << std::endl;
	assert(request.protocol().length() == 4 || request.protocol().length() == 5);
	assert(request.protocol() == "http" || request.protocol() == "https");
	std::cout << "\trequest host => " << request.host() << std::endl;
	assert(request.host().length() > 0);
	std::cout << "\trequest port => " << request.port() << std::endl;
	assert(request.port() > -1);
	std::cout << "\trequest path => " << request.path() << std::endl;
	assert(request.path().length() > 0);
	return true;
}