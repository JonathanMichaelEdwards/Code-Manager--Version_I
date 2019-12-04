#ifndef CREATE_WINDOW_H
#define CREATE_WINDOW_H

#define DEFAULT_SIZE 1
#define PROJECT_NAME "Code Manager"
#define DESTROY_WIDGET(WINDOW) gtk_widget_destroy(WINDOW); // Destroy's GtkWidget


typedef struct {
    GtkWidget *window;
} Layout;

typedef union {
    struct {
        Layout window;
    };
    GtkWidget **widget;
} Widget;


void createWindow(Widget *widgets, const char *names[], const char *title, int size);


#endif // CREATE_WINDOW_H
