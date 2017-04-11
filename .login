#  .login  C shell script. This C shell script should be sourced by
# every  Karma  user.


#   Copyright (C) 1992-2004  Richard Gooch
#
#   This program is free software; you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation; either version 2 of the License, or
#   (at your option) any later version.
#
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with this program; if not, write to the Free Software
#   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
#
#   Richard Gooch may be reached by email at  karma-request@atnf.csiro.au
#   The postal address is:
#     Richard Gooch, c/o ATNF, P. O. Box 76, Epping, N.S.W., 2121, Australia.


# Written by		Richard Gooch	22-SEP-1992

# Last updated by	Richard Gooch	20-AUG-2004

# $Id: .login,v 2.4 2011/05/04 06:33:00 cal103 Exp $


# Define Karma installed base (for ordinary users)
# Try various known Karma base directories
foreach i (/usr/local/karma /local/karma /usr/physics/karma)
    if ("$?KARMABASE" == "0") then
	if (-d $i) setenv KARMABASE $i
    endif
end

if ("$?KARMABASE" == "0") then
    # Still not defined. Use dirty, Linux-specific trick
    if (-d /proc/$$/fd) then
	set file = `\ls -l /proc/$$/fd | fgrep .login | awk '{print $NF}'`
	setenv KARMABASE $file:h
	unset file
    endif
endif

# Find out what kind of platform this is
if ("$?MACHINE_OS" == "0") then
    if (-x /usr/local/bin/platform) then
	set _platform_file = /usr/local/bin/platform
    else
	set _platform_file = ${KARMABASE}/csh_script/uname_to_platform
    endif
    setenv MACHINE_OS `$_platform_file`
    unset _platform_file
endif

###############################################################################
#			No user servicable parts below			      #
###############################################################################

if ("$?OS" == "0") then
    set tmp = `echo "$MACHINE_OS" | sed -e 's/_\([^_]*\)$/ \1/'`
    setenv MACHINE "$tmp[1]"
    setenv OS "$tmp[2]"
    unset tmp
endif

# Figure out OS subversion (if appropriate)
setenv OS_MINOR ""
switch ("$OS")
  case "Linux":
    if (-l /lib/libc.so.6) then
	if (`\ls -l /lib/libc.so.6 | fgrep -c "libc-2.3."` == 1) then
	    setenv OS_MINOR "libc6.3"
	else if (`\ls -l /lib/libc.so.6 | fgrep -c "libc-2.2."` == 1) then
	    setenv OS_MINOR "libc6.2"
	else
	    setenv OS_MINOR "libc6.1"
	endif
    endif
    breaksw
endsw

setenv KARMABINPATH ${KARMABASE}/bin
setenv KARMALIBPATH ${KARMABASE}/lib
setenv KARMAINCLUDEPATH ${KARMABASE}/include

# Set version number environment variable
set _versionfile = $KARMABASE/include/k_version.h
set tmp = `fgrep KARMA_VERSION $_versionfile | tr '"' ' '`
setenv KARMA_VERSION "$tmp[$#tmp]"
if ("$KARMA_VERSION" == "") then
    echo "WARNING: KARMA_VERSION environment variable could not be computed."
endif
unset _versionfile
unset tmp

# Libraries to depend on (for modules)
switch ("$OS")
    case "SunOS":
	setenv KDEPLIB_KARMA $KARMALIBPATH/libkarma.sa.$KARMA_VERSION
	#setenv KDEPLIB_KARMAX11 $KARMALIBPATH/libkarmaX11.sa.$KARMA_VERSION
	#setenv KDEPLIB_KARMAXT $KARMALIBPATH/libkarmaXt.sa.$KARMA_VERSION
	#setenv KDEPLIB_KARMAXVIEW $KARMALIBPATH/libkarmaxview.sa.$KARMA_VERSION
	#setenv KDEPLIB_KARMAGRAPHICS $KARMALIBPATH/libkarmagraphics.sa.$KARMA_VERSION
	setenv KARMASTATICLIBPATH ${KARMABASE}/static-lib
	breaksw
    case "Solaris":
	setenv KARMASTATICLIBPATH ${KARMABASE}/lib
	breaksw
    case "Linux"
	setenv KARMASTATICLIBPATH ${KARMABASE}/lib
	breaksw
    case "IRIX5":
    case "IRIX6":
    case "OSF1":
    case "AIX":
    case "HPUX":
    case "Darwin":
	# Platforms with shared libraries: no dependencies on libraries.
	setenv KARMASTATICLIBPATH ${KARMABASE}/lib
	breaksw
    default:
	# Platforms with static libraries: modules depend on libraries.
	setenv KDEPLIB_KARMA $KARMALIBPATH/libkarma.a
	setenv KDEPLIB_KARMAX11 $KARMALIBPATH/libkarmaX11.a
	setenv KDEPLIB_KARMAXT $KARMALIBPATH/libkarmaXt.a
	setenv KDEPLIB_KARMAGRAPHICS $KARMALIBPATH/libkarmagraphics.a
	setenv KDEPLIB_KARMAWIDGETS $KARMALIBPATH/libkarmawidgets.a
	setenv KARMASTATICLIBPATH ${KARMABASE}/lib
	breaksw
endsw

# Operating system specific hacks
switch ("$OS")
  case "Linux":
    if (`fgrep -c __GLIBC__ /usr/include/features.h` > "0") then
      setenv _HAS_POSIX_THREADS TRUE
    endif
    breaksw
  case "SunOS":
  case "Solaris":
  case "IRIX5":
  case "IRIX6":
  case "OSF1":
  case "AIX":
  case "HPUX":
  default:
    breaksw
endsw

if ("$?_k_need_llp" != "0") then
    if ("$?LD_LIBRARY_PATH" == "0") then
	setenv LD_LIBRARY_PATH $KARMALIBPATH
    else
	setenv LD_LIBRARY_PATH "${KARMALIBPATH}:${LD_LIBRARY_PATH}"
    endif
endif

if ("$?VXPATH" != "0") then
    if ("$?KARMAVXMVXBASE" == "0") setenv KARMAVXMVXBASE /phoenix/karmaVXMVX
    setenv KARMAVXMVXBINPATH $KARMAVXMVXBASE/bin
    setenv KARMAVXMVXLIBPATH $KARMAVXMVXBASE/lib
    setenv VXPATH "${KARMAVXMVXBINPATH}:$VXPATH"
endif

set karmabin = (${KARMABASE}/cm_script ${KARMABASE}/csh_script $KARMABASE/site/$MACHINE_OS/bin $KARMABINPATH)
if ("$?_newpath" == "0") then
    # User does not use  _newpath  as a fast way of setting the path
    set path = ($karmabin $path)
else
    # User uses  _newpath  as a fast way of setting the path
    set _newpath = ($karmabin $_newpath)
endif

if ("$?MANPATH" == "0") then
    # Initialise MANPATH
    setenv MANPATH "${KARMABASE}/man"
    if (-r /etc/manpath.config) then
	setenv MANPATH ${MANPATH}:`egrep "^MANDATORY_MANPATH" /etc/manpath.config | awk '{print $2}' | tr "[:space:]" ":"`
    else
	if (-d /usr/share/man) setenv MANPATH "${MANPATH}:/usr/share/man"
	if (-d /usr/man) setenv MANPATH "${MANPATH}:/usr/man"
    endif
else
    setenv MANPATH "${KARMABASE}/man:${MANPATH}"
endif

# Run the site Karma .login file if it exists
if (-r ${KARMABASE}/site/.login) then
    source ${KARMABASE}/site/.login
endif
