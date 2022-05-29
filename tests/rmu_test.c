#include "../src/rmu.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

int main() {
    void * p;

    // xmalloc
    p = xmalloc(10);
    assert(p != NULL);

    memcpy(p, "ovIHMIK1S", 10);
    assert(strncmp(p, "ovIHMIK1S", 10) == 0);

    // nfree
    nfree(p);
    assert(p == NULL);

    // xcalloc
    p = xcalloc(20);
    assert(p != NULL);

    void * pp = xmalloc(20);
    memset(pp, 0, 20);
    assert(memcmp(p, pp, 20) == 0);

    nfree(pp);
    nfree(p);

    return EXIT_SUCCESS;
}
