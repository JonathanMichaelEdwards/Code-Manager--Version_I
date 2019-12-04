#include <gtk/gtk.h>
#include "manager.h"
#include "createWindow.h"
#include "createProject.h"

#define FILENAME "manager"
#define STRUCT_SIZE 1


typedef union {
    struct {
        Layout window;
    };
    GtkWidget **widget;
} Widgets;


static const char *WidgetNames[STRUCT_SIZE] = {
    FILENAME
};


/**
 * Exit button action.
 * - Exit's the App.
 */
void on_optManage_destroy(void)
{
    gtk_main_quit();
}


/**
 * Create button action.
 * - When pushed, go to the choose options window.
 */
void on_btnFile_clicked(GtkButton *button,  Widgets *widgets)
{
    DESTROY_WIDGET(widgets->widget[0]);
    createProject();
}


/**
 * Runs the Managers GUI Glade application.
 */
void manager(void)
{
    Widgets *widgets = (Widgets*)malloc(sizeof(Widgets));
    createWindow((Widget*)&widgets, WidgetNames, FILENAME, STRUCT_SIZE); 
}
