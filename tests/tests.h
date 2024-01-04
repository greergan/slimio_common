#ifndef __slimIO__TESTS__H
#define __slimIO__TESTS__H
#include <slimIO/http/client.h>
#include <slimIO/http/headers.h>
#include <slimIO/http/parser.h>
#include <slimIO/http/request.h>
#include <slimIO/http/response.h>
bool assert_client_fetch(std::string request_string);
bool assert_request_parses(std::string request_string);
bool assert_utilities_get_ip_address(void);
#endif