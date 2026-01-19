#include "Os_Cfg.h"
#include "Os_Task.h"

/* ==========================================
 * Task Configuration Table
 * - User configuration
 * ========================================== */

/* Stack Memory for Tasks */
static Os_StackType Stack_Init[128];
static Os_TCBType TCB_Init;

static Os_StackType Stack_10ms[256];
static Os_TCBType TCB_10ms;

static Os_StackType Stack_50ms[128];
static Os_TCBType TCB_50ms;

static Os_StackType Stack_100ms[128];
static Os_TCBType TCB_100ms;

/* Task Configuration Table */
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
		.TaskID = TASK_ID_10ms,
		.TaskFunc = Task_10ms,
		.TaskName = "Task_10ms",
		.Priority = OS_PRIORITY_HIGH,
		.StackSize = 256,
		.StackBuffer = Stack_10ms,
		.TaskBuffer = &TCB_10ms,
		.AutoStart = 1
	},
	{
		.TaskID = TASK_ID_50ms,
		.TaskFunc = Task_50ms,
		.TaskName = "Task_50ms",
		.Priority = OS_PRIORITY_MEDIUM,
		.StackSize = 128,
		.StackBuffer = Stack_50ms,
		.TaskBuffer = &TCB_50ms,
		.AutoStart = 1
	},
	{
		.TaskID = TASK_ID_100ms,
		.TaskFunc = Task_100ms,
		.TaskName = "Task_100ms",
		.Priority = OS_PRIORITY_LOWEST,
		.StackSize = 128,
		.StackBuffer = Stack_100ms,
		.TaskBuffer = &TCB_100ms,
		.AutoStart = 1
	}
};

const Os_AlarmConfigType Os_AlarmConfig[OS_ALARM_COUNT] = {
		{
			.AlarmID = ALARM_ID_10ms,
			.Action = ALARM_ACTION_SET_EVENT,
			.TaskID = TASK_ID_10ms,
			.EventMask = EVT_WAKEUP
		},
		{
			.AlarmID = ALARM_ID_50ms,
			.Action = ALARM_ACTION_SET_EVENT,
			.TaskID = TASK_ID_50ms,
			.EventMask = EVT_WAKEUP
		},
		{
			.AlarmID = ALARM_ID_100ms,
			.Action = ALARM_ACTION_SET_EVENT,
			.TaskID = TASK_ID_100ms,
			.EventMask = EVT_WAKEUP
		}
};
