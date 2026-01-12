#include "Os_Cfg.h"

/* ==========================================
 * Task Configuration Table
 * - User configuration
 * ========================================== */

extern void Task_Init_Func(void); // example - Init Function
extern void Task_500ms(void); // example - 500ms Function


/* Stack Memory for Tasks */
static Os_StackType Stack_Init[256];
static Os_TCBType TCB_Init;

static Os_StackType Stack_500ms[256];
static Os_TCBType TCB_500ms;

const Os_TaskConfigType Os_TaskConfig[OS_TASK_COUNT] = {
	// [0]: Init Task (Higher priority)
	{
		.TaskID = TASK_ID_INIT,
		.TaskFunc = Task_Init_Func,
		.TaskName = "Task_Init",
		.Priority = 3,
		/* Allocate Memory */
		.StackSize = 256,
		.StackBuffer = Stack_Init,
		.TaskBuffer = &TCB_Init,
		.AutoStart = 1
	},
	// [1]: 100ms Task (Lower priority)
	{
		.TaskID = TASK_ID_500ms,
		.TaskFunc = Task_500ms,
		.TaskName = "Task_500ms",
		.Priority = 2,
		/* Allocate Memory */
		.StackSize = 256,
		.StackBuffer = Stack_500ms,
		.TaskBuffer = &TCB_500ms,
		.AutoStart = 1
	}
};

const Os_AlarmConfigType Os_AlarmConfig[OS_ALARM_COUNT] = {
		{
			.AlarmID = ALARM_ID_500ms,
			.Action = ALARM_ACTION_SET_EVENT,
			.TaskID = TASK_ID_500ms,
			.EventMask = (EventMaskType)0x01
		}
};
