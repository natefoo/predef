/*************************************************************************
 *
 * $Id: dirent.h,v 1.1 2003/08/03 17:55:44 breese Exp $
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

#ifndef PREDEF_DIRENT_H
#define PREDEF_DIRENT_H

#ifndef PREDEF_PREDEF_H
# include <predef/predef.h>
#endif

#if defined(PREDEF_STANDARD_XPG3) || defined(PREDEF_STANDARD_POSIX1990)
# define PREDEF_HEADER_DIRENT
# include <dirent.h>
# define PREDEF_FUNC_CLOSEDIR
# define PREDEF_FUNC_OPENDIR
# define PREDEF_FUNC_READDIR
# define PREDEF_FUNC_REWINDDIR
# if defined(PREDEF_STANDARD_XPG3) || defined(PREDEF_STANDARD_UNIX95)
#  define PREDEF_FUNC_SEEKDIR
#  define PREDEF_FUNC_TELLDIR
# endif
# if defined(PREDEF_STANDARD_UNIX98) \
  || (defined(PREDEF_LIBC_GNU) && (PREDEF_LIBC_GNU >= 20000) \
      && (defined(__USE_POSIX) || defined(__USE_MISC)))
#  define PREDEF_FUNC_READDIR_R
# endif
#endif

#endif /* PREDEF_DIRENT_H */
