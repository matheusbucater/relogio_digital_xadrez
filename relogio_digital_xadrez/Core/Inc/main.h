/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#define SCL1_Pin GPIO_PIN_10
#define SCL1_GPIO_Port GPIOB
#define buzzer_Pin GPIO_PIN_9
#define buzzer_GPIO_Port GPIOA
#define player2_button_Pin GPIO_PIN_10
#define player2_button_GPIO_Port GPIOA
#define player1_button_Pin GPIO_PIN_11
#define player1_button_GPIO_Port GPIOA
#define reset_match_button_Pin GPIO_PIN_12
#define reset_match_button_GPIO_Port GPIOA
#define SDA1_Pin GPIO_PIN_3
#define SDA1_GPIO_Port GPIOB
#define SCL2_Pin GPIO_PIN_6
#define SCL2_GPIO_Port GPIOB
#define SDA2_Pin GPIO_PIN_7
#define SDA2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
