/*
 * task 13: Implement LKM and make it persistent, i.e. it should automatically load on system boot. Reboot and check if it is loaded using lsmod .
 * Author : Rohan Vartak
 */

#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/printk.h>

MODULE_LICENSE("GPL");

static int start(void){
	printk(KERN_INFO"hello world\n");
	return 0;
}

static void stop(void){
	printk(KERN_INFO"goodbye world\n");
}

module_init(start);
module_exit(stop);
