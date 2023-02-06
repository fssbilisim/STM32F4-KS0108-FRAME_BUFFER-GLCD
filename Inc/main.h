/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#define DB5_Pin GPIO_PIN_2
#define DB5_GPIO_Port GPIOB
#define RS_Pin GPIO_PIN_8
#define RS_GPIO_Port GPIOE
#define RW_Pin GPIO_PIN_9
#define RW_GPIO_Port GPIOE
#define EN_Pin GPIO_PIN_10
#define EN_GPIO_Port GPIOE
#define DB0_Pin GPIO_PIN_11
#define DB0_GPIO_Port GPIOE
#define DB1_Pin GPIO_PIN_12
#define DB1_GPIO_Port GPIOE
#define DB2_Pin GPIO_PIN_13
#define DB2_GPIO_Port GPIOE
#define DB3_Pin GPIO_PIN_14
#define DB3_GPIO_Port GPIOE
#define DB4_Pin GPIO_PIN_15
#define DB4_GPIO_Port GPIOE
#define DB6_Pin GPIO_PIN_11
#define DB6_GPIO_Port GPIOB
#define DB7_Pin GPIO_PIN_12
#define DB7_GPIO_Port GPIOB
#define CS1_Pin GPIO_PIN_13
#define CS1_GPIO_Port GPIOB
#define CS2_Pin GPIO_PIN_15
#define CS2_GPIO_Port GPIOB
#define RST_Pin GPIO_PIN_8
#define RST_GPIO_Port GPIOD
#define LED_Pin GPIO_PIN_15
#define LED_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
