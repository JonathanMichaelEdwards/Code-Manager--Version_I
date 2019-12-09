#include <gtk/gtk.h>
#include "manager.h"
#include "createWindow.h"
#include "createProject.h"


// GUI information
#define FILENAME "manager"
#define STRUCT_SIZE 1


/**
 * store a **widget
 */
typedef union {
    struct {
        Layout window;
    };
    GtkWidget **widget;
} WidgetManager;


static const char *WidgetNames[STRUCT_SIZE] = {
    FILENAME
};



/**
 * Quit the program.
 */
void on_optManage_destroy(void)
{
    gtk_main_quit();
}


/**
 * Create Project button.
 * - When pushed, destroy the current window 
 *   and go to the choose options window.
 * 
 * @param ptr_button, contains button signals.
 * @param ptr_widgets, contains all widgets used
 *        in the window.
 */
void on_btnCreateProject_clicked(GtkButton *button,  WidgetManager *widgets)
{
    DESTROY_WIDGET(widgets->widget[0]);
    createProject();
}


/**
 * Runs glades manager GUI application, passes
 * information about the window in the function 
 * createWindow.
 */
void manager(void)
{
    WidgetManager *widgets = NULL;

    // Casting Widgets to the default Widget struct
    createWindow((Widget*)&widgets, WidgetNames, FILENAME, STRUCT_SIZE); 
}
