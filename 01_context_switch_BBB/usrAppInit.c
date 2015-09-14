/*
 *  COPYRIGHT (c) 1989-2012.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.org/license/LICENSE.
 */


#include "usrAppInit.h"

rtems_task Task1(rtems_task_argument unused);
rtems_task Task2(rtems_task_argument unused);
rtems_task Task3(rtems_task_argument unused);
rtems_task Task4(rtems_task_argument unused);

rtems_id   Task_id[ 4 ];   /* Task IDs Array */
rtems_name Task_name[ 4 ]; /* Task NAMES Array */

void usrAppInit(){

	Task_name[ 0 ] = rtems_build_name( 'T', 'S', 'K', '1' );
	Task_name[ 1 ] = rtems_build_name( 'T', 'S', 'K', '2' );
	Task_name[ 2 ] = rtems_build_name( 'T', 'S', 'K', '3' );
	Task_name[ 3 ] = rtems_build_name( 'T', 'S', 'K', '4' );


	rtems_task_create(Task_name[ 0 ],2,RTEMS_MINIMUM_STACK_SIZE * 2,RTEMS_PREEMPT | RTEMS_TIMESLICE | RTEMS_ASR |RTEMS_INTERRUPT_LEVEL(0),RTEMS_GLOBAL,&Task_id[ 0 ]);

	rtems_task_create(Task_name[ 1 ],2,RTEMS_MINIMUM_STACK_SIZE * 2,RTEMS_PREEMPT | RTEMS_TIMESLICE | RTEMS_ASR | RTEMS_INTERRUPT_LEVEL(0),RTEMS_GLOBAL,&Task_id[ 1 ]);

	rtems_task_create(Task_name[ 2 ],2,RTEMS_MINIMUM_STACK_SIZE * 2,RTEMS_PREEMPT | RTEMS_TIMESLICE | RTEMS_ASR | RTEMS_INTERRUPT_LEVEL(0),RTEMS_GLOBAL,&Task_id[ 2 ]);

	rtems_task_create(Task_name[ 3 ],2,RTEMS_MINIMUM_STACK_SIZE * 2,RTEMS_PREEMPT | RTEMS_TIMESLICE | RTEMS_ASR | RTEMS_INTERRUPT_LEVEL(0),RTEMS_GLOBAL,&Task_id[ 3 ]);

	printf( "[TASKS CREATED v1.0]\n" );

	rtems_task_start( Task_id[ 0 ], Task1, 0 );
	rtems_task_start( Task_id[ 1 ], Task2, 0 );
	rtems_task_start( Task_id[ 2 ], Task3, 0 );
	rtems_task_start( Task_id[ 3 ], Task4, 0 );

}
