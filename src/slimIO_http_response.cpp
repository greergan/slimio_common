#include <algorithm>
#include <string>
#include <unordered_map>
#include <slimIO/http/headers.h>
#include <slimIO/http/parser.h>
#include <slimIO/http/response.h>
#include <slimIO/http/request.h>

#include <iostream>

void slimIO::http::Response::version(std::string value) {
	version_string = value;
}
void slimIO::http::Response::version(std::string* value) {
	version_string = std::string(*value);
}
std::string& slimIO::http::Response::version(void) {
	return version_string;
}
void slimIO::http::Response::body(std::string value) {
	body_string = value;
}
void slimIO::http::Response::body(std::string* value) {
	body_string = std::string(*value);
}
std::string& slimIO::http::Response::body(void) {
	return body_string;
}
void slimIO::http::Response::response_code(int value) {
	response_code_int = value;
	switch(response_code_int) {
		case 200: response_code_string_value = "OK"; break;
		case 404: response_code_string_value = "Not Found"; break;
		case 501: response_code_string_value = "Not Implemented"; break;
		case 505: response_code_string_value = "HTTP Version Not Supported"; break;
	}
}
int slimIO::http::Response::response_code(void) {
	return response_code_int;
}
std::string& slimIO::http::Response::response_code_string(void) {
	return response_code_string_value;
}
