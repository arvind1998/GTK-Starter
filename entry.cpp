#include<gtk/gtk.h>
static void buttonclick(GtkWidget *widget, gpointer data)
{
	g_print("%s\n",gtk_entry_get_text(GTK_ENTRY(data)));
	//gtk_entry_set_text(GTK_ENTRY(data),"HELLO"); This hello will get entered no matter whatever u type

	//gtk_editable_select_region(GTK_EDITABLE(data),0,-1); it selects the entered text

	//gtk_editable_copy_clipboard(GTK_EDITABLE(data)); it copies the selected text...cut and paste can also be used instead of copy
}

int main(int argc, char* argv[])
{
	gtk_init(&argc,&argv);
	GtkWidget *window,*entry,*button,*hbox;
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(window,"delete-event",G_CALLBACK(gtk_main_quit),NULL);

	entry=gtk_entry_new();
	button=gtk_button_new_with_mnemonic("_WRITE");	
	g_signal_connect(button,"clicked",G_CALLBACK(buttonclick),entry);
	g_signal_connect(button,"activate",G_CALLBACK(buttonclick),entry);
	

	hbox=gtk_hbox_new(0,0);
	gtk_box_pack_start(GTK_BOX(hbox),entry,0,0,0);
	gtk_box_pack_start(GTK_BOX(hbox),button,0,1,0);
	gtk_container_add(GTK_CONTAINER(window),hbox);
	gtk_widget_show_all(window);
	gtk_main();
	return 0;
}
