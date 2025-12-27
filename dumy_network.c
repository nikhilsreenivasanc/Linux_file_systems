// dummy_e1000e.c
// Minimal demo net driver that binds to Intel I219-LM (8086:15d7)
// WARNING: This will claim the real NIC if loaded. Use with caution.

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/pci.h>
#include <linux/netdevice.h>
#include <linux/etherdevice.h>

#define DRV_NAME "dummy_e1000e"

/* PCI ID for Intel I219-LM (example) */
static const struct pci_device_id dummy_pci_tbl[] = {
    { PCI_DEVICE(0x8086, 0x15d7) }, /* Intel I219-LM */
    { 0, }
};
MODULE_DEVICE_TABLE(pci, dummy_pci_tbl);

struct dummy_priv {
    struct net_device *netdev;
    struct pci_dev *pdev;
};

static netdev_tx_t dummy_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
    struct net_device_stats *stats = &dev->stats;

    /* Simulate immediate transmission: update stats and free skb */
    stats->tx_packets++;
    stats->tx_bytes += skb->len;

    dev_kfree_skb(skb);
    return NETDEV_TX_OK;
}

static int dummy_open(struct net_device *dev)
{
    netif_start_queue(dev);
    printk(KERN_INFO "%s: device opened\n", dev->name);
    return 0;
}

static int dummy_stop(struct net_device *dev)
{
    netif_stop_queue(dev);
    printk(KERN_INFO "%s: device stopped\n", dev->name);
    return 0;
}

static const struct net_device_ops dummy_netdev_ops = {
    .ndo_open       = dummy_open,
    .ndo_stop       = dummy_stop,
    .ndo_start_xmit = dummy_start_xmit,
};

static int dummy_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
    int err;
    struct net_device *netdev;
    struct dummy_priv *priv;

    err = pci_enable_device(pdev);
    if (err) {
        dev_err(&pdev->dev, "pci_enable_device failed\n");
        return err;
    }

    netdev = alloc_etherdev(sizeof(struct dummy_priv));
    if (!netdev) {
        pci_disable_device(pdev);
        return -ENOMEM;
    }

    priv = netdev_priv(netdev);
    priv->netdev = netdev;
    priv->pdev = pdev;

    /* Setup netdev */
    ether_setup(netdev);
    netdev->netdev_ops = &dummy_netdev_ops;
    netdev->flags |= IFF_BROADCAST | IFF_MULTICAST;
    memcpy(netdev->dev_addr, "\x02\x00\x00\x00\x00\x01", ETH_ALEN); /* locally administered MAC */

    pci_set_drvdata(pdev, priv);

    if (register_netdev(netdev)) {
        dev_err(&pdev->dev, "register_netdev failed\n");
        free_netdev(netdev);
        pci_disable_device(pdev);
        return -ENODEV;
    }

    dev_info(&pdev->dev, "%s: registered netdev %s\n", DRV_NAME, netdev->name);
    return 0;
}

static void dummy_remove(struct pci_dev *pdev)
{
    struct dummy_priv *priv = pci_get_drvdata(pdev);
    if (!priv) return;

    unregister_netdev(priv->netdev);
    free_netdev(priv->netdev);
    pci_disable_device(pdev);
    dev_info(&pdev->dev, "%s: removed\n", DRV_NAME);
}

static struct pci_driver dummy_driver = {
    .name = DRV_NAME,
    .id_table = dummy_pci_tbl,
    .probe = dummy_probe,
    .remove = dummy_remove,
};

module_pci_driver(dummy_driver);

MODULE_AUTHOR("ChatGPT Demo");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Minimal demo driver for Intel I219-LM (non-functional hardware emulation)");
