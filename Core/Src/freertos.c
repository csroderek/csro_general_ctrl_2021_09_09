/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "fnd_input.h"
#include "fnd_output.h"
#include "fnd_com.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for Task01 */
osThreadId_t Task01Handle;
const osThreadAttr_t Task01_attributes = {
  .name = "Task01",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime7,
};
/* Definitions for Task02 */
osThreadId_t Task02Handle;
const osThreadAttr_t Task02_attributes = {
  .name = "Task02",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime5,
};
/* Definitions for Task03 */
osThreadId_t Task03Handle;
const osThreadAttr_t Task03_attributes = {
  .name = "Task03",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime3,
};
/* Definitions for Task04 */
osThreadId_t Task04Handle;
const osThreadAttr_t Task04_attributes = {
  .name = "Task04",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime1,
};
/* Definitions for Task05 */
osThreadId_t Task05Handle;
const osThreadAttr_t Task05_attributes = {
  .name = "Task05",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityHigh7,
};
/* Definitions for Task06 */
osThreadId_t Task06Handle;
const osThreadAttr_t Task06_attributes = {
  .name = "Task06",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityHigh5,
};
/* Definitions for Task07 */
osThreadId_t Task07Handle;
const osThreadAttr_t Task07_attributes = {
  .name = "Task07",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityHigh3,
};
/* Definitions for Task08 */
osThreadId_t Task08Handle;
const osThreadAttr_t Task08_attributes = {
  .name = "Task08",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityHigh1,
};
/* Definitions for Queue01 */
osMessageQueueId_t Queue01Handle;
const osMessageQueueAttr_t Queue01_attributes = {
  .name = "Queue01"
};
/* Definitions for Queue02 */
osMessageQueueId_t Queue02Handle;
const osMessageQueueAttr_t Queue02_attributes = {
  .name = "Queue02"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartTask01(void *argument);
void StartTask02(void *argument);
void StartTask03(void *argument);
void StartTask04(void *argument);
void StartTask05(void *argument);
void StartTask06(void *argument);
void StartTask07(void *argument);
void StartTask08(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
  fnd_com_modbus_rtu_init();

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* creation of Queue01 */
  Queue01Handle = osMessageQueueNew (16, sizeof(uint16_t), &Queue01_attributes);

  /* creation of Queue02 */
  Queue02Handle = osMessageQueueNew (16, sizeof(uint16_t), &Queue02_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of Task01 */
  Task01Handle = osThreadNew(StartTask01, NULL, &Task01_attributes);

  /* creation of Task02 */
  Task02Handle = osThreadNew(StartTask02, NULL, &Task02_attributes);

  /* creation of Task03 */
  Task03Handle = osThreadNew(StartTask03, NULL, &Task03_attributes);

  /* creation of Task04 */
  Task04Handle = osThreadNew(StartTask04, NULL, &Task04_attributes);

  /* creation of Task05 */
  Task05Handle = osThreadNew(StartTask05, NULL, &Task05_attributes);

  /* creation of Task06 */
  Task06Handle = osThreadNew(StartTask06, NULL, &Task06_attributes);

  /* creation of Task07 */
  Task07Handle = osThreadNew(StartTask07, NULL, &Task07_attributes);

  /* creation of Task08 */
  Task08Handle = osThreadNew(StartTask08, NULL, &Task08_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartTask01 */
/**
  * @brief  Function implementing the Task01 thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartTask01 */
void StartTask01(void *argument)
{
  /* USER CODE BEGIN StartTask01 */
  /* Infinite loop */
  for (;;)
  {
    fnd_com_modbus_rtu_slave1_wait();
  }
  /* USER CODE END StartTask01 */
}

/* USER CODE BEGIN Header_StartTask02 */
/**
* @brief Function implementing the Task02 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask02 */
void StartTask02(void *argument)
{
  /* USER CODE BEGIN StartTask02 */
  /* Infinite loop */
  for (;;)
  {
    fnd_com_modbus_rtu_slave2_wait();
  }
  /* USER CODE END StartTask02 */
}

/* USER CODE BEGIN Header_StartTask03 */
/**
* @brief Function implementing the Task03 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask03 */
void StartTask03(void *argument)
{
  /* USER CODE BEGIN StartTask03 */
  /* Infinite loop */
  for (;;)
  {
    fnd_com_modbus_rtu_master1_read_write();
    osDelay(1000);
  }
  /* USER CODE END StartTask03 */
}

/* USER CODE BEGIN Header_StartTask04 */
/**
* @brief Function implementing the Task04 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask04 */
void StartTask04(void *argument)
{
  /* USER CODE BEGIN StartTask04 */
  /* Infinite loop */
  for (;;)
  {
    fnd_com_modbus_rtu_master2_read_write();
    osDelay(1000);
  }
  /* USER CODE END StartTask04 */
}

/* USER CODE BEGIN Header_StartTask05 */
/**
* @brief Function implementing the Task05 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask05 */
void StartTask05(void *argument)
{
  /* USER CODE BEGIN StartTask05 */
  fnd_output_stepper_init();
  /* Infinite loop */
  for (;;)
  {
    osDelay(10);
    fnd_output_stepper_10ms_tick();
  }
  /* USER CODE END StartTask05 */
}

/* USER CODE BEGIN Header_StartTask06 */
/**
* @brief Function implementing the Task06 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask06 */
void StartTask06(void *argument)
{
  /* USER CODE BEGIN StartTask06 */
  fnd_input_peripheral_init();
  fnd_output_peripheral_init();
  /* Infinite loop */
  for (;;)
  {
    osDelay(100);
    fnd_input_update_value();
    fnd_output_update_value();
  }
  /* USER CODE END StartTask06 */
}

/* USER CODE BEGIN Header_StartTask07 */
/**
* @brief Function implementing the Task07 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask07 */
void StartTask07(void *argument)
{
  /* USER CODE BEGIN StartTask07 */
  /* Infinite loop */
  for (;;)
  {
    osDelay(1000);
    fnd_input_update_sht_value();
  }
  /* USER CODE END StartTask07 */
}

/* USER CODE BEGIN Header_StartTask08 */
/**
* @brief Function implementing the Task08 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask08 */
void StartTask08(void *argument)
{
  /* USER CODE BEGIN StartTask08 */
  sys_regs.inputs[INPUT_FAN_PWM_CTRL_START + 0] = 200;
  sys_regs.inputs[INPUT_FAN_PWM_CTRL_START + 1] = 400;
  sys_regs.inputs[INPUT_VAL_PWM_CTRL_START + 0] = 800;
  /* Infinite loop */
  for (;;)
  {
    osDelay(2000);
    sys_regs.inputs[INPUT_RLY_DO_CTRL_START] = 0;
    osDelay(2000);
    sys_regs.inputs[INPUT_RLY_DO_CTRL_START] = 1;
  }
  /* USER CODE END StartTask08 */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
