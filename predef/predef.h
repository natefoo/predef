/*************************************************************************
 *
 * $Id: predef.h,v 1.1 2003/08/03 17:55:44 breese Exp $
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

#ifndef PREDEF_PREDEF_H
#define PREDEF_PREDEF_H

/*
 * References:
 *   http://predef.sourceforge.net/
 *   http://www.UNIX-systems.org/v3-apis.html
 *   http://petef.port5.com/c/portability.txt
 */

/*************************************************************************
 * Compilers
 */

/*
 * Borland C/C++
 *
 * Version: 0xVRR : V = Version, RR = Revision
 * Example: 0x551 = Borland C++ 5.51
 */
#if defined(__BORLANDC__)
# define PREDEF_COMPILER_BORLAND __BORLANDC__

/*
 * Comeau C++
 *
 * Version: VRR : V = Version, RR = Revision
 * Example: 230 = Comeau C++ 2.30
 */
#elif defined(__COMO__)
# if defined(__COMO_VERSION__)
#  define PREDEF_COMPILER_COMEAU __COMO_VERSION__
# else
#  define PREDEF_COMPILER_COMEAU 0
# endif

/*
 * Cray C/C++
 *
 * Version: V : V = Version
 * Example: ?
 */
#elif defined(_CRAYC)
# if defined(_REVISION)
#  define PREDEF_COMPILER_CRAY _REVISION
# else
#  define PREDEF_COMPILER_CRAY 0
# endif

/*
 * Cygwin
 */
#elif defined(__CYGWIN__)
# define PREDEF_COMPILER_CYGWIN 0

/*
 * Compaq C++
 *
 * Version: VVRRTPPP : VV = Version, RR = Revision, T = Type, PPP = Patch
 * Example: 60090001 = DEC C/C++ 6.0-001
 */
#elif defined(__DECC) || defined(__DECCXX)
# if defined(__DECC_VER)
#  define PREDEF_COMPILER_DECC __DECC_VER
# else
#  define PREDEF_COMPILER_DECC 0
# endif
#elif defined(VAXC) || defined(__VAXC)
# define PREDEF_COMPILER_DECC 0
#elif defined(__osf__) && defined(__LANGUAGE_C__) && !defined(__GNUC__)
/* Workaround for old DEC C compilers */
# define PREDEF_COMPILER_DECC 0

/*
 * Diab C/C++
 *
 * Version: VRPP : V = Version, R = Revision, PP = Patch
 * Example: 4426 = Diab C/C++ 4.4q
 */
#elif defined(__DCC__) && defined(__VERSION_NUMBER__)
# define PREDEF_COMPILER_DIAB __VERSION_NUMBER__

/*
 * Digital Mars (Symatec C++, Zortech C++)
 *
 * Version: 0xVRP : V = Version, R = Revision, P = Patch
 * Example: 0x720 = Digital Mars 7.2
 */
#elif defined(__DMC__)
# define PREDEF_COMPILER_DMC __DMC__
#elif defined(__SC__) || defined(__ZTC__)
# define PREDEF_COMPILER_DMC 0

/*
 * GNU C/C++
 *
 * Version: VVRRPP : VV = Version, RR = Revision, PP = Patch
 * Example: 030200 = GCC 3.0.2
 */
#elif defined(__GNUC__)
# if defined(__GNU_PATCHLEVEL__)
#  define PREDEF_COMPILER_GCC ((__GNUC__ * 10000) + \
                               (__GNUC_MINOR__ * 100) + \
                               (__GNUC_PATCHLEVEL__))
# else
#  define PREDEF_COMPILER_GCC ((__GNUC__ * 10000) + \
                               (__GNUC_MINOR__ * 100))
# endif

/*
 * HP ANSI C / aC++
 *
 * Version: VVRRPP : VV = Version, RR = Revision, PP = Patch
 * Example: 012100 = A.01.21
 *
 * The __HP_aCC was introduced in version A.01.15 (and A.03.13), where
 * it is set to 1. Beginning with version A.01.21 (and A.03.25) __HP_aCC
 * is set as above.
 *
 * The C compiler defines the __HP_cc macro, and the C++ compiler the
 * __HP_aCC macro.
 */
#elif defined(__HP_aCC)
# if (__HP_aCC == 1)
#  define PREDEF_COMPILER_HPCC 011500
# else
#  define PREDEF_COMPILER_HPCC __HP_aCC
# endif
#elif defined(__HP_cc)
# define PREDEF_COMPILER_HPCC __HP_cc
#elif (defined(__cplusplus) && (__cplusplus >= 199707L) && defined(__hpux))
# define PREDEF_COMPILER_HPCC 0

/*
 * Intel C++
 *
 * Version: VRP : V = Version, R = Revision, P = Patch
 * Example: 500 = ICC 5.0
 */
#elif defined(__INTEL_COMPILER)
# define PREDEF_COMPILER_INTEL __INTEL_COMPILER
#elif defined(__ICC)
# define PREDEF_COMPILER_INTEL 0

/*
 * KAI C++
 *
 * Version: 0xVRPP : V = Version, R = Revision, PP = Patch
 * Example: 0x4004 = KAI C++ 4.0d
 *
 * Please note that Intel has discontinued development of the KAI C++
 * compiler in spring 2002:
 *
 *   http://developer.intel.com/software/products/kcc/announcement.htm
 */
#elif defined(__KCC)
# define PREDEF_COMPILER_KAI __KCC_VERSION

/*
 * MinGW32
 */
#elif defined(__MINGW32__)
# define PREDEF_COMPILER_MINGW32 0

/*
 * SGI MIPSpro
 *
 * Version: VRP : V = Version, R = Revision, P = Patch
 * Example: 721 = MIPSpro 7.2.1
 */
#elif (defined(sgi) || defined(__sgi)) && defined(__COMPILER_VERSION)
# define PREDEF_COMPILER_MIPSPRO __COMPILER_VERSION

/*
 * Apple MPW C++
 *
 * Version: 0xVVRR : VV = Version, RR = Revision
 * Example: 0x0500 = MPW C++ 5.0
 */
#elif defined(__MRC__) || defined(MPW_C) || defined(MPW_CPLUS)
# define PREDEF_COMPILER_MPW __MRC__

/*
 * Metrowerks CodeWarrior
 *
 * Version: 0xVRPP : V = Version, R = Revision, PP = Patch
 * Example: 0x2200 = Metrowerks C/C++ 2.2
 *
 * Versions prior to CodeWarrior 7 sets __MWERKS__ to 1.
 */
#elif defined(__MWERKS__)
# define PREDEF_COMPILER_MWERKS __MWERKS__

/*
 * Norcroft C
 *
 * The __ARMCC_VERSION macro is assigned a floating-point number,
 * so it cannot be used by the preprocessor to compare versions.
 */
#elif defined(__CC_NORCROFT)
# define PREDEF_COMPILER_NORCROFT 0

/*
 * SCO OpenServer
 */
#elif defined(_SCO_DS)
# define PREDEF_COMPILER_SCO 0

/*
 * Sun Forte C/C++ (Workshop Pro)
 *
 * Version: 0xVRP : V = Version, R = Revision, P = Patch
 * Example: 0x500 = Workshop Pro 5.0
 */
#elif defined(__SUNPRO_C)
# define PREDEF_COMPILER_SUNPRO __SUNPRO_C
#elif defined(__SUNPRO_CC_)
# define PREDEF_COMPILER_SUNPRO __SUNPRO_CC

/*
 * USL C
 *
 * Version: 0xVRRYYYYMM : V = Version, RR = Revision, YYYY = Year, MM = Month
 * Example: 0x302199801 = USL C 3.2
 */
#elif defined(__USLC__)
# if defined(__SCO_VERSION__)
#  define PREDEF_COMPILER_USLC __SCO_VERSION__
# else
#  define PREDEF_COMPILER_USLC 0
# endif

/*
 * Microsoft Visual C++
 *
 * Version: VVRR : VV = Version, RR = Revision
 * Example: 1200 = Visual C++ 6.0 (compiler 12.0)
 */
#elif defined(_MSC_VER)
# define PREDEF_COMPILER_VISUALC __MSC_VER

/*
 * Watcom C++
 *
 * Version: VVRR : VV = Version, RR = Revision
 * Example: 1050 = Watcom C++ 10.5
 */
#elif defined(__WATCOMC__)
# define PREDEF_COMPILER_WATCOM __WATCOMC__

/*
 * IBM xlC
 *
 * Version: 0xVVRR : VV = Version, RR = Revision
 * Example: 0x0500 = IBM xlC 5.0
 */
#elif defined(__xlC__)
# define PREDEF_COMPILER_XLC __xlC__
#elif defined(__IBMC__) || defined(__IBMCPP__)
# define PREDEF_COMPILER_XLC 0
#elif defined(_AIX) && !defined(__GNUC__)
/* Workaround for old xlc */
# define PREDEF_COMPILER_XLC 0

#endif

/*************************************************************************
 * Operating Systems
 */

#if defined(__amigaos__) || defined(AMIGA)
# define PREDEF_OS_AMIGA

#elif defined(_AIX) || defined(__TOS_AIX__) || defined(PREDEF_COMPILER_XLC)
# define PREDEF_OS_AIX

#elif defined(__BEOS__)
# define PREDEF_OS_BEOS

#elif defined(bsdi) || defined(__bsdi__)
# define PREDEF_OS_BSDI

#elif defined(_UNICOS) || defined(_CRAY)
# define PREDEF_OS_CRAY

#elif defined(DGUX) || defined(__DGUX__) || defined(__dgux__)
# define PREDEF_OS_DGUX

#elif defined(__FreeBSD__)
# define PREDEF_OS_FREEBSD

#elif defined(hpux) || defined(__hpux) || defined(_HPUX_SOURCE)
# define PREDEF_OS_HPUX

#elif defined(__GNU__)
# define PREDEF_OS_HURD

#elif defined(sgi) || defined(mips) || defined(_SGI_SOURCE)
# define PREDEF_OS_IRIX

#elif defined(linux) || defined(__linux) || defined(__linux__)
# define PREDEF_OS_LINUX

#elif defined(macintosh) || defined(Macintosh) || defined(__MACOS__)
# define PREDEF_OS_MACINTOSH

#elif defined(__MACOSX__) || (defined(__APPLE__) && defined(__MACH__))
# define PREDEF_OS_MACOSX

#elif defined(mpeix) || defined(__mpexl)
# define PREDEF_OS_MPEIX

#elif defined(MSDOS) || defined(__MSDOS__) || defined(_MSDOS) \
   || defined(__DOS__)
# define PREDEF_OS_MSDOS

#elif defined(__NetBSD__)
# define PREDEF_OS_NETBSD

#elif defined(__OpenBSD__)
# define PREDEF_OS_OPENBSD

#elif defined(OS2) || defined(_OS2) || defined(__OS2__) \
   || defined(__TOS_OS2__)
# define PREDEF_OS_OS2

#elif defined(__osf__) || defined(__osf) || defined(PREDEF_COMPILER_DECC)
# define PREDEF_OS_OSF

#elif defined(pyr)
# define PREDEF_OS_PYRAMID

#elif defined(__QNX__) || defined(__QNXNTO__)
# define PREDEF_OS_QNX

#elif defined(M_I386) || defined(M_XENIX) \
   || defined(_SCO_DS) || defined(_SCO_C_DIALECT)
# define PREDEF_OS_SCO

#elif defined(_SEQUENT_) || defined(sequent)
# define PREDEF_OS_SEQUENT

#elif defined(sinix)
# define PREDEF_OS_SINIX

#elif defined(sun) || defined(__sun__) || defined(PREDEF_COMPILER_SUNPRO)
# if defined(__SVR4) || defined(__svr4__)
#  define PREDEF_OS_SOLARIS
# else
#  define PREDEF_OS_SUNOS
# endif

#elif defined(ultrix) || defined(__ultrix) || defined(__ultrix__)
# define PREDEF_OS_ULTRIX

#endif

/*************************************************************************
 * Platforms
 */

#if defined(VMS) || defined(__VMS)
/*
 * VMS is placed first to avoid identifying the platform as Unix based on
 * the DECC compiler idenfitication done above.
 */
# undef PREDEF_OS_OSF
# define PREDEF_PLATFORM_VMS
# if defined(__VMS_VER)
#  define PREDEF_OS_VMS __VMS_VER
# else
#  define PREDEF_OS_VMS 0
# endif

#elif defined(unix) || defined(__unix) || defined(__unix__)
# define PREDEF_PLATFORM_UNIX
#elif defined(PREDEF_OS_AIX) || defined(PREDEF_OS_OSF) \
   || defined(PREDEF_OS_NETBSD) || defined(PREDEF_OS_QNX)
/*
 * The Unix macros are not always defined on these platforms.
 */
# define PREDEF_PLATFORM_UNIX
#elif defined(PREDEF_COMPILER_CYGWIN)
# define PREDEF_PLATFORM_UNIX
#elif defined(AMIGA) && defined(PREDEF_COMPILER_GCC)
# define PREDEF_PLATFORM_UNIX
#endif

#if defined(PREDEF_COMPILER_VISUALC) || defined(WIN32) || defined(_WIN32) \
 || defined(__TOS_WIN__)
# define PREDEF_PLATFORM_WIN32
# define PREDEF_OS_WINDOWS
#endif

#if defined(PREDEF_OS_FREEBSD) || defined(PREDEF_OS_NETBSD) \
 || defined(PREDEF_OS_OPENBSD) || defined(PREDEF_OS_BSDI) \
 || defined(_BSD_SOURCE) || defined(_SYSTYPE_BSD)
# define PREDEF_PLATFORM_BSD
#endif

#if defined(__sysv__) || defined(__SVR4) || defined(__svr4__) \
 || defined(_SVR4_SOURCE) || defined(_SYSTYPE_SVR4)
# define PREDEF_PLATFORM_SVR4
#endif

#if defined(UWIN)
# define PREDEF_PLATFORM_UWIN
#endif

#if defined(_WINDU_SOURCE)
# define PREDEF_PLATFORM_WINDU
#endif

/*************************************************************************
 * C Standards
 */

#if defined(__STDC__) || defined(_MSC_EXTENSIONS) || defined(PREDEF_COMPILER_BORLAND)
# define PREDEF_STANDARD_C89
# if defined(__STDC_VERSION__)
#  define PREDEF_STANDARD_C90
#  if (__STDC_VERSION__ >= 199409L)
#   define PREDEF_STANDARD_C94
#  endif
#  if (__STDC_VERSION__ >= 199901L)
#   define PREDEF_STANDARD_C99
#  endif
# elif defined(PREDEF_COMPILER_SUNPRO)
#  if (PREDEF_COMPILER_SUNPRO >= 0x420)
#    define PREDEF_STANDARD_C94
#  endif
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

/*
 * PREDEF_STANDARD_POSIX1990 : POSIX 1003.1  = ISO/IEC 9945-1:1990
 * PREDEF_STANDARD_POSIX1992 : POSIX 1003.2  = ISO/IEC 9945-2:1993
 * PREDEF_STANDARD_POSIX1993 : POSIX 1003.1b = IEEE 1003.1b-1993
 * PREDEF_STANDARD_POSIX1995 : POSIX 1003.1c = IEEE 1003.1c-1995
 * PREDEF_STANDARD_POSIX1996 : ISO/IEC 9945-1:1996 = IEEE 1003.1-1996
 * PREDEF_STANDARD_POSIX2001 : 
 */
#if defined(__POSIX_SOURCE)
# define PREDEF_STANDARD_POSIX1990
#elif defined(__POSIX_C_SOURCE)
# if (__POSIX_C_SOURCE >= 1)
#  define PREDEF_STANDARD_POSIX1990
# endif
# if (__POSIX_C_SOURCE >= 2)
#  define PREDEF_STANDARD_POSIX1992
# endif
# if (__POSIX_C_SOURCE >= 199309L)
#  define PREDEF_STANDARD_POSIX1993
# endif
# if (__POSIX_C_SOURCE >= 199506L)
#  define PREDEF_STANDARD_POSIX1995
# endif
#endif
#if defined(POSIX_VERSION)
# if  (__POSIX_C_SOURCE >= 200112L)
#  define PREDEF_STANDARD_POSIX2001
# endif
#endif

#if defined(_XOPEN_VERSION)
# if (_XOPEN_VERSION >= 3)
#  define PREDEF_STANDARD_XPG3
# endif
# if (_XOPEN_VERSION >= 4)
#  define PREDEF_STANDARD_XPG4
# endif
# if (_XOPEN_VERSION > 4) \
  || ((_XOPEN_VERSION == 4) && defined(_XOPEN_SOURCE_EXTENDED))
#  define PREDEF_STANDARD_UNIX95
# endif
# if (_XOPEN_VERSION >= 500)
#  define PREDEF_STANDARD_UNIX98
# endif
# if (_XOPEN_VERSION >= 600)
#  define PREDEF_STANDARD_UNIX01
# endif
#endif

/*************************************************************************
 * Libraries
 */

#if defined(__GLIBC__)
# if defined(__GLIBC_MINOR__)
#  define PREDEF_LIBC_GNU ((__GLIBC__ * 10000) + \
                           (__GLIBC_MINOR__ * 100))
# else
#  define PREDEF_LIBC_GNU ((__GLIBC__ * 10000))
# endif
#elif defined(__GNU_LIBRARY__)
/*
 * If __GNU_LIBRARY__ is defined, but __GLIBC__ is not we are using the
 * older GNU libc rather than glibc. Libc version 6 was succeeded by glibc
 * version 2. To enable easy chronological comparison, the PREDEF_LIBC_GNU
 * macro defines the libc version number to be 100 times smaller than the
 * version number of glibc. For example, libc version 6.0 becomes 600 and
 * glibc version 2.1 becomes 20100.
 */
# if defined(__GNU_LIBRARY_MINOR__)
#  define PREDEF_LIBC_GNU ((__GNU_LIBRARY__ * 100) + \
                           (__GNU_LIBRARY_MINOR__))
# else
#  define PREDEF_LIBC_GNU ((__GNU_LIBRARY__ * 100))
# endif
#endif

#if defined(PREDEF_COMPILER_VISUALC)
# define PREDEF_LIBC_VISUALC 0
#endif

#if defined(__CTRL_VER)
# define PREDEF_LIBC_VMS __CTRL_VER
#endif

#endif
