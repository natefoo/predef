/*************************************************************************
 *
 * $Id: setjmp.h,v 1.1 2003/08/03 17:55:44 breese Exp $
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

#ifndef PREDEF_SETJMP_H
#define PREDEF_SETJMP_H

#ifndef PREDEF_PREDEF_H
# include <predef/predef.h>
#endif

#define PREDEF_HEADER_SETJMP
#include <setjmp.h>

#if defined(PREDEF_STANDARD_XPG3) || defined(PREDEF_STANDARD_POSIX1990)
# define PREDEF_FUNC_SIGLONGJMP
# define PREDEF_FUNC_SIGSETJMP
#endif
#if defined(PREDEF_STANDARD_UNIX95)
# define PREDEF_FUNC__LONGJMP
# define PREDEF_FUNC__SETJMP
#endif

#endif /* PREDEF_SETJMP_H */
