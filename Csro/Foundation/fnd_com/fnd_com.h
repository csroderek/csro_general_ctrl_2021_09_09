#ifndef FND_COM_H_
#define FND_COM_H_

#include "stm32f4xx_hal.h"
#include "mb_slave.h"

//input registers address define
#define INPUT_PRE_START 0     //0-2
#define INPUT_VAL_START 3     //3
#define INPUT_NTC_START 4     //4-9
#define INPUT_SHT_START 10    //10-13
#define INPUT_DIN_START 14    //14-17
#define INPUT_FANSPD_START 18 // 18-19
#define INPUT_ID_START 20

#define INPUT_FAN_PWM_CTRL_START 30 //30-31
#define INPUT_VAL_PWM_CTRL_START 32 //32
#define INPUT_RLY_DO_CTRL_START 33  //33-38
#define INPUT_STEPPER_CTRL_START 39 //39-42

//holding registers address define

extern modbus_slave slaves[3];
extern modbus_regs sys_regs;

void fnd_com_modbus_rtu_init(void);
void fnd_com_modbus_rtu_uart_idle_irq(UART_HandleTypeDef *huart);
void fnd_com_modbus_rtu_slave1_wait(void);
void fnd_com_modbus_rtu_slave2_wait(void);

#endif
