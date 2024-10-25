#include <c/assert.h>
#include <c/app.h>
#include <c/io.h>

void verify(bool condition, cstr_t message) {
    if (condition) {
        out(cout, (void *)(message));
        exit(EXIT_FAILURE);
    }
}

#ifdef DEBUG
void assert(bool condition, cstr_t message) {
    verify(condition, message);
}
#else // DEBUG
void assert(bool condition, cstr_t message) {}
#endif
