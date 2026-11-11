/**
 *  Copyright (C) 2019  Andrew Gaul
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 */
#include <stdarg.h>
#include <stdio.h>
#define _GNU_SOURCE
#include <syslog.h>

#include "global.h"

void mbp_log(int level, const char *fmt, ...)
{
    va_list args;
    if (daemonize) {
        va_start(args, fmt);
        vsyslog(level, fmt, args);  // NOLINT(misc-include-cleaner)
        va_end(args);
    }

    va_start(args, fmt);
    vprintf(fmt, args);
    puts(""); // trailing newline
    va_end(args);
}
