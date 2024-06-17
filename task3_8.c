/*
task 8: Implement LKM to create and manipulate a kernel linked list. Use the struct definition given below for the linked list node. Your module should take a number from the command-line which will specify the number of nodes to add in the linked list.
Author : Rohan Vartak
*/

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/random.h>

MODULE_LICENSE("GPL");

static int num_nodes;
module_param(num_nodes, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(num_nodes, "Number of nodes to add to the linked list");

struct my_node {
	int num;     
	int sqrt;    
	struct my_node *next; 
};

struct my_node *head = NULL;

static int compute_sqrt(int num) {
	int sqrt = 0; 
	while (sqrt * sqrt <= num) { 
		sqrt++;
	}
	return sqrt - 1;  
}

static void add_node(int num) {
	struct my_node *new_node;
	struct my_node *temp;

	new_node = kmalloc(sizeof(struct my_node), GFP_KERNEL);
	if (!new_node) {
		printk(KERN_ALERT "Memory allocation failed\n");
		return;
	}

	new_node->num = num;
	new_node->sqrt = compute_sqrt(num);
	new_node->next = NULL;

	if (!head) {
		head = new_node;
	} else {
		temp = head;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = new_node;
	}
}

static void print_list_reverse(struct my_node *node) {
	if (!node) return;
	print_list_reverse(node->next);
	printk(KERN_INFO "Node num: %d, sqrt: %d\n", node->num, node->sqrt);
}

static void free_list(void) {
	struct my_node *temp;
	struct my_node *next;

	temp = head;
	while (temp) {
		next = temp->next;
		kfree(temp);
		temp = next;
	}
	head = NULL;
}

static void print_list(void){
	struct my_node *temp=head;
	while(temp->next){
		printk(KERN_INFO"Node num: %d,sqrt: %d\n",temp->num,temp->sqrt);
		temp=temp->next;
	}
	printk(KERN_INFO"Node num: %d,sqrt: %d\n",temp->num,temp->sqrt);
}

static int __init start(void) {
	int i, random_num;
	printk(KERN_INFO "Initializing linked list module with %d nodes\n", num_nodes);

	for (i = 0; i < num_nodes; i++) {
		get_random_bytes(&random_num, sizeof(int)); 
		random_num = random_num < 0 ? -random_num : random_num;
		random_num = random_num % 100;
		add_node(random_num);
	}

	printk(KERN_INFO "linked list before\n");
	print_list();

	printk(KERN_INFO "linked list after\n");
	print_list_reverse(head); 

	return 0;

}
static void __exit stop(void){
	printk(KERN_INFO "Cleaning up module and freeing memory\n");
	free_list();                                                                                      
	printk(KERN_INFO "Module cleanup complete\n");
}

module_init(start);
module_exit(stop);

