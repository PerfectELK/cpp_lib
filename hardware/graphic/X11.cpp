#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>
#include <unistd.h>

using namespace std;

union mem {
public:
    int *pointer = nullptr;
} m;

struct hwc {
public:
    int h = 0;
    int w = 0;
    int c = 3;
} _hwc_;



extern "C" int* getScreenShot() {

    Display *display = XOpenDisplay(NULL);
    Window root = DefaultRootWindow(display);
    XWindowAttributes gwa;
    XGetWindowAttributes(display, root, &gwa);

    if(_hwc_.h == 0 && _hwc_.w == 0){

        _hwc_.w = gwa.width;
        _hwc_.h = gwa.height;
        m.pointer = new int[_hwc_.h * _hwc_.w * _hwc_.c];
    }

    XImage *image = XGetImage(display,root, 0,0 , _hwc_.w,_hwc_.h,AllPlanes, ZPixmap);

    int _c = 0;
    for (int y = 0; y < _hwc_.h ; y++) {
        for (int x = 0; x < _hwc_.w; x++) {
            unsigned long pixel = XGetPixel(image, x, y);
            int red = pixel & 0xFF;
            int green = (pixel >> 8) & 0xFF;
            int blue = (pixel >> 16) & 0xFF;

            m.pointer[_c] = red;
            m.pointer[++_c] = green;
            m.pointer[++_c] = blue;
            _c++;
        }
    }

    XDestroyImage(image);
    XDestroyWindow(display, root);
    XCloseDisplay(display);
    return m.pointer;
}

extern "C" int getWidth(){

    Display *display = XOpenDisplay(NULL);
    Window root = DefaultRootWindow(display);
    XWindowAttributes gwa;

    XGetWindowAttributes(display, root, &gwa);
    int width = gwa.width;
    XDestroyWindow(display, root);
    XCloseDisplay(display);
    return width;
}

extern "C" int getHeight(){

    Display *display = XOpenDisplay(NULL);
    Window root = DefaultRootWindow(display);
    XWindowAttributes gwa;

    XGetWindowAttributes(display, root, &gwa);
    int height = gwa.height;

    XDestroyWindow(display, root);
    XCloseDisplay(display);
    return height;
}