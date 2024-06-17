#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/printk.h>
#include<linux/module.h>

MODULE_LICENSE("GPL");

static int __init init_hello(void){
       printk(KERN_INFO"hello world");
	return 0;
}

static void __exit exit_hello(void){
	printk(KERN_INFO"End hello world");
}

module_init(init_hello);
module_exit(exit_hello);


