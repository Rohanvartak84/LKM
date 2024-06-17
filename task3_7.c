/*
task 7: Extend above LKM to Sort the integers in decreasing order and print them. Define your own function or find & use the one available in Linux  headers.
Author : Rohan Vartak
*/

#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/moduleparam.h>
#define ARR_SIZE 5

MODULE_LICENSE("GPL");


static int num_elements=0;
static int arr[ARR_SIZE];

module_param_array(arr,int,&num_elements,0000);
MODULE_PARM_DESC(arr,"this a array\n");

int __init sort_init(void){
	//module_param_array(arr,int,&num_elements,0);
//	MODULE_PARM_DESC(arr,"this a array\n");

	for(int i=0;i<ARR_SIZE;i++)
		printk(KERN_INFO"arr[%d] : %d\n",i,arr[i]);

	for(int i=0;i<ARR_SIZE-1;i++){
		for(int j=0;j<ARR_SIZE-i-1;j++){
			if(arr[j]<arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}

	for(int i=0;i<ARR_SIZE;i++)
                printk(KERN_INFO"arr[%d] : %d\n",i,arr[i]);


		
return 0;
}

void __exit sort_exit(void){
	printk(KERN_INFO"sort module end\n");
}

module_init(sort_init);
module_exit(sort_exit);
