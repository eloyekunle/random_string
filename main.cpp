#include <phpcpp.h>
#include <string>
#include <algorithm>

Php::Value random_string(Php::Parameters &parameters) {
    bool $alpha = parameters[0];
    bool $numeric = parameters[1];
    int length = parameters[2];
    auto randchar = []() -> char
    {
        const char charset[] =
                "0123456789"
                        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    std::string str(length,0);
    std::generate_n( str.begin(), length, randchar );
    return str;
}

/**
 *  tell the compiler that the get_module is a pure C function
 */
extern "C" {

/**
 *  Function that is called by PHP right after the PHP process
 *  has started, and that returns an address of an internal PHP
 *  strucure with all the details and features of your extension
 *
 *  @return void*   a pointer to an address that is understood by PHP
 */
PHPCPP_EXPORT void *get_module() {
    // static(!) Php::Extension object that should stay in memory
    // for the entire duration of the process (that's why it's static)
    static Php::Extension extension("random_string", "1.0");

    // @todo    add your own functions, classes, namespaces to the extension
    extension.add<random_string>("random_string");

    // return the extension
    return extension;
}
}
