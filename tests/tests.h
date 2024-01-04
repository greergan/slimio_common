#ifndef __SLIMIO__TESTS__H
#define __SLIMIO__TESTS__H
#include <slimio/http/client.h>
#include <slimio/http/headers.h>
#include <slimio/http/parser.h>
#include <slimio/http/request.h>
#include <slimio/http/response.h>
bool assert_request_parses(std::string request_string);
#endif