#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/printk.h>

MODULE_LICENSE("GPL");

static int __init init_panic(void){
	printk(KERN_INFO"kernel panic\n");
	panic("kernel panic\n");

return 0;
}
static void __exit exit_panic(void){
	printk(KERN_INFO"kernel panic end\n");
}

module_init(init_panic);
module_exit(exit_panic);
