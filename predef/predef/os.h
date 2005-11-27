/*************************************************************************
 *
 * $Id: $
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

#ifndef PREDEF_OS_H
#define PREDEF_OS_H

#ifndef PREDEF_COMPILER_H
# include <predef/predef/compiler.h>
#endif

/*************************************************************************
 * Operating System
 */

#if defined(__amigaos__) \
 || defined(AMIGA)
# define PREDEF_OS_AMIGA
#endif

#if defined(_AIX) \
 || defined(__TOS_AIX__) \
 || defined(PREDEF_COMPILER_XLC)
# define PREDEF_OS_AIX
#endif

#if defined(__BEOS__)
# define PREDEF_OS_BEOS
#endif

#if defined(bsdi) \
 || defined(__bsdi__)
# define PREDEF_OS_BSDI
#endif

#if defined(_UNICOS) \
 || defined(_CRAY)
# define PREDEF_OS_CRAY
#endif

#if defined(DGUX) \
 || defined(__DGUX__) \
 || defined(__dgux__)
# define PREDEF_OS_DGUX
#endif

#if defined(__DragonFly__)
# define PREDEF_OS_DRAGONFLY
#endif

#if defined(__FreeBSD__)
# define PREDEF_OS_FREEBSD
#endif

#if defined(hpux) \
 || defined(__hpux) \
 || defined(_HPUX_SOURCE)
# define PREDEF_OS_HPUX
#endif

#if defined(__GNU__)
# define PREDEF_OS_HURD
#endif

#if defined(sgi) \
 || defined(__sgi) \
 || defined(mips) \
 || defined(_SGI_SOURCE)
# define PREDEF_OS_IRIX
#endif

#if defined(linux) \
 || defined(__linux) \
 || defined(__linux__)
# define PREDEF_OS_LINUX
#endif

#if defined(macintosh) \
 || defined(Macintosh) \
 || defined(__MACOS__)
# define PREDEF_OS_MACINTOSH
#endif

#if defined(__MACOSX__) \
 || (defined(__APPLE__) && defined(__MACH__))
# define PREDEF_OS_MACOSX
#endif

#if defined(mpeix) \
 || defined(__mpexl)
# define PREDEF_OS_MPEIX
#endif

#if defined(MSDOS) \
 || defined(__MSDOS__) \
 || defined(_MSDOS) \
 || defined(__DOS__)
# define PREDEF_OS_MSDOS
#endif

#if defined(__NetBSD__)
# define PREDEF_OS_NETBSD
#endif

#if defined(__OpenBSD__)
# define PREDEF_OS_OPENBSD
#endif

#if defined(OS2) \
 || defined(_OS2) \
 || defined(__OS2__) \
 || defined(__TOS_OS2__)
# define PREDEF_OS_OS2
#endif

#if defined(__osf__) \
 || defined(__osf) \
 || defined(PREDEF_COMPILER_DECC)
/* See VMS below */
# define PREDEF_OS_OSF
#endif

#if defined(pyr)
# define PREDEF_OS_PYRAMID
#endif

#if defined(__QNX__) \
 || defined(__QNXNTO__)
# define PREDEF_OS_QNX
#endif

#if defined(M_I386) \
 || defined(M_XENIX) \
 || defined(_SCO_C_DIALECT) \
 || defined(PREDEF_COMPILER_SCO)
# define PREDEF_OS_SCO
#endif

#if defined(_SEQUENT_) \
 || defined(sequent)
# define PREDEF_OS_SEQUENT
#endif

#if defined(sinix)
# define PREDEF_OS_SINIX
#endif

#if defined(sun) \
 || defined(__sun__) \
 || defined(PREDEF_COMPILER_SUNPRO)
# if defined(__SVR4) || defined(__svr4__)
#  define PREDEF_OS_SOLARIS
# else
#  define PREDEF_OS_SUNOS
# endif
#endif

#if defined(__SYMBIAN32__)
# define PREDEF_OS_SYMBIAN
#endif

#if defined(ultrix) \
 || defined(__ultrix) \
 || defined(__ultrix__)
# define PREDEF_OS_ULTRIX
#endif


/*************************************************************************
 * Platforms
 */

#if defined(VMS) \
 || defined(__VMS)
# undef PREDEF_OS_OSF
# define PREDEF_PLATFORM_VMS
# if defined(__VMS_VER)
#  define PREDEF_OS_VMS __VMS_VER
# else
#  define PREDEF_OS_VMS 0
# endif
#endif

#if defined(unix) \
 || defined(__unix) \
 || defined(__unix__)
# define PREDEF_PLATFORM_UNIX
#endif
#if defined(PREDEF_OS_AIX) \
 || defined(PREDEF_OS_OSF) \
 || defined(PREDEF_OS_NETBSD) \
 || defined(PREDEF_OS_QNX)
/*
 * The Unix macros are not always defined on these platforms.
 */
# if !defined(PREDEF_PLATFORM_UNIX)
#  define PREDEF_PLATFORM_UNIX
# endif
#endif
#if defined(PREDEF_COMPILER_CYGWIN)
# define PREDEF_PLATFORM_UNIX
#endif
#if defined(AMIGA) && defined(PREDEF_COMPILER_GCC)
# define PREDEF_PLATFORM_UNIX
#endif

#if defined(WIN32) \
 || defined(_WIN32) \
 || defined(__TOS_WIN__) \
 || defined(PREDEF_COMPILER_VISUALC)
# define PREDEF_PLATFORM_WIN32
# define PREDEF_OS_WINDOWS
#endif

#if defined(PREDEF_OS_FREEBSD) \
 || defined(PREDEF_OS_NETBSD) \
 || defined(PREDEF_OS_OPENBSD) \
 || defined(PREDEF_OS_BSDI) \
 || defined(PREDEF_OS_DRAGONFLY) \
 || defined(_BSD_SOURCE) \
 || defined(_SYSTYPE_BSD)
# define PREDEF_PLATFORM_BSD
#endif

#if defined(__sysv__) \
 || defined(__SVR4) \
 || defined(__svr4__) \
 || defined(_SVR4_SOURCE) \
 || defined(_SYSTYPE_SVR4)
# define PREDEF_PLATFORM_SVR4
#endif

#if defined(UWIN)
# define PREDEF_PLATFORM_UWIN
#endif

#if defined(_WINDU_SOURCE)
# define PREDEF_PLATFORM_WINDU
#endif

#endif
