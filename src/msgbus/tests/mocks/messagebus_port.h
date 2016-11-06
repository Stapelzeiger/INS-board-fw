#ifndef MESSAGEBUS_PORT_H
#define MESSAGEBUS_PORT_H

#include <pthread.h>

typedef struct {
    int mutex;
    int cond;
} messagebus_condvar_wrapper_t;

#ifdef __cplusplus
extern "C" {
#endif

void messagebus_condvar_wrapper_init(messagebus_condvar_wrapper_t *c);

#ifdef __cplusplus
}
#endif
#endif