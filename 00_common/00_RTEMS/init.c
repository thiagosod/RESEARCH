/*
 *  COPYRIGHT (c) 1989-2012.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.org/license/LICENSE.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <rtems/test.h>

#include <bsp.h> /* for device driver prototypes */

#include <stdio.h>
#include <stdlib.h>
#include "hardwareconfiguration.h"

/* forward declarations to avoid warnings */
rtems_task Init(rtems_task_argument argument);
rtems_task Task1(rtems_task_argument unused);
rtems_task Task2(rtems_task_argument unused);
rtems_task Task3(rtems_task_argument unused);
rtems_task Task4(rtems_task_argument unused);


rtems_id   Task_id[ 4 ];   /* Task IDs Array */
rtems_name Task_name[ 4 ]; /* Task NAMES Array */

void usrAppInit();

rtems_task Init(rtems_task_argument ignored) {

	
	int status;
	
	printf( "Initializing RTEMS \n" );
	initHWConfiguration();
	usrAppInit();

   	printf("Ending the RTEMS Init task.\n");
   	status = rtems_task_delete( RTEMS_SELF );    /* should not return */
   	printf( "rtems_task_delete returned with status of %d.\n", status );
   	exit( 1 );
}

#if 0
/* NOTICE: the clock driver is explicitly disabled */
#define CONFIGURE_APPLICATION_DOES_NOT_NEED_CLOCK_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER

#define CONFIGURE_MAXIMUM_TASKS            1
#define CONFIGURE_USE_DEVFS_AS_BASE_FILESYSTEM

#define CONFIGURE_RTEMS_INIT_TASKS_TABLE

#define CONFIGURE_INITIAL_EXTENSIONS RTEMS_TEST_INITIAL_EXTENSION

#define CONFIGURE_INIT
#endif

#define CONFIGURE_INIT

#define CONFIGURE_APPLICATION_NEEDS_LIBBLOCK

#define CONFIGURE_APPLICATION_NEEDS_CLOCK_DRIVER

#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER

#define CONFIGURE_MAXIMUM_TASKS             5

#define CONFIGURE_RTEMS_INIT_TASKS_TABLE

#define CONFIGURE_EXTRA_TASK_STACKS         (RTEMS_MINIMUM_STACK_SIZE * 4)

#define CONFIGURE_USE_MINIIMFS_AS_BASE_FILESYSTEM

#define CONFIGURE_MICROSECONDS_PER_TICK      500

#define CONFIGURE_TICKS_PER_TIMESLICE        20        //Default is 50


#include <rtems/confdefs.h>
