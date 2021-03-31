#include "flame.h"

#define 	TIME_MS		1000
#define		BUF_LEN		(sizeof(DP_buf) / sizeof(DP_buf[0]))

unsigned long sys_time = 0;
uint8_t DP_buf[4] = {0x65, 0x01, 0x01, 0x00}; //{DP_ID, DP_type, DP_len, DP_data}

void flame_init(void)
{
    gpio_set_func(SENSOR_PIN, AS_GPIO);
    gpio_set_input_en(SENSOR_PIN, 1);
}

void flame_fun(void)
{
	if(!clock_time_exceed(sys_time, 1000 * TIME_MS)){
		return;
	}
	sys_time = clock_time();

	if(gpio_read(SENSOR_PIN) == FALSE) {
		DP_buf[3] = ALARM;
		TUYA_APP_LOG_INFO("flame_alarm");
		tuya_ble_dp_data_report(DP_buf, BUF_LEN);
	} else {
		DP_buf[3] = NORMAL;
		TUYA_APP_LOG_INFO("no_flame");
		tuya_ble_dp_data_report(DP_buf, BUF_LEN);
	}

}
