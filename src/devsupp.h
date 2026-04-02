/* devsupp.h: */
#ifndef DEVSUPP_H
#define DEVSUPP_H

#include "debug.h"

#if !defined(NDEBUG) || defined(DEBUG_SECTORS)
#if !(defined(__AROS__) || defined(__MORPHOS__) || defined(DEBUG_USE_SERIAL))
void dbinit (struct CDVDBase *global);
void dbuninit (struct CDVDBase *global);
void dbprintf (struct CDVDBase *global, char *, ...);
#endif
#endif

char *typetostr (int ty);
int Get_Startup (struct CDVDBase *global, struct FileSysStartupMsg *);
int Handle_Control_Packet (struct CDVDBase *global, ULONG p_type, IPTR p_par1, IPTR p_par2);

#define DEVICE_VERSION  1
#define DEVICE_REVISION 10

#define STR(s) #s      // Turn s into a string literal without macro expansion
#define XSTR(s) STR(s) // Turn s into a string literal after macro expansion
#define DEVICE_ID_STRING "\0$VER: CDVDFS " XSTR(DEVICE_VERSION) "." \
        XSTR(DEVICE_REVISION) " (" AMIGA_DATE ")\r\n"
        /* format: "$VER: name version.revision (dd.mm.yyyy)" */

#define HANDLER_VERSION "cdrom-handler " XSTR(DEVICE_VERSION) "." \
        XSTR(DEVICE_REVISION) " (" AMIGA_DATE ")\r\n"
        /* format: "name version.revision (dd.mm.yyyy)" */

#endif /* DEVSUPP_H */
