#define _GNU_SOURCE
#include <gtk/gtk.h>
#include "random.h"

GtkWidget *bar, *button, *entry, *spinner, *window;

void correct_horse_gtk_generate() {
  g_autofree gchar *passphrase, *subtitle;
  long n = gtk_spin_button_get_value(GTK_SPIN_BUTTON(spinner));

  passphrase = correct_horse_random_passphrase(" ", n);
  gtk_entry_set_text(GTK_ENTRY(entry), passphrase);

  if (G_UNLIKELY(asprintf(&subtitle, "%d words, %d bits", n, 16 * n) < 0))
    g_error("asprintf: allocation failure");

  gtk_header_bar_set_subtitle(GTK_HEADER_BAR(bar), subtitle);
}

int main(int argc, char *argv[]) {
  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(window), 350, -1);
  gtk_window_set_icon_name(GTK_WINDOW(window), "correct-horse");
  gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
  gtk_window_set_title(GTK_WINDOW(window), "Correct Horse");
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  button = gtk_button_new_from_icon_name("view-refresh-symbolic", GTK_ICON_SIZE_BUTTON);
  g_signal_connect(button, "clicked", G_CALLBACK(correct_horse_gtk_generate), NULL);

  spinner = gtk_spin_button_new_with_range(2, 16, 1);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinner), 6);
  g_signal_connect(spinner, "value-changed", G_CALLBACK(correct_horse_gtk_generate), NULL);

  bar = gtk_header_bar_new();
  gtk_header_bar_pack_start(GTK_HEADER_BAR(bar), button);
  gtk_header_bar_pack_start(GTK_HEADER_BAR(bar), spinner);
  gtk_header_bar_set_title(GTK_HEADER_BAR(bar), "Correct Horse");
  gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(bar), TRUE);
  gtk_window_set_titlebar(GTK_WINDOW(window), bar);

  entry = gtk_entry_new();
  correct_horse_gtk_generate();
  gtk_container_add(GTK_CONTAINER(window), entry);

  gtk_widget_show_all(window);
  gtk_main();
}
