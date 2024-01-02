#include <sstream>
#include <strstream>
#include <string>
#include <slimio/http/parser.h>
static void slimio::http::parser::parse_line_1(std::string& method_string, slimio::http::Request* request) {
	std::stringstream method_string_stream(method_string);
	std::string value;
	int count = 0;
	while(getline(method_string_stream, value, ' ')) {
		switch(count) {
			case 0: request->method(value); break;
			case 1: request->path(value); break;;
			case 2: request->version(value); break;
		}
		count++;
	}
}
void slimio::http::parser::parse_http_request(const char* request_pointer, slimio::http::Request* request) {
	std::stringstream request_stream;
	request_stream << request_pointer;
	std::string line;
	int line_number = 1;
	while(getline(request_stream, line)) {
		if(line_number == 1) {
			auto endl_pos = line.find("\r");
			line = line.substr(0, endl_pos);
			parse_line_1(line, request);
			line_number++;
		}
		else if(line.find("\r") == 0) {
			break;
		}
		else if(line.find(" ")) {
			auto endl_pos = line.find("\r");
			line = line.substr(0, endl_pos);
			int token_position = line.find(" ");
			std::string key = line.substr(0, token_position - 1);
			std::string value = line.substr(token_position + 1);
			request->headers().set(key, value);
		}
    }
}
void slimio::http::parser::parse_http_request(std::string& request_string, slimio::http::Request* request) {
	parse_http_request(request_string.c_str(), request);
}