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

#ifndef PREDEF_COMPILER_H
#define PREDEF_COMPILER_H

/*
 * Borland C/C++
 *
 * Version: 0xVRR : V = Version, RR = Revision
 * Example: 0x551 = Borland C++ 5.51
 */
#if defined(__BORLANDC__)
# define PREDEF_COMPILER_BORLAND __BORLANDC__
#endif

/*
 * Comeau C++
 *
 * Version: VRR : V = Version, RR = Revision
 * Example: 230 = Comeau C++ 2.30
 */
#if defined(__COMO__)
# if defined(__COMO_VERSION__)
#  define PREDEF_COMPILER_COMEAU __COMO_VERSION__
# else
#  define PREDEF_COMPILER_COMEAU 0
# endif
#endif

/*
 * Cray C/C++
 *
 * Version: V : V = Version
 * Example: ?
 */
#if defined(_CRAYC)
# if defined(_REVISION)
#  define PREDEF_COMPILER_CRAY _REVISION
# else
#  define PREDEF_COMPILER_CRAY 0
# endif
#endif

/*
 * Cygwin
 */
#if defined(__CYGWIN__)
# define PREDEF_COMPILER_CYGWIN 0
#endif

/*
 * Compaq C++
 *
 * Version: VVRRTPPP : VV = Version, RR = Revision, T = Type, PPP = Patch
 * Example: 60090001 = DEC C/C++ 6.0-001
 */
#if defined(__DECC) || defined(__DECCXX)
# if defined(__DECC_VER)
#  define PREDEF_COMPILER_DECC __DECC_VER
# else
#  define PREDEF_COMPILER_DECC 0
# endif
#else
# if defined(VAXC) || defined(__VAXC)
#  define PREDEF_COMPILER_DECC 0
# else
#  if defined(__osf__) && defined(__LANGUAGE_C__) && !defined(__GNUC__)
/* Workaround for old DEC C compilers */
#   define PREDEF_COMPILER_DECC 0
#  endif
# endif
#endif

/*
 * Diab C/C++
 *
 * Version: VRPP : V = Version, R = Revision, PP = Patch
 * Example: 4426 = Diab C/C++ 4.4q
 */
#if defined(__DCC__) && defined(__VERSION_NUMBER__)
# define PREDEF_COMPILER_DIAB __VERSION_NUMBER__
#endif

/*
 * Digital Mars (Symatec C++, Zortech C++)
 *
 * Version: 0xVRP : V = Version, R = Revision, P = Patch
 * Example: 0x720 = Digital Mars 7.2
 */
#if defined(__DMC__)
# define PREDEF_COMPILER_DMC __DMC__
#else
# if defined(__SC__) || defined(__ZTC__)
#  define PREDEF_COMPILER_DMC 0
# endif
#endif

/*
 * GNU C/C++
 *
 * Version: VVRRPP : VV = Version, RR = Revision, PP = Patch
 * Example: 030200 = GCC 3.0.2
 */
#if defined(__GNUC__)
# if defined(__GNUC_PATCHLEVEL__)
#  define PREDEF_COMPILER_GCC ((__GNUC__ * 10000) + \
                               (__GNUC_MINOR__ * 100) + \
                               (__GNUC_PATCHLEVEL__))
# else
#  define PREDEF_COMPILER_GCC ((__GNUC__ * 10000) + \
                               (__GNUC_MINOR__ * 100))
# endif
#endif

/*
 * HP ANSI C / aC++
 *
 * Version: VVRRPP : VV = Version, RR = Revision, PP = Patch
 * Example: 12100 = A.01.21
 *
 * The __HP_aCC was introduced in version A.01.15 (and A.03.13), where
 * it is set to 1. Beginning with version A.01.21 (and A.03.25) __HP_aCC
 * is set as above.
 *
 * The C compiler defines the __HP_cc macro, and the C++ compiler the
 * __HP_aCC macro.
 */
#if defined(__HP_aCC)
# if (__HP_aCC == 1)
#  define PREDEF_COMPILER_HPCC 11500
# else
#  define PREDEF_COMPILER_HPCC __HP_aCC
# endif
#else
# if defined(__HP_cc)
#  define PREDEF_COMPILER_HPCC __HP_cc
# else
#  if (__cplusplus >= 199707L) && defined(__hpux)
#   define PREDEF_COMPILER_HPCC 0
#  endif
# endif
#endif

/*
 * Intel C++
 *
 * Version: VRP : V = Version, R = Revision, P = Patch
 * Example: 500 = ICC 5.0
 */
#if defined(__INTEL_COMPILER)
# define PREDEF_COMPILER_INTEL __INTEL_COMPILER
#else
# if defined(__ICC)
#  define PREDEF_COMPILER_INTEL 0
# endif
#endif

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
#if defined(__KCC)
# if defined(__KCC_VERSION)
#  define PREDEF_COMPILER_KAI __KCC_VERSION
# else
#  define PREDEF_COMPILER_KAI 0
# endif
#endif

/*
 * MinGW32
 */
#if defined(__MINGW32__)
# define PREDEF_COMPILER_MINGW32 0
#endif

/*
 * SGI MIPSpro
 *
 * Version: VRP : V = Version, R = Revision, P = Patch
 * Example: 721 = MIPSpro 7.2.1
 */
#if (defined(sgi) || defined(__sgi)) && defined(_COMPILER_VERSION)
# define PREDEF_COMPILER_MIPSPRO _COMPILER_VERSION
#endif

/*
 * Apple MPW C++
 *
 * Version: 0xVVRR : VV = Version, RR = Revision
 * Example: 0x0500 = MPW C++ 5.0
 */
#if defined(__MRC__)
# define PREDEF_COMPILER_MPW __MRC__
#else
# if defined(MPW_C) || defined(MPW_CPLUS)
#  define PREDEF_COMPILER_MPW 0
# endif
#endif

/*
 * Metrowerks CodeWarrior
 *
 * Version: 0xVRPP : V = Version, R = Revision, PP = Patch
 * Example: 0x2200 = Metrowerks C/C++ 2.2
 *
 * Versions prior to CodeWarrior 7 sets __MWERKS__ to 1.
 */
#if defined(__MWERKS__)
# define PREDEF_COMPILER_MWERKS __MWERKS__
#endif

/*
 * Norcroft C
 *
 * The __ARMCC_VERSION macro is assigned a floating-point number,
 * so it cannot be used by the preprocessor to compare versions.
 */
#if defined(__CC_NORCROFT)
# define PREDEF_COMPILER_NORCROFT 0
#endif

/*
 * SCO OpenServer
 */
#if defined(_SCO_DS)
# define PREDEF_COMPILER_SCO 0
#endif

/*
 * Sun Forte C/C++ (Workshop Pro)
 *
 * Version: 0xVRP : V = Version, R = Revision, P = Patch
 * Example: 0x500 = Workshop Pro 5.0
 */
#if defined(__SUNPRO_C)
# define PREDEF_COMPILER_SUNPRO __SUNPRO_C
#else
# if defined(__SUNPRO_CC)
#  define PREDEF_COMPILER_SUNPRO __SUNPRO_CC
# endif
#endif

/*
 * TenDRA
 */
#if defined(__TenDRA__)
# define PREDEF_COMPILER_TENDRA 0
#endif

/*
 * USL C
 *
 * Version: 0xVRRYYYYMM : V = Version, RR = Revision, YYYY = Year, MM = Month
 * Example: 0x302199801 = USL C 3.2
 */
#if defined(__USLC__)
# if defined(__SCO_VERSION__)
#  define PREDEF_COMPILER_USLC __SCO_VERSION__
# else
#  define PREDEF_COMPILER_USLC 0
# endif
#endif

/*
 * Microsoft Visual C++
 *
 * Version: VVRR : VV = Version, RR = Revision
 * Example: 1200 = Visual C++ 6.0 (compiler 12.0)
 */
#if defined(_MSC_VER)
# define PREDEF_COMPILER_VISUALC _MSC_VER
# define PREDEF_VERSION_VISUALC_6_0 1200
# define PREDEF_VERSION_VISUALC_7_0 1300
#endif

/*
 * Watcom C++
 *
 * Version: VVRR : VV = Version, RR = Revision
 * Example: 1050 = Watcom C++ 10.5
 */
#if defined(__WATCOMC__)
# define PREDEF_COMPILER_WATCOM __WATCOMC__
#endif

/*
 * IBM xlC
 *
 * Version: 0xVVRR : VV = Version, RR = Revision
 * Example: 0x0500 = IBM xlC 5.0
 */
#if defined(__xlC__)
# define PREDEF_COMPILER_XLC __xlC__
#else
# if defined(__IBMC__) || defined(__IBMCPP__)
#  define PREDEF_COMPILER_XLC 0 /* Version is decimal */
# else
#  if defined(_AIX) && !defined(__GNUC__)
/* Workaround for old xlc */
#   define PREDEF_COMPILER_XLC 0
#  endif
# endif
#endif

#endif
