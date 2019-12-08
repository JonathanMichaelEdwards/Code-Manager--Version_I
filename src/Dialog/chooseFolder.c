#include <gtk/gtk.h>
#include "chooseFolder.h"
#include "createWindow.h"
#include "createProject.h"
#include "fileIO.h"
#include "manager.h"


// GUI information
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
 * Quit the program.
 */
void on_chooseFolder_destroy(void)
{
    gtk_main_quit();
}


/**
 * Choose Folder button.
 * - When pushed, destroy the current window 
 *   and go to the choose options window.
 * 
 * @param ptr_choose, contains button signals.
 * @param ptr_widgets, contains all widgets used
 *        in the window.
 */
void on_btnChooseFolder_clicked(GtkButton *btnChoose, Widgets *widgets)
{
    char *folder = gtk_file_chooser_get_current_folder(GTK_FILE_CHOOSER(widgets->widget[0]));
    writeFile("../src/Files/folderName.dat", folder);

    DESTROY_WIDGET(widgets->widget[0]);
}


/**
 * Runs glades chooseFolder GUI application, passes
 * information about the window in the function 
 * createWindow.
 */
void chooseFolder(void)
{
    Widgets *widgets = NULL;

    // Casting Widgets to the default Widget struct
    createWindow((Widget*)&widgets, WidgetNames, FILENAME, STRUCT_SIZE);
}
