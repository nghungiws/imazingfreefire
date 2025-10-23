#ifndef TROLLFOOL_H
#define TROLLFOOL_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// TrollFool library version
#define TROLLFOOL_VERSION "1.0.0"

// Function declarations
int trollfool_init(void);
void trollfool_cleanup(void);
int trollfool_do_something(const char* input);
int trollfool_get_version(char* version, size_t max_len);
void trollfool_print_info(void);

#ifdef __cplusplus
}
#endif

#endif // TROLLFOOL_H