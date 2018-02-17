#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <stdio.h>
/** !< macro to switch on debug system*/
#define DEBUG


#define debug_printf(...) printf(__VA_ARGS__)
/** !< macro to switch on the debug types */
/** options: DBG_TRACE, DBG_STATE, DBG_FRESH, DBG_HALT */
#define DBG_TYPES_ON         (DBG_TRACE|DBG_STATE|DBG_HALT)

/** !< macro to switch on debug level */
/** options: DBG_LEVEL_WARNING, DBG_LEVEL_SERIOUS,
 *           DBG_LEVEL_SEVERE , DBG_LEVEL_ALL */
#define DBG_MIN_LEVEL	      DBG_LEVEL_WARNING

/**                             level 1 | level 2 | level 3 */
#define NORMAL_DEBUG            DBG_ON | DBG_STATE | DBG_LEVEL_WARNING
#define TRACE_DEBUG             DBG_ON | DBG_TRACE | DBG_LEVEL_WARNING
#define FRESH_DEBUG             DBG_ON | DBG_FRESH | DBG_LEVEL_WARNING
#endif