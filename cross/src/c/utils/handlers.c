#include <c/utils/handlers.h>
#include <c/io.h>

static cstr_t _error_intro_msg = "[ELLIPSE RUN-TIME]:";

static cstr_t _error_msg[] = {
    [ERR_MEM_NULL_POINTER]  = "Error, null pointer to data."
};

void error_handler_set(err_t error, void*(handler)(void), file_point_t point) {
    if (handler == NULL) {
        error_handler_call(error);
    } else {
        
        handler();
    }
}

void error_handler_call(err_t error, file_point_t point) {
    print("%s %s:%u:%u %s", _error_intro_msg, point.line, point.indent, _error_msg[error]);
}
