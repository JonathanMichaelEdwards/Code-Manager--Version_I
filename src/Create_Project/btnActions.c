#include <gtk/gtk.h>
#include <stdio.h>
#include "createProject.h"
#include "createWindow.h"
#include "fileIO.h"
#include "manager.h"
#include "chooseFolder.h"



/**
 * Create a project python script.
 * - When pushed, update the label field which 
 *   contains the Name of the Project. The text
 *   that is entered in the entry box is the projects
 *   name.
 * 
 * @param ptr_confirm, contains button signals.
 * @param ptr_widgets, contains all widgets used
 *        in the window.
 */
void on_btnPythonScript_clicked(GtkButton *btnConfirm, CreateProjectWidgets *widgets)
{

}