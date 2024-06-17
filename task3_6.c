/*
task 6: Implement  LKM a module to accept an array of integers as the command-line argument. The number of elements should be fixed (say 10) and the module should exit after printing suitable message if the number of elements passed is not equal to 10; print the integers in the array otherwise.
Author : Rohan Vartak
*/

#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/printk.h>


MODULE_LICENSE("GPL");

static int arr_argc=0;
static int myArr[5];
module_param_array(myArr,int,&arr_argc,0000);
MODULE_PARM_DESC(myArr,"this a array\n");

static int __init start(void){
	int i;
	for(i=0;i<ARRAY_SIZE(myArr);i++){
		pr_info("arr[%d] = %d\n",i,myArr[i]);
		pr_info("arg %d\n",arr_argc);
	}
return 0;
}
static void __exit stop(void){
	pr_info("exit the module\n");
}
module_init(start);
module_exit(stop);
