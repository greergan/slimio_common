#include <slimio/http/client.h>
#include <slimio/http/headers.h>
#include <slimio/http/parser.h>
#include <slimio/http/request.h>
#include <slimio/http/response.h>

#include <iostream>
slimio::http::Response slimio::http::client::fetch(char* request_pointer) {
	Request request(request_pointer);
	return fetch(request);
}
slimio::http::Response slimio::http::client::fetch(std::string& request_string) {
	Request request(request_string);
	return fetch(request);
}
slimio::http::Response slimio::http::client::fetch(Request& request) {
	std::cout << "fetch: request.protocol => " << request.protocol() << std::endl;
	std::cout << "fetch: request.host => " << request.host() << std::endl;
	std::cout << "fetch: request.port => " << request.port() << std::endl;
	std::cout << "fetch: request.method => " << request.method() << std::endl;
	std::cout << "fetch: request.path => " << request.path() << std::endl;
}