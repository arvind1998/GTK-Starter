#include<gtk/gtk.h>

int main(int argc, char* argv[])
{
	gtk_init(&argc,&argv);
	GtkWidget *window,*table,*label,*button;
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(window,"delete_event",G_CALLBACK(gtk_main_quit),NULL);
	table=gtk_table_new(2,2,0);
	button=gtk_button_new_with_mnemonic("_BUTTON");
	label=gtk_label_new("LABEL");
	gtk_table_attach(GTK_TABLE(table),label,0,1,0,1,GTK_FILL,GTK_FILL,0,0);
	gtk_table_attach(GTK_TABLE(table),button,1,2,0,1,GTK_FILL,GTK_FILL,0,0);
	button=gtk_button_new_with_mnemonic("_BUTTON 2");
        label=gtk_label_new("LABEL 2");
        gtk_table_attach(GTK_TABLE(table),label,0,1,1,2,GTK_FILL,GTK_FILL,0,0);
        gtk_table_attach(GTK_TABLE(table),button,1,2,1,2,GTK_FILL,GTK_FILL,0,0);
	
	gtk_container_add(GTK_CONTAINER(window),table);

	gtk_widget_show_all(window);
	gtk_main();
	return 0;
}
