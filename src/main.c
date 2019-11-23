#include <gtk/gtk.h>
#include "manager.h"
#include "createProject.h"
#include "chooseFolder.h"
// #include <stdio.h>
// #include <stdlib.h>



int main(int argc, char **argv)
{
    // Initialize gtk
    gtk_init(&argc, &argv);

    // run the program
    manager();
    // createProject();
    // chooseFolder();


    return 0;// EXIT_SUCCESS;
}
