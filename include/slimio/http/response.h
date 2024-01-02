#ifndef __SLIMIO__HTTP__RESPONSE__H
#define __SLIMIO__HTTP__RESPONSE__H
#include <slimio/http/headers.h>
namespace slimio::http {
	struct Response {
		void body(std::string value);
		void body(std::string* value);
		std::string& body(void);
		Headers& headers(void);
		void response_code(int value);
		int response_code(void);
		std::string& response_code_string(void);
		void version(std::string value);
		void version(std::string* value);
		std::string& version(void);
		private:
			std::string body_string;
			std::string version_string;
			int response_code_int;
			std::string response_code_string_value;
			Headers headers_map;
	};
}
#endif