#include "fnd_com.h"
#include "usart.h"
#include "gpio.h"

modbus_port port[4] = {{&huart1,
                        EN1_GPIO_Port,
                        EN1_Pin},
                       {&huart2,
                        EN2_GPIO_Port,
                        EN2_Pin},
                       {&huart3,
                        EN3_GPIO_Port,
                        EN3_Pin},
                       {&huart6,
                        EN4_GPIO_Port,
                        EN4_Pin}};
modbus_regs sys_regs;
modbus_master master[2];
modbus_slave slaves[2];

void fnd_com_modbus_rtu_init(void)
{
    master_init(&master[0], &port[0], 21);
    master_init(&master[1], &port[1], 21);
    slave_init(&slaves[0], &port[2], 1, &sys_regs);
    slave_init(&slaves[1], &port[3], 2, &sys_regs);
}
void fnd_com_modbus_rtu_uart_idle_irq(UART_HandleTypeDef *huart)
{
    if (huart == master[0].uart_port->uart)
    {
        master_uart_idle(&master[0]);
    }
    else if (huart == master[1].uart_port->uart)
    {
        master_uart_idle(&master[1]);
    }
    else if (huart == slaves[0].uart_port->uart)
    {
        slave_uart_idle(&slaves[0]);
    }
    else if (huart == slaves[1].uart_port->uart)
    {
        slave_uart_idle(&slaves[1]);
    }
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart == master[0].uart_port->uart)
    {
        master_set_tx_rx(&master[0], rx);
    }
    else if (huart == master[1].uart_port->uart)
    {
        master_set_tx_rx(&master[1], rx);
    }
    if (huart == slaves[0].uart_port->uart)
    {
        slave_set_tx_rx(&slaves[0], rx);
    }
    else if (huart == slaves[1].uart_port->uart)
    {
        slave_set_tx_rx(&slaves[1], rx);
    }
}

void fnd_com_modbus_rtu_master1_read_write(void)
{
    //master_read_holding_regs(&master[0], 100, 8, &sys_regs.inputs[INPUT_AQI_START]);
}

void fnd_com_modbus_rtu_master2_read_write(void)
{
    master_read_holding_regs(&master[1], 100, 8, &sys_regs.inputs[INPUT_AQI_START]);
}

void fnd_com_modbus_rtu_slave1_wait(void)
{
    slave_wait_request(&slaves[0]);
}
void fnd_com_modbus_rtu_slave2_wait(void)
{
    slave_wait_request(&slaves[1]);
}
