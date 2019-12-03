#include <libusb-1.0/libusb.h>
#include <cassert>
#include "iostream"]


void ls_devices_pid_vid(){
    libusb_context *ctx = NULL;
    libusb_device **list = NULL;


    int rc = 0;
    ssize_t count = 0;

    rc = libusb_init(&ctx);
    assert(rc == 0);

    count = libusb_get_device_list(ctx, &list);
    assert(count > 0);

    for (size_t idx = 0; idx < count; ++idx) {
        libusb_device *device = list[idx];
        libusb_device_descriptor desc;

        rc = libusb_get_device_descriptor(device, &desc);
        assert(rc == 0);

        printf("Vendor:Device = %04x:%04x\n", desc.idVendor, desc.idProduct);
    }

    libusb_free_device_list(list, count);
    libusb_exit(ctx);
}