#include <c/app.h>
#include <c/mem.h>

// From signal.h
extern void _Exit(i32_t code);

err_t ellipse_init(ellipse_init_flags_t flags) {
    
}

void abort(ellipse_exit_code_t code) {
    _Exit(code);
}

void exit(ellipse_exit_code_t code) {
    mem_global_all_resources_free();
    _Exit(code);
}

main_t ellipse_main(app_args_t args);
