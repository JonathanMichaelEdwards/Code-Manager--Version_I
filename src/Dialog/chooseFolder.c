#include <gtk/gtk.h>
#include "chooseFolder.h"
#include "createWindow.h"
#include "createProject.h"
#include "manager.h"


#define FILENAME "chooseFolder"
#define STRUCT_SIZE 2



typedef union {
    struct {
        Layout window;
        GtkWidget *choose;
    };
    GtkWidget **widget;
} Widgets;


static const char *WidgetNames[STRUCT_SIZE] = {
    FILENAME,
    "btnchooseFolder"
};



/**
 * Exit button action.
 * - Exit's the App.
 */
void on_chooseFolder_destroy(void)
{
    gtk_main_quit();
}


// void sendDirLabel()
// {

// }


void on_btnChooseFolder_clicked(GtkButton *btnUpdate, Widgets *widgets)
{
    char *folder = gtk_file_chooser_get_current_folder(GTK_FILE_CHOOSER(widgets->widget[0]));
    // sendDirLabel(char *folder)
    puts("send dir");
    // gtk_label_set_label(GTK_LABEL("needs to change"), folder);
    DESTROY_WIDGET(widgets->widget[0]);
}


/**
 * Runs the Create Project GUI application
 */
void chooseFolder(void)
{
    Widgets *widgets = (Widgets*)malloc(sizeof(Widgets));
    int fd_4 = fork();

    if (fd_4 == 0) {
        puts("here");
        createWindow((Widget*)&widgets, WidgetNames, FILENAME, STRUCT_SIZE);
    } else {
        wait(fd_4);
        
        // gtk_label_set_label(GTK_LABEL(WidgetNames[2]), "hello");
    }
}
