/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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
#define Vcp2_Pin GPIO_PIN_0
#define Vcp2_GPIO_Port GPIOA
#define MS1B_Pin GPIO_PIN_1
#define MS1B_GPIO_Port GPIOA
#define MS2B_Pin GPIO_PIN_2
#define MS2B_GPIO_Port GPIOA
#define STNDBY2_Pin GPIO_PIN_3
#define STNDBY2_GPIO_Port GPIOA
#define DIR2_Pin GPIO_PIN_4
#define DIR2_GPIO_Port GPIOA
#define STEP2_Pin GPIO_PIN_5
#define STEP2_GPIO_Port GPIOA
#define VCC_IO2_Pin GPIO_PIN_6
#define VCC_IO2_GPIO_Port GPIOA
#define SPREAD2_Pin GPIO_PIN_7
#define SPREAD2_GPIO_Port GPIOA
#define D2_Pin GPIO_PIN_0
#define D2_GPIO_Port GPIOB
#define STEP_Pin GPIO_PIN_1
#define STEP_GPIO_Port GPIOB
#define DIR_Pin GPIO_PIN_2
#define DIR_GPIO_Port GPIOB
#define MS1A_Pin GPIO_PIN_12
#define MS1A_GPIO_Port GPIOB
#define MS2A_Pin GPIO_PIN_13
#define MS2A_GPIO_Port GPIOB
#define VCC_IO_Pin GPIO_PIN_14
#define VCC_IO_GPIO_Port GPIOB
#define ISR1_Pin GPIO_PIN_15
#define ISR1_GPIO_Port GPIOB
#define ISR2_Pin GPIO_PIN_8
#define ISR2_GPIO_Port GPIOA
#define USB_D__Pin GPIO_PIN_11
#define USB_D__GPIO_Port GPIOA
#define USB_D_A12_Pin GPIO_PIN_12
#define USB_D_A12_GPIO_Port GPIOA
#define Vref_Pin GPIO_PIN_3
#define Vref_GPIO_Port GPIOB
#define SPREAD1_Pin GPIO_PIN_4
#define SPREAD1_GPIO_Port GPIOB
#define STNDBY_Pin GPIO_PIN_9
#define STNDBY_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
