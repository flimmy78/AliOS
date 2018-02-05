////////////////////////////////////////////////////////////////////////////////
//                   Mountain View Silicon Tech. Inc.
//		Copyright 2011, Mountain View Silicon Tech. Inc., ShangHai, China
//                   All rights reserved.
//
//		Filename	:types.h
//		Description	:re-define language C basic data type for porting conveniently
//						over platforms
//		Changelog	:
//					2012-02-21	Create basic data type re-definition for uniform
//						platform by Robert
///////////////////////////////////////////////////////////////////////////////

/**
 * @addtogroup MVUtils
 * @{
 * @defgroup types types
 * @{
 */


#ifndef		__TYPES_H__
#define		__TYPES_H__

#include <stdint.h>
//#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif//__cplusplus

#ifndef NULL	
#define	NULL			((void*)0)
#endif

#define	FALSE			(0)
#define	TRUE			(1)

typedef	void(*FPCALLBACK)(void);

#ifndef bool
typedef unsigned char   		bool;
#endif
typedef bool(*TerminateFunc)(void);

//#ifndef int8_t
#if !__int8_t_defined
typedef signed char				int8_t;
#endif

//#ifndef uint8_t
#if !__int8_t_defined
typedef unsigned char			uint8_t;
#endif

//#ifndef int16_t
#if !__int16_t_defined
typedef signed short			int16_t;
#endif

//#ifndef uint16_t
#if !__int16_t_defined
typedef unsigned short			uint16_t;
#endif

#if !__int32_t_defined
typedef signed int				int32_t;
#endif

//#ifndef uint32_t
#if !__int32_t_defined
typedef unsigned int			uint32_t;
#endif

typedef signed char				int8;
typedef unsigned char			uint8;
typedef signed short			int16;
typedef unsigned short			uint16;
typedef signed int				int32;
typedef unsigned int			uint32;

//typedef	unsigned int			size_t;


#if defined(__ICCARM__)    // For IAR compiler
#define __ATTRIBUTE__(keyword)  keyword
#define BITBAND
#define AT(address)             @ address
#define SECTION(name)           @ name
#define WEAK                    __weak
#define UNUSED
#define __NO_INIT__             __no_init
#elif defined(__CC_ARM)    // For Keil compiler
#define __ATTRIBUTE__(keyword)  __attribute__((keyword))
#define BITBAND                 bitband
#define AT(address)             at(address)
#define SECTION(name)           section(name)
#define WEAK                    weak
#define UNUSED                  unused
#define __NO_INIT__
#else                      // For other compiler
#define __ATTRIBUTE__(keyword)  keyword
//#define BITBAND
//#define AT(address)
//#define SECTION(name)
//#define WEAK
#define UNUSED
#define __NO_INIT__
#endif
	


//大小端转换宏，ARM CPU为小端模式
#define Le16ToCpu(Val)		(Val)
#define Le32ToCpu(Val)		(Val)
#define CpuToLe16(Val)		(Val)
#define CpuToLe32(Val)		(Val)

#define Be16ToCpu(Val)		(((Val) << 8) | ((Val) >> 8))
#define Be32ToCpu(Val)		(((Val) << 24) | (((Val) << 8) & 0x00FF0000) | (((Val) >> 8) & 0x0000FF00) | ((Val) >> 24))
#define CpuToBe16(Val)		(((Val) << 8) | ((Val) >> 8))
#define CpuToBe32(Val)		(((Val) << 24) | (((Val) << 8) & 0x00FF0000) | (((Val) >> 8) & 0x0000FF00) | ((Val) >> 24))


const unsigned char *GetLibVersionDriver(void);

#ifdef __cplusplus
}
#endif//__cplusplus

#endif	//__TYPE_H__



