#include <gtk/gtk.h>
#include "createProject.h"
#include "manager.h"
#include "chooseFolder.h"

#define LEN_OF_FILE(FILENAME) 18 + strlen(FILENAME)
#define FILENAME "createProject"


typedef struct {
    Layout window;
    GtkWidget *lblProjectName;
    GtkWidget *lblLocation;
    GtkWidget *entProjectName;
} Widgets;
    


/**
 * Exit button action.
 * - Exit's the App.
 */
void on_chooseTemplate_destroy(void)
{
    gtk_main_quit();
}


/**
 * Create button action.
 * - When pushed, go to the choose options window.
 */
void on_btnBack_clicked(GtkButton *button, Layout *_window)
{
    DESTROY_WIDGET(_window->window);
    manager();
}


void on_btnLocation_clicked(void)
{
    chooseFolder();
}


/**
 * Set Label when label pushed
 */
void on_btnConfirm_clicked(GtkButton *btnConfirm, Widgets *widgets)
{
    const char *pName = gtk_entry_get_text(GTK_ENTRY(widgets->entProjectName));

    if (strlen(pName) == 0);
    else
        gtk_label_set_label(GTK_LABEL(widgets->lblProjectName), pName);
}


/**
 * Free all memory used.
 * @param char *fileG - Glade file freed.
 * @param Widgets *widgets - Glade widgets.
 */
static void freeMem(char *fileG, Widgets *widgets)
{
    free(fileG);
    g_free(widgets);
}


/**
 * Runs the Create Project GUI application
 */
void createProject(void)
{
    Widgets *widgets = (Widgets*)malloc(sizeof(Widgets));

    // Link the Glade GUI builder
    char *fileG = (char*)malloc(sizeof(char) * LEN_OF_FILE(FILENAME));
    sprintf(fileG, "../glade/%s.glade", FILENAME);
    GtkBuilder *builder = gtk_builder_new_from_file(fileG);

    // Create the window
    GtkWidget *window = GTK_WIDGET(gtk_builder_get_object(builder, FILENAME));
    widgets->window.window = window;
    widgets->lblProjectName = GTK_WIDGET(gtk_builder_get_object(builder, "lblProjectName"));
    widgets->entProjectName = GTK_WIDGET(gtk_builder_get_object(builder, "entProjectName"));
    widgets->lblLocation = GTK_WIDGET(gtk_builder_get_object(builder, "lblLocation"));
    setDirectory = widgets->lblLocation;

    gtk_window_set_title(GTK_WINDOW(window), PROJECT_NAME);
    gtk_builder_connect_signals(builder, widgets);
    
    g_object_unref(builder);  // Reference builder 

    // Execute window
    gtk_widget_show(window);                
    gtk_main();

    // Free memory
    freeMem(fileG, widgets);
}
