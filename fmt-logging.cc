#include "fmt-logging.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define LOG_LEVEL_TYPES 5
#define LOG_BUFSIZ 8192
#define DATETIME_BUFSIZ 100
#define LINE_BUFSIZ 20

const char* LOG_LEVEL_COLOR[LOG_LEVEL_TYPES] = {
  "\x1B[0;36m",
  "\x1B[0;32m",
  "\x1B[0;33m",
  "\x1B[0;31m",
  "\x1B[1;31m" };
const char* LOG_LEVEL_NOTE[LOG_LEVEL_TYPES] = {
  "DEBUG",
  "INFO",
  "WARN",
  "ERROR",
  "FATAL" };


bool fmt_logging::is_log_enabled = false;
int fmt_logging::log_level = FMT_LOG_LEVEL_INFO;

bool fmt_logging::set_log_level(const char* const log_level_name) {
  for (int i = 0; i < LOG_LEVEL_TYPES; i++) {
    if (strcmp(LOG_LEVEL_NOTE[i], log_level_name) == 0) {
      log_level = i;
      return true;
    }
  }
  return false;
}

void fmt_logging::log_internal(int level, const char* file_name,
    const int line_number, const char* format, ...) {
  if (!is_log_enabled || level < log_level) {
    return;
  }
  static char log_buffer[LOG_BUFSIZ];
  static char datetime[DATETIME_BUFSIZ];
  static char line_str[LINE_BUFSIZ];
  static time_t now;
  va_list ap;

  now = time(NULL);
  strftime(datetime, DATETIME_BUFSIZ - 1, "%Y-%m-%d %H:%M:%S", localtime(&now));
  snprintf(line_str, LINE_BUFSIZ - 1, "%d", line_number);

  va_start(ap, format);
  vsnprintf(log_buffer, LOG_BUFSIZ, format, ap);
  va_end(ap);

  fprintf(stderr, "[%s%s\x1B[m][%s][%s:%d]\n%s\n",
      LOG_LEVEL_COLOR[level], LOG_LEVEL_NOTE[level], datetime, file_name, line_number, log_buffer);
}

