#include <stdbool.h>
#include <gtk/gtk.h>
#include "codeManager.h"

#define LEN_OF_FILE(FILENAME) 18 + strlen(FILENAME)
#define NEXT_WINDOW "./chooseTemplate.out"

GtkWidget *window = NULL;
char command[20];
bool destroy = false;


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
void on_btnFile_clicked(void)
{
    destroy = true;
    memcpy(command, NEXT_WINDOW, strlen(NEXT_WINDOW));
    gtk_widget_destroy(window);
}


/**
 * Free all memory used.
 * @param fileG - Glade file freed.
 */
void freeMem(char *fileG)
{
    free(fileG);
}


void nextWindow(char *cmd) 
{
    if (destroy) system(cmd);
}


int main(int argc, char **argv)
{
    // Initialize gtk
    gtk_init(&argc, &argv);

    // Link the Glade GUI builder
    char *fileG = (char*)malloc(sizeof(char) * LEN_OF_FILE(FILENAME));
    sprintf(fileG, "../glade/%s.glade", FILENAME);
    GtkBuilder *builder = gtk_builder_new_from_file(fileG);

    // Create the default Window
    window = GTK_WIDGET(gtk_builder_get_object(builder, FILENAME));
    gtk_window_set_title(GTK_WINDOW(window), PROJECT_NAME);
    gtk_builder_connect_signals(builder, NULL);
    
    g_object_unref(builder);  // Reference builder 

    // Execute window
    gtk_widget_show(window);                
    gtk_main();

    // Free memory and change screens
    freeMem(fileG);
    nextWindow(command);

    return EXIT_SUCCESS;
}
