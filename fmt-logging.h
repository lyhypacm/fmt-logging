#ifndef __FMT_LOGGING_H__ 
#define __FMT_LOGGING_H__

#define FMT_LOG(level, x...) fmt_logging::log_internal(level, __FILE__, __LINE__, ##x)

#define FMT_LOG_LEVEL_DEBUG 0
#define FMT_LOG_LEVEL_INFO 1
#define FMT_LOG_LEVEL_WARN 2
#define FMT_LOG_LEVEL_ERROR 3
#define FMT_LOG_LEVEL_FATAL 4

namespace fmt_logging {

extern bool is_log_enabled;
extern int log_level;

// sets log_level according to its name.
bool set_log_level(const char* const log_level_name);

void log_internal(int level, const char* file_name,
    const int line_number, const char* format, ...);

}

#endif // __FMT_LOGGING_H__

