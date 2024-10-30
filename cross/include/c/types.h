#ifndef ELLIPSE_2_TYPES_H_
#define ELLIPSE_2_TYPES_H_

/**************************************************************************//**
 * @file     types.h
 * @brief    Ellipse types for C/C++.
 * @version  V0.3.0
 * @date     30. Sep 2024
 * @author   Matvey Rybalkin
******************************************************************************/

#ifndef __cplusplus
/// @brief A null pointer definition for C.
/// @details This definition is included only when the code is compiled as C,
/// since C++ already includes the `nullptr` equivalent.
/// @note For C++, `nullptr` is used instead.
#   define NULL (void*)(0)

/// @brief Boolean type for C.
/// @details This header is included for boolean type support in C. In C++,
/// `bool` is already a built-in type.
#   include <stdbool.h>
#endif

/////////////////////////////////////////////
///////////// Types definition ////////////// 
/////////////////////////////////////////////

/**
 * @typedef ptr_t
 * @brief Pointer to any type.
 */
typedef void*               ptr_t;
/**
 * @typedef i8_t
 * @brief Signed 8-bit integer.
 */
typedef signed char         i8_t;
/**
 * @typedef u8_t
 * @brief Unsigned 8-bit integer.
 */
typedef unsigned char       u8_t;
/**
 * @typedef i16_t
 * @brief Signed 16-bit integer.
 */
typedef signed short        i16_t;
/**
 * @typedef u16_t
 * @brief Unsigned 16-bit integer.
 */
typedef unsigned short      u16_t;
/**
 * @typedef i32_t
 * @brief Signed 32-bit integer.
 */
typedef signed int          i32_t;
/**
 * @typedef u32_t
 * @brief Unsigned 32-bit integer.
 */
typedef unsigned int        u32_t;
/**
 * @typedef i64_t
 * @brief Signed 64-bit integer.
 */
typedef signed long long    i64_t;
/**
 * @typedef u64_t
 * @brief Unsigned 64-bit integer.
 */
typedef unsigned long long  u64_t;

#ifdef __SIZEOF_INT128__
/**
 * @typedef i128_t
 * @brief Signed 128-bit integer (if supported by the platform).
 */
typedef __int128_t  i128_t;
/**
 * @typedef u128_t
 * @brief Unsigned 128-bit integer (if supported by the platform).
 */
typedef __uint128_t u128_t;
/**
 * @typedef imax_t
 * @brief Maximum-sized signed integer, equivalent to 128-bit if supported.
 */
typedef i128_t      imax_t;
/**
 * @typedef umax_t
 * @brief Maximum-sized unsigned integer, equivalent to 128-bit if supported.
 */
typedef u128_t      umax_t;
#else
/**
 * @typedef imax_t
 * @brief Maximum-sized signed integer, equivalent to 64-bit if 128-bit is not supported.
 */
typedef i64_t       imax_t;
/**
 * @typedef umax_t
 * @brief Maximum-sized unsigned integer, equivalent to 64-bit if 128-bit is not supported.
 */
typedef u64_t       umax_t;
#endif

/**
 * @typedef f32_t
 * @brief 32-bit floating-point type.
 */
typedef float       f32_t;
/**
 * @typedef f64_t
 * @brief 64-bit floating-point type (double precision).
 */
typedef double      f64_t;

#ifdef __SIZEOF_FLOAT128__
/**
 * @typedef f128_t
 * @brief 128-bit floating-point type (if supported by the platform).
 */
typedef __float128  f128_t;
/**
 * @typedef fmax_t
 * @brief Maximum-sized floating-point type, equivalent to 128-bit if supported.
 */
typedef f128_t      fmax_t;
#else
/**
 * @typedef fmax_t
 * @brief Maximum-sized floating-point type, equivalent to long double (usually 64-bit or more).
 */
typedef long double fmax_t;
#endif

/**
 * @def SIZEOF_FMAX
 * @brief Defines the size of the largest available floating-point type.
 */
#define SIZEOF_FMAX sizeof(fmax_t)

/**
 * @typedef char_t
 * @brief 8-bit signed character type (ASCII).
 */
typedef i8_t    char_t;
/**
 * @typedef uchar_t
 * @brief 8-bit unsigned character type.
 */
typedef u8_t    uchar_t;

/**
 * @typedef char8_t
 * @brief Alias for 8-bit character (ASCII).
 */
typedef i8_t    char8_t;
/**
 * @typedef char16_t
 * @brief 16-bit character type (UTF-16 or `wchar_t`).
 */
typedef u16_t   char16_t;

#ifndef __cplusplus
/**
 * @typedef wchar_t
 * @brief Wide character type for C (16-bit).
 * @details In C++, this type is already defined.
 */
typedef u16_t   wchar_t;
#endif

/**
 * @typedef char32_t
 * @brief 32-bit character type (UTF-32).
 */
typedef u32_t   char32_t;

#ifndef size_t
/**
 * @typedef size_t
 * @brief Data type for representing sizes of objects (usually in bytes).
 */
typedef unsigned long size_t;
#endif

#ifndef ssize_t
/**
 * @typedef ssize_t
 * @brief Signed data type for representing sizes of objects (usually in bytes).
 */
typedef signed long ssize_t;
#endif

/**
 * @typedef len_t
 * @brief Data type for representing quantities or lengths (not in bytes).
 * @warning Don't confuse with `size_t`.
 */
typedef size_t len_t;

/**
 * @union any_t
 * @brief Union for storing various data types in a single variable.
 * @details This union allows for flexible storage of different types of data, including pointers, 
 * integers of various sizes, and floating-point numbers. It supports both signed and unsigned types, 
 * as well as maximum width integer and floating-point types.
 */
typedef union {
    /**
     * @brief Pointer to any type.
     * @details Allows the storage of a generic pointer, which can be cast to any other type as needed.
     */
    void* ptr;

    /**
     * @brief 8-bit signed integer.
     * @details Stores a signed 8-bit integer (i.e., `int8_t`).
     */
    i8_t i8;

    /**
     * @brief 8-bit unsigned integer.
     * @details Stores an unsigned 8-bit integer (i.e., `uint8_t`).
     */
    u8_t u8;

    /**
     * @brief 16-bit signed integer.
     * @details Stores a signed 16-bit integer (i.e., `int16_t`).
     */
    i16_t i16;

    /**
     * @brief 16-bit unsigned integer.
     * @details Stores an unsigned 16-bit integer (i.e., `uint16_t`).
     */
    u16_t u16;

    /**
     * @brief 32-bit signed integer.
     * @details Stores a signed 32-bit integer (i.e., `int32_t`).
     */
    i32_t i32;

    /**
     * @brief 32-bit unsigned integer.
     * @details Stores an unsigned 32-bit integer (i.e., `uint32_t`).
     */
    u32_t u32;

    /**
     * @brief 64-bit signed integer.
     * @details Stores a signed 64-bit integer (i.e., `int64_t`).
     */
    i64_t i64;

    /**
     * @brief 64-bit unsigned integer.
     * @details Stores an unsigned 64-bit integer (i.e., `uint64_t`).
     */
    u64_t u64;

#ifdef __SIZEOF_INT128__
    /**
     * @brief 128-bit signed integer.
     * @details Stores a signed 128-bit integer (i.e., `__int128_t`). (if supported by the system)
     */
    i128_t i128;

    /**
     * @brief 128-bit unsigned integer.
     * @details Stores an unsigned 128-bit integer (i.e., `unsigned __int128_t`). (if supported by the system)
     */
    u128_t u128;
#endif

    /**
     * @brief 32-bit floating-point number.
     * @details Stores a 32-bit floating-point value (i.e., `float`).
     */
    f32_t f32;

    /**
     * @brief 64-bit floating-point number.
     * @details Stores a 64-bit floating-point value (i.e., `double`).
     */
    f64_t f64;

#ifdef __SIZEOF_FLOAT128__
    /**
     * @brief 128-bit floating-point number.
     * @details Stores a 128-bit floating-point value (i.e., `__float128`). (if supported by the system)
     */
    f128_t f128;
#endif

    /**
     * @brief Maximum signed integer.
     * @details Stores the largest signed integer available (i.e., `intmax_t`), depending on the platform.
     */
    imax_t imax;

    /**
     * @brief Maximum unsigned integer.
     * @details Stores the largest unsigned integer available (i.e., `uintmax_t`), depending on the platform.
     */
    umax_t umax;

    /**
     * @brief Maximum floating point number.
     * @details Stores the largest floating-point number available, depending on the platform.
     */
    fmax_t fmax;
} any_t;

/////////////////////////////////////////////
///////////// Types enumerations //////////// 
/////////////////////////////////////////////

/**
 * @brief Enumeration of data types for Ellipse framework.
 * 
 * This enumeration lists different data types that can be used in the framework.
 * It supports integer types, floating-point types, and system-specific maximum types.
 */
typedef enum {
    TYPE_I8,        ///< Signed 8-bit integer `i8_t`
    TYPE_U8,        ///< Unsigned 8-bit integer `ui8_t`
    TYPE_I16,       ///< Signed 16-bit integer `i16_t`
    TYPE_U16,       ///< Unsigned 16-bit integer `u16_t`
    TYPE_I32,       ///< Signed 32-bit integer `i32_t`
    TYPE_U32,       ///< Unsigned 32-bit integer `u32_t`
    TYPE_I64,       ///< Signed 64-bit integer `i64_t`
    TYPE_U64,       ///< Unsigned 64-bit integer `u64_t`
    TYPE_IMAX,      ///< Maximum signed integer type available on the system `imax_t`
    TYPE_UMAX,      ///< Maximum unsigned integer type available on the system `umax_t`
    TYPE_FMAX,      ///< Maximum floating point type available on the system `fmax_t`

#ifdef __SIZEOF_INT128__
    TYPE_I128,      ///< Signed 128-bit integer `i128_t` (if supported by the system)
    TYPE_U128,      ///< Unsigned 128-bit integer `u128_t` (if supported by the system)
#endif

#ifdef __SIZEOF_FLOAT128__
    TYPE_F128,      ///< Floating point 128-bit `f128_t` (if supported by the system)
#endif
    TYPE_AGGREGATE, ///< Udefined data type of a complex type that cannot be expressed using standard C language types. 
    TYPE_UNKNOWN,   ///< Undefined data type that cannot be uniquely defined, such as `void*`
} type_t;

extern size_t type_size(type_t type);

/**
 * @brief Enumeration of generic value types.
 * 
 * This enumeration defines different value categories used during tokenization
 * and processing of data.
 */
typedef enum {
    VALUE_TYPE_INTEGER,   ///< Represents an integer value (signed or unsigned)
    VALUE_TYPE_DECIMAL,   ///< Represents a decimal value (floating-point)
    VALUE_TYPE_CHARACTER, ///< Represents a single character
    VALUE_TYPE_STRING,    ///< Represents a string (sequence of characters)
} value_type_t;

/////////////////////////////////////////////
//////// Error / Warnings definitions /////// 
/////////////////////////////////////////////


/**
 * @enum err_t
 * @brief Error codes for various operations.
 * @details Includes general, memory-related, I/O, network, validation, and hardware errors.
 */
typedef enum {
    ERR_OK = 0,                      ///< Operation completed successfully.
    ERR_GENERAL = 1,                 ///< General error.

    // Memory Errors
    ERR_MEM_GENERAL = 100,           ///< General memory error.
    ERR_MEM_OUT_OF_MEMORY = 101,     ///< Out of memory (heap or stack exhausted).
    ERR_MEM_NULL_POINTER = 102,      ///< Null pointer dereference.
    ERR_MEM_LEAK = 103,              ///< Memory leak detected.
    ERR_MEM_CORRUPTION = 104,        ///< Memory corruption detected.
    ERR_MEM_SEGMENTATION_FAULT = 105,///< Invalid memory access (segmentation fault).

    // I/O Errors
    ERR_IO_GENERAL = 200,            ///< General I/O error.
    ERR_IO_FILE_NOT_FOUND = 201,     ///< File not found.
    ERR_IO_FILE_PERMISSION = 202,    ///< File access permission denied.
    ERR_IO_FILE_READ = 203,          ///< File read error.
    ERR_IO_FILE_WRITE = 204,         ///< File write error.
    ERR_IO_TIMEOUT = 205,            ///< I/O operation timed out.
    ERR_IO_DISK_FULL = 206,          ///< No space left on device.
    ERR_IO_PATH_TOO_LONG = 207,      ///< File path too long.
    ERR_IO_FILE_EXISTS = 208,        ///< File already exists.

    // Network Errors
    ERR_NET_GENERAL = 300,           ///< General network error.
    ERR_NET_CONNECTION_FAILED = 301, ///< Network connection failed.
    ERR_NET_CONNECTION_LOST = 302,   ///< Network connection lost.
    ERR_NET_TIMEOUT = 303,           ///< Network connection timed out.
    ERR_NET_INVALID_ADDRESS = 304,   ///< Invalid network address.
    ERR_NET_DNS_RESOLUTION = 305,    ///< DNS resolution failed.
    ERR_NET_PROTOCOL = 306,          ///< Protocol error.
    ERR_NET_SSL = 307,               ///< SSL/TLS error.

    // Argument and Data Errors
    ERR_ARG_INVALID = 400,           ///< Invalid function argument.
    ERR_ARG_OUT_OF_BOUNDS = 401,     ///< Index or pointer out of bounds.
    ERR_ARG_INVALID_DATA = 402,      ///< Invalid data format.
    ERR_ARG_DATA_OVERFLOW = 403,     ///< Data overflow (buffer too small).
    ERR_ARG_DATA_UNDERFLOW = 404,    ///< Data underflow (buffer is already empty).
    ERR_ARG_TYPE_MISMATCH = 405,     ///< Type mismatch error.
    ERR_ARG_ENCODING = 406,          ///< Encoding error.

    // State and Logic Errors
    ERR_STATE_UNINITIALIZED = 500,   ///< Uninitialized variable or state.
    ERR_STATE_MISMATCH = 501,        ///< Invalid state or state mismatch.
    ERR_STATE_LOGIC_FAILURE = 502,   ///< General logical failure.
    ERR_STATE_NOT_IMPLEMENTED = 503, ///< Functionality not implemented.
    ERR_STATE_UNSUPPORTED = 504,     ///< Operation not supported.
    ERR_STATE_INTERNAL = 505,        ///< Internal error.

    // Parsing and Syntax Errors
    ERR_PARSE_SYNTAX = 600,          ///< Syntax error.
    ERR_PARSE_FAILURE = 601,         ///< Parsing failure.
    ERR_PARSE_UNEXPECTED_TOKEN = 602,///< Unexpected token encountered during parsing.
    ERR_PARSE_LEXER = 603,           ///< Lexical analysis error.
    ERR_PARSE_TOKENIZATION = 604,    ///< Tokenization error.
    ERR_PARSE_SEMANTIC = 605,        ///< Semantic analysis error.
    ERR_PARSE_UNEXPECTED_EOF = 606,  ///< Unexpected end of file/input.

    // Hardware and Device Errors
    ERR_HW_GENERAL = 700,            ///< General hardware error.
    ERR_HW_DEVICE_FAILURE = 701,     ///< Hardware device failure.
    ERR_HW_DEVICE_BUSY = 702,        ///< Hardware device is busy.
    ERR_HW_DEVICE_NOT_FOUND = 703,   ///< Hardware device not found.
    ERR_HW_DEVICE_NOT_READY = 704,   ///< Device not ready.
    ERR_HW_DEVICE_TIMEOUT = 705,     ///< Device operation timed out.
    ERR_HW_DEVICE_UNSUPPORTED = 706, ///< Device not supported.

    // Security and Authentication Errors
    ERR_SEC_AUTH = 800,              ///< Authentication failure.
    ERR_SEC_ACCESS_DENIED = 801,     ///< Access denied.
    ERR_SEC_ENCRYPTION = 802,        ///< Encryption or decryption failure.
    ERR_SEC_GENERAL = 803,           ///< General security error.
    ERR_SEC_PRIVILEGE = 804,         ///< Insufficient privileges.

    // Threading and Concurrency Errors
    ERR_THREAD_GENERAL = 900,        ///< General threading error.
    ERR_THREAD_MUTEX = 901,          ///< Mutex acquisition or release failure.
    ERR_THREAD_DEADLOCK = 902,       ///< Deadlock detected.
    ERR_THREAD_TIMEOUT = 903,        ///< Threading operation timed out.
    ERR_THREAD_CREATION = 904,       ///< Failed to create a new thread.
    ERR_THREAD_JOIN = 905,           ///< Failed to join a thread.
    ERR_THREAD_INTERRUPTED = 906,    ///< Thread was interrupted.
    ERR_THREAD_MUTEX_INIT = 907,     ///< Mutex initialization failed.
    ERR_THREAD_MUTEX_LOCK = 908,     ///< Failed to acquire mutex lock.
    ERR_THREAD_MUTEX_UNLOCK = 909,   ///< Failed to release mutex lock.
    ERR_THREAD_CONDITION_WAIT = 910, ///< Condition variable wait failed.
    ERR_THREAD_CONDITION_SIGNAL = 911, ///< Condition variable signal failed.

    // Time and Timer Errors
    ERR_TIME_CLOCK = 1000,           ///< Clock error.
    ERR_TIME_TIMER = 1001,           ///< Timer error.
    ERR_TIME_OPERATION_TIMEOUT = 1002, ///< Operation timed out.

    // Configuration Errors
    ERR_CONFIG_GENERAL = 1003,       ///< Configuration error.
    ERR_CONFIG_INVALID = 1004,       ///< Invalid configuration.

    // Resource Errors
    ERR_RESOURCE_LIMIT = 1005,       ///< Resource limit exceeded.
    ERR_RESOURCE_BUSY = 1006,        ///< Resource is busy.

    // Signal and Exception Errors
    ERR_SIGNAL_GENERAL = 1007,       ///< Signal received.
    ERR_EXCEPTION = 1008,            ///< Exception occurred.

    // Module and Plugin Errors
    ERR_MODULE_LOAD = 1009,          ///< Failed to load module.
    ERR_MODULE_UNLOAD = 1010,        ///< Failed to unload module.
    ERR_MODULE_INIT = 1011,          ///< Module initialization failed.

    // Server Errors
    ERR_SERVER_START = 1012,         ///< Failed to start server.
    ERR_SERVER_STOP = 1013,          ///< Failed to stop server.
    ERR_SERVER_OVERLOAD = 1014,      ///< Server is overloaded.

    // Database Errors
    ERR_DB_GENERAL = 1100,           ///< General database error.
    ERR_DB_CONNECTION = 1101,        ///< Database connection failed.
    ERR_DB_QUERY = 1102,             ///< Database query failed.
    ERR_DB_TRANSACTION = 1103,       ///< Database transaction failed.

    // Serialization and Deserialization Errors
    ERR_SERIALIZATION = 1200,        ///< Serialization error.
    ERR_DESERIALIZATION = 1201,      ///< Deserialization error.

    // Compression and Decompression Errors
    ERR_COMPRESSION = 1300,          ///< Compression error.
    ERR_DECOMPRESSION = 1301,        ///< Decompression error.

    // Internationalization Errors
    ERR_LOCALE_GENERAL = 1400,       ///< Locale error.
    ERR_ENCODING_CONVERSION = 1401,  ///< Encoding conversion error.

    // Machine Learning and AI Errors (if applicable)
    ERR_ML_MODEL_LOAD = 1500,        ///< Failed to load model.
    ERR_ML_INFERENCE = 1501,         ///< Inference error.
    ERR_ML_DATA_PREPROCESSING = 1502,///< Data preprocessing error.

    // User Interface Errors
    ERR_UI_RENDER = 1600,            ///< UI rendering error.
    ERR_UI_EVENT = 1601,             ///< UI event handling error.

    // API Errors
    ERR_API_GENERAL = 1700,          ///< General API error.
    ERR_API_LIMIT = 1701,            ///< API rate limit exceeded.
    ERR_API_RESPONSE = 1702,         ///< Invalid API response.

    // Cryptography Errors
    ERR_CRYPTO_GENERAL = 1800,       ///< General cryptography error.
    ERR_CRYPTO_KEY_GENERATION = 1801,///< Key generation error.
    ERR_CRYPTO_SIGNATURE = 1802,     ///< Digital signature error.

    // File System Errors
    ERR_FS_GENERAL = 1900,           ///< General filesystem error.
    ERR_FS_DIRECTORY_NOT_FOUND = 1901,///< Directory not found.
    ERR_FS_READ_ONLY = 1902,         ///< Filesystem is read-only.

    // General Purpose Errors
    ERR_UNKNOWN = 2000,              ///< Unknown error.
    ERR_NOT_FOUND = 2001,            ///< Requested item not found.
    ERR_ALREADY_EXISTS = 2002,       ///< Item already exists.
    ERR_NOT_AVAILABLE = 2003,        ///< Item not available.
    ERR_READ_ONLY = 2004,            ///< Data is read-only.
} err_t;

/**
 * @enum warn_t
 * @brief Warning codes for various operations.
 * @details Includes general, memory-related, I/O, network, validation, and hardware warnings.
 */
typedef enum {
    WARN_OK = 0,                      ///< No warnings.

    // General Warnings
    WARN_GENERAL = 1,                 ///< General warning.

    // Memory Warnings
    WARN_MEM_GENERAL = 100,             ///< General memory warning.
    WARN_MEM_USAGE_HIGH = 101,          ///< High memory usage.
    WARN_MEM_FRAGMENTATION = 102,       ///< Memory fragmentation detected.
    WARN_MEM_NEAR_OUT = 103,            ///< Memory nearly exhausted.
    WARN_MEM_IMPLICIT_ALLOCATION = 104, ///< Implicit memory allocation.
    WARN_MEM_IMPLICIT_FREED = 105,      ///< Implicit memory freeing.
    WARN_MEM_USELESS_OPERATION = 106,   ///< Memory useless operation.

    // I/O Warnings
    WARN_IO_GENERAL = 200,              ///< General I/O warning.
    WARN_IO_FILE_PERMISSION_WEAK = 201, ///< Weak file permissions.
    WARN_IO_FILE_DEPRECATED = 202,      ///< File format deprecated.
    WARN_IO_FILE_CORRUPTED = 203,       ///< File potentially corrupted.
    WARN_IO_TIMEOUT_RISK = 204,         ///< Risk of I/O timeout.
    WARN_IO_DISK_SPACE_LOW = 205,       ///< Low disk space warning.

    // Network Warnings
    WARN_NET_GENERAL = 300,             ///< General network warning.
    WARN_NET_LATENCY_HIGH = 301,        ///< High network latency.
    WARN_NET_PACKET_LOSS = 302,         ///< Packet loss detected.
    WARN_NET_BANDWIDTH_LOW = 303,       ///< Low network bandwidth.
    WARN_NET_CONNECTION_UNSTABLE = 304, ///< Unstable network connection.

    // Argument and Data Warnings
    WARN_ARG_GENERAL = 400,             ///< General argument warning.
    WARN_ARG_DEPRECATED = 401,          ///< Deprecated function argument.
    WARN_ARG_VALUE_AT_LIMIT = 402,      ///< Argument value near limit.
    WARN_ARG_TYPE_MISMATCH_RISK = 403,  ///< Potential type mismatch.
    WARN_ARG_TRUNCATION = 404,          ///< Possible data truncation.

    // State and Logic Warnings
    WARN_STATE_GENERAL = 500,           ///< General state warning.
    WARN_STATE_INCONSISTENT = 501,      ///< Inconsistent state.
    WARN_STATE_TRANSITION_DELAY = 502,  ///< Delayed state transition.
    WARN_STATE_DEPRECATED_USAGE = 503,  ///< Deprecated state usage.

    // Parsing and Syntax Warnings
    WARN_PARSE_GENERAL = 600,           ///< General parsing warning.
    WARN_PARSE_DEPRECATED_SYNTAX = 601, ///< Deprecated syntax detected.
    WARN_PARSE_AMBIGUOUS_TOKEN = 602,   ///< Ambiguous token detected.
    WARN_PARSE_POTENTIAL_ERROR = 603,   ///< Parsing might fail under certain conditions.

    // Hardware and Device Warnings
    WARN_HW_GENERAL = 700,              ///< General hardware warning.
    WARN_HW_OVERHEATING_RISK = 701,     ///< Risk of hardware overheating.
    WARN_HW_POWER_LOW = 702,            ///< Low power warning.
    WARN_HW_PERFORMANCE_DEGRADED = 703, ///< Hardware performance degraded.
    WARN_HW_UNSUPPORTED_FEATURE = 704,  ///< Unsupported hardware feature in use.

    // Security and Authentication Warnings
    WARN_SEC_GENERAL = 800,           ///< General security warning.
    WARN_SEC_AUTH_WEAK = 801,         ///< Weak authentication.
    WARN_SEC_PRIVILEGE_LOW = 802,     ///< Insufficient privileges, but no immediate risk.
    WARN_SEC_ENCRYPTION_WEAK = 803,   ///< Weak encryption algorithm.

    // Threading and Concurrency Warnings
    WARN_THREAD_GENERAL = 900,          ///< General threading warning.
    WARN_THREAD_DEADLOCK_RISK = 901,    ///< Potential deadlock risk.
    WARN_THREAD_CONTENTION_HIGH = 902,  ///< High contention detected.
    WARN_THREAD_OVERHEAD_HIGH = 903,    ///< Threading overhead is high.

    // Time and Timer Warnings
    WARN_TIME_GENERAL = 1000,         ///< General time warning.
    WARN_TIME_SKEW_DETECTED = 1001,   ///< Time skew detected.
    WARN_TIME_CLOCK_DRIFT = 1002,     ///< Clock drift detected.

    // Configuration Warnings
    WARN_CONFIG_GENERAL = 1100,       ///< General configuration warning.
    WARN_CONFIG_INCONSISTENT = 1101,  ///< Inconsistent configuration.
    WARN_CONFIG_DEPRECATED = 1102,    ///< Deprecated configuration setting.

    // Resource Warnings
    WARN_RESOURCE_LIMIT_NEAR = 1200,  ///< Approaching resource limit.
    WARN_RESOURCE_USAGE_HIGH = 1201,  ///< High resource usage detected.
    WARN_RESOURCE_CONTENTION = 1202,  ///< Resource contention detected.

    // Module and Plugin Warnings
    WARN_MODULE_GENERAL = 1300,       ///< General module warning.
    WARN_MODULE_DEPRECATED = 1301,    ///< Module or plugin is deprecated.
    WARN_MODULE_LOAD_DELAYED = 1302,  ///< Module loading is delayed.

    // Server Warnings
    WARN_SERVER_GENERAL = 1400,             ///< General server warning.
    WARN_SERVER_LOAD_HIGH = 1401,           ///< High server load detected.
    WARN_SERVER_RESTART_REQUIRED = 1402,    ///< Server restart required.

    // Database Warnings
    WARN_DB_GENERAL = 1500,           ///< General database warning.
    WARN_DB_QUERY_SLOW = 1501,        ///< Slow database query detected.
    WARN_DB_TRANSACTION_RISKY = 1502, ///< Risky database transaction.

    // Serialization and Deserialization Warnings
    WARN_SERIALIZATION_GENERAL = 1600,      ///< General serialization warning.
    WARN_SERIALIZATION_DEPRECATED = 1601,   ///< Deprecated serialization format.
    WARN_DESERIALIZATION_INCOMPLETE = 1602, ///< Incomplete deserialization.

    // Compression and Decompression Warnings
    WARN_COMPRESSION_GENERAL = 1700,    ///< General compression warning.
    WARN_COMPRESSION_LOSSY = 1701,      ///< Lossy compression detected.
    WARN_DECOMPRESSION_SLOW = 1702,     ///< Slow decompression.

    // Internationalization Warnings
    WARN_LOCALE_GENERAL = 1800,         ///< General locale warning.
    WARN_LOCALE_MISMATCH = 1801,        ///< Locale mismatch detected.
    WARN_LOCALE_PARTIAL_SUPPORT = 1802, ///< Partial locale support.

    // Machine Learning and AI Warnings (if applicable)
    WARN_ML_MODEL_GENERAL = 1900,       ///< General model warning.
    WARN_ML_MODEL_ACCURACY_LOW = 1901,  ///< Model accuracy is lower than expected.
    WARN_ML_DATA_INSUFFICIENT = 1902,   ///< Insufficient data for training or inference.

    // User Interface Warnings
    WARN_UI_GENERAL = 2000,             ///< General UI warning.
    WARN_UI_DEPRECATED_COMPONENT = 2001,    ///< Deprecated UI component in use.
    WARN_UI_LAYOUT_SUBOPTIMAL = 2002,       ///< Suboptimal UI layout detected.

    // API Warnings
    WARN_API_GENERAL = 2100,            ///< General API warning.
    WARN_API_DEPRECATED = 2101,         ///< Deprecated API in use.
    WARN_API_RESPONSE_DELAYED = 2102,   ///< Delayed API response.

    // Cryptography Warnings
    WARN_CRYPTO_GENERAL = 2200,         ///< General cryptography warning.
    WARN_CRYPTO_KEY_EXPIRING = 2201,    ///< Cryptographic key nearing expiration.
    WARN_CRYPTO_SIGNATURE_WEAK = 2202,  ///< Weak cryptographic signature detected.

    // File System Warnings
    WARN_FS_GENERAL = 2300,                 ///< General filesystem warning.
    WARN_FS_DEPRECATED_FORMAT = 2301,       ///< Deprecated filesystem format.
    WARN_FS_SPACE_FRAGMENTATION = 2302,     ///< Filesystem fragmentation detected.

    // Miscellaneous Warnings
    WARN_MISC_GENERAL = 2400,               ///< General miscellaneous warning.
    WARN_MISC_DEPRECATED_FEATURE = 2401,    ///< Deprecated feature in use.
    WARN_MISC_PERFORMANCE_DEGRADED = 2402,  ///< System performance degraded.

    // General Purpose Warnings
    WARN_UNKNOWN = 2500,              ///< Unknown warning.
} warn_t;

/**
 * @typedef status_t
 * @brief Type definition for representing both error and warning codes.
 * 
 * The combined 32-bit value is used to store error and warning codes simultaneously.
 * - The upper 16 bits represent the error code.
 * - The lower 16 bits represent the warning code.
 * 
 * This approach allows for compact representation and handling of both error conditions
 * and additional warnings within a single return value, which can be easily extracted using
 * the provided macros.
*/
typedef u32_t status_t;

#define WARN_MASK 0x0000FFFF ///< Mask for extracting warnings
#define ERR_MASK  0xFFFF0000 ///< Mask for extracting errors

/**
 * @brief Returns a combined error and warning value.
 * @param error The error code (upper 16 bits)
 * @param warning The warning code (lower 16 bits)
 * @return err_warn_t combined error and warning value
 */
#define MAKE_ERR_WARN(error, warning) (((error) << 16) | (warning))

/**
 * @brief Extracts the error code.
 * @param[in] status Combined error and warning value
 * @return The error code
 */
extern inline err_t extract_error(status_t status);

/**
 * @brief Extracts the warning code.
 * @param[in] status Combined error and warning value
 * @return The warning code
 */
extern inline warn_t extract_warning(status_t status);


/////////////////////////////////////////////
////////////////// Aliases //////////////////
/////////////////////////////////////////////

/**
 * @def MIN(a, b)
 * @brief Safely computes the minimum of two values.
 * 
 * This macro computes the minimum of two values `a` and `b` in a safe manner.
 * It uses temporary variables to avoid the potential risks of evaluating 
 * the arguments more than once (which can happen in unsafe macros).
 * 
 * The macro is designed to be generic and works with any data type that supports
 * the less-than (`<`) comparison operator.
 * 
 * @param[in] a The first value to compare.
 * @param[in] b The second value to compare.
 * @return The smaller of the two values [a] and [b].
 * 
 * @note This macro uses GCC's __typeof__ keyword and a GCC-specific block expression 
 * ({...}), which may not be portable across all compilers.
 */
#define MIN(a, b) ({ __typeof__(a) _a = (a); __typeof__(b) _b = (b); _a < _b ? _a : _b; })

/**
 * @def MAX(a, b)
 * @brief Safely computes the maximum of two values.
 * 
 * This macro computes the maximum of two values [a] and [b] in a safe manner.
 * Similar to MIN, it uses temporary variables to avoid multiple evaluations of 
 * the arguments and ensure safe execution.
 * 
 * The macro is designed to be generic and works with any data type that supports
 * the greater-than (`>`) comparison operator.
 * 
 * @param[in] a The first value to compare.
 * @param[in] b The second value to compare.
 * @return The larger of the two values [a] and [b].
 * 
 * @note This macro uses GCC's __typeof__ keyword and a GCC-specific block expression 
 * ({...}), which may not be portable across all compilers.
 */
#define MAX(a, b) ({ __typeof__(a) _a = (a); __typeof__(b) _b = (b); _a > _b ? _a : _b; })

/**
 * @def RANGE(i, n)
 * @brief Alias for a for loop with an index variable `i`.
 * 
 * This macro simplifies the syntax for creating a for loop that iterates 
 * from 0 to `n - 1`. It is equivalent to `for (ssize_t i = 0; i < n; ++i)`.
 * 
 * @param[in] i Iterator variable to be declared and used in the loop.
 * @param[in] n Loop count limit, specifying how many times the loop should run.
 * 
 * @note This macro assumes that the loop variable [i] is an integer or can be implicitly converted to an integer.
 * @warning Ensure that the value of [n] is non-negative, otherwise the loop might result in undefined behavior.
 */
#define RANGE(i, n) for(ssize_t i = 0; i < (n); ++i)

/**
 * @def IN_RANGE(i, min, max)
 * @brief Checks if a value is within a specified range.
 * 
 * This macro checks whether the value [i] falls within the inclusive range specified by [min] and [max].
 * It is equivalent to `(i >= min && i <= max)`.
 * 
 * @param[in] i The value to check.
 * @param[in] min The lower bound of the range (inclusive).
 * @param[in] max The upper bound of the range (inclusive).
 * 
 * @return 1 if [i] is within the range, 0 otherwise.
 * 
 * @note This macro works for any data type that supports comparison operators.
 */
#define IN_RANGE(i, min, max) ((i) >= (min) && (i) <= (max))

/**
 * @def SWAP(a, b, type)
 * @brief Swaps the values of two variables of the same type.
 *
 * This macro swaps the values of two variables [a] and [b], both of which 
 * must be of the same type. It uses a temporary variable to hold the value 
 * of [a] while assigning [b] to [a], and then assigns the value stored in the 
 * temporary variable to [b]. This is useful for in-place swapping without 
 * creating deep copies or additional memory allocations.
 *
 * @param[in, out] a First variable, passed by reference, to be swapped with [b].
 * @param[in, out] b Second variable, passed by reference, to be swapped with [a].
 * @param[in] type The type of the variables [a] and [b]. This ensures that the 
 *        macro is type-safe and works only when both variables are of the same type.
 *
 * @warning Both [a] and [b] must be valid pointers of the same type. 
 * Using this macro with different types, or with invalid pointers, 
 * can lead to undefined behavior.
 *
 * Potential Pitfalls:
 * - Ensure that both [a] and [b] are valid pointers.
 * - Ensure that [a] and [b] point to objects of the same type.
 * - Do not use this macro for complex types that require special handling (like structs with dynamic memory).
 * - Be cautious with const-qualified pointers, as the macro attempts to modify values, which is illegal for const-qualified objects.
 */
#define SWAP(a, b, type)    type temp = a; \
                            *a = b;        \
                            *b = temp;

                            
#endif // ELLIPSE_2_TYPES_H_
