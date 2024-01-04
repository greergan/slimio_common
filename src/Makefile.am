lib_LTLIBRARIES   = libslimio_common.la
libslimio_common_la_SOURCES = slimio_http_client.cpp \
							slimio_http_headers.cpp \
							slimio_http_parser.cpp \
							slimio_http_request.cpp \
							slimio_http_response.cpp \
							slimio_utilities.cpp
libslimio_common_la_CPPFLAGS = -std=c++20
libslimio_common_la_LDFLAGS  = -shared

nobase_include_HEADERS = \
	slimio/http/client.h \
	slimio/http/headers.h \
	slimio/http/parser.h \
	slimio/http/request.h \
	slimio/http/response.h
