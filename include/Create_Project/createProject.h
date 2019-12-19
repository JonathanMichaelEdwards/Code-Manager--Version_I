#ifndef CHOOSETEMPLATE_H
#define CHOOSETEMPLATE_H

#include "createWindow.h"

typedef union {
    struct {
        Layout window;
        GtkWidget *lblProjectName;
        GtkWidget *lblLocation;
        GtkWidget *entProjectName;
        GtkWidget *btnConfirm;
        GtkWidget *btnLocation;
        GtkWidget *btnPythonScript;
    };
    GtkWidget **widget;
} CreateProjectWidgets;


void createProject(void);


#endif // CHOOSETEMPLATE_H
