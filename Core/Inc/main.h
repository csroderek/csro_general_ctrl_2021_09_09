/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define RLY2_Pin GPIO_PIN_2
#define RLY2_GPIO_Port GPIOE
#define RLY1_Pin GPIO_PIN_3
#define RLY1_GPIO_Port GPIOE
#define STEP_A8_Pin GPIO_PIN_4
#define STEP_A8_GPIO_Port GPIOE
#define STEP_A7_Pin GPIO_PIN_5
#define STEP_A7_GPIO_Port GPIOE
#define STEP_A6_Pin GPIO_PIN_6
#define STEP_A6_GPIO_Port GPIOE
#define STEP_A5_Pin GPIO_PIN_13
#define STEP_A5_GPIO_Port GPIOC
#define STEP_A4_Pin GPIO_PIN_14
#define STEP_A4_GPIO_Port GPIOC
#define STEP_A3_Pin GPIO_PIN_15
#define STEP_A3_GPIO_Port GPIOC
#define DP_VF3_Pin GPIO_PIN_0
#define DP_VF3_GPIO_Port GPIOC
#define DP_VF2_Pin GPIO_PIN_2
#define DP_VF2_GPIO_Port GPIOC
#define DP_VF1_Pin GPIO_PIN_3
#define DP_VF1_GPIO_Port GPIOC
#define NTC_VF1_Pin GPIO_PIN_0
#define NTC_VF1_GPIO_Port GPIOA
#define NTC_VF2_Pin GPIO_PIN_3
#define NTC_VF2_GPIO_Port GPIOA
#define NTC_VF3_Pin GPIO_PIN_4
#define NTC_VF3_GPIO_Port GPIOA
#define NTC_VF4_Pin GPIO_PIN_5
#define NTC_VF4_GPIO_Port GPIOA
#define NTC_VF5_Pin GPIO_PIN_6
#define NTC_VF5_GPIO_Port GPIOA
#define NTC_VF6_Pin GPIO_PIN_0
#define NTC_VF6_GPIO_Port GPIOB
#define VALVE_FEEDBACK_Pin GPIO_PIN_1
#define VALVE_FEEDBACK_GPIO_Port GPIOB
#define STEP_A2_Pin GPIO_PIN_2
#define STEP_A2_GPIO_Port GPIOB
#define STEP_A1_Pin GPIO_PIN_7
#define STEP_A1_GPIO_Port GPIOE
#define STEP_B8_Pin GPIO_PIN_8
#define STEP_B8_GPIO_Port GPIOE
#define FAN1_PWM_Pin GPIO_PIN_9
#define FAN1_PWM_GPIO_Port GPIOE
#define STEP_B7_Pin GPIO_PIN_10
#define STEP_B7_GPIO_Port GPIOE
#define FAN2_PWM_Pin GPIO_PIN_11
#define FAN2_PWM_GPIO_Port GPIOE
#define STEP_B6_Pin GPIO_PIN_12
#define STEP_B6_GPIO_Port GPIOE
#define STEP_B5_Pin GPIO_PIN_13
#define STEP_B5_GPIO_Port GPIOE
#define STEP_B4_Pin GPIO_PIN_14
#define STEP_B4_GPIO_Port GPIOE
#define STEP_B3_Pin GPIO_PIN_15
#define STEP_B3_GPIO_Port GPIOE
#define STEP_B2_Pin GPIO_PIN_10
#define STEP_B2_GPIO_Port GPIOB
#define RSTN_Pin GPIO_PIN_14
#define RSTN_GPIO_Port GPIOB
#define EN3_Pin GPIO_PIN_15
#define EN3_GPIO_Port GPIOB
#define STEP_B1_Pin GPIO_PIN_10
#define STEP_B1_GPIO_Port GPIOD
#define DI1_Pin GPIO_PIN_11
#define DI1_GPIO_Port GPIOD
#define DI2_Pin GPIO_PIN_12
#define DI2_GPIO_Port GPIOD
#define DI3_Pin GPIO_PIN_13
#define DI3_GPIO_Port GPIOD
#define DI4_Pin GPIO_PIN_14
#define DI4_GPIO_Port GPIOD
#define EN4_Pin GPIO_PIN_15
#define EN4_GPIO_Port GPIOD
#define EN1_Pin GPIO_PIN_11
#define EN1_GPIO_Port GPIOA
#define IDA4_Pin GPIO_PIN_15
#define IDA4_GPIO_Port GPIOA
#define IDA3_Pin GPIO_PIN_10
#define IDA3_GPIO_Port GPIOC
#define IDA2_Pin GPIO_PIN_11
#define IDA2_GPIO_Port GPIOC
#define IDA1_Pin GPIO_PIN_12
#define IDA1_GPIO_Port GPIOC
#define IDB4_Pin GPIO_PIN_0
#define IDB4_GPIO_Port GPIOD
#define IDB3_Pin GPIO_PIN_1
#define IDB3_GPIO_Port GPIOD
#define IDB2_Pin GPIO_PIN_2
#define IDB2_GPIO_Port GPIOD
#define IDB3D3_Pin GPIO_PIN_3
#define IDB3D3_GPIO_Port GPIOD
#define EN2_Pin GPIO_PIN_4
#define EN2_GPIO_Port GPIOD
#define VALVE_PWM_Pin GPIO_PIN_3
#define VALVE_PWM_GPIO_Port GPIOB
#define FAN1_SPD_Pin GPIO_PIN_4
#define FAN1_SPD_GPIO_Port GPIOB
#define FAN2_SPD_Pin GPIO_PIN_5
#define FAN2_SPD_GPIO_Port GPIOB
#define RLY6_Pin GPIO_PIN_8
#define RLY6_GPIO_Port GPIOB
#define RLY5_Pin GPIO_PIN_9
#define RLY5_GPIO_Port GPIOB
#define RLY4_Pin GPIO_PIN_0
#define RLY4_GPIO_Port GPIOE
#define RLY3_Pin GPIO_PIN_1
#define RLY3_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
