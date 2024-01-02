#ifndef __SLIMIO__HTTP__REQUEST__H
#define __SLIMIO__HTTP__REQUEST__H
#include <slimio/http/headers.h>
namespace slimio::http {
	struct Request {
		Request(void);
		Request(char* request_pointer);
		Request(std::string& request_string);
		slimio::http::Headers& headers(void);
		void path(std::string value);
		void path(std::string* value);
		std::string& path(void);
		void method(std::string value);
		void method(std::string* value);
		std::string& method(void);
		void version(std::string value);
		void version(std::string* value);
		std::string& version(void);
		private:
			std::string method_string;
			std::string path_string;
			std::string version_string;
			std::string host_string;
			std::string protocol_string;
			int port;
			Headers headers_map;
	};
};
#endif