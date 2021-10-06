#ifndef FND_COM_H_
#define FND_COM_H_

#include "stm32f4xx_hal.h"
#include "mb_slave.h"
#include "mb_master.h"

//input registers address define
#define INPUT_PRE_START 0     //0-2
#define INPUT_VAL_START 3     //3
#define INPUT_NTC_START 4     //4-9
#define INPUT_SHT_START 10    //10-13
#define INPUT_DIN_START 14    //14-17
#define INPUT_FANSPD_START 18 // 18-19
#define INPUT_ID_START 20     //20
#define INPUT_AQI_START 30    //30-37

#define INPUT_FAN_PWM_CTRL_START 200 //200-201
#define INPUT_VAL_PWM_CTRL_START 202 //202
#define INPUT_RLY_DO_CTRL_START 203  //203-208
#define INPUT_STEPPER_CTRL_START 209 //209-212

//holding registers address define

extern modbus_regs sys_regs;
extern modbus_master master[2];
extern modbus_slave slaves[2];

void fnd_com_modbus_rtu_init(void);
void fnd_com_modbus_rtu_uart_idle_irq(UART_HandleTypeDef *huart);
void fnd_com_modbus_rtu_master1_read_write(void);
void fnd_com_modbus_rtu_master2_read_write(void);
void fnd_com_modbus_rtu_slave1_wait(void);
void fnd_com_modbus_rtu_slave2_wait(void);

#endif
