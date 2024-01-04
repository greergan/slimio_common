#include <cassert>
#include <iostream>
#include <tests.h>
#include <slimIO/http/client.h>
#include <slimIO/http/headers.h>
#include <slimIO/http/request.h>
#include <slimIO/http/response.h>
bool assert_client_fetch(std::string request_string) {
	auto response = slimIO::http::client::fetch(request_string);
	std::cout << "\r response.code"	<< response.response_code() << std::endl;
	assert(response.response_code() == 200);
	std::cout << "\r response.response_code_string"	<< response.response_code_string() << std::endl;
	assert(response.response_code_string() == "Ok");
	return true;
}