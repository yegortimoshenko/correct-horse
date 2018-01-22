#include <gtk/gtk.h>
#include <string.h>

#include "random.h"

int main(int argc, char *argv[]) {
  gtk_init(&argc, &argv);

  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(window), 350, -1);
  gtk_window_set_icon_name(GTK_WINDOW(window), "correct-horse");
  gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
  gtk_window_set_title(GTK_WINDOW(window), "Correct Horse");
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  g_autofree gchar *password = correct_horse_random_passphrase(" ", 6);

  GtkEntryBuffer *buf = gtk_entry_buffer_new(password, strlen(password));
  GtkWidget *entry = gtk_entry_new_with_buffer(buf);
  gtk_container_add(GTK_CONTAINER(window), entry);

  gtk_widget_show_all(window);
  gtk_main();
}
