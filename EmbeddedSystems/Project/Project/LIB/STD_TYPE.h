//   ___     ___    ____    ____    ____    ____    	   |	     	             |_     ___    ____    ____    ____    ____
// _/   \___/   \__/    \__/    \__/    \__/    \__/AUTHOR | MARIAM RAMADAN EL-Badri | \___/   \__/    \__/    \__/    \__/    \__
//																	Layer: LIB

#ifndef STD_TYPE_H
#define STD_TYPE_H

//Only positive data types
typedef unsigned char 			u8 ;
typedef unsigned short int 		u16 ;
typedef unsigned int 			u32;
typedef unsigned long long int	u64;

//Signed/ positive and negative data types
typedef signed char 			s8 ;
typedef signed short int 		s16 ;
typedef signed int 				s32 ;
typedef signed long long int 	s64 ;

//Floating data types
typedef float  					f32 ;
typedef double 					f64 ;

//Enum -- true false
typedef enum {False,True}boole;
	
#define NULL                 0
#endif