#ifndef Code_Manager_H
#define Code_Manager_H

#include "createWindow.h"

#define PROJECT_NAME "Code Manager"
#define DESTROY_WIDGET(WINDOW) gtk_widget_destroy(WINDOW);
#define ENABLE_WIDGETS(WINDOW, ENABLE) gtk_widget_set_sensitive(WINDOW, ENABLE);


void manager(void);


#endif // Code_Manager_H

