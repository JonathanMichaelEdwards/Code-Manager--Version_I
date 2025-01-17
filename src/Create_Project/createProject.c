#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include "manager.h"
#include "createWindow.h"
#include "createProject.h"
#include "fileIO.h"
#include "chooseFolder.h"


// GUI information
#define FILENAME "createProject"
#define STRUCT_SIZE 7
    


static const char *WidgetNames[STRUCT_SIZE] = {
    FILENAME,
    "lblProjectName",
    "lblLocation",
    "entProjectName",
    "btnConfirm",
    "btnLocation",
    "btnPythonScript"
};



/**
 * Quit the program.
 */
void on_createProject_destroy(void)
{
    gtk_main_quit();
}


/**
 * Back to manager button.
 * - When pushed, destroy the current window 
 *   and go back to the manager window.
 * 
 * @param ptr_button, contains button signals.
 * @param ptr_widgets, contains all widgets used
 *        in the window.
 */
void on_btnBack_clicked(GtkButton *button, CreateProjectWidgets *widgets)
{
    DESTROY_WIDGET(widgets->widget[0]);
    manager();
}


void on_btnNext_clicked(GtkButton *button, CreateProjectWidgets *widgets)
{

}


/**
 * Directory location button.
 * - When pushed, open the choose folder window.
 */
void on_btnLocation_clicked(GtkButton *location, CreateProjectWidgets *widgets)
{
    char *dir = NULL;

    // Disable widgets
    ENABLE_WIDGETS(widgets->widget[0], FALSE);
    ENABLE_WIDGETS(widgets->widget[5], FALSE);

    chooseFolder();  // Pop up window

    // Enable widgets
    ENABLE_WIDGETS(widgets->widget[0], TRUE);
    ENABLE_WIDGETS(widgets->widget[5], TRUE);

    int ferror = readFile("../src/Files/folderName.dat", &dir);
    if (ferror == EXIT_SUCCESS) {
        gtk_label_set_label(GTK_LABEL(widgets->widget[2]), dir);

        const char *pName = gtk_label_get_label(GTK_LABEL(widgets->widget[1]));
        char *projectDir = (char*)malloc(sizeof(char) * (strlen(dir) + strlen(pName)));

        sprintf(projectDir, "%s/%s", dir, pName);
        // dirCreate(projectDir);

        ENABLE_WIDGETS(widgets->widget[5], FALSE);
        ENABLE_WIDGETS(widgets->widget[6], TRUE);

        free(dir);  
        free(projectDir);
    }
}


/**
 * Confirm button.
 * - When pushed, update the label field which 
 *   contains the Name of the Project. The text
 *   that is entered in the entry box is the projects
 *   name.
 * 
 * @param ptr_confirm, contains button signals.
 * @param ptr_widgets, contains all widgets used
 *        in the window.
 */
void on_btnConfirm_clicked(GtkButton *btnConfirm, CreateProjectWidgets *widgets)
{
    const char *pName = gtk_entry_get_text(GTK_ENTRY(widgets->widget[3]));

    if (strlen(pName) == EXIT_SUCCESS);  // pop up dialog box !!!
    else {
        gtk_label_set_label(GTK_LABEL(widgets->widget[1]), pName);
        
        ENABLE_WIDGETS(widgets->widget[4], FALSE);
        ENABLE_WIDGETS(widgets->widget[5], TRUE);
    }
}


/**
 * Runs glades createProject GUI application, passes
 * information about the window in the function 
 * createWindow.
 */
void createProject(void)
{
    CreateProjectWidgets *widgets = NULL;
    
    // Casting Widgets to the default Widget struct
    createWindow((Widget*)&widgets, WidgetNames, FILENAME, STRUCT_SIZE);
}
