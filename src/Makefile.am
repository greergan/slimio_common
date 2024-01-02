lib_LTLIBRARIES   = slimio_common.la
slimio_common_la_SOURCES  = slimio_http.cpp \
							slimio_http_parser.cpp
slimio_common_la_CPPFLAGS = -std=c++20
slimio_common_la_LDFLAGS  = -module -shared

nobase_include_HEADERS = \
	slimio/http/headers.h \
	slimio/http/parser.h \
	slimio/http/request.h \
	slimio/http/response.h
