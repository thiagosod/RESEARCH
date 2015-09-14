/**
 * COMPANY: NCB - Sistemas Embarcados LTDA.
 * PROJECT: Uniespaço 1 e 2
 * TITLE: Ambiente de Testes para Sistemas Operacionais de Tempo Real
 *
 * Copyright (c) 2011 NCB - Sistemas Embarcados LTDA.
 *
 * File: task4.c
 * Author: Developer1
 * Created on: Oct 28, 2011
 * Revision: Rev.0
 **/

#ifndef TASK4_C_
#define TASK4_C_

#if defined (TASK4_C_)

#include <rtems.h>
#include <inttypes.h>
#include "specific.h"


/**********************
 * RTEMS TASK 4
 */
rtems_task Task4(
  rtems_task_argument unused
)
{

  volatile uint32_t task4_wait_count = 2;

  /**********************
   * Generate a square output on GPIO4
   * Manual loop-striping was applied for optimization
   */
  for(;;)
  {
	  SETIOTASK_4
	  WAIT(task4_wait_count);
	  CLRALL;
	  WAIT(task4_wait_count);
  }

}

#else

/**********************
* Define Error
*/
#error "task4.c not defined"

#endif

#endif /* TASK4_C_ */
