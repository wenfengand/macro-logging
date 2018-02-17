#ifndef __DEBUG_H__
#define __DEBUG_H__

#include "macro-logging/ports/config.h"
#include <stdio.h>
/** lower two bits indicate debug level
 * - 0 all
 * - 1 warning
 * - 2 serious
 * - 3 severe
 */
#define DBG_LEVEL_ALL     0x00
#define DBG_LEVEL_OFF     DBG_LEVEL_ALL /* compatibility define only */

#define DBG_LEVEL_WARNING 0x01 /* bad checksums, dropped packets, ... */
#define DBG_LEVEL_SERIOUS 0x02 /* memory allocation failures, ... */
#define DBG_LEVEL_SEVERE  0x03

#define DBG_MASK_LEVEL    0x03

/** flag for DEBUGF to enable that debug message */
#define DBG_ON            0x80U
/** flag for DEBUGF to disable that debug message */
#define DBG_OFF           0x00U

/** flag for DEBUGF indicating a tracing message (to follow program flow) */
#define DBG_TRACE         0x40U
/** flag for DEBUGF indicating a state debug message (to follow module states) */
#define DBG_STATE         0x20U
/** flag for DEBUGF indicating newly added code, not thoroughly tested yet */
#define DBG_FRESH         0x10U
/** flag for DEBUGF to halt after printing this debug message */
#define DBG_HALT          0x08U


#ifndef PLATFORM_ASSERT
#define PLATFORM_ASSERT(x) do { debug_printf( \
    "Assertion \"%s\" failed at line %d in %s\n",  \
     x, __LINE__, __FILE__);} while(0)
#endif

#ifndef NOASSERT
#define ASSERT(message, assertion) do { if(!(assertion)) \
  PLATFORM_ASSERT(message); } while(0)
#else  /* NOASSERT */
#define ASSERT(message, assertion) 
#endif /* NOASSERT */

/** if "expression" isn't true, then print "message" and execute "handler" expression */
#ifndef ERROR
#define ERROR(message, expression, handler) do { if (!(expression)) { \
  PLATFORM_ASSERT(message); handler;}} while(0)
#endif /* ERROR */


#define PLATFORM_DIAG(x)   do { debug_printf(x); } while(0)

#ifdef DEBUG
/** print debug message only if debug message type is enabled...
 *  AND is of correct type AND is at least DBG_LEVEL
 */
#define DEBUGF(debug, message) do { \
                               if ( \
                                   ((debug) & DBG_ON) && \
                                   ((debug) & DBG_TYPES_ON) && \
                                   ((short unsigned int)((debug) & DBG_MASK_LEVEL) >= DBG_MIN_LEVEL)) { \
                                 PLATFORM_DIAG(message); \
                                 if ((debug) & DBG_HALT) { \
                                   while(1); \
                                 } \
                               } \
                             } while(0)

#else  /* DEBUG */
#define DEBUGF(debug, message) 
#endif /* DEBUG */

#endif /* __DEBUG_H__ */