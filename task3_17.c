/* 
 * task 17: Implement LKM to  get a pointer to the task that is currently executing on the current CPU i.e. calculate the value of current macro.
 * Author: Rohan Vartak
 */


#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/printk.h>
#include<linux/module.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");

static int current_init(void){
        struct task_struct *current_task = current;

    printk(KERN_INFO "Current task PID: %d, Name: %s\n", current_task->pid, current_task->comm);

    return 0;
}   

static void current_exit(void){
        printk(KERN_INFO"exiting module\n");
}       

module_init(current_init);
module_exit(current_exit);


