/**
 * COMPANY: NCB - Sistemas Embarcados LTDA.
 * PROJECT: Uniespaço 1 e 2
 * TITLE: Ambiente de Testes para Sistemas Operacionais de Tempo Real
 *
 * Copyright (c) 2011 NCB - Sistemas Embarcados LTDA.
 *
 * File: task2.c
 * Author: Developer1
 * Created on: Oct 28, 2011
 * Revision: Rev.0
 **/

#ifndef TASK2_C_
#define TASK2_C_

#if defined (TASK2_C_)

#include <rtems.h>
#include <inttypes.h>
#include "specific.h"


/**********************
 * RTEMS TASK 2
 */
rtems_task Task2(
  rtems_task_argument unused
)
{

  volatile uint32_t task2_wait_count = 2;

  /**********************
   * Generate a square output on GPIO5
   * Manual loop-striping was applied for optimization
   */
  for(;;)
  {
	  SETIOTASK_2
	  WAIT(task2_wait_count);
	  CLRALL
	  WAIT(task2_wait_count);
  }

}

#else

/**********************
* Define Error
*/
#error "task2.c not defined"

#endif

#endif /* TASK2_C_ */
