#ifndef __slimIO__HTTP__PARSER__H
#define __slimIO__HTTP__PARSER__H
#include <string>
#include <slimIO/http/request.h>
namespace slimIO::http::parser {
	static void parse_line_1(std::string& line_1_string, slimIO::http::Request* request);
	void parse_http_request(const char* request_pointer, slimIO::http::Request* request);
	void parse_http_request(std::string& request_string, slimIO::http::Request* request);
}
#endif