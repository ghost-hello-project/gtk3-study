#include <glib.h>

#include "glib_hello_test_common.h"

gint main(gint argc, gchar **argv) {
    // 初始化日志
    g_log_set_default_handler(g_log_default_handler, NULL);
    g_log_set_handler(NULL, G_LOG_LEVEL_MASK | G_LOG_FLAG_FATAL | G_LOG_FLAG_RECURSION, g_log_default_handler, NULL);

    g_test_init(&argc, &argv, NULL);

    g_test_add_func("/test_common", glib_hello_test_common);

    return g_test_run();
}
