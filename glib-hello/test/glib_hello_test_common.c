#include "glib_hello_test_common.h"

#include <glib.h>

void glib_hello_test_common() {
    g_log("test_common", G_LOG_LEVEL_INFO, "test common start");
    g_log("test_common", G_LOG_LEVEL_INFO, "test common end");
}