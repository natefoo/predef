/*************************************************************************
 *
 * $Id: stdint.h,v 1.1 2003/08/03 17:55:44 breese Exp $
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

#ifndef PREDEF_STDINT_H
#define PREDEF_STDINT_H

#ifndef PREDEF_PREDEF_H
# include <predef/predef.h>
#endif

#if defined(PREDEF_STANDARD_C99) || defined(PREDEF_STANDARD_UNIX01)
# define PREDEF_HEADER_STDINT
# include <stdint.h>
#endif

#endif /* PREDEF_STDINT_H */
