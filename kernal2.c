// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Simple HID example for Dell USB mouse
 */

#include <linux/module.h>
#include <linux/hid.h>

static int generic_probe(struct hid_device *hdev,
                         const struct hid_device_id *id)
{
    int ret;

    ret = hid_parse(hdev);
    if (ret) {
        hid_err(hdev, "parse failed\n");
        return ret;
    }

    ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT);
    if (ret) {
        hid_err(hdev, "hw start failed\n");
        return ret;
    }

    printk(KERN_INFO "Custom HID driver bound to Dell MS116 mouse\n");
    return 0;
}

static void generic_remove(struct hid_device *hdev)
{
    hid_hw_stop(hdev);
    printk(KERN_INFO "Custom HID driver removed\n");
}

/* Hardcoded IDs for Dell MS116 USB mouse */
static const struct hid_device_id generic_devices[] = {
    { HID_USB_DEVICE(0x412c, 0x301a) },   /* Dell MS116 Optical Mouse */
    { } /* terminating entry */
};
MODULE_DEVICE_TABLE(hid, generic_devices);

static struct hid_driver generic_driver = {
    //.name       = "my-hid-generic",
    .name       = "my-hid-generic",
    .id_table   = generic_devices,
    .probe      = generic_probe,
    .remove     = generic_remove,
};
module_hid_driver(generic_driver);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("xeedo");
MODULE_DESCRIPTION("Custom HID driver for Dell mouse");
