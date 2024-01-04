#include <algorithm>
#include <string>
#include <unordered_map>
#include <slimIO/http/headers.h>
#include <slimIO/http/parser.h>
#include <slimIO/http/response.h>
#include <slimIO/http/request.h>

std::unordered_map<std::string, std::string>& slimIO::http::Headers::get(void) {
	return headers;
}
void slimIO::http::Headers::set(std::string key, std::string value) {
	headers[key] = value;
}
slimIO::http::Headers& slimIO::http::Response::headers(void) {
	return headers_map;
}
