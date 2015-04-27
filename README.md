This is a simple format logging library for C++.

### Usage
logging is disabled by default, and you can set
`fmt_logging::is_log_enabled` flag to enable logging.

There are 5 different logging level: `DEBUG`, `INFO`,
`WARN`, `ERROR` and `FATAL`.

use macros `FMT_LOG(log_level, format, parameters)` to log level.

### Logging options

- `fmt_logging::is_log_enabled`: enable logging or not. It's a boolean value.
- `fmt_logging::log_level`: will show all log\_level higher
than or equal to it. It's a int value as the mapping below, also, you can use
`set_log_level` to set it.
  - `DEBUG`: 0
  - `INFO`: 1
  - `WARN`: 2
  - `ERROR`: 3
  - `FATAL`: 4

### Examples
```
FMT_LOG(FMT_LOG_LEVEL_INFO, "The process exit with exit code %d\n", exit_code)
```

