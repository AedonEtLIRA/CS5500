#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/module.h>

asmlinkage int print_self(void){
        struct task_struct *task;

       // printk(KERN_INFO "Process id/pid; %d\n", current->pid);
       // printk(KERN_INFO "Name: %s\n", current->comm);
        //printk(KERN_INFO "Parent processes until init :\n");

        for (task = current; task != &init_task; task = task->parent){
                printk(KERN_INFO "%s [%d]\n",task->comm , task->pid);
        }
        return 0;
}
