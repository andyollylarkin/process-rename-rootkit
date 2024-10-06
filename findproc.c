#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched/signal.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("andylarkin");
MODULE_DESCRIPTION("A simple kernel module to find a process init");
MODULE_VERSION("1.0");

static int __init find_process_init(void)
{
    struct task_struct *task;

    printk(KERN_INFO "Module initialized: Searching for process with pid 1\n");

    for_each_process(task)
    {
        if (task->pid == 1)
        {
            printk(KERN_INFO "Process 'PID: 1' found! PID: %d\nTask name: %s", task->pid, task->comm);
            strncpy(task->comm, "hacked process", TASK_COMM_LEN);
        }
    }

    return 0;
}

static void __exit find_process_exit(void)
{
    printk(KERN_INFO "Module exiting: Finished searching for init process\n");
}

module_init(find_process_init);
module_exit(find_process_exit);
