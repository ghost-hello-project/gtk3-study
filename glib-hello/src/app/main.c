#include <glib.h>
#include <stdio.h>

const gchar *get_log_level_string(GLogLevelFlags log_level) {
    switch (log_level & G_LOG_LEVEL_MASK) {
        case G_LOG_LEVEL_ERROR:
            return "ERROR";
        case G_LOG_LEVEL_CRITICAL:
            return "CRITICAL";
        case G_LOG_LEVEL_WARNING:
            return "WARNING";
        case G_LOG_LEVEL_MESSAGE:
            return "MESSAGE";
        case G_LOG_LEVEL_INFO:
            return "INFO";
        case G_LOG_LEVEL_DEBUG:
            return "DEBUG";
        default:
            return "UNKNOWN";
    }
}

void custom_log_handler(const gchar *log_domain, GLogLevelFlags log_level, const gchar *message, gpointer user_data) {
    // 输出日志到标准输出，包含日志级别
    fprintf(stdout, "[%s] - [%s] - %s\n", get_log_level_string(log_level), log_domain, message);
}

int main(int argc, char **argv) {  // NOLINT
    // 设置自定义日志处理器
    g_log_set_default_handler(custom_log_handler, NULL);

    g_log("app", G_LOG_LEVEL_INFO, "Hello glib-2.0.");

    return 0;
}