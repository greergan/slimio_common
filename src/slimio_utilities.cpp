#include <algorithm>
#include <arpa/inet.h>
#include <cstdlib>
#include <netdb.h>
#include <netinet/in.h>
#include <stdexcept>
#include <string>
#include <slimio/utilities.h>
bool slimio::utilities::get_bool_value_from_string(char* value) {
	if(value) {
		std::string string_value(value);
		std::transform(string_value.begin(), string_value.end(), string_value.begin(), ::tolower);
		if(string_value == "true") {
			return true;
		}
        try {
            return std::stoi(std::string(value));
        }
        catch (std::invalid_argument const& ex) {
            return false;
        }
        catch (std::out_of_range const& ex) {
			return false;
        }
	}
	return false;
}
std::string slimio::utilities::get_ip_address(std::string host) {
	std::string ip_address;
	hostent* host_ent = gethostbyname(host.c_str());
	if(host_ent != NULL) {
		in_addr* address = (in_addr*)host_ent->h_addr;
		ip_address = inet_ntoa(* address);
	}
	return ip_address;
}
int slimio::utilities::get_int_value_from_string(char* value) {
	std::string string_value{value};
	return get_int_value_from_string(string_value);
}
int slimio::utilities::get_int_value_from_string(std::string* value) {
	std::string string_value{value->c_str()};
	return get_int_value_from_string(string_value);
}
int slimio::utilities::get_int_value_from_string(std::string value) {
	if(!value.empty()) {
        try {
            return std::stoi(value);
        }
        catch (std::invalid_argument const& ex) {
            return -1;
        }
        catch (std::out_of_range const& ex) {
			return -1;
        }
	}
	return -1;
}
