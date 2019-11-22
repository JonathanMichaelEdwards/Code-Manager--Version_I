#include <gtk/gtk.h>
#include "chooseFolder.h"
#include "createProject.h"
#include "manager.h"

#define LEN_OF_FILE(FILENAME) 18 + strlen(FILENAME)
#define FILENAME "chooseFolder"


typedef struct {
    Layout window;
    GtkWidget *choose;
} Widgets;



/**
 * Exit button action.
 * - Exit's the App.
 */
void on_chooseFolder_destroy(void)
{
    gtk_main_quit();
}


void on_btnChooseFolder_clicked(GtkButton *btnUpdate, Widgets *widgets)
{
    char *folder = gtk_file_chooser_get_current_folder(GTK_FILE_CHOOSER(widgets->choose));
    gtk_label_set_label(GTK_LABEL(setDirectory), folder);
    DESTROY_WIDGET(widgets->window.window);
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
void chooseFolder(void)
{
    Widgets *widgets = (Widgets*)malloc(sizeof(Widgets));

    // Link the Glade GUI builder
    char *fileG = (char*)malloc(sizeof(char) * LEN_OF_FILE(FILENAME));
    sprintf(fileG, "../glade/%s.glade", FILENAME);
    GtkBuilder *builder = gtk_builder_new_from_file(fileG);

    // Create the window
    GtkWidget *window = GTK_WIDGET(gtk_builder_get_object(builder, FILENAME));

    widgets->window.window = window;
    widgets->choose = GTK_WIDGET(gtk_builder_get_object(builder, "chooseFolder"));

    gtk_window_set_title(GTK_WINDOW(window), PROJECT_NAME);
    gtk_builder_connect_signals(builder, widgets);
    
    g_object_unref(builder);  // Reference builder 

    // Execute window
    gtk_widget_show(window);                
    gtk_main();

    // Free memory
    freeMem(fileG, widgets);
}
