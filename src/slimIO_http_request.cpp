#include <algorithm>
#include <string>
#include <unordered_map>
#include <slimIO/http/headers.h>
#include <slimIO/http/parser.h>
#include <slimIO/http/response.h>
#include <slimIO/http/request.h>

#include <iostream>
slimIO::http::Request::Request(void) {}
slimIO::http::Request::Request(char* request_pointer) {
	slimIO::http::parser::parse_http_request(request_pointer, this);
}
slimIO::http::Request::Request(std::string& request_string) {
	slimIO::http::parser::parse_http_request(request_string, this);
}
slimIO::http::Headers& slimIO::http::Request::headers(void) {
	return headers_map;
}
void slimIO::http::Request::body(std::string value) {
	body_string = value;
}
void slimIO::http::Request::body(std::string* value) {
	body_string = std::string(*value);
}
std::string& slimIO::http::Request::body(void) {
	return body_string;
}
void slimIO::http::Request::host(std::string value) {
	host_string = value;
}
void slimIO::http::Request::host(std::string* value) {
	host_string = std::string(*value);
}
std::string& slimIO::http::Request::host(void) {
	return host_string;
}
void slimIO::http::Request::method(std::string value) {
	method_string = value;
}
void slimIO::http::Request::method(std::string* value) {
	method_string = std::string(*value);
}
std::string& slimIO::http::Request::method(void) {
	return method_string;
}
void slimIO::http::Request::path(std::string value) {
	path_string = value;
}
void slimIO::http::Request::path(std::string* value) {
	path_string = std::string(*value);
}
std::string& slimIO::http::Request::path(void) {
	return path_string;
}
int& slimIO::http::Request::port(void) {
	return port_value;
}
void slimIO::http::Request::port(int value) {
	port_value = value;
}
void slimIO::http::Request::protocol(std::string value) {
	protocol_string = value;
}
void slimIO::http::Request::protocol(std::string* value) {
	protocol_string = std::string(*value);
}
std::string& slimIO::http::Request::protocol(void) {
	return protocol_string;
}
void slimIO::http::Request::version(std::string value) {
	version_string = value;
}
void slimIO::http::Request::version(std::string* value) {
	version_string = std::string(*value);
}
std::string& slimIO::http::Request::version(void) {
	return version_string;
}