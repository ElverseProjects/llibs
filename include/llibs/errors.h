#ifndef LERRORS_H_
#define LERRORS_H_

typedef enum {
    LERR_OK = 0,             // Operation completed successfully
    LERR_FAILURE,            // Generic or unknown error
    LERR_INVALID_ARG,        // Null pointer or invalid argument passed to function
    LERR_OUT_OF_BOUNDS,      // Index is outside the buffer or array range
    LERR_OUT_OF_MEMORY,      // Failed to allocate or reallocate memory
    LERR_NOT_FOUND,          // Requested item, file, or key was not found
    LERR_ACCESS_DENIED,      // Insufficient permissions for the operation
    LERR_ALREADY_EXISTS,     // Attempt to create an entity that already exists
    LERR_OVERFLOW,           // Data exceeds the maximum capacity of the type/buffer
    LERR_UNDERFLOW,          // Data is less than the minimum required size/value
    LERR_NOT_IMPLEMENTED,    // Functionality is planned but not yet available
    LERR_BUSY,               // Resource is currently locked or in use
    LERR_TIMEOUT,            // Operation exceeded the allocated time limit
} lerr;


#endif // LERRORS_H_