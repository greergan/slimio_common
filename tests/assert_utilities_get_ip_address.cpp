#include <cassert>
#include <iostream>
#include "tests.h"
#include <slimIO/http/request.h>
#include <slimIO/utilities.h>
bool assert_utilities_get_ip_address(void) {
	auto ip_address = slimIO::utilities::get_ip_address("www.google.com");
	std::cout << "\thost www.google.com" << std::endl;
	std::cout << "\tip address => " << ip_address << std::endl;
	assert(ip_address.length() >= 7 && ip_address.length() <= 15);
	ip_address = slimIO::utilities::get_ip_address("localhost");
	std::cout << "\thost localhost" << std::endl;
	std::cout << "\tip address => " << ip_address << std::endl;
	assert(ip_address.length() >= 7 && ip_address.length() <= 15);
	ip_address = slimIO::utilities::get_ip_address("");
	std::cout << "\thost (empty string)" << std::endl;
	std::cout << "\tip address => " << ip_address << std::endl;
	assert(ip_address.length() == 0);
	ip_address = slimIO::utilities::get_ip_address("192.168.122.33");
	std::cout << "\thost 192.168.122.33" << std::endl;
	std::cout << "\tip address => " << ip_address << std::endl;
	assert(ip_address.length() == 14);

	slimIO::http::Request request("http://www.google.com");
	ip_address = slimIO::utilities::get_ip_address(request.host());
	std::cout << "\thost from parsed request " << request.host() << std::endl;
	std::cout << "\tip address => " << ip_address << std::endl;
	assert(ip_address.length() >= 7 && ip_address.length() <= 15);

	std::cout << "\tbinding to www.google.com by ip address" << std::endl;
	int socket_handle = -1;
	try {
		socket_handle = slimIO::utilities::bind_to_host(ip_address, 80);
		std::cout << "\tsocket_handle => " << socket_handle << std::endl;
		assert(socket_handle >= 0);
	}
	catch(std::runtime_error& error) {
		std::cout << "\t" << error.what() << std::endl;
		assert(socket_handle >= 0);
	}
	return true;
}