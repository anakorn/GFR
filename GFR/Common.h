#ifndef GFR_COMMON_H
#define GFR_COMMON_H

#include <assert.h>
#include <stdint.h>

#pragma region Doom 3 BFG Edition GPL Source Code: https://github.com/id-Software/DOOM-3-BFG
template<bool> struct compile_time_assert_failed;
template<> struct compile_time_assert_failed<true> {};
template<int x> struct compile_time_assert_test {};
#define compile_time_assert_join2( a, b )	a##b
#define compile_time_assert_join( a, b )	compile_time_assert_join2(a,b)
#define compile_time_assert( x )			typedef compile_time_assert_test<sizeof(compile_time_assert_failed<(bool)(x)>)> compile_time_assert_join(compile_time_assert_typedef_, __LINE__)
#define assert_sizeof( type, size )			compile_time_assert( sizeof( type ) == size )
#pragma endregion

/***************	Primitive Types	***************/

typedef int8_t		s8;
typedef int16_t		s16;
typedef int32_t		s32;
typedef int64_t		s64;
typedef uint8_t		u8;
typedef uint16_t	u16;
typedef uint32_t	u32;
typedef uint64_t	u64;

typedef float		f32;
typedef double		f64;

assert_sizeof( f32,	4 );
assert_sizeof( f64,	8 );

/***************	Allegro Types	***************/



/***************	Math	***************/

#pragma region Doom 3 BFG Edition GPL Source Code: https://github.com/id-Software/DOOM-3-BFG
#define MATH_PI				= 3.14159265358979323846f;
#define MATH_TWO_PI			= 2.0f * PI;
#define MATH_HALF_PI		= 0.5f * PI;
#define MATH_ONEFOURTH_PI	= 0.25f * PI;
#define MATH_ONEOVER_PI		= 1.0f / MATH_PI;
#define MATH_ONEOVER_TWOPI	= 1.0f / MATH_TWO_PI;
#define MATH_E				= 2.71828182845904523536f;
#define MATH_SQRT_TWO		= 1.41421356237309504880f;
#define MATH_SQRT_THREE		= 1.73205080756887729352f;
#define MATH_SQRT_1OVER2	= 0.70710678118654752440f;
#define MATH_SQRT_1OVER3	= 0.57735026918962576450f;
#define MATH_DEG2RAD		= PI / 180.0f;
#define MATH_RAD2DEG		= 180.0f / PI;
#define MATH_SEC2MS			= 1000.0f;
#define MATH_MS2SEC			= 0.001f;
#define MATH_INFINITY		= 1e30f;
#define MATH_FLT_EPSILON	= 1.192092896e-07f;
#pragma endregion

#endif