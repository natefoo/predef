/*************************************************************************
 *
 * $Id: standard.h,v 1.1 2005/11/27 14:03:10 breese Exp $
 *
 * Copyright (C) 2005 Bjorn Reese <breese@users.sourceforge.net>
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

#ifndef PREDEF_STANDARD_H
#define PREDEF_STANDARD_H

#ifndef PREDEF_COMPILER_H
# include <predef/predef/compiler.h>
#endif

/*************************************************************************
 * C Standards
 */

#define PREDEF_VERSION_C_1989 198900L
#define PREDEF_VERSION_C_1990 199000L
#define PREDEF_VERSION_C_1994 199409L
#define PREDEF_VERSION_C_1999 199901L

#if defined(__STDC_VERSION__)
# if (__STDC_VERSION__ > 1)
#  define PREDEF_STANDARD_C __STDC_VERSION__
# else
#  if (PREDEF_COMPILER_SUNPRO >= 0x420)
#   define PREDEF_STANDARD_C PREDEF_VERSION_C_1994
#  else
#   define PREDEF_STANDARD_C PREDEF_VERSION_C_1990
#  endif
# endif
#else
# if defined(__STDC__) \
  || defined(_MSC_EXTENSIONS) \
  || defined(PREDEF_COMPILER_BORLAND)
#  define PREDEF_STANDARD_C PREDEF_VERSION_C_1989
# endif
#endif

#if defined(PREDEF_STANDARD_C)
# if (PREDEF_STANDARD_C >= PREDEF_VERSION_C_1989)
#  define PREDEF_STANDARD_C_1989
# endif
# if (PREDEF_STANDARD_C >= PREDEF_VERSION_C_1990)
#  define PREDEF_STANDARD_C_1990
# endif
# if (PREDEF_STANDARD_C >= PREDEF_VERSION_C_1994)
#  define PREDEF_STANDARD_C_1994
# endif
# if (PREDEF_STANDARD_C >= PREDEF_VERSION_C_1999)
#  define PREDEF_STANDARD_C_1999
# endif
#endif

/*************************************************************************
 * C++ Standards
 */

#define PREDEF_VERSION_CXX_1998 199711L

#if defined(__cplusplus)
# if (__cplusplus == 1)
#  define PREDEF_STANDARD_CXX PREDEF_VERSION_CXX98
# else
#  define PREDEF_STANDARD_CXX __cplusplus
# endif
#endif

#if defined(PREDEF_STANDARD_CXX)
# if (PREDEF_STANDARD_CXX >= PREDEF_VERSION_CXX_1998)
#  define PREDEF_STANDARD_CXX_1998
# endif
#endif

/*************************************************************************
 * Unix Standards
 */

#if defined(PREDEF_PLATFORM_UNIX)
/*
 * Get the version test macros.
 */
# include <unistd.h>
#endif

/* POSIX 1003.1  = ISO/IEC 9945-1:1990 */
#define PREDEF_VERSION_POSIX_1990 199009L
/* POSIX 1003.1b = IEEE 1003.1b-1993 */
#define PREDEF_VERSION_POSIX_1993 199309L
/* ISO/IEC 9945-1:1996 = IEEE 1003.1-1996 */
#define PREDEF_VERSION_POSIX_1996 199506L
#define PREDEF_VERSION_POSIX_2001 200112L

#if defined(_POSIX_VERSION)
# define PREDEF_STANDARD_POSIX _POSIX_VERSION
#endif

#if defined(PREDEF_STANDARD_POSIX)
# if (PREDEF_STANDARD_POSIX >= PREDEF_VERSION_POSIX_1990)
#  define PREDEF_STANDARD_POSIX_1990
# endif
# if (PREDEF_STANDARD_POSIX >= PREDEF_VERSION_POSIX_1993)
#  define PREDEF_STANDARD_POSIX_1993
# endif
# if (PREDEF_STANDARD_POSIX >= PREDEF_VERSION_POSIX_1996)
#  define PREDEF_STANDARD_POSIX_1996
# endif
# if (PREDEF_STANDARD_POSIX >= PREDEF_VERSION_POSIX_2001)
#  define PREDEF_STANDARD_POSIX_2001
# endif
#endif

#if defined(_POSIX2_C_VERSION)
# if (_POSIX2_C_VERSION >= 199209L)
#  define PREDEF_STANDARD_POSIX_1992
# endif
#endif

/* X/Open Portability Guide 3 (XPG3)*/
#define PREDEF_VERSION_XOPEN_1989 300
/* X/Open Portability Guide 4 (XPG4) */
#define PREDEF_VERSION_XOPEN_1992 400
/* X/Open Single Unix Specification (XPG4v2, UNIX95) */
#define PREDEF_VERSION_XOPEN_1995 450
/* X/Open Single Unix Specification version 2 (UNIX98) */
#define PREDEF_VERSION_XOPEN_1998 500
/* Open Group Single Unix Specification version 3 (UNIX03) */
#define PREDEF_VERSION_XOPEN_2003 600


/* Normalize XOPEN versions */
#if defined(_XOPEN_VERSION)
# if (_XOPEN_VERSION == 4) && defined(_XOPEN_UNIX)
#  define PREDEF_STANDARD_XOPEN PREDEF_VERSION_XOPEN_1995
# else
#  if (_XOPEN_VERSION <= 4)
#   define PREDEF_STANDARD_XOPEN (_XOPEN_VERSION * 100)
#  else
#   define PREDEF_STANDARD_XOPEN _XOPEN_VERSION
#  endif
# endif
#else
# if defined(_XOPEN_XPG4)
#  define PREDEF_STANDARD_XOPEN PREDEF_VERSION_XOPEN_1992
# else
#  if defined(_XOPEN_XPG3)
#   define PREDEF_STANDARD_XOPEN PREDEF_VERSION_XOPEN_1989
#  endif
# endif
#endif

#if defined(PREDEF_STANDARD_XOPEN)
# if (PREDEF_STANDARD_XOPEN >= PREDEF_VERSION_XOPEN_1989)
#  define PREDEF_STANDARD_XOPEN_1989
# endif
# if (PREDEF_STANDARD_XOPEN >= PREDEF_VERSION_XOPEN_1992)
#  define PREDEF_STANDARD_XOPEN_1992
# endif
# if (PREDEF_STANDARD_XOPEN >= PREDEF_VERSION_XOPEN_1995)
#  define PREDEF_STANDARD_XOPEN_1995
# endif
# if (PREDEF_STANDARD_XOPEN >= PREDEF_VERSION_XOPEN_1998)
#  define PREDEF_STANDARD_XOPEN_1998
# endif
# if (PREDEF_STANDARD_XOPEN >= PREDEF_VERSION_XOPEN_2003)
#  define PREDEF_STANDARD_XOPEN_2003
# endif
#endif

#endif
