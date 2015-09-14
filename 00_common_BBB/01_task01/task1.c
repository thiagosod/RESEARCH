/**
 * COMPANY: NCB - Sistemas Embarcados LTDA.
 * PROJECT: Uniespaço 1 e 2
 * TITLE: Ambiente de Testes para Sistemas Operacionais de Tempo Real
 *
 * Copyright (c) 2011 NCB - Sistemas Embarcados LTDA.
 *
 * File: task1.c
 * Author: Developer1
 * Created on: Oct 28, 2011
 * Revision: Rev.0
 **/

#ifndef TASK1_C_
#define TASK1_C_

#if defined (TASK1_C_)

#include <rtems.h>
#include <inttypes.h>
#include "specific.h"


/**********************
 * RTEMS TASK 1
 */
rtems_task Task1(rtems_task_argument unused) {

  volatile uint32_t task1_wait_count = 2;

  /**********************
   * Generate a square output on ready LED
   * Manual loop-striping was applied for optimization
   */

  for(;;){
	SETIOTASK_1 
	WAIT(task1_wait_count);
	CLRALL
	WAIT(task1_wait_count);
  }

}

#else

/**********************
* Define Error
*/
#error "task1.c not defined"

#endif

#endif /* TASK1_C_ */
