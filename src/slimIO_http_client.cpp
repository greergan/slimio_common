#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <slimIO/http/client.h>
#include <slimIO/http/headers.h>
#include <slimIO/http/parser.h>
#include <slimIO/http/request.h>
#include <slimIO/http/response.h>
#include <slimIO/utilities.h>

#include <iostream>
slimIO::http::Response slimIO::http::client::fetch(char* request_pointer) {
	Request request(request_pointer);
	return fetch(request);
}
slimIO::http::Response slimIO::http::client::fetch(std::string& request_string) {
	std::cout << request_string << std::endl;
	Request request(request_string);
	std::cout << request_string << std::endl;
	return fetch(request);
}
slimIO::http::Response slimIO::http::client::fetch(Request& request) {
	slimIO::http::Response response;
	auto ip_address = slimIO::utilities::get_ip_address(request.host());
/* 	std::cout << "fetch: request.protocol => " << request.protocol() << std::endl;
	std::cout << "fetch: request.host => " << request.host() << std::endl;
	std::cout << "fetch: request.port => " << request.port() << std::endl;
	std::cout << "fetch: request.method => " << request.method() << std::endl;
	std::cout << "fetch: request.path => " << request.path() << std::endl; */
	std::cout << "response body => " << response.body() << std::endl;
	return response;
}