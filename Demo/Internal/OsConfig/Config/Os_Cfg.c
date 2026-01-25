#include "Os_Cfg.h"
#include "Os_Task.h"

/* ==========================================
 * Task Configuration Table
 * - User configuration
 * ========================================== */

/* Stack Memory for Tasks */
static Os_StackType Stack_Init[128];
static Os_TCBType TCB_Init;

static Os_StackType Stack_Sensor[128];
static Os_TCBType TCB_Sensor;

static Os_StackType Stack_Display[128];
static Os_TCBType TCB_Display;

static Os_StackType Stack_Math[128];
static Os_TCBType TCB_Math;

static Os_StackType Stack_Control[128];
static Os_TCBType TCB_Control;

const Os_TaskConfigType Os_TaskConfig[OS_TASK_COUNT] = {
	{
		.TaskID = TASK_ID_INIT,
		.TaskFunc = Task_Init_Func,
		.TaskName = "Task_Init",
		.Priority = OS_PRIORITY_HIGH,
		.StackSize = 128,
		.StackBuffer = Stack_Init,
		.TaskBuffer = &TCB_Init,
		.AutoStart = 1
	},
	{
		.TaskID = TASK_ID_SENSOR,
		.TaskFunc = Task_Sensor,
		.TaskName = "Task_Sensor",
		.Priority = OS_PRIORITY_MEDIUM,
		.StackSize = 128,
		.StackBuffer = Stack_Sensor,
		.TaskBuffer = &TCB_Sensor,
		.AutoStart = 1
	},
	{
		.TaskID = TASK_ID_DISPLAY,
		.TaskFunc = Task_Display,
		.TaskName = "Task_Display",
		.Priority = OS_PRIORITY_MEDIUM,
		.StackSize = 128,
		.StackBuffer = Stack_Display,
		.TaskBuffer = &TCB_Display,
		.AutoStart = 1
	},
	{
		.TaskID = TASK_ID_MATH,
		.TaskFunc = Task_Math,
		.TaskName = "Task_Math",
		.Priority = OS_PRIORITY_HIGH,
		.StackSize = 128,
		.StackBuffer = Stack_Math,
		.TaskBuffer = &TCB_Math,
		.AutoStart = 1
	},
	{
		.TaskID = TASK_ID_CONTROL,
		.TaskFunc = Task_Control,
		.TaskName = "Task_Control",
		.Priority = OS_PRIORITY_HIGH,
		.StackSize = 128,
		.StackBuffer = Stack_Control,
		.TaskBuffer = &TCB_Control,
		.AutoStart = 1
	}
};

const Os_AlarmConfigType Os_AlarmConfig[OS_ALARM_COUNT] = {
		{
			.AlarmID = ALARM_ID_SENSOR,
			.Action = ALARM_ACTION_SET_EVENT,
			.TaskID = TASK_ID_SENSOR,
			.EventMask = EVT_WAKEUP
		},
		{
			.AlarmID = ALARM_ID_DISPLAY,
			.Action = ALARM_ACTION_SET_EVENT,
			.TaskID = TASK_ID_DISPLAY,
			.EventMask = EVT_WAKEUP
		},
		{
			.AlarmID = ALARM_ID_CONTROL,
			.Action = ALARM_ACTION_SET_EVENT,
			.TaskID = TASK_ID_CONTROL,
			.EventMask = EVT_WAKEUP
		}
};
