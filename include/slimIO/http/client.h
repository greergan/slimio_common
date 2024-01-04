#ifndef __slimIO__HTTP__CLIENT__H
#define __slimIO__HTTP__CLIENT__H
#include <string>
#include <slimIO/http/request.h>
#include <slimIO/http/response.h>
namespace slimIO::http::client {
	slimIO::http::Response fetch(char* request_pointer);
	slimIO::http::Response fetch(std::string& request_string);
	slimIO::http::Response fetch(Request& request);
}
#endif