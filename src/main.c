#include <gtk/gtk.h>
#include "manager.h"


int main(int argc, char **argv)
{
    // Initialize gtk
    gtk_init(&argc, &argv);

    // run the program
    manager();

    return EXIT_SUCCESS;
}
