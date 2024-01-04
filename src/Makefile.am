lib_LTLIBRARIES   = libslimIO_common.la
libslimIO_common_la_SOURCES = slimIO_http_client.cpp \
							slimIO_http_headers.cpp \
							slimIO_http_parser.cpp \
							slimIO_http_request.cpp \
							slimIO_http_response.cpp \
							slimIO_utilities.cpp
libslimIO_common_la_CPPFLAGS = -std=c++20
libslimIO_common_la_LDFLAGS  = -shared

nobase_include_HEADERS = \
	slimIO/http/client.h \
	slimIO/http/headers.h \
	slimIO/http/parser.h \
	slimIO/http/request.h \
	slimIO/http/response.h
