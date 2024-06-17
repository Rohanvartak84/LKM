#include<linux/printk.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>
MODULE_LICENSE("GPL");

static int __init start(void){
	printk(KERN_EMERG"emergency\n");
	printk(KERN_ALERT"ALERT!\n");
	printk(KERN_CRIT"CRITICAL\n");
	printk(KERN_ERR"ERROR\n");
	printk(KERN_WARNING"WARNING!\n");
	printk(KERN_NOTICE"NOTICE\n");
	printk(KERN_DEBUG"DEBUG\n");

	return 0;
}
static void __exit stop(void){
	printk(KERN_INFO"exit\n");
}
module_init(start);
module_exit(stop);
