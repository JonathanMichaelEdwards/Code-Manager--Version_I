#include <stdbool.h>
#include <gtk/gtk.h>
#include "chooseTemplate.h"

#define LEN_OF_FILE(FILENAME) 18 + strlen(FILENAME)
#define NEXT_WINDOW "./Code_Manager.out"

GtkWidget *window = NULL;
char command[100];
bool destroy = false;

int argc;
char **argv;

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
void on_btnBack_clicked(void)
{
    // destroy = true;
    // memcpy(command, NEXT_WINDOW, strlen(NEXT_WINDOW));
    gtk_widget_destroy(window);

        // Initialize gtk
    gtk_init(&argc, &argv);

    // Link the Glade GUI builder
    char *fileG = (char*)malloc(sizeof(char) * LEN_OF_FILE("codeManager"));
    sprintf(fileG, "../glade/%s.glade", "codeManager");
    GtkBuilder *builder = gtk_builder_new_from_file(fileG);

    // Create the window
    window = GTK_WIDGET(gtk_builder_get_object(builder, "codeManager"));
    gtk_window_set_title(GTK_WINDOW(window), PROJECT_NAME);
    gtk_builder_connect_signals(builder, NULL);
    
    g_object_unref(builder);  // Reference builder 

    // Execute window
    gtk_widget_show(window);                
    gtk_main();

    // Free memory
    freeMem(fileG);
}


void on_btnConfirm_clicked(GtkButton *btnConfirm, GtkLabel *lblProjectName)
{
    gtk_label_set_label(lblProjectName, "Hello the button was pushed");
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

    // Create the window
    window = GTK_WIDGET(gtk_builder_get_object(builder, FILENAME));
    gtk_window_set_title(GTK_WINDOW(window), PROJECT_NAME);
    gtk_builder_connect_signals(builder, NULL);
    
    g_object_unref(builder);  // Reference builder 

    // Execute window
    gtk_widget_show(window);                
    gtk_main();

    // Free memory
    freeMem(fileG);
    // nextWindow(command);

    return EXIT_SUCCESS;
}
