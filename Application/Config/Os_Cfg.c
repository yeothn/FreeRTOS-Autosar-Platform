#include "Os_Cfg.h"

/* ==========================================
 * Task Configuration Table
 * - User configuration
 * ========================================== */

extern void Task_Init_Func(void); // example - Init Function
extern void Task_Sensor(void);
extern void Task_Display(void);
extern void Task_Math(void);


/* Stack Memory for Tasks */
static Os_StackType Stack_Init[128];
static Os_TCBType TCB_Init;

static Os_StackType Stack_Sensor[128];
static Os_TCBType TCB_Sensor;

static Os_StackType Stack_Display[128];
static Os_TCBType TCB_Display;

static Os_StackType Stack_Math[128];
static Os_TCBType TCB_Math;

const Os_TaskConfigType Os_TaskConfig[OS_TASK_COUNT] = {
	// [0]: Init Task (Higher priority)
	{
		.TaskID = TASK_ID_INIT,
		.TaskFunc = Task_Init_Func,
		.TaskName = "Task_Init",
		.Priority = 3,
		/* Allocate Memory */
		.StackSize = 128,
		.StackBuffer = Stack_Init,
		.TaskBuffer = &TCB_Init,
		.AutoStart = 1
	},
	// [1]: Sensor Task (500ms Period)
	{
		.TaskID = TASK_ID_SENSOR,
		.TaskFunc = Task_Sensor,
		.TaskName = "Task_Sensor",
		.Priority = 3,
		/* Allocate Memory */
		.StackSize = 128,
		.StackBuffer = Stack_Sensor,
		.TaskBuffer = &TCB_Sensor,
		.AutoStart = 1
	},
	{
		.TaskID = TASK_ID_DISPLAY,
		.TaskFunc = Task_Display,
		.TaskName = "Task_Display",
		.Priority = 2,
		/* Allocate Memory */
		.StackSize = 128,
		.StackBuffer = Stack_Display,
		.TaskBuffer = &TCB_Display,
		.AutoStart = 1
	},
	{
		.TaskID = TASK_ID_MATH,
		.TaskFunc = Task_Math,
		.TaskName = "Task_Math",
		.Priority = 4,
		/* Allocate Memory */
		.StackSize = 128,
		.StackBuffer = Stack_Math,
		.TaskBuffer = &TCB_Math,
		.AutoStart = 1
	}
};

const Os_AlarmConfigType Os_AlarmConfig[OS_ALARM_COUNT] = {
		{
			.AlarmID = ALARM_ID_SENSOR,
			.Action = ALARM_ACTION_SET_EVENT,
			.TaskID = TASK_ID_SENSOR,
			.EventMask = (EventMaskType)0x01
		},
		{
			.AlarmID = ALARM_ID_DISPLAY,
			.Action = ALARM_ACTION_SET_EVENT,
			.TaskID = TASK_ID_DISPLAY,
			.EventMask = (EventMaskType)0x01
		}
};
