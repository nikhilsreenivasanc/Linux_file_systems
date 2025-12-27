#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/err.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>  // for copy_from_user, copy_to_user

#define BUF_SIZE 128

static dev_t dev = 0;
static struct class *dev_class = NULL;
static struct cdev my_cdev;

static char kernel_buffer[BUF_SIZE];
static size_t data_len = 0;

/* Prototypes */
static int my_open(struct inode *inode, struct file *file);
static int my_release(struct inode *inode, struct file *file);
static ssize_t my_read(struct file *file, char __user *ubuf, size_t count, loff_t *ppos);
static ssize_t my_write(struct file *file, const char __user *ubuf, size_t count, loff_t *ppos);

/* File ops struct */
static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = my_open,
    .release = my_release,
    .read = my_read,
    .write = my_write,
};

static int __init my_init(void)
{
    /* 1. allocate device number */
    if (alloc_chrdev_region(&dev, 0, 1, "etx_Dev") < 0) {
        pr_err("Cannot allocate major number\n");
        return -1;
    }
    pr_info("Major = %d Minor = %d\n", MAJOR(dev), MINOR(dev));

    /* 2. initialize cdev */
    cdev_init(&my_cdev, &fops);

    /* 3. add cdev */
    if (cdev_add(&my_cdev, dev, 1) < 0) {
        pr_err("Cannot add the device to system\n");
        unregister_chrdev_region(dev, 1);
        return -1;
    }

    /* 4. create class */
    dev_class = class_create("etx_class");
    if (IS_ERR(dev_class)) {
        pr_err("Cannot create class\n");
        cdev_del(&my_cdev);
        unregister_chrdev_region(dev, 1);
        return PTR_ERR(dev_class);
    }

    /* 5. create device file /dev/etx_device */
    if (IS_ERR(device_create(dev_class, NULL, dev, NULL, "etx_device"))) {
        pr_err("Cannot create device file\n");
        class_destroy(dev_class);
        cdev_del(&my_cdev);
        unregister_chrdev_region(dev, 1);
        return -1;
    }

    pr_info("Module inserted successfully\n");
    return 0;
}

static void __exit my_exit(void)
{
    device_destroy(dev_class, dev);
    class_destroy(dev_class);
    cdev_del(&my_cdev);
    unregister_chrdev_region(dev, 1);
    pr_info("Module removed\n");
}

/* Called when /dev/etx_device is opened */
static int my_open(struct inode *inode, struct file *file)
{
    pr_info("Device open\n");
    return 0;
}

/* Called when /dev/etx_device is closed */
static int my_release(struct inode *inode, struct file *file)
{
    pr_info("Device close\n");
    return 0;
}

/* Read: copy data from kernel_buffer to user */
static ssize_t my_read(struct file *file, char __user *ubuf, size_t count, loff_t *ppos)
{
    size_t to_copy;

    if (*ppos >= data_len) {
        return 0;  // EOF
    }

    to_copy = min(count, data_len - *ppos);
    if (copy_to_user(ubuf, kernel_buffer + *ppos, to_copy) > 0) {
        pr_err("copy_to_user failed\n");
        return -EFAULT;
    }
    *ppos += to_copy;

    pr_info("Read %zu bytes, pos = %lld\n", to_copy, *ppos);
    return to_copy;
}

/* Write: copy data from user to kernel_buffer */
static ssize_t my_write(struct file *file, const char __user *ubuf, size_t count, loff_t *ppos)
{
    size_t to_copy;

    /* Limit to buffer */
    to_copy = min(count, BUF_SIZE - 1);  // leave space for NUL
    if (copy_from_user(kernel_buffer, ubuf, to_copy) > 0) {
        pr_err("copy_from_user failed\n");
        return -EFAULT;
    }
    kernel_buffer[to_copy] = '\0';   // null-terminate
    data_len = to_copy;
    *ppos += to_copy;

    pr_info("Write %zu bytes, data = %s\n", to_copy, kernel_buffer);
    return to_copy;
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Char driver with read/write example");
