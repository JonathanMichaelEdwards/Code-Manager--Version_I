#include <gtk/gtk.h>
#include "manager.h"
#include "createProject.h"

#define LEN_OF_FILE(FILENAME) 18 + strlen(FILENAME)
#define FILENAME "manager"


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
void on_btnFile_clicked(GtkButton *button, Layout *_window)
{
    DESTROY_WIDGET(_window->window);
    createProject();
}


/**
 * Free all memory used.
 * @param char *fileG - Glade file freed.
 * @param Layout *_window - Glade _window that are stored 
 *        in a struct.
 */
static void freeMem(char *fileG, Layout *_window)
{
    free(fileG);
    free(_window);
}


/**
 * Runs the Managers GUI application
 */
void manager(void)
{
    Layout *_window = (Layout*)malloc(sizeof(Layout));

    // Link the Glade GUI builder
    char *fileG = (char*)malloc(sizeof(char) * LEN_OF_FILE(FILENAME));
    sprintf(fileG, "../glade/%s.glade", FILENAME);
    GtkBuilder *builder = gtk_builder_new_from_file(fileG);

    // Create the default Window
    GtkWidget *window = GTK_WIDGET(gtk_builder_get_object(builder, FILENAME));
    _window->window = window;

    gtk_window_set_title(GTK_WINDOW(window), PROJECT_NAME);
    gtk_builder_connect_signals(builder, _window);
    
    g_object_unref(builder);  // Reference builder 

    // Execute window
    gtk_widget_show(window);                
    gtk_main();

    // Free memory
    freeMem(fileG, _window);
}
