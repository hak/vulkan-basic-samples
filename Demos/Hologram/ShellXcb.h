#ifndef SHELL_XCB_H
#define SHELL_XCB_H

#include <xcb/xcb.h>
#include "Shell.h"

class ShellXcb : public Shell {
public:
    ShellXcb(Game &game);
    ~ShellXcb();

    void run();

private:
    enum Action {
        NONE,
        QUIT,
        DRAW,
    };

    void init_connection();

    PFN_vkGetInstanceProcAddr load_vk();
    bool can_present(VkPhysicalDevice phy, uint32_t queue_family);

    void create_window();
    VkSurfaceKHR create_surface(VkInstance instance);

    Action handle_event(const xcb_generic_event_t *ev);

    xcb_connection_t *c_;
    xcb_screen_t *scr_;
    xcb_window_t win_;

    xcb_atom_t wm_protocols_;
    xcb_atom_t wm_delete_window_;

    void *lib_handle_;
};

#endif // SHELL_XCB_H
