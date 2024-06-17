/*
task 2: Implement LKM  to print hostname  and email ID in the kernel logs. Name your init and cleanup functions as "start" and "stop", respectively, instead of init_module and cleanup_module .
Author: Rohan Vartak
*/

#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/printk.h>
#include<linux/module.h>
#include <linux/utsname.h>

MODULE_LICENSE("GPL");

#define email "rohan.vartak@einfochips.com"

static int __init start(void){
	struct new_utsname *uts;
	uts=utsname();
	if(uts){
       printk(KERN_INFO"hostname: %s\n",uts->nodename);
       printk(KERN_INFO"email id: %s\n",email);
	}
	return 0;
}

static void __exit stop(void){
	printk(KERN_INFO"exit");
}

module_init(start);
module_exit(stop);


