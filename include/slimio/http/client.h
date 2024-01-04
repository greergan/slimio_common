#ifndef __SLIMIO__HTTP__CLIENT__H
#define __SLIMIO__HTTP__CLIENT__H
#include <string>
#include <slimio/http/request.h>
#include <slimio/http/response.h>
namespace slimio::http::client {
	slimio::http::Response fetch(char* request_pointer);
	slimio::http::Response fetch(std::string& request_string);
	slimio::http::Response fetch(Request& request);
}
#endif