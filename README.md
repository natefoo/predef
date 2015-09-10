predef
======

Overview of pre-defined compiler macros for standards, compilers, operating
systems, and hardware architectures.

This repository contains includes that can be used to set standardized macros
based on these system variables. If you are only interested in what standards,
compilers, etc. define what macros (e.g. how to detect them on your own), see
[the documentation in the wiki](https://github.com/natefoo/predef/wiki/)

predef was originally created by [Bjorn
Reese](http://sourceforge.net/u/breese/profile/) and maintained in
[SourceForce](http://sourceforge.net/projects/predef/). This copy is maintained
by [Nate Coraor](https://github.com/natefoo/).

License
-------

The original license for this project is a modified version of the MIT license,
and can be found in the
[LICENSE](https://github.com/natefoo/predef/blob/master/LICENSE) file.

src export
----------

This repository is a cvs->git export of the [predef project on
SourceForge](http://sourceforge.net/p/predef/wiki/Home/) as of September 08,
2015. I won't be attempting to synchronize past this point.

The original predef repository was stored in the
[src](http://predef.cvs.sourceforge.net/viewvc/predef/src/) module of the
[predef CVS repository](http://predef.cvs.sourceforge.net/).  I used Eric
Raymond's [cvs-fast-export tool](http://www.catb.org/esr/cvs-fast-export/) to
convert to git.

wiki export
-----------

The [doc module](http://predef.cvs.sourceforge.net/viewvc/predef/doc/) in CVS
unfortunately only contained outdated Emacs Muse source files. Instead, I
created and used [slurpwiki](https://github.com/natefoo/slurpwiki) to grab the
[predef wiki from SourceForge](http://sourceforge.net/p/predef/wiki/Home/) with
revision history and attribution.

predef macros
-------------

These files are work in progress. Please submit a [pull
request](https://github.com/natefoo/predef/pull/new/master) to contribute.

The include directory and subdirectories contains predef wrappers for common
system header files.

The wrappers must be included as normal header files. They define macros for
each function provided by the individual system header file, and include the
associated system header file. For example, instead of including `<stdio.h>`,
you should include `<predef/stdio.h>` which will include `<stdio.h>` and set
various macros.

All wrapper files depends on `<predef/predef.h>` and the associated header
files directory. If single files are copied into the distribution of an
application, then the following header files must be copied as well:

```
  <predef/predef.h>
  <predef/predef/compiler.h>
  <predef/predef/os.h>
  <predef/predef/standard.h>
  <predef/predef/library.h>
```

Example of use
--------------

Using autoconf type:

```c
#include <config.h>
#if defined(HAVE_INTTYPES_H)
#include <inttypes.h> /* strtoimax */
#else
#include <stdlib.h> /* strtol */
#endif

intmax_t my_atoimax(const char *text)
{
#if defined(HAVE_STRTOIMAX)
  return strtoimax(text, 0, 10);
#else
  return strtol(text, 0, 10);
#endif
}
```

Using predef type:

```c
#include <predef/inttypes.h> /* strtoimax */
#if !defined(PREDEF_HEADER_INTTYPES)
#include <stdlib.h> /* strtol */
#endif

intmax_t my_atoimax(const char *text)
{
#if defined(PREDEF_FUNC_STRTOIMAX)
  return strtoimax(text, 0, 10);
#else
  return strtol(text, 0, 10);
#endif
}
```
