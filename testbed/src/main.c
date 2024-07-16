#include <core/logger.h>
#include <core/asserts.h>

#include <platform/platform.h>

int main(void) {
    RFATAL("A test message: %f", 3.14f);
    RERROR("A test message: %f", 3.14f);
    RWARN("A test message: %f", 3.14f);
    RINFO("A test message: %f", 3.14f);
    RDEBUG("A test message: %f", 3.14f);
    RTRACE("A test message: %f", 3.14f);

    platform_state state;
    if (platform_startup(&state, "RKale Engine Testbed", 100, 100, 1280, 720)) {
        while (TRUE) {
            platform_pump_message(&state);
        }
    }

    platform_shutdown(&state);

    return 0;
}