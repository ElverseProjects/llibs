#define USE_LINGUA
#define USE_ELIX
#include <llibs.h>

main_t ellipse_main(app_args_t args) {
    ellipse_init(ELLIPSE_INIT_EVERYTHING);
    xstr_t string = xstr_create(NULL, XSTR_ENCODE_UTF8, true);

    memory_t my_data = allocate(1024, sizeof(i64_t));
    

    xstr_delete(&string);
    return EXIT_SUCCESS;
}