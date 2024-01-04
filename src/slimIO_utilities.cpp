#include <algorithm>
#include <arpa/inet.h>
#include <cstdlib>
#include <netdb.h>
#include <netinet/in.h>
#include <stdexcept>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <slimIO/utilities.h>
int slimIO::utilities::bind_to_host(std::string ip_address, int port) {
	int socket_handle;
	int opt = 1;
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = ntohs(port);
    if((socket_handle = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		throw std::runtime_error("Socket creation error");
    }
	if(setsockopt(socket_handle, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
		throw std::runtime_error("Error setting socket option to " + std::to_string(opt));
    }
    if(inet_pton(AF_INET, ip_address.c_str(), &server_address.sin_addr) <= 0) {
		throw std::runtime_error("IP address error => " + ip_address);
    }
    if(connect(socket_handle, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
		throw std::runtime_error("Unable to connect to server using => " + ip_address + " on port " + std::to_string(port));
    }
	return socket_handle;
}
bool slimIO::utilities::get_bool_value_from_string(char* value) {
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
std::string slimIO::utilities::get_ip_address(std::string host) {
	std::string ip_address;
	hostent* host_ent = gethostbyname(host.c_str());
	if(host_ent != NULL) {
		in_addr* address = (in_addr*)host_ent->h_addr;
		ip_address = inet_ntoa(* address);
	}
	return ip_address;
}
int slimIO::utilities::get_int_value_from_string(char* value) {
	std::string string_value{value};
	return get_int_value_from_string(string_value);
}
int slimIO::utilities::get_int_value_from_string(std::string* value) {
	std::string string_value{value->c_str()};
	return get_int_value_from_string(string_value);
}
int slimIO::utilities::get_int_value_from_string(std::string value) {
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
