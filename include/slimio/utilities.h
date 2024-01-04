#ifndef __TENDRIL__UTILITIES__H
#define __TENDRIL__UTILITIES__H
#include <string>
namespace slimio::utilities {
	bool get_bool_value_from_string(char* value);
	std::string get_ip_address(std::string host);
	int get_int_value_from_string(char* value);
	int get_int_value_from_string(std::string value);
	int get_int_value_from_string(std::string* value);
}
#endif