#include <c/main.h>
#include <c/app.h>

#if defined(ELLIPSE_MAIN_NO_ARGS_SIGNATURE)

main_t main(void) {
    app_args_t args = (app_args_t){
        .num = 0,
        .args = NULL
    };
    return ellipse_main(args);
}

#elif defined(ELLIPSE_WMAIN_ARGS_SIGNATURE)

// TODO: FINISH IT
main_t wmain(i32_t argc, wchar_t* argv[]) {
}

#else // defined(ELLIPSE_MAIN_ARGS_SIGNATURE)

#ifndef ELLIPSE_MAIN_ARGS_SIGNATURE
#   define ELLIPSE_MAIN_ARGS_SIGNATURE
#endif

main_t main(i32_t argc, char_t* argv[]) {
    app_args_t args = (app_args_t){
        .num = argc,
        .args = argv
    };
    return ellipse_main(args);
}

#endif 