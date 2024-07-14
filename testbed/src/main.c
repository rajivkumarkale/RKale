#include <core/logger.h>
#include <core/asserts.h>

int main(void) {
    RFATAL("A test message: %f", 3.14f);
    RERROR("A test message: %f", 3.14f);
    RWARN("A test message: %f", 3.14f);
    RINFO("A test message: %f", 3.14f);
    RDEBUG("A test message: %f", 3.14f);
    RTRACE("A test message: %f", 3.14f);

    RASSERT(1 == 0);

    return 0;
}