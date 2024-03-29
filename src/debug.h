#ifndef ACDR_DEBUG_H
#define ACDR_DEBUG_H

#if defined(__AROS__) || defined(__MORPHOS__) || defined(DEBUG_USE_SERIAL)
#ifdef __AROS__
#	include <aros/debug.h>
#elif defined(__MORPHOS__)
#       include <proto/sysdebug.h>
#else
int kprintf(const char* format, ...);
#endif
#	if DEBUG>0
#		define BUG(x) x
#               define dbinit(global) kprintf("Debugger running:" HANDLER_VERSION "GNU C" __VERSION__ "," __TIME__ "\n")
#               define dbuninit(global)
#		define dbprintf(global,fmt,args...) kprintf(fmt ,##args )
#	else
#		define BUG(x)
#	endif
#	define BUG2(x)
#else
#	ifdef NDEBUG
#		define BUG(x) /* nothing */
#	else
#		define BUG(x) x
#	endif
#	if !defined(NDEBUG) || defined(DEBUG_SECTORS)
#		define BUG2(x) x
#	else
#		define BUG2(x) /* nothing */
#	endif
#endif

#ifndef D
#define D BUG
#endif
#ifndef bug
#define bug(fmt,args...) dbprintf(global, fmt ,##args )
#endif

#endif /* ACDR_DEBUG_H */
