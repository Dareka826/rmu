#include "rmu.h"
#include <stdio.h>
#include <stdlib.h>

// Exit if malloc failed
void * xmalloc(size_t size) { /*{{{*/
    void * ptr = malloc(size);

    if(ptr == NULL)
        exit(1);

    return ptr;
} /*}}}*/

// Exit if malloc failed and print a debug message
void * xmallocn(size_t size, const char * const name) { /*{{{*/
    fprintf(stderr, "[I]: Allocating %lu bytes of memory (%s)\n", size, name);
    return xmalloc(size);
} /*}}}*/

// Exit if calloc failed
void * xcalloc(size_t size) { /*{{{*/
    void * ptr = calloc(1, size);

    if(ptr == NULL)
        exit(1);

    return ptr;
} /*}}}*/

// Exit if calloc failed and print a debug message
void * xcallocn(size_t size, const char * const name) { /*{{{*/
    fprintf(stderr, "[I]: Allocating %lu bytes of zeroed memory (%s)\n", size, name);
    return xcalloc(size);
} /*}}}*/

// Protect against freeing NULL and warn
void _nfree(void * ptr) { /*{{{*/
    // If not warning against NULL frees, allow the user to sigsegv
    if(ptr == NULL && _RMU_WARN_NULL_FREE == 1) {
        fprintf(stderr, "[W]: Attempted to free NULL!\n");
        return;
    }

    free(ptr);
} /*}}}*/

// Protect against freeing NUll and warn, print a debug message
void _nfreen(void * ptr, const char * const name) { /*{{{*/
    fprintf(stderr, "[I]: Freeing [%p] (%s)\n", ptr, name);
    _nfree(ptr);
} /*}}}*/
