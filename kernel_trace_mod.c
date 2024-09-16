// sudo insmod trace_open.ko
// dmesg | grep trace_open
// sudo rmmod trace_open



// trace_open.c
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/kprobes.h>
#include <linux/sched.h>
#include <linux/fs.h>

// Define a kprobe structure
static struct kprobe kp = {
    .symbol_name = "do_sys_open",
};

// Function to be called when the probe is triggered
static int handler_pre(struct kprobe *p, struct pt_regs *regs) {
    // Get the filename from the register (assuming x86_64 architecture)
    char *filename = (char *)regs->di; // Register di holds the filename pointer in x86_64

    printk(KERN_INFO "do_sys_open called with filename: %s\n", filename);
    return 0; // Continue execution
}

// Initialize the module
static int __init trace_open_init(void) {
    kp.pre_handler = handler_pre;
    
    // Register the kprobe
    if (register_kprobe(&kp) < 0) {
        printk(KERN_ERR "Failed to register kprobe\n");
        return -1;
    }

    printk(KERN_INFO "Kprobe registered at %p\n", kp.addr);
    return 0;
}

// Cleanup the module
static void __exit trace_open_exit(void) {
    unregister_kprobe(&kp);
    printk(KERN_INFO "Kprobe unregistered\n");
}

module_init(trace_open_init);
module_exit(trace_open_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("A simple kernel module to trace do_sys_open");
MODULE_AUTHOR("Your Name");
