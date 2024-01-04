#include <algorithm>
#include <string>
#include <unordered_map>
#include <slimio/http/headers.h>
#include <slimio/http/parser.h>
#include <slimio/http/response.h>
#include <slimio/http/request.h>

#include <iostream>

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
