#ifndef ANALOG_H
#define ANALOG_H

#ifdef __cplusplus
extern "C" {
#endif

void analog_init(void);

int32_t analog_get(void);

#ifdef __cplusplus
}
#endif

#endif /* ANALOG_H */
