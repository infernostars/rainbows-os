#include <stdint.h>
#include <stddef.h>
#include <limine.h>

// The Limine requests can be placed anywhere, but it is important that
// the compiler does not optimise them away, so, usually, they should
// be made volatile or equivalent.

static volatile struct limine_terminal_request terminal_request = {
    .id = LIMINE_TERMINAL_REQUEST,
    .revision = 0
};

static void done(void) {
    for (;;) {
        __asm__("hlt");
    }
}

// The following will be our kernel's entry point.
void _start(void) {
    // Ensure we got a terminal
    if (terminal_request.response == NULL
     || terminal_request.response->terminal_count < 1) {
        done();
    }

    // We should now be able to call the Limine terminal to print out
    // a simple "Hello Wrld" to screen.
    struct limine_terminal *terminal = terminal_request.response->terminals[0];
    terminal_request.response->write(terminal, "\x1b[38;2;255;255;255mWelcome to \x1b[38;2;200;53;0mR\x1b[38;2;107;149;0ma\x1b[38;2;10;243;0mi\x1b[38;2;0;173;81mn\x1b[38;2;0;81;172mb\x1b[38;2;10;1;242mo\x1b[38;2;106;0;149mw\x1b[38;2;201;1;53ms\x1b[38;2;255;255;255m [version 0]\n>", 202);
    done();
}
