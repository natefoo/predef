/*************************************************************************
 *
 * $Id: time.h,v 1.1 2003/08/03 17:55:44 breese Exp $
 *
 * Copyright (C) 2003 Bjorn Reese <breese@users.sourceforge.net>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF
 * MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE. THE AUTHORS AND
 * CONTRIBUTORS ACCEPT NO RESPONSIBILITY IN ANY CONCEIVABLE MANNER.
 *
 ************************************************************************/

#ifndef PREDEF_SYS_TIME_H
#define PREDEF_SYS_TIME_H

#ifndef PREDEF_PREDEF_H
# include <predef/predef.h>
#endif

#if defined(PREDEF_STANDARD_UNIX95) \
  || (defined(PREDEF_LIBC_GNU) && (PREDEF_LIBC_GNU >= 20000))
# define PREDEF_HEADER_SYS_TIME
# include <sys/time.h>

# define PREDEF_FUNC_GETITIMER
# define PREDEF_FUNC_GETTIMEOFDAY
# define PREDEF_FUNC_SELECT
# define PREDEF_FUNC_SETITIMER
# define PREDEF_FUNC_UTIMES
#endif

#endif /* PREDEF_SYS_TIME_H */
