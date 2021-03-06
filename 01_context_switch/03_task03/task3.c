/**
 * COMPANY: NCB - Sistemas Embarcados LTDA.
 * PROJECT: Uniespaço 1 e 2
 * TITLE: Ambiente de Testes para Sistemas Operacionais de Tempo Real
 *
 * Copyright (c) 2011 NCB - Sistemas Embarcados LTDA.
 *
 * File: task3.c
 * Author: Developer1
 * Created on: Oct 28, 2011
 * Revision: Rev.0
 **/

#ifndef TASK3_C_
#define TASK3_C_

#if defined (TASK3_C_)

#include <rtems.h>
#include <inttypes.h>
#include "specific.h"


/**********************
 * RTEMS TASK 3
 */
rtems_task Task3(
  rtems_task_argument unused
)
{

  volatile uint32_t task3_wait_count = 2;

  /**********************
   * Generate a square output on GPIO6
   * Manual loop-striping was applied for optimization
   */
  for(;;)
  {
	  SETIOTASK_3
	  WAIT(task3_wait_count);
	  CLRALL
	  WAIT(task3_wait_count);
  }

}

#else

/**********************
* Define Error
*/
#error "task3.c not defined"

#endif

#endif /* TASK3_C_ */
