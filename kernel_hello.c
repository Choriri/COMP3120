#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int __init init_hello(void){
	printk("[COMP3120] Hi, I am Eunhye!\n");
	printk("[COMP312p] I am now on 4.9.70!\n");
	return 0;
}

static void __exit exit_hello(void){
	printk("[COMP3120] bye. This is over. See you next time.\n");
}

module_init(init_hello);
module_exit(exit_hello);
MODULE_LICENSE("GPL");
