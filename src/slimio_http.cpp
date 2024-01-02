#include <algorithm>
#include <string>
#include <unordered_map>
#include <slimio/http/headers.h>
#include <slimio/http/parser.h>
#include <slimio/http/response.h>
#include <slimio/http/request.h>

#include <iostream>


/* slimio::http::Headers */
std::unordered_map<std::string, std::string>& slimio::http::Headers::get(void) {
	return headers;
}
void slimio::http::Headers::set(std::string key, std::string value) {
	headers[key] = value;
}
slimio::http::Headers& slimio::http::Response::headers(void) {
	return headers_map;
}
/* slimio::http::Response */
void slimio::http::Response::version(std::string value) {
	version_string = value;
}
void slimio::http::Response::version(std::string* value) {
	version_string = std::string(*value);
}
std::string& slimio::http::Response::version(void) {
	return version_string;
}
void slimio::http::Response::body(std::string value) {
	body_string = value;
}
void slimio::http::Response::body(std::string* value) {
	body_string = std::string(*value);
}
std::string& slimio::http::Response::body(void) {
	return body_string;
}
void slimio::http::Response::response_code(int value) {
	response_code_int = value;
	switch(response_code_int) {
		case 200: response_code_string_value = "OK"; break;
		case 404: response_code_string_value = "Not Found"; break;
		case 501: response_code_string_value = "Not Implemented"; break;
		case 505: response_code_string_value = "HTTP Version Not Supported"; break;
	}
}
int slimio::http::Response::response_code(void) {
	return response_code_int;
}
std::string& slimio::http::Response::response_code_string(void) {
	return response_code_string_value;
}
/* slimio::http::Request */
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
void slimio::http::Request::version(std::string value) {
	version_string = value;
}
void slimio::http::Request::version(std::string* value) {
	version_string = std::string(*value);
}
std::string& slimio::http::Request::version(void) {
	return version_string;
}