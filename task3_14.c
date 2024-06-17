#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/time.h>
#include<linux/timekeeping.h>

MODULE_LICENSE("GPL");

static int __init start(void){
	
	printk(KERN_INFO"===========TASK 14==========\n");

	struct timespec64 ts;
	struct tm tm;

	ktime_get_real_ts64(&ts);
	time64_to_tm(ts.tv_sec,0,&tm);

	printk(KERN_INFO" %4ld : %2d : %2d : %2d : %2d : %2d",tm.tm_year+1900,tm.tm_mon+1,tm.tm_mday,tm.tm_hour,tm.tm_min,tm.tm_sec);

	return 0;
}

static void __exit stop(void){
	printk(KERN_INFO"exit module\n");
}

module_init(start);
module_exit(stop);                              
