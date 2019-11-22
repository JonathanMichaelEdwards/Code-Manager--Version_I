#ifndef Code_Manager_H
#define Code_Manager_H

#define PROJECT_NAME "Code Manager"
#define DESTROY_WIDGET(WINDOW) gtk_widget_destroy(WINDOW);

typedef struct {
    GtkWidget *window;
} Layout;

void manager(void);


#endif // Code_Manager_H

