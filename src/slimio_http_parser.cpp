#include <algorithm>
#include <sstream>
#include <strstream>
#include <string>
#include <slimio/http/parser.h>
#include <slimio/utilities.h>
static void slimio::http::parser::parse_line_1(std::string& line_1_string, slimio::http::Request* request) {
	std::string temp_string_to_lower = line_1_string;
	std::transform(temp_string_to_lower.begin(), temp_string_to_lower.end(), temp_string_to_lower.begin(), ::tolower);
	if(temp_string_to_lower.find("http://") || temp_string_to_lower.find("https://")) {
		int protocol_token_position = temp_string_to_lower.find("://");
		if(protocol_token_position) {
			request->protocol(temp_string_to_lower.substr(0, protocol_token_position));
			temp_string_to_lower = temp_string_to_lower.substr(protocol_token_position + 3);
			int path_token_position = temp_string_to_lower.find("/");
			if(path_token_position > 1) {
				request->path(temp_string_to_lower.substr(path_token_position));
				request->host(temp_string_to_lower.substr(0, path_token_position - 1));
			}
			else {
				request->path("/");
				request->host(temp_string_to_lower);
			}
			int host_token_position = request->host().find(":");
			if(host_token_position) {
				int port = slimio::utilities::get_int_value_from_string(request->host());
				request->port(port > -1 ? port : 80);
				request->host(request->host().substr(0, host_token_position));
			}
		}
	}
	else {
		std::stringstream line_1_string_stream(line_1_string);
		std::string value;
		int count = 0;
		while(getline(line_1_string_stream, value, ' ')) {
			switch(count) {
				case 0: request->method(value); break;
				case 1: request->path(value); break;;
				case 2: request->version(value); break;
			}
			count++;
		}
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