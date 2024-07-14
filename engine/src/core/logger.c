#include "logger.h"
#include "asserts.h"

// TODO: temporary
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

b8 initialize_logging() {
    // TODO: create log file
    return TRUE;
}
void shutdown_logging() {
    // TODO: cleanup logging/write queued entries.
}

void log_output(log_level level, const char* message, ...) {
    const char* level_strings[6] = {
        "[FATAL]: ",
        "[ERROR]: ",
        "[WARN]: ",
        "[INFO]: ",
        "[DEBUG]: ",
        "[TRACE]: "};

    // b8 is_error = level < 2;

    // 32k characters limit
    char out_message[32000];
    memset(out_message, 0, sizeof(out_message));

    // Format original message
    __builtin_va_list arg_ptr;
    va_start(arg_ptr, message);
    vsnprintf(out_message, 32000, message, arg_ptr);
    va_end(arg_ptr);

    char print_message[32000];
    memset(print_message, 0, sizeof(print_message));
    sprintf(print_message, "%s%s\n", level_strings[level], out_message);

    // TODO: platform specific output
    printf("%s", print_message);
}

void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line) {
    log_output(LOG_LEVEL_FATAL, "Assertion Failure: %s, message: '%s', in file: %s, in line: %d", expression, message, file, line);
}