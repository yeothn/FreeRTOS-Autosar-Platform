#ifndef STD_TYPES_H
#define STD_TYPES_H

/* ===============================================
 * AUTOSAR Types
 * - Define Autosar Standard types
 * =============================================== */

#include <stdint.h>

/* Standard Data types */
typedef uint8_t 	uint8;

typedef uint16_t 	uint16;
typedef uint32_t	uint32;
typedef uint64_t	uint64;

typedef int8_t 		sint8;
typedef int16_t 	sint16;
typedef int32_t 	sint32;
typedef int64_t 	sint64;

typedef uint8_t		boolean;

typedef float		float32;
typedef double		float64;

/* Standard Return Type */
typedef uint8_t Std_ReturnType;

/* Standard Return Values */
#define E_OK 		 ((Std_ReturnType)0x00)
#define E_NOT_OK	 ((Std_ReturnType)0x01)

/* CPU Byte order */
#define CPU_TYPE_8        8
#define CPU_TYPE_16       16
#define CPU_TYPE_32       32
#define MSB_FIRST         0  /* Big Endian */
#define LSB_FIRST         1  /* Little Endian */

/* Common Symbols */
#ifndef TRUE
	#define TRUE ((boolean)1)
#endif

#ifndef FALSE
	#define FALSE ((boolean)0)
#endif

#ifndef NULL_PTR
	#define NULL_PTR ((void*)0)
#endif

#endif /* STD_TYPES_H */
