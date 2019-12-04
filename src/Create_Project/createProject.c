#include <gtk/gtk.h>
#include <sys/types.h>
#include "createProject.h"
#include "createWindow.h"
#include "manager.h"
#include "chooseFolder.h"

#define FILENAME "createProject"
#define STRUCT_SIZE 4


typedef union {
    struct {
        Layout window;
        GtkWidget *lblProjectName;
        GtkWidget *lblLocation;
        GtkWidget *entProjectName;
    };
    GtkWidget **widget;
} Widgets;
    

static const char *WidgetNames[STRUCT_SIZE] = {
    FILENAME,
    "lblProjectName",
    "lblLocation",
    "entProjectName"
};



/**
 * Exit button action.
 * - Exit's the App.
 */
void on_createProject_destroy(void)
{
    gtk_main_quit();
}


/**
 * Create button action.
 * - When pushed, go to the choose options window.
 */
void on_btnBack_clicked(GtkButton *button, Widgets *widgets)
{
    DESTROY_WIDGET(widgets->widget[0]);
    manager();
}


void on_btnNext_clicked(GtkButton *button, Widgets *widgets)
{
    // DESTROY_WIDGET(_window->window);
    // manager();
    // createProject();
}


void on_btnLocation_clicked(void)
{
    chooseFolder();
}


/**
 * Set Project Label Name when the Confirm button is pressed, and
 * entry is no NULL.
 */
void on_btnConfirm_clicked(GtkButton *btnConfirm, Widgets *widgets)
{
    const char *pName = gtk_entry_get_text(GTK_ENTRY(widgets->widget[3]));

    if (strlen(pName) == 0);
    else
        gtk_label_set_label(GTK_LABEL(widgets->widget[1]), pName);
}


/**
 * Runs the Create Project GUI application
 */
void createProject(void)
{
    Widgets *widgets = (Widgets*)malloc(sizeof(Widgets));
    
    int fd_3 = fork();

    if (fd_3 == 0) {
        puts("here");
        createWindow((Widget*)&widgets, WidgetNames, FILENAME, STRUCT_SIZE);
    } 
}
