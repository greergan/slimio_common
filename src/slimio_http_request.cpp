#include <algorithm>
#include <string>
#include <unordered_map>
#include <slimio/http/headers.h>
#include <slimio/http/parser.h>
#include <slimio/http/response.h>
#include <slimio/http/request.h>

#include <iostream>
slimio::http::Request::Request(void) {}
slimio::http::Request::Request(char* request_pointer) {
	slimio::http::parser::parse_http_request(request_pointer, this);
}
slimio::http::Request::Request(std::string& request_string) {
	slimio::http::parser::parse_http_request(request_string, this);
}
slimio::http::Headers& slimio::http::Request::headers(void) {
	return headers_map;
}
void slimio::http::Request::host(std::string value) {
	host_string = value;
}
void slimio::http::Request::host(std::string* value) {
	host_string = std::string(*value);
}
std::string& slimio::http::Request::host(void) {
	return host_string;
}

void slimio::http::Request::method(std::string value) {
	method_string = value;
}
void slimio::http::Request::method(std::string* value) {
	method_string = std::string(*value);
}
std::string& slimio::http::Request::method(void) {
	return method_string;
}
void slimio::http::Request::path(std::string value) {
	path_string = value;
}
void slimio::http::Request::path(std::string* value) {
	path_string = std::string(*value);
}
std::string& slimio::http::Request::path(void) {
	return path_string;
}
int& slimio::http::Request::port(void) {
	return port_value;
}
void slimio::http::Request::port(int value) {
	port_value = value;
}
void slimio::http::Request::protocol(std::string value) {
	protocol_string = value;
}
void slimio::http::Request::protocol(std::string* value) {
	protocol_string = std::string(*value);
}
std::string& slimio::http::Request::protocol(void) {
	return protocol_string;
}
void slimio::http::Request::version(std::string value) {
	version_string = value;
}
void slimio::http::Request::version(std::string* value) {
	version_string = std::string(*value);
}
std::string& slimio::http::Request::version(void) {
	return version_string;
}