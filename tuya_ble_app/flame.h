#ifndef FLAME_H_
#define FLAME_H_

#include "tuya_ble_common.h"
#include "tuya_ble_log.h"

#define SENSOR_PIN		GPIO_PB4
#define ALARM		1
#define NORMAL 		0

void flame_init(void);
void flame_fun(void);

#endif
