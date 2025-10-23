#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trollfool.h"

// TrollFool library implementation
static int trollfool_initialized = 0;

int trollfool_init(void) {
    if (trollfool_initialized) {
        return 1; // Already initialized
    }
    
    printf("TrollFool library initialized!\n");
    trollfool_initialized = 1;
    return 0;
}

void trollfool_cleanup(void) {
    if (trollfool_initialized) {
        printf("TrollFool library cleaned up!\n");
        trollfool_initialized = 0;
    }
}

int trollfool_do_something(const char* input) {
    if (!trollfool_initialized) {
        printf("TrollFool not initialized!\n");
        return -1;
    }
    
    if (input == NULL) {
        printf("TrollFool: Invalid input!\n");
        return -1;
    }
    
    printf("TrollFool processing: %s\n", input);
    return 0;
}

int trollfool_get_version(char* version, size_t max_len) {
    if (version == NULL || max_len == 0) {
        return -1;
    }
    
    const char* ver = "1.0.0";
    size_t ver_len = strlen(ver);
    
    if (ver_len >= max_len) {
        return -1;
    }
    
    strncpy(version, ver, max_len - 1);
    version[max_len - 1] = '\0';
    
    return 0;
}

void trollfool_print_info(void) {
    printf("TrollFool Dynamic Library v1.0.0\n");
    printf("A simple C library for demonstration purposes\n");
}