
#pragma once

#include <string>

#ifndef __FILENAME__

    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)

        #define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

    #else

        #define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

    #endif

#endif

#ifndef EZJ_THROW
#define EZJ_THROW(throw_error_message)                   \
throw std::runtime_error (                              \
  std::string( "error in " )                            \
+ std::string( __FILENAME__ )                           \
+ std::string(" (line ")                                \
+ std::string( std::to_string(__LINE__ ) )              \
+ std::string(") ")                                     \
+ std::string( __FUNCTION__ )                           \
+ std::string(": '")                                    \
+ std::string( throw_error_message ) );                    
#endif

#ifndef EZJ_THROW_NULL
#define THROW_NULL THROW("null pointer encountered")
#endif

#ifndef EZJ_THROW_IF_NULL
#define THROW_IF_NULL(pointerVariable)               \
if ( pointerVariable == nullptr ) { THROW_NULL }
#endif

#ifndef EZJ_THROW_IF_BAD_VALUE
#define EZJ_THROW_IF_BAD_VALUE( VALUE, MIN_VAL, MAX_VAL )                          \
if( VALUE < MIN_VAL || VALUE > MAX_VAL ) {                                     \
std::stringstream BADVALUEMESSAGE;                                             \
BADVALUEMESSAGE << "value out of range. " <<                                   \
#VALUE << " = " << VALUE << ", min = " << MIN_VAL << ", max = " << MAX_VAL;    \
EZJ_THROW( BADVALUEMESSAGE.str() ) }
#endif

#ifndef EZJ_BUG
#define EZJ_BUG EZJ_THROW( "this exception is due to a coding error, please report the bug https://github.com/Webern/MusicXML-Class-Library/issues" );
#endif

#ifndef EZJ_ASSERT
#define EZJ_ASSERT(expectedTrueStatement)               \
if ( ! (expectedTrueStatement) ) { EZJ_THROW("assertion failed '" #expectedTrueStatement "'"); }
#endif


#ifndef EZJ_NOT_IMPLEMENTED
#define EZJ_NOT_IMPLEMENTED                             \
EZJ_THROW("not implemented")
#endif
