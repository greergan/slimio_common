#ifndef __SLIMIO__HTTP__PARSER__H
#define __SLIMIO__HTTP__PARSER__H
#include <string>
#include <slimio/http/request.h>
namespace slimio::http::parser {
	static void parse_line_1(std::string& line_1_string, slimio::http::Request* request);
	void parse_http_request(const char* request_pointer, slimio::http::Request* request);
	void parse_http_request(std::string& request_string, slimio::http::Request* request);
}
#endif