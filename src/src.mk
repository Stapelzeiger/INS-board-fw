
PROJINC += $(PROJROOT)/src/
PROJINC += $(PROJROOT)/src/flight-stack/src/
PROJINC += $(PROJROOT)/src/msgbus/ports/ChibiOS



PROJCPPSRC += $(PROJROOT)/src/flight-stack/src/attitude_estimation/ekf_gyro_acc.cpp
PROJCPPSRC += $(PROJROOT)/src/flight-stack/src/attitude_estimation/ekf_gyro_acc_mag.cpp

PROJCSRC += $(PROJROOT)/src/error.c
PROJCPPSRC += $(PROJROOT)/src/attitude_determination.cpp
PROJCSRC += $(PROJROOT)/src/datagram_message_comm.c
PROJCSRC += $(PROJROOT)/src/log.c
PROJCSRC += $(PROJROOT)/src/onboardsensors.c
PROJCSRC += $(PROJROOT)/src/sdcard.c
PROJCSRC += $(PROJROOT)/src/sdlog.c
PROJCSRC += $(PROJROOT)/src/sqrtpatch.c
PROJCSRC += $(PROJROOT)/src/stream.c
PROJCSRC += $(PROJROOT)/src/sumd_input.c
PROJCSRC += $(PROJROOT)/src/syscalls.c
PROJCSRC += $(PROJROOT)/src/timestamp/timestamp_stm32.c
PROJCSRC += $(PROJROOT)/src/hott/sumd.c
PROJCSRC += $(PROJROOT)/src/msgbus/msgbus.c
PROJCSRC += $(PROJROOT)/src/msgbus/ports/ChibiOS/msgbus_port.c
PROJCSRC += $(PROJROOT)/src/msgbus/serialization_msgpack.c
PROJCSRC += $(PROJROOT)/src/msgbus/type_print.c
PROJCSRC += $(PROJROOT)/src/msgbus_scheduler.c
PROJCSRC += $(PROJROOT)/src/parameter/parameter.c
PROJCSRC += $(PROJROOT)/src/parameter/parameter_msgpack.c
PROJCSRC += $(PROJROOT)/src/parameter/parameter_print.c
PROJCSRC += $(PROJROOT)/src/rate_limiter.c
PROJCSRC += $(PROJROOT)/src/timestamp/timestamp.c
