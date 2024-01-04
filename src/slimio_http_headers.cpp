#include <algorithm>
#include <string>
#include <unordered_map>
#include <slimio/http/headers.h>
#include <slimio/http/parser.h>
#include <slimio/http/response.h>
#include <slimio/http/request.h>

std::unordered_map<std::string, std::string>& slimio::http::Headers::get(void) {
	return headers;
}
void slimio::http::Headers::set(std::string key, std::string value) {
	headers[key] = value;
}
slimio::http::Headers& slimio::http::Response::headers(void) {
	return headers_map;
}
