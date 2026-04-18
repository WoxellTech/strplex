#include <stdio.h>
#include "strplex.h"

void strplex_print(const strplex *sp) {
    strplex_element *e = (strplex_element *)sp->data;

    for (size_t i = 0; i < sp->count; i++) {
        printf("length: %u, s: %s\n", strplex_length(e), e->value);
        e = strplex_nextelement(e);
    }
}

int main(void) {
    char v[2000];

    strplex sp = {
        .capacity = 2000,
        .count = 0,
        .endn = 0,
        .data = v
    };

    strplex_addstr(&sp, 0, "hello world", STRPLEX_MAXLEN);
    strplex_addstr(&sp, 0, "how are you", STRPLEX_MAXLEN);
    strplex_addstr(&sp, 0, "im under the water", STRPLEX_MAXLEN);
    strplex_addstr(&sp, 0, "please help me :(", STRPLEX_MAXLEN);

    strplex_print(&sp);
}