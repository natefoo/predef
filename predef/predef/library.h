/*************************************************************************
 *
 * $Id: library.h,v 1.1 2005/11/27 14:03:10 breese Exp $
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

#ifndef PREDEF_LIBRARY_H
#define PREDEF_LIBRARY_H

#ifndef PREDEF_COMPILER_H
# include <predef/predef/compiler.h>
#endif
#ifndef PREDEF_STANDARD_H
# include <predef/predef/standard.h>
#endif

/*************************************************************************
 * C Libraries
 */

#if defined(PREDEF_COMPILER_MWERKS) && defined(TARGET_API_MAC_CARBON)
# define PREDEF_LIBC_CARBON 0
/*
 * Although the Metrowerks compiler supports C99, the Carbon library
 * does not contain all C99 functions.
 */
# if defined(PREDEF_STANDARD_C_1999)
#  undef PREDEF_STANDARD_C_1999
# endif
#endif

#if defined(__GLIBC__)
# if defined(__GLIBC_MINOR__)
#  define PREDEF_LIBC_GNU ((__GLIBC__ * 10000) + \
                           (__GLIBC_MINOR__ * 100))
# else
#  define PREDEF_LIBC_GNU ((__GLIBC__ * 10000))
# endif
#else
# if defined(__GNU_LIBRARY__)
/*
 * If __GNU_LIBRARY__ is defined, but __GLIBC__ is not we are using the
 * older GNU libc rather than glibc. Libc version 6 was succeeded by glibc
 * version 2. To enable easy chronological comparison, the PREDEF_LIBC_GNU
 * macro defines the libc version number to be 100 times smaller than the
 * version number of glibc. For example, libc version 6.0 becomes 600 and
 * glibc version 2.1 becomes 20100.
 */
#  if defined(__GNU_LIBRARY_MINOR__)
#   define PREDEF_LIBC_GNU ((__GNU_LIBRARY__ * 100) + \
                            (__GNU_LIBRARY_MINOR__))
#  else
#   define PREDEF_LIBC_GNU ((__GNU_LIBRARY__ * 100))
#  endif
# endif
#endif

#if defined(__CRTL_VER)
# define PREDEF_LIBC_VMS __CRTL_VER
# if (__CRTL_VER < 80000000)
/*
 * Although the compiler supports C99 language constructs, the C
 * run-time library does not contain all C99 functions.
 *
 * This was the case for 70300022. Update the 80000000 value when
 * it has been accurately determined what version of the library
 * supports C99.
 */
#  if defined(PREDEF_STANDARD_C_1999)
#   undef PREDEF_STANDARD_C_1999
#  endif
# endif
#endif

/*************************************************************************
 * C++ Libraries
 */

#if defined(__CPPLIB_VER)
# define PREDEF_LIBCXX_DINKUM __CPPLIB_VER
#endif

#if defined(__GLIBCXX__)
# define PREDEF_LIBCXX_GNU __GLIBCXX__
#else
# if defined(__GLIBCPP__)
#  define PREDEF_LIBCXX_GNU __GLIBCPP__
# endif
#endif

#if defined(PREDEF_COMPILER_VISUALC)
# if defined(PREDEF_LIBCXX_DINKUM)
#  define PREDEF_LIBCXX_VISUALC PREDEF_LIBCXX_DINKUM
# else
#  define PREDEF_LIBCXX_VISUALC 0
# endif
#endif

#endif
