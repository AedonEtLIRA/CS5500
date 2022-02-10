#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/module.h>

int init_module(void){
        struct task_struct *task;

        printk(KERN_INFO "Process id/pid; %d\n", current->pid);
        printk(KERN_INFO "Running state; ");

        switch(current->state){
                case -1 :
                        printk("Unrunnable\n");
                        break;
                case 0 :
                        printk("Runnable\n");
                        break;
                default :
                        printk("Stopped\n");
                        break;
        }
        printk(KERN_INFO "Name: %s\n", current->comm);
        printk(KERN_INFO "Parent processes until init :\n");

        for(task=current;task!=&init_task;task=task->parent){
                printk(KERN_INFO "%s [%d]\n",task->comm , task->pid);
        }
        printk(KERN_INFO "Start time: %llu\n", (unsigned long long)current->se.exec_start);
        printk(KERN_INFO "Virtual runtime: %llu", (unsigned long long)current->se.vruntime);
        return 0;
}
void cleanup_module(void){
        printk(KERN_INFO "Cleaning Up.\n");
}
asmlinkage int print_self(void){
        init_module();
        cleanup_module();
        return 1;
}
