#include <gtk/gtk.h>
#include "createWindow.h"

#define LEN_OF_FILE(NAME) 18 + strlen(NAME)



Widget *builderGetObject(GtkBuilder *builder, Widget *widgets, const char *names[], int size)
{
    widgets->widget[0] = GTK_WIDGET(gtk_builder_get_object(builder, names[0]));

    // if size is greater, build widget
    if (size > DEFAULT_SIZE)
        for (int i = DEFAULT_SIZE; i < size; i++)
            widgets->widget[i] =  GTK_WIDGET(gtk_builder_get_object(builder, names[i]));
    
    return widgets;
}


void createWindow(Widget *widgets, const char *names[], const char *title, int size)
{
    // Allocating memory for struct Widget
    widgets = malloc(sizeof(Widget));
    widgets->widget = (GtkWidget**)malloc(sizeof(widgets->widget) * size);

    // Link Glade's GUI builder
    char *fileG = (char*)malloc(sizeof(char) * LEN_OF_FILE(names[0]));
    sprintf(fileG, "../glade/%s.glade", names[0]);
    GtkBuilder *builder = gtk_builder_new_from_file(fileG);
    
    // Create and link widgets for window
    widgets = builderGetObject(builder, widgets, names, size);
    gtk_window_set_title(GTK_WINDOW(widgets->widget[0]), title);
    gtk_builder_connect_signals(builder, widgets);
    g_object_unref(builder);  // Reference builder 
    
    // Execute window
    gtk_widget_show(widgets->widget[0]);             
    gtk_main();
    
    // Free memory
    free(fileG);
    free(widgets->widget);
    free(widgets);
}
