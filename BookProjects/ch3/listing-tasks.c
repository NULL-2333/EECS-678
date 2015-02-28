#include <linux/sched.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init_task.h>

/* This function is called when the module is loaded. */
int simple_init(void)
{
  struct task_struct *task;
  struct list_head *list;
 /* Initial task structure */

  printk(KERN_INFO "Loading Module\n");


  /*  for_each_process(task) { // Part I
      printk(KERN_INFO "Name: %s; State: %d; Process Id: %d\n", task->comm, task->state, task->pid);
      }*/

  struct task_struck *t = &init_task;
  list_for_each(list, t->children) {
    task = list_entry(list, struct task_struct, sibling);
    printk(KERN_INFO "Name: %s; State: %ld; Process Id: %d\n", task->comm, task->state, task->pid);
  }
  return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
  printk(KERN_INFO "Removing Module\n");
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");
