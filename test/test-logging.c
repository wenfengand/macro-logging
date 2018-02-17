#include <stdio.h>
#include "macro-logging/debug.h"

int main(void)
{
    printf("This is debug demo\n");
    DEBUGF(NORMAL_DEBUG, "normal module debug\n");
    DEBUGF(TRACE_DEBUG, "trace module debug\n");
    DEBUGF(FRESH_DEBUG, "fresh module debug\n");
    return 0;
}