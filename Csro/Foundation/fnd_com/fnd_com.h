#ifndef FND_COM_H_
#define FND_COM_H_

#include "stm32f4xx_hal.h"
#include "mb_slave.h"

//input registers address define
#define INPUT_NTC_START 0
#define INPUT_RHI_START 4
#define INPUT_VAL_START 8
#define INPUT_SHT_START 10
#define INPUT_DIN_START 14
#define INPUT_SPD_START 18

#define INPUT_VOLT_CTRL_START 20
#define INPUT_PWM_CTRL_START 22
#define INPUT_DOUT_CTRL_START 24

//holding registers address define

extern modbus_slave slaves[3];
extern modbus_regs sys_regs;

void fnd_com_modbus_rtu_init(void);
void fnd_com_modbus_rtu_uart_idle_irq(UART_HandleTypeDef *huart);
void fnd_com_modbus_rtu_slave1_wait(void);
void fnd_com_modbus_rtu_slave2_wait(void);
void fnd_com_modbus_rtu_slave3_wait(void);

#endif
