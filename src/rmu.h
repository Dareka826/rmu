#ifndef __RMU_H_6kNk4PKktTLZ4lw7uIjC
#define __RMU_H_6kNk4PKktTLZ4lw7uIjC

#include <stdlib.h>

#ifndef _RMU_WARN_NULL_FREE
#define _RMU_WARN_NULL_FREE 1
#endif

// Exit if memory not granted
void * xmalloc(size_t size);
void * xcalloc(size_t size);

// For internal use: Check if ptr is null and warn if so, but don't exit
void  _nfree(void * ptr);

// Same as above, but print user-given name/reason if debugging
#ifndef _RMU_SUPPRESS_DEBUG_INFO
void * xmallocn(size_t size, const char * const name);
void * xcallocn(size_t size, const char * const name);
void    _nfreen(void * ptr,  const char * const name);
#else
#define xmallocn(s,n) xmalloc(s)
#define xcallocn(s,n) xcalloc(s)
#define  _nfreen(p,n) _nfree(p)
#endif

// Clear pointer after free
#define nfree(ptr)        {  _nfree(ptr);       ptr = NULL; }
#define nfreen(ptr, name) { _nfreen(ptr, name); ptr = NULL; }

#endif
