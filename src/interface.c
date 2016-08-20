/*
 *	GTelnet
 *	by: 	Kenth Andersson <d99kan@du.se> (Initial development v1.0)
 *		Prana <*****@*****.***> (v1.1, v1.2, v2.0, v2.1, v2.2, v2.3, v2.4)
 *
 *	Developed partially with Glade <http://glade.pn.org>
 */

#include "interface.h"

#define default_background_location "/usr/share/pixmaps/gtelnet/gtelnet_bg_black.jpg"


gushort	red[] =
{
   0x0000,0xaaaa,0x0000,
   0xaaaa,0x0000,0xaaaa,
   0x0000,0x5fbb,0x5555,
   0xffff,0x5555,0xffff,
   0x5555,0xffff,0x5555,
   0xffff,0x0000,0x0000  
};

gushort green[] =
{
   0x0000,0x0000,0xaaaa,
   0x5555,0x0000,0x0000,
   0xaaaa,0xee8b,0x5555,
   0x5555,0xffff,0xffff,
   0x5555,0x5555,0xffff,
   0xffff,0xea60,0x0000
};

gushort blue[] =
{
   0x0000,0x0000,0x0000,
   0x0000,0xaaaa,0xaaaa, 
   0xaaaa,0x2fc9,0x5555, 
   0x5555,0x5555,0x5555, 
   0xffff,0xffff,0xffff, 
   0xffff,0x0000,0x0000 
};


char *the_terminal_types[] = {
  "ansi", 	// 1
  "ansi-bbs",
  "ansi-cis",
  "aixterm",
  "arm100",	// 5
  "att700",
  "bsdos-pc",
  "crt",
  "hpansi",
  "hpterm",  	// 10
  "iris-ansi",
  "iris-color",
  "linux",
  "mach",
  "mgr",	// 15
  "ncsa",
  "pckermit",
  "ncsa",  
  "qnx",
  "rcons",
  "rcons-color",// 20
  "rxvt", 	
  "rxvt-color",
  "scoansi",
  "sun",
  "vt52",	// 25	
  "vt100",	
  "vt102",
  "vt131",
  "vt220",
  "vt320",	// 30
  "vt340",	
  "vt400",
  "vt420",
  "vt525",
  "wyse30",	// 35
  "wyse50",	
  "wyse60",
  "wy100",
  "xterm",
  "xterm-debian"  
  "xterm-color"	// 40
  };

char *the_encryption_types[] = {
  "none",
  "des",
  "3des",
  "blowfish",
  "idea",
  "arcfour",
  "twofish",
  "any",
  "anystd",
  "anycipher",
  "anystdcipher"
  };

struct opt_widget telnet_checkbox[] = {
{ NULL, "tlnt_chk1", N_("8-bit data path (both output and input)")},
{ NULL, "tlnt_chk2", N_("8-bit data path on output")}, 
{ NULL, "tlnt_chk3", N_("Stop any character from being recognized as an escape character")},
{ NULL, "tlnt_chk4", N_("Forward a forwardable copy of the local credentials to the remote system (if Kerberos V5 is used)")},
{ NULL, "tlnt_chk5", N_("Attempt automatic login")},    
{ NULL, "tlnt_chk6", N_("Specify a user interface similar to rlogin")},
{ NULL, "tlnt_chk7", N_("Turn on encryption of the data stream")},
{ NULL, "tlnt_chk8", N_("Set the initial value of the debug flag to TRUE")},
{ NULL, "tlnt_chk9", N_("Set the initial telnet escape character to:")},
{ NULL, "tlnt_chk10", N_("Set the IP type-of-service  (TOS)  option  to the value:")},
{ NULL, "tlnt_chk11", N_("Disable the type of authentication: ")},
{ NULL, "tlnt_chk12", N_("Request  Kerberos tickets for the remote host in the realm:")},
{ NULL, "tlnt_chk13", N_("Trace file :")}
};

struct opt_widget ssh_checkbox[] = {
{ NULL, "ssh_chk1",  N_("Redirect input from /dev/null")},
{ NULL, "ssh_chk2",  N_("Disable authentication agent forwarding")},
{ NULL, "ssh_chk3",  N_("Disable X11 connection forwarding")},
{ NULL, "ssh_chk4",  N_("Allocate a tty even if command is given")},
{ NULL, "ssh_chk5",  N_("Display verbose debugging messages")},
{ NULL, "ssh_chk6",  N_("Don't allocate a privileged port")},
{ NULL, "ssh_chk7",  N_("Don't display any warning messages")},
{ NULL, "ssh_chk8",  N_("Fork into background after authentication")},
{ NULL, "ssh_chk9",  N_("Enable compression")},
{ NULL, "ssh_chk10", N_("Allow remote hosts to connect to local forwarded ports")},
{ NULL, "ssh_chk11", N_("Don't request a session")},
{ NULL, "ssh_chk12", N_("Set SSH2 debug level to:")},
{ NULL, "ssh_chk13", N_("Identity file for public key authentication to:")},
{ NULL, "ssh_chk14", N_("Set escape character to:")},
{ NULL, "ssh_chk15", N_("Select encryption algorithm (For OpenSSH: only '3des' and 'blowfish' are supported)")},
};

struct opt_widget rlogin_checkbox[] = {
{ NULL, "rlogin_chk1", N_("Allows an eight-bit input data path at all times")},
{ NULL, "rlogin_chk2", N_("Stops any character from being recognized as an escape character")},
{ NULL, "rlogin_chk3", N_("Turns off all Kerberos authentication")},
{ NULL, "rlogin_chk4", N_("Allows the rlogin session to be run in \"litout\" mode")},
{ NULL, "rlogin_chk5", N_("Turns on socket debugging")},
{ NULL, "rlogin_chk6", N_("Turns on DES encryption for all data passed via the rlogin session")},
{ NULL, "rlogin_chk7", N_("Set the initial telnet escape character to:")},
{ NULL, "rlogin_chk8", N_("Request Kerberos tickets for the remote host in the realm:")}
};

struct opt_widget display_option_labels[] = {
{ NULL, "display_lbl1", N_("Background Color")},
{ NULL, "display_lbl2", N_("Foreground Color")},
{ NULL, "display_lbl3", N_("Executable Files Color")},
{ NULL, "display_lbl4", N_("Directories Color")},
{ NULL, "display_lbl5", N_("Display Font")},
{ NULL, "display_lbl6", N_("Background Image")},
};

static void selectconnection (GtkWidget *item, int num) {
/* 
 Select 
 0: telnet
 1: ssh
 2: rlogin
*/
  connection_type = num; 
}

static void select_ssh_encrypt_type (GtkWidget *item, int num) {
/* 
 Select the ssh encryption type..
 Note: for OpenSSH, only "3des" and "blowfish" will work right now... but for SSH2, "idea", etc will work ;)
*/
 gnome_property_box_changed(GNOME_PROPERTY_BOX(property_box));
 ssh_encrypt_type = num;
}

static void add_menu_item (void *callback, char *label, GtkWidget *menu, void *parameters) {
/*
   Add menu item
*/
   GtkWidget *item;

   item = gtk_menu_item_new_with_label (label);
   gtk_menu_append (GTK_MENU (menu), item);
   gtk_signal_connect (GTK_OBJECT (item), "activate", GTK_SIGNAL_FUNC (callback), parameters);
   gtk_widget_show (item);
}

static void destroy_win(GtkWidget *widget, gpointer data) {
/*
   Kill application - cropped directly from GTelnet
*/
   gtk_main_quit();
}

static void changed(GtkWidget *widget, gint page_num, gpointer data) {
/*
   Indicates that there has been a settings that's changed in Property Box dialog
  - cropped directly from old GTelnet v1.0
*/
   gnome_property_box_changed(GNOME_PROPERTY_BOX(property_box));
}

static GtkWidget *new_toolbar_button(GtkWidget *parent, GtkWidget *a_toolbar,char *icon, char *namez, gchar *title, gchar *tooltips) {

  GtkWidget *tmp_toolbar_icon;
  GtkWidget *tool_button;

  tmp_toolbar_icon = gnome_stock_pixmap_widget (parent, icon);
  tool_button = gtk_toolbar_append_element (GTK_TOOLBAR (a_toolbar),
    GTK_TOOLBAR_CHILD_BUTTON,NULL, title, tooltips, NULL, tmp_toolbar_icon, NULL, NULL);
  gtk_widget_ref (tool_button);
  gtk_object_set_data_full (GTK_OBJECT (parent), namez, tool_button, (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (tool_button);
  return tool_button;
}

static GtkWidget *new_label(GtkWidget *parent,gchar *namez, gchar *title)
/*
   New label
*/
{
  GtkWidget *label;
  
  label = gtk_label_new (title);
  gtk_widget_ref (label);
  gtk_object_set_data_full (GTK_OBJECT (parent), namez, label, (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (label);
  return label;
}

static GtkWidget *new_checkbox(GtkWidget *parent, char *namez, gchar *label) {
/* 
   Just for  code cleanup
*/
  GtkWidget *checkbox;
  
  checkbox = gtk_check_button_new_with_label (label);
  gtk_widget_ref (checkbox);
  gtk_object_set_data_full (GTK_OBJECT (parent), namez, checkbox, (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (checkbox);
  return checkbox;
}

static GtkWidget *new_box(GtkWidget *parent, char *namez, int box_direction)
// make a box with
{
  GtkWidget *a_box;
  
  if (box_direction==vertbox)
    a_box = gtk_vbox_new (FALSE, 0);
  else
     a_box = gtk_hbox_new (FALSE, 0);
  gtk_widget_ref (a_box);
  gtk_object_set_data_full (GTK_OBJECT (parent), namez, a_box, (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (a_box);
  return a_box;
}
static GtkWidget *new_entry(GtkWidget *parent, char *namez)
// make new option menu
{
  GtkWidget *entry;
  
  entry = gtk_entry_new ();
  gtk_widget_ref (entry);
  gtk_object_set_data_full (GTK_OBJECT (parent), namez, entry, (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (entry);
  return entry;
}

GtkWidget* create_main_window (int x_count, char *x_choice, char *x_hostname, char *x_port)
{
/*
   Main Window
*/
  GtkWidget *main_window;
  GtkWidget *dock1;
  GtkWidget *toolbar;
  GtkWidget *connect_via_menu;
  GtkWidget *host_label;
  GtkWidget *port_label;
  GtkWidget *vbox8;
  GtkWidget *entry6;
  GtkWidget *hbox4;
  GtkWidget *vscrollbar1;
  GtkWidget *connect_button, *disconnect_button, *preferences_button, *about_button;

  main_window = gnome_app_new ("gnome-telnet", _("GTelnet"));
  gtk_object_set_data (GTK_OBJECT (main_window), "main_window", main_window);
  gtk_window_set_position (GTK_WINDOW (main_window), GTK_WIN_POS_CENTER);
  gtk_window_set_policy (GTK_WINDOW (main_window), TRUE, TRUE, TRUE);
  gtk_widget_realize(main_window);

  dock1 = GNOME_APP (main_window)->dock;
  gtk_widget_ref (dock1);
  gtk_object_set_data_full (GTK_OBJECT (main_window), "dock1", dock1,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (dock1);

  toolbar = gtk_toolbar_new (GTK_ORIENTATION_HORIZONTAL, GTK_TOOLBAR_BOTH);
  gtk_widget_ref (toolbar);
  gtk_object_set_data_full (GTK_OBJECT (main_window), "toolbar", toolbar,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (toolbar);
  gnome_app_add_toolbar (GNOME_APP (main_window), GTK_TOOLBAR (toolbar), "toolbar",
                                GNOME_DOCK_ITEM_BEH_EXCLUSIVE,
                                GNOME_DOCK_TOP, 0, 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (toolbar), 1);
  gtk_toolbar_set_space_size (GTK_TOOLBAR (toolbar), 16);
  gtk_toolbar_set_space_style (GTK_TOOLBAR (toolbar), GTK_TOOLBAR_SPACE_LINE);
  gtk_toolbar_set_button_relief (GTK_TOOLBAR (toolbar), GTK_RELIEF_NONE);

  connect_via = gtk_option_menu_new ();
  gtk_widget_ref (connect_via);
  gtk_object_set_data_full (GTK_OBJECT (main_window), "connect_via", connect_via,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (connect_via);
  gtk_toolbar_append_widget (GTK_TOOLBAR (toolbar), connect_via, _("Select one of the options"), NULL);
  connect_via_menu = gtk_menu_new ();
  add_menu_item (selectconnection, "telnet", connect_via_menu, (void *)0);
  add_menu_item (selectconnection, "ssh", connect_via_menu, (void *)1);
  add_menu_item (selectconnection, "rlogin", connect_via_menu, (void *)2);
  gtk_option_menu_set_menu (GTK_OPTION_MENU (connect_via), connect_via_menu);
  
  // for handling cmdline param
  if (x_count > 1)
  {

    if (!strcmp(x_choice,"telnet"))
       connection_type = 0;
    else if (!strcmp(x_choice,"ssh"))
       connection_type = 1;
    else if (!strcmp(x_choice,"rlogin"))
       connection_type = 2;
  }
  gtk_option_menu_set_history(GTK_OPTION_MENU(connect_via),connection_type);
  host_label=new_label(main_window, "host_label",_(" Host name "));
  gtk_toolbar_append_widget (GTK_TOOLBAR (toolbar), host_label,NULL, NULL);

  hostname_entry = gnome_entry_new ("host_history");
  gnome_entry_load_history(GNOME_ENTRY(hostname_entry)); 
  
  gtk_widget_ref (hostname_entry);
  gtk_object_set_data_full (GTK_OBJECT (main_window), "hostname_entry", hostname_entry,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (hostname_entry);
  gtk_toolbar_append_widget (GTK_TOOLBAR (toolbar), hostname_entry, NULL, NULL);

  hostname_combo_entry = gnome_entry_gtk_entry (GNOME_ENTRY (hostname_entry));
   
  gtk_widget_ref (hostname_combo_entry);
  gtk_object_set_data_full (GTK_OBJECT (main_window), "hostname_combo_entry", hostname_combo_entry,
                            (GtkDestroyNotify) gtk_widget_unref);

  if (x_count > 1)
     gtk_entry_set_text (GTK_ENTRY (hostname_combo_entry),x_hostname);
  else if (x_count > 3 && !atoi(x_port))
  {
        int length = strlen(x_port)+1+strlen(x_hostname);
        char *temp = (char *) malloc (length+1);
        snprintf(temp, length+1, "%s@%s", x_port, x_hostname);
        gtk_entry_set_text (GTK_ENTRY (hostname_combo_entry),temp);
        free (temp);
  }                         
  gtk_widget_show (hostname_combo_entry);

  port_label=new_label(main_window, "port_label",_(" Port "));  
  gtk_toolbar_append_widget (GTK_TOOLBAR (toolbar), port_label, NULL, NULL);

  port_entry = new_entry(main_window,"port_entry");
  if ((x_count > 3) && atoi(x_port))
     gtk_entry_set_text (GTK_ENTRY (port_entry),x_port);
  
  gtk_toolbar_append_widget (GTK_TOOLBAR (toolbar), port_entry, _("port number -- leave blank for default"), NULL);
  gtk_widget_set_usize (port_entry, 50, -2);

// Make the toolbar button
  connect_button=new_toolbar_button(main_window,toolbar,GNOME_STOCK_PIXMAP_EXEC,"connect_button",
  _("Connect"), _("Connect to the remote host"));
  disconnect_button = new_toolbar_button(main_window,toolbar,GNOME_STOCK_PIXMAP_STOP,"disconnect_button",
  _("Disconnect"), _("Disconnect from the remote host"));
  preferences_button = new_toolbar_button(main_window,toolbar,GNOME_STOCK_PIXMAP_PREFERENCES,"preferences_button",
  _("Preferences"), _("Change your settings"));
  about_button = new_toolbar_button(main_window,toolbar,GNOME_STOCK_PIXMAP_HELP,"help_button",
  _("Help"), _("Documentation"));

  vbox8 = new_box(main_window,"vbox8",vertbox);
  gnome_app_set_contents (GNOME_APP (main_window), vbox8);

  entry6 = new_entry(main_window,"entry6");
  gtk_box_pack_start (GTK_BOX (vbox8), entry6, FALSE, FALSE, 0);
  gtk_widget_set_usize (entry6, -2, 4);
  
  hbox4 = new_box(main_window,"hbox4",horzbox);  
  gtk_box_pack_start (GTK_BOX (vbox8), hbox4, TRUE, TRUE, 0);

//////////////////////////////////////////////////////////////////////////////////////////////

/* Make term */
  term = zvt_term_new_with_size(81,24);
  gtk_widget_ref (term);
  gtk_object_set_data_full (GTK_OBJECT (main_window), "term", term,(GtkDestroyNotify) gtk_widget_unref);  
  GTK_WIDGET_SET_FLAGS(term,GTK_HAS_FOCUS + GTK_CAN_FOCUS + GTK_VISIBLE + GTK_SENSITIVE + GTK_HAS_GRAB);
  gtk_widget_show (term);
  gtk_box_pack_start (GTK_BOX (hbox4), term, TRUE, TRUE, 0);

/////////////////////////////////////////////////////////////////////////////////////////////
  vscrollbar1 = gtk_vscrollbar_new (GTK_ADJUSTMENT (ZVT_TERM(term)->adjustment));
  gtk_widget_ref (vscrollbar1);
  gtk_object_set_data_full (GTK_OBJECT (main_window), "vscrollbar1", vscrollbar1,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (vscrollbar1);
  gtk_box_pack_end (GTK_BOX (hbox4), vscrollbar1, FALSE, FALSE, 0);

  app_statusbar = gnome_appbar_new (TRUE, TRUE, GNOME_PREFERENCES_NEVER);
  gtk_widget_ref (app_statusbar);
  gtk_object_set_data_full (GTK_OBJECT (main_window), "app_statusbar", app_statusbar,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (app_statusbar);
  gnome_app_set_statusbar (GNOME_APP (main_window), app_statusbar);

  gtk_signal_connect(GTK_OBJECT (main_window), "delete_event", GTK_SIGNAL_FUNC(destroy_win), NULL);
  gtk_signal_connect(GTK_OBJECT (connect_button), "clicked", GTK_SIGNAL_FUNC (on_connect_button_clicked), NULL);
  gtk_signal_connect(GTK_OBJECT (disconnect_button), "clicked", GTK_SIGNAL_FUNC (on_disconnect_button_clicked),NULL);
  gtk_signal_connect(GTK_OBJECT (term), "child_died", GTK_SIGNAL_FUNC (on_disconnect_button_clicked), NULL);
  gtk_signal_connect(GTK_OBJECT (term), "destroy", GTK_SIGNAL_FUNC (on_disconnect_button_clicked), NULL);
  gtk_signal_connect(GTK_OBJECT (preferences_button), "clicked",GTK_SIGNAL_FUNC (on_preferences_button_clicked), NULL);
  gtk_signal_connect(GTK_OBJECT (about_button), "clicked", GTK_SIGNAL_FUNC (on_about_button_clicked), NULL);
  gtk_signal_connect(GTK_OBJECT (entry6), "enter_notify_event", GTK_SIGNAL_FUNC (on_dock_leave), NULL);
  gtk_signal_connect(GTK_OBJECT (hostname_combo_entry), "activate", GTK_SIGNAL_FUNC (on_connect_button_clicked), NULL);
  gtk_widget_grab_focus (hostname_entry);
  if (x_count > 1)  // if it has 1 param (telnet/ssh/rlogin) + a host
     on_connect_button_clicked(NULL, NULL);

  return main_window;
}

void show_term(void)
/*
   Show the terminal window
*/
{
  zvt_term_set_font_name(ZVT_TERM(term), fontstr);
  zvt_term_set_background(ZVT_TERM(term),image_file_location,bgimg_transparent,4);  //addition since v1.2 
// The following line HAS TO BE AFTER gtk_widget_show (main_window), otherwise it will crash with Segmentation Fault
  zvt_term_set_del_key_swap(ZVT_TERM(term),swap_del_backspace); 
  zvt_term_set_color_scheme(ZVT_TERM(term), red, green,blue);
}

GtkWidget* create_message_box (gchar * s) {
/*
   Message box for displaying errors
*/
  GtkWidget *dialog_vbox3;
  GtkWidget *button5;
  GtkWidget *dialog_action_area3;
  GtkWidget *message_box;

  message_box = gnome_message_box_new (s,GNOME_MESSAGE_BOX_INFO, NULL);
  gtk_object_set_data (GTK_OBJECT (message_box), "message_box", message_box);
  gtk_window_set_title (GTK_WINDOW (message_box), _("Information"));
  gtk_window_set_position (GTK_WINDOW (message_box), GTK_WIN_POS_CENTER);
  gtk_window_set_modal (GTK_WINDOW (message_box), TRUE);
  gtk_window_set_policy (GTK_WINDOW (message_box), FALSE, FALSE, FALSE);
  gnome_dialog_close_hides (GNOME_DIALOG (message_box), TRUE);

  dialog_vbox3 = GNOME_DIALOG (message_box)->vbox;
  gtk_object_set_data (GTK_OBJECT (message_box), "dialog_vbox3", dialog_vbox3);
  gtk_widget_show (dialog_vbox3);

  gnome_dialog_append_button (GNOME_DIALOG (message_box), GNOME_STOCK_BUTTON_OK);
  button5 = g_list_last (GNOME_DIALOG (message_box)->buttons)->data;
  gtk_widget_ref (button5);
  gtk_object_set_data_full (GTK_OBJECT (message_box), "button5", button5,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (button5);
  GTK_WIDGET_SET_FLAGS (button5, GTK_CAN_DEFAULT);

  dialog_action_area3 = GNOME_DIALOG (message_box)->action_area;
  gtk_widget_ref (dialog_action_area3);
  gtk_object_set_data_full (GTK_OBJECT (message_box), "dialog_action_area3", dialog_action_area3,
                            (GtkDestroyNotify) gtk_widget_unref);
  return message_box;
}

GtkWidget* create_about_dialog (void)
/*
   Give credits to people who participated making gnome-telnet
*/
{
  GtkWidget *button8;
  GtkWidget *about_dialog;
  GtkWidget *dialog_vbox4;
  GtkWidget *notebook2;
  GtkWidget *vbox7;
  GtkWidget *vbox6;
  GtkWidget *hbox1;  
  GtkWidget *scrolledwindow1;  
  GtkWidget *text1;
  GtkWidget *text3;
  GtkWidget *pixmap2;
  GtkWidget *pixmap3;  

  GtkWidget *table10;

  GtkWidget *label12;
  GtkWidget *label13;  
  GtkWidget *label21;
  GtkWidget *label22;
  GtkWidget *label23;
  GtkWidget *label24;
  GtkWidget *label25;
  GtkWidget *label27;
  GtkWidget *label33;
  GtkWidget *label34;
  
  GtkWidget *href1;
  GtkWidget *href6;
  GtkWidget *href7;
    
  GtkWidget *scrolledwindow4;
  GtkWidget *scrolledwindow2;
  GtkWidget *text2;
  GtkWidget *dialog_action_area4;

  about_dialog = gnome_dialog_new (_("About GTelnet"), NULL);
  gtk_object_set_data (GTK_OBJECT (about_dialog), "about_dialog", about_dialog);
  gtk_widget_set_usize (about_dialog, 600, -2);
  gtk_window_set_policy (GTK_WINDOW (about_dialog), FALSE, FALSE, FALSE);

  dialog_vbox4 = GNOME_DIALOG (about_dialog)->vbox;
  gtk_object_set_data (GTK_OBJECT (about_dialog), "dialog_vbox4", dialog_vbox4);
  gtk_widget_show (dialog_vbox4);

  notebook2 = gtk_notebook_new ();
  gtk_widget_ref (notebook2);
  gtk_object_set_data_full (GTK_OBJECT (about_dialog), "notebook2", notebook2,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (notebook2);
  gtk_box_pack_start (GTK_BOX (dialog_vbox4), notebook2, TRUE, TRUE, 0);

  vbox7 = new_box(about_dialog,"vbox7", vertbox);
  gtk_container_add (GTK_CONTAINER (notebook2), vbox7);
  
  href7 = gnome_href_new ("ghelp:/usr/share/doc/gnome-telnet-2.4/index.html", _("Click here for a complete documentation"));
  gtk_widget_ref (href7);
  gtk_object_set_data_full (GTK_OBJECT (about_dialog), "href7", href7,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (href7);
  gtk_box_pack_start (GTK_BOX (vbox7), href7, FALSE, FALSE, 0);
  

  scrolledwindow1 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_ref (scrolledwindow1);
  gtk_object_set_data_full (GTK_OBJECT (about_dialog), "scrolledwindow1", scrolledwindow1,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (scrolledwindow1);
  gtk_box_pack_start (GTK_BOX (vbox7), scrolledwindow1, TRUE, TRUE, 0);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow1), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);

  text1 = gtk_text_new (NULL, NULL);
  gtk_widget_ref (text1);
  gtk_object_set_data_full (GTK_OBJECT (about_dialog), "text1", text1,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (text1);
  gtk_container_add (GTK_CONTAINER (scrolledwindow1), text1);
  gtk_text_insert (GTK_TEXT (text1), NULL, NULL, NULL,
                   _("GTelnet is a frontend for the following programs:\n\n- Telnet:  to communicate with another host using the TELNET protocol. \n\n- SSH:  ssh (Secure Shell) is a program for logging into a remote machine and for executing commands on a remote machine.  It is intended to replace rlogin and rsh, and provide secure encrypted communications between two untrusted hosts over an insecure network.  X11 connections and arbitrary TCP/IP ports can also be forwarded over the secure channel. (Copied from SSH manual)\n\n- RLogin: rlogin is a program that is a little bit similar to telnet. It is intended to make remote administration over local area network easier, but it can be very insecure. It is recommended that you use SSH instead of rlogin."), 733);

  label33 = new_label (about_dialog,"doc_label",_("Documentation"));
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (notebook2), gtk_notebook_get_nth_page (GTK_NOTEBOOK (notebook2), 0), label33);

  vbox6 = new_box(about_dialog,"vbox6",vertbox);
  gtk_container_add (GTK_CONTAINER (notebook2), vbox6);

  hbox1 = new_box(about_dialog,"hbox1", horzbox);
  gtk_box_pack_start (GTK_BOX (vbox6), hbox1, TRUE, TRUE, 0);

  pixmap2  = gnome_pixmap_new_from_xpm_d(gnome_telnet_xpm);

  gtk_widget_ref (pixmap2);
  gtk_object_set_data_full (GTK_OBJECT (about_dialog), "pixmap2", pixmap2,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (pixmap2);
  gtk_box_pack_start (GTK_BOX (hbox1), pixmap2, TRUE, TRUE, 0);

  label21 = new_label (about_dialog,"about_label","Gnome Telnet v2.4");
  label22 = new_label (about_dialog,"copyright_label",_("Copyright (C) 2000 the Free Software Foundation"));
  label23 = new_label (about_dialog,"blank","");
  label24 = new_label (about_dialog,"desc",_("GTelnet is a frontend to the ole good telnet, ssh, and rlogin"));    
  label25 = new_label (about_dialog,"blank","");  
  label27 = new_label (about_dialog,"auth_label",_("Authors: "));
  
  gtk_box_pack_start (GTK_BOX (vbox6), label21, FALSE, FALSE, 0);  
  gtk_box_pack_start (GTK_BOX (vbox6), label22, FALSE, FALSE, 0);  
  gtk_box_pack_start (GTK_BOX (vbox6), label23, FALSE, FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox6), label24, FALSE, FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox6), label25, FALSE, FALSE, 0);

  href1 = gnome_href_new ("http://***.*****.***", "http://***.*****.***");
  gtk_widget_ref (href1);
  gtk_object_set_data_full (GTK_OBJECT (about_dialog), "href1", href1,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (href1);
  gtk_box_pack_start (GTK_BOX (vbox6), href1, FALSE, FALSE, 0);

  gtk_box_pack_start (GTK_BOX (vbox6), label27, FALSE, FALSE, 0);
  gtk_misc_set_alignment (GTK_MISC (label27), 0, 0.5);

  scrolledwindow4 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_ref (scrolledwindow4);
  gtk_object_set_data_full (GTK_OBJECT (about_dialog), "scrolledwindow4", scrolledwindow4,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (scrolledwindow4);
  gtk_box_pack_start (GTK_BOX (vbox6), scrolledwindow4, TRUE, TRUE, 0);
  gtk_widget_set_usize (scrolledwindow4, -2, 80);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow4), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);

  text3 = gtk_text_new (NULL, NULL);
  gtk_widget_ref (text3);
  gtk_object_set_data_full (GTK_OBJECT (about_dialog), "text3", text3,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (text3);
  gtk_container_add (GTK_CONTAINER (scrolledwindow4), text3);
  gtk_text_insert (GTK_TEXT (text3), NULL, NULL, NULL,"Kenth Anderson <d99kan@du.se> - v1.0\nPrana <*****@*****.***> - v1.1, v1.2, v2.0, v2.1, v2.2, v2.3, v2.4\nMatthias Wimmer <matthias@matthias-wimmer.de> - Deutsch translation\nTakeshi Aihana <aihana@turbolinux.co.jp> - Japanese translation\nGrega Bremec <gregab@gbsoft.org> - Slovene translation + some patches for v2.3", 316);

  label12 = new_label (about_dialog,"auth2_label",_("Authors"));
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (notebook2), gtk_notebook_get_nth_page (GTK_NOTEBOOK (notebook2), 1), label12);

  table10 = gtk_table_new (2, 2, FALSE);
  gtk_widget_ref (table10);
  gtk_object_set_data_full (GTK_OBJECT (about_dialog), "table10", table10,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (table10);
  gtk_container_add (GTK_CONTAINER (notebook2), table10);

  pixmap3  = gnome_pixmap_new_from_xpm_d(stoerer_xpm);
  gtk_widget_ref (pixmap3);
  gtk_object_set_data_full (GTK_OBJECT (about_dialog), "pixmap3", pixmap3,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (pixmap3);
  gtk_table_attach (GTK_TABLE (table10), pixmap3, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);

  scrolledwindow2 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_ref (scrolledwindow2);
  gtk_object_set_data_full (GTK_OBJECT (about_dialog), "scrolledwindow2", scrolledwindow2,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (scrolledwindow2);
  gtk_table_attach (GTK_TABLE (table10), scrolledwindow2, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (GTK_FILL), 0, 0);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow2), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);

  text2 = gtk_text_new (NULL, NULL);
  gtk_widget_ref (text2);
  gtk_object_set_data_full (GTK_OBJECT (about_dialog), "text2", text2,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (text2);
  gtk_container_add (GTK_CONTAINER (scrolledwindow2), text2);
  gtk_text_insert (GTK_TEXT (text2), NULL, NULL, NULL,
                   _("Today, there's a lot of poor children out there who need your help.\n\nFor a dollar a day, you can help change a child's life forever. With your sponsorship, you will help provide basic needs like clean water, schools, clinics and agricultural training that will lift your sponsored child, his/her family, and community - out of poverty.\n\nIf you have the resources available and if you're willing to help those who are less fortunate, please sponsor a child."), 456);

  label34 = new_label (about_dialog,"more_info",_("For more information, please visit:"));
  gtk_table_attach (GTK_TABLE (table10), label34, 0, 1, 1, 2,
                    (GtkAttachOptions) (0), (GtkAttachOptions) (0), 0, 0);

  href6 = gnome_href_new ("http://www.worldvision.com", _("http://www.WorldVision.com"));
  gtk_widget_ref (href6);
  gtk_object_set_data_full (GTK_OBJECT (about_dialog), "href6", href6,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (href6);
  gtk_table_attach (GTK_TABLE (table10), href6, 1, 2, 1, 2,
                    (GtkAttachOptions) (0),
                    (GtkAttachOptions) (0), 0, 0);

  label13 = new_label (about_dialog,"pls_hlp",_("Please Help Needy Children"));
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (notebook2), gtk_notebook_get_nth_page (GTK_NOTEBOOK (notebook2), 2), label13);

  dialog_action_area4 = GNOME_DIALOG (about_dialog)->action_area;
  gtk_object_set_data (GTK_OBJECT (about_dialog), "dialog_action_area4", dialog_action_area4);
  gtk_widget_show (dialog_action_area4);
  gtk_button_box_set_layout (GTK_BUTTON_BOX (dialog_action_area4), GTK_BUTTONBOX_END);
  gtk_button_box_set_spacing (GTK_BUTTON_BOX (dialog_action_area4), 8);

  gnome_dialog_append_button (GNOME_DIALOG (about_dialog), GNOME_STOCK_BUTTON_OK);
  button8 = g_list_last (GNOME_DIALOG (about_dialog)->buttons)->data;
  gtk_widget_ref (button8);
  gtk_object_set_data_full (GTK_OBJECT (about_dialog), "button8", button8,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (button8);
  GTK_WIDGET_SET_FLAGS (button8, GTK_CAN_DEFAULT);

  gtk_signal_connect (GTK_OBJECT (button8), "clicked",
                      GTK_SIGNAL_FUNC (on_about_dialog_cancel_clicked),
                      NULL);

  return about_dialog;
}

GtkWidget* create_property_box (void) {
/*
   Property Box - Preferences - generated by Glade, modified a little bit
*/
  GtkWidget *notebook2;
  GtkWidget *vbox2;
  GtkWidget *vbox3;
  GtkWidget *vbox4;
  
  GtkWidget *table3;
  GtkWidget *table4;
  GtkWidget *table6;  
  GtkWidget *table7;
  
  GtkWidget *temp_label;
   
  GtkWidget *label10;  
  GtkWidget *label11;
  GtkWidget *label12;  
  GtkWidget *label13;
  GtkWidget *label37;
  
  GList *term_type_entry_items = NULL;
  int x;

  property_box = gnome_property_box_new ();
  gtk_object_set_data (GTK_OBJECT (property_box), "property_box", property_box);
  gtk_window_set_title (GTK_WINDOW (property_box), _("Preferences"));
/*  gtk_window_set_position (GTK_WINDOW (property_box), GTK_WIN_POS_CENTER);
  gtk_window_set_modal (GTK_WINDOW (property_box), TRUE);
  gtk_window_set_policy (GTK_WINDOW (property_box), TRUE, TRUE, TRUE);*/

  notebook2 = GNOME_PROPERTY_BOX (property_box)->notebook;
  gtk_object_set_data (GTK_OBJECT (property_box), "notebook2", notebook2);
  gtk_widget_show (notebook2);

  vbox4 = gtk_vbox_new (FALSE, 0);
  gtk_widget_ref (vbox4);
  gtk_object_set_data_full (GTK_OBJECT (property_box), "vbox4", vbox4,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (vbox4);
  gtk_container_add (GTK_CONTAINER (notebook2), vbox4);
  
  // Create telnet checkboxes  
  for (x=0;x < max_telnet_desc; x++) 
     telnet_checkbox[x].widget = new_checkbox(property_box, telnet_checkbox[x].name,telnet_checkbox[x].desc);

  for (x=0;x < 8; x++) 
     gtk_box_pack_start (GTK_BOX (vbox4), (telnet_checkbox[x].widget), FALSE, FALSE, 0);
  
  table6 = gtk_table_new (5, 2, FALSE);
  gtk_widget_ref (table6);
  gtk_object_set_data_full (GTK_OBJECT (property_box), "table6", table6,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (table6);
  gtk_box_pack_start (GTK_BOX (vbox4), table6, FALSE, FALSE, 0);

  gtk_table_attach (GTK_TABLE (table6), telnet_checkbox[8].widget, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  tos_entry = new_entry(property_box, "tos_entry");
  gtk_table_attach (GTK_TABLE (table6), tos_entry, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  atype_entry = new_entry(property_box,"atype_entry");
  gtk_table_attach (GTK_TABLE (table6), atype_entry, 1, 2, 2, 3,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), (GtkAttachOptions) (0), 0, 0);

  realm_entry = new_entry(property_box,"realm_entry");
  gtk_table_attach (GTK_TABLE (table6), realm_entry, 1, 2, 3, 4,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), (GtkAttachOptions) (0), 0, 0);

  gtk_table_attach (GTK_TABLE (table6), telnet_checkbox[10].widget, 0, 1, 2, 3,
                    (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);

  gtk_table_attach (GTK_TABLE (table6), telnet_checkbox[11].widget, 0, 1, 3, 4,
                    (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);

  initchar_entry = gtk_entry_new_with_max_length (10);
  gtk_widget_ref (initchar_entry);
  gtk_object_set_data_full (GTK_OBJECT (property_box), "initchar_entry", initchar_entry,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (initchar_entry);
  gtk_table_attach (GTK_TABLE (table6), initchar_entry, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  gtk_table_attach (GTK_TABLE (table6), telnet_checkbox[9].widget, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);

  tracefiles_entry = gnome_file_entry_new (NULL, _("Trace file"));
  gtk_widget_ref (tracefiles_entry);
  gtk_object_set_data_full (GTK_OBJECT (property_box), "tracefiles_entry", tracefiles_entry,                             (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (tracefiles_entry);
  gtk_table_attach (GTK_TABLE (table6), tracefiles_entry, 1, 2, 4, 5,
                    (GtkAttachOptions) (0), (GtkAttachOptions) (0), 0, 0);
  gnome_file_entry_set_modal (GNOME_FILE_ENTRY (tracefiles_entry), TRUE);

  tracefile_entry = gnome_file_entry_gtk_entry (GNOME_FILE_ENTRY (tracefiles_entry));
  gtk_widget_ref (tracefile_entry);
  gtk_object_set_data_full (GTK_OBJECT (property_box), "tracefile_entry", tracefile_entry,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (tracefile_entry);

  gtk_table_attach (GTK_TABLE (table6), telnet_checkbox[12].widget, 0, 1, 4, 5,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  label10 = new_label (property_box,"tlnt_opt_lbl",_("Telnet Options"));
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (notebook2), gtk_notebook_get_nth_page (GTK_NOTEBOOK (notebook2), 0), label10);

  vbox2 = new_box(property_box,"vbox2",vertbox);
  gtk_container_add (GTK_CONTAINER (notebook2), vbox2);

  for (x=0;x < max_ssh_desc; x++) 
     ssh_checkbox[x].widget = new_checkbox(property_box, ssh_checkbox[x].name, _(ssh_checkbox[x].desc));

  for (x=0;x < 11; x++) 
     gtk_box_pack_start (GTK_BOX (vbox2), (ssh_checkbox[x].widget), FALSE, FALSE, 0);
     
  table3 = gtk_table_new (3, 3, FALSE);
  gtk_widget_ref (table3);
  gtk_object_set_data_full (GTK_OBJECT (property_box), "table3", table3,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (table3);  
  gtk_box_pack_start (GTK_BOX (vbox2), table3, TRUE, TRUE, 0);

  for (x=0;x < 4; x++)
  { 
     gtk_table_attach (GTK_TABLE (table3), ssh_checkbox[x+11].widget, 0, 1, x, x+1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  }
  ssh_encryption_option = gtk_option_menu_new ();
  gtk_widget_ref (ssh_encryption_option);
  gtk_object_set_data_full (GTK_OBJECT (property_box), "ssh_encryption_option", ssh_encryption_option,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (ssh_encryption_option);
  gtk_table_attach (GTK_TABLE (table3), ssh_encryption_option, 1, 2, 3, 4,
                    (GtkAttachOptions) (0), (GtkAttachOptions) (0), 0, 0);
  
  //////////////////////////// 

  ssh_encryption_option_menu = gtk_menu_new ();
  for (x=0; x < 11; x++)
    add_menu_item (select_ssh_encrypt_type, the_encryption_types[x], ssh_encryption_option_menu, (void *) x );
  gtk_option_menu_set_menu (GTK_OPTION_MENU (ssh_encryption_option), ssh_encryption_option_menu);
  
  //////////////////////////// 
  ssh_esc_char_entry = gtk_entry_new_with_max_length (3);
  gtk_widget_ref (ssh_esc_char_entry);
  gtk_object_set_data_full (GTK_OBJECT (property_box), "ssh_esc_char_entry", ssh_esc_char_entry,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (ssh_esc_char_entry);
  gtk_table_attach (GTK_TABLE (table3), ssh_esc_char_entry, 1, 2, 2, 3,
                    (GtkAttachOptions) (GTK_EXPAND),
                    (GtkAttachOptions) (0), 0, 0);

  rsa_identity_entry = gnome_file_entry_new (NULL, NULL);
  gtk_widget_ref (rsa_identity_entry);
  gtk_object_set_data_full (GTK_OBJECT (property_box), "rsa_identity_entry", rsa_identity_entry,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (rsa_identity_entry);
  gtk_table_attach (GTK_TABLE (table3), rsa_identity_entry, 1, 2, 1, 2,
                    (GtkAttachOptions) (0),
                    (GtkAttachOptions) (0), 0, 0);
  gnome_file_entry_set_modal (GNOME_FILE_ENTRY (rsa_identity_entry), TRUE);

  rsa_identity = gnome_file_entry_gtk_entry (GNOME_FILE_ENTRY (rsa_identity_entry));
  gtk_widget_ref (rsa_identity);
  gtk_object_set_data_full (GTK_OBJECT (property_box), "rsa_identity", rsa_identity,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (rsa_identity);

  ssh_debug_level = gtk_entry_new_with_max_length (5);
  gtk_widget_ref (ssh_debug_level);
  gtk_object_set_data_full (GTK_OBJECT (property_box), "ssh_debug_level", ssh_debug_level,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (ssh_debug_level);
  gtk_table_attach (GTK_TABLE (table3), ssh_debug_level, 1, 2, 0, 1,
                    (GtkAttachOptions) (0),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_widget_set_usize (ssh_debug_level, 50, -2);

  label11 = new_label (property_box,"sshopt_lbl",_("SSH Options"));
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (notebook2), gtk_notebook_get_nth_page (GTK_NOTEBOOK (notebook2), 1), label11);

  vbox3 = gtk_vbox_new (FALSE, 0);
  gtk_widget_ref (vbox3);
  gtk_object_set_data_full (GTK_OBJECT (property_box), "vbox3", vbox3,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (vbox3);
  gtk_container_add (GTK_CONTAINER (notebook2), vbox3);

  for (x=0;x < max_rlogin_desc; x++) 
     rlogin_checkbox[x].widget = new_checkbox(property_box, rlogin_checkbox[x].name,rlogin_checkbox[x].desc);

  for (x=0;x < 6; x++) 
     gtk_box_pack_start (GTK_BOX (vbox3), (rlogin_checkbox[x].widget), FALSE, FALSE, 0);

  table7 = gtk_table_new (2, 2, FALSE);
  gtk_widget_ref (table7);
  gtk_object_set_data_full (GTK_OBJECT (property_box), "table7", table7,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (table7);
  gtk_box_pack_start (GTK_BOX (vbox3), table7, FALSE, FALSE, 0);

  init_rlogin_esc_entry = gtk_entry_new_with_max_length (10);
  gtk_widget_ref (init_rlogin_esc_entry);
  gtk_object_set_data_full (GTK_OBJECT (property_box), "init_rlogin_esc_entry", init_rlogin_esc_entry,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (init_rlogin_esc_entry);
  gtk_table_attach (GTK_TABLE (table7), init_rlogin_esc_entry, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  gtk_table_attach (GTK_TABLE (table7), rlogin_checkbox[7].widget, 0, 1, 1, 2,
                    (GtkAttachOptions) (0),
                    (GtkAttachOptions) (0), 0, 0);

  gtk_table_attach (GTK_TABLE (table7), rlogin_checkbox[6].widget, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  rlogin_ticket_entry = gtk_entry_new_with_max_length (10);
  gtk_widget_ref (rlogin_ticket_entry);
  gtk_object_set_data_full (GTK_OBJECT (property_box), "rlogin_ticket_entry", rlogin_ticket_entry,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (rlogin_ticket_entry);
  gtk_table_attach (GTK_TABLE (table7), rlogin_ticket_entry, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  label12 = new_label (property_box,"rlogin_label",_("RLogin Options"));
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (notebook2), gtk_notebook_get_nth_page (GTK_NOTEBOOK (notebook2), 2),label12);

  table4 = gtk_table_new (9, 2, FALSE);
  gtk_widget_ref (table4);
  gtk_object_set_data_full (GTK_OBJECT (property_box), "table4", table4,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (table4);
  gtk_container_add (GTK_CONTAINER (notebook2), table4);

  for (x = 0; x < 6;x ++)
  {
     temp_label = new_label (property_box,display_option_labels[x].name,display_option_labels[x].desc);
     gtk_table_attach (GTK_TABLE (table4), temp_label, 0, 1, x, x+1,
                    (GtkAttachOptions) (0), (GtkAttachOptions) (0), 0, 0);
  } // end for

  transparent_checkbox = new_checkbox(property_box, "trans_checkbox", "Transparent");
  gtk_table_attach (GTK_TABLE (table4), transparent_checkbox, 1, 2, 6, 7,
                    (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);

  label37 = new_label (property_box,"ttp_label",_("Terminal type:"));
  gtk_table_attach (GTK_TABLE (table4), label37, 0, 1, 7, 8,
                    (GtkAttachOptions) (0),
                    (GtkAttachOptions) (0), 0, 0);                    

  bgimage_combo_entry = gnome_file_entry_new (NULL, NULL);
  gtk_widget_ref (bgimage_combo_entry);
  gtk_object_set_data_full (GTK_OBJECT (property_box), "bgimage_combo_entry", bgimage_combo_entry,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (bgimage_combo_entry);
  gtk_table_attach (GTK_TABLE (table4), bgimage_combo_entry, 1, 2, 5, 6,
                    (GtkAttachOptions) (0),
                    (GtkAttachOptions) (0), 0, 0);
  gnome_file_entry_set_modal (GNOME_FILE_ENTRY (bgimage_combo_entry), TRUE);

  bgimage_fileentry = gnome_file_entry_gtk_entry (GNOME_FILE_ENTRY (bgimage_combo_entry));
  gtk_widget_ref (bgimage_fileentry);
  gtk_object_set_data_full (GTK_OBJECT (property_box), "bgimage_fileentry", bgimage_fileentry,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (bgimage_fileentry);

  fontpicker = gnome_font_picker_new ();
  gtk_widget_ref (fontpicker);
  gtk_object_set_data_full (GTK_OBJECT (property_box), "fontpicker", fontpicker,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (fontpicker);
  gtk_table_attach (GTK_TABLE (table4), fontpicker, 1, 2, 4, 5,
                    (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
                    
  gnome_font_picker_set_mode (GNOME_FONT_PICKER (fontpicker), GNOME_FONT_PICKER_MODE_FONT_INFO);
  gnome_font_picker_fi_set_use_font_in_label (GNOME_FONT_PICKER (fontpicker),
                                              TRUE, 14);

  dircolor_picker = gnome_color_picker_new ();
  gtk_widget_ref (dircolor_picker);
  gtk_object_set_data_full (GTK_OBJECT (property_box), "dircolor_picker", dircolor_picker,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (dircolor_picker);
  gtk_table_attach (GTK_TABLE (table4), dircolor_picker, 1, 2, 3, 4,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  execolor_picker = gnome_color_picker_new ();
  gtk_widget_ref (execolor_picker);
  gtk_object_set_data_full (GTK_OBJECT (property_box), "execolor_picker", execolor_picker,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (execolor_picker);
  gtk_table_attach (GTK_TABLE (table4), execolor_picker, 1, 2, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  fgcolor_picker = gnome_color_picker_new ();
  gtk_widget_ref (fgcolor_picker);
  gtk_object_set_data_full (GTK_OBJECT (property_box), "fgcolor_picker", fgcolor_picker,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (fgcolor_picker);
  gtk_table_attach (GTK_TABLE (table4), fgcolor_picker, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  bgcolor_picker = gnome_color_picker_new ();
  gtk_widget_ref (bgcolor_picker);
  gtk_object_set_data_full (GTK_OBJECT (property_box), "bgcolor_picker", bgcolor_picker,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (bgcolor_picker);
  gtk_table_attach (GTK_TABLE (table4), bgcolor_picker, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

///////////////////////////////////////////////////////////////////////////////
  term_type_entry = gtk_combo_new ();
  gtk_widget_ref (term_type_entry);
  gtk_object_set_data_full (GTK_OBJECT (property_box), "term_type_entry", term_type_entry,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (term_type_entry);
  gtk_table_attach (GTK_TABLE (table4), term_type_entry, 1, 2, 7, 8,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  for (x=0;x < 41;x++) // from 1 to 40
  {
     term_type_entry_items = g_list_append (term_type_entry_items, the_terminal_types[x]);     
  }

  swap_del_key_checkbox = new_checkbox(property_box, "swap_del_key", "Swap the Del and Backspace Key");
  gtk_table_attach (GTK_TABLE (table4), swap_del_key_checkbox, 1, 2, 8, 9,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  gtk_combo_set_popdown_strings (GTK_COMBO (term_type_entry), term_type_entry_items);
  g_list_free (term_type_entry_items);

  term_type_combo_entry = GTK_COMBO (term_type_entry)->entry;
  gtk_widget_ref (term_type_combo_entry);
  gtk_object_set_data_full (GTK_OBJECT (property_box), "term_type_combo_entry", term_type_combo_entry,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (term_type_combo_entry);

//////////////////////////////////////////////////////////////////////////////////////////
  label13 = new_label (property_box,"disp_sttngs",_("Display Settings"));
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (notebook2), gtk_notebook_get_nth_page (GTK_NOTEBOOK (notebook2),3),label13);

  gtk_signal_connect(GTK_OBJECT(property_box),"apply", GTK_SIGNAL_FUNC (on_pref_ok_button_clicked), NULL);
  gtk_signal_connect(GTK_OBJECT(property_box),"help", GTK_SIGNAL_FUNC (on_pref_help_button_clicked), NULL);
  
  ////////////////////////////////////////////////////
  for (x=0; x < max_telnet_desc; x++)
  {
     gtk_signal_connect(GTK_OBJECT(telnet_checkbox[x].widget), "clicked", GTK_SIGNAL_FUNC(changed), NULL);
     gtk_signal_connect(GTK_OBJECT(ssh_checkbox[x].widget), "clicked", GTK_SIGNAL_FUNC(changed), NULL);
  }

  ////////////////////////////////////////////////////  
  for (x=max_ssh_desc - max_telnet_desc - 1; x < max_ssh_desc; x++)
     gtk_signal_connect(GTK_OBJECT(ssh_checkbox[x].widget), "clicked", GTK_SIGNAL_FUNC(changed), NULL);

  for (x=0; x < max_rlogin_desc; x++)
     gtk_signal_connect(GTK_OBJECT(rlogin_checkbox[x].widget), "clicked", GTK_SIGNAL_FUNC(changed), NULL);
  ////////////////////////////////////////////////////
  
  gtk_signal_connect(GTK_OBJECT(tos_entry), "changed", GTK_SIGNAL_FUNC(changed), NULL);
  gtk_signal_connect(GTK_OBJECT(atype_entry), "changed", GTK_SIGNAL_FUNC(changed), NULL);
  gtk_signal_connect(GTK_OBJECT(tracefiles_entry), "browse_clicked", GTK_SIGNAL_FUNC(changed), NULL);
  gtk_signal_connect(GTK_OBJECT(realm_entry), "changed", GTK_SIGNAL_FUNC(changed), NULL);
  gtk_signal_connect(GTK_OBJECT(rlogin_ticket_entry), "changed", GTK_SIGNAL_FUNC(changed), NULL);
  gtk_signal_connect(GTK_OBJECT(ssh_esc_char_entry), "changed", GTK_SIGNAL_FUNC(changed), NULL);
  gtk_signal_connect(GTK_OBJECT(init_rlogin_esc_entry), "changed", GTK_SIGNAL_FUNC(changed), NULL);  
  gtk_signal_connect(GTK_OBJECT(bgcolor_picker), "clicked", GTK_SIGNAL_FUNC(changed), NULL);
  gtk_signal_connect(GTK_OBJECT(fgcolor_picker), "clicked", GTK_SIGNAL_FUNC(changed), NULL);
  gtk_signal_connect(GTK_OBJECT(dircolor_picker), "clicked", GTK_SIGNAL_FUNC(changed), NULL);
  gtk_signal_connect(GTK_OBJECT(execolor_picker), "clicked", GTK_SIGNAL_FUNC(changed), NULL);
  gtk_signal_connect(GTK_OBJECT(fontpicker), "clicked", GTK_SIGNAL_FUNC(changed), NULL);
  gtk_signal_connect(GTK_OBJECT(bgimage_combo_entry), "browse_clicked", GTK_SIGNAL_FUNC(changed), NULL);
  gtk_signal_connect(GTK_OBJECT(term_type_combo_entry),"changed", GTK_SIGNAL_FUNC(changed), NULL);

  return property_box;
}

GtkWidget* create_ssh_dialog (void)
{
  GtkWidget *dialog_vbox5, *scrolledwindow5, *text4;
  GtkWidget *table11;
  GtkWidget *label36;
  GtkWidget *dialog_action_area5;
  GtkWidget *ssh_login_ok_button;
  GtkWidget *ssh_login_cancel_button;

  GtkAccelGroup *accel_group;
  
  accel_group = gtk_accel_group_new ();
  ssh_dialog = gnome_dialog_new (_("SSH Login"), NULL);
  gtk_object_set_data (GTK_OBJECT (ssh_dialog), "ssh_dialog", ssh_dialog);
  gtk_window_set_default_size (GTK_WINDOW (ssh_dialog), 400, 200);  
  gtk_window_set_modal(GTK_WINDOW(ssh_dialog), TRUE);
  gtk_window_set_position(GTK_WINDOW (ssh_dialog), GTK_WIN_POS_CENTER);
  gtk_window_set_policy (GTK_WINDOW (ssh_dialog), TRUE, TRUE, TRUE);

  dialog_vbox5 = GNOME_DIALOG (ssh_dialog)->vbox;
  gtk_object_set_data (GTK_OBJECT (ssh_dialog), "dialog_vbox5", dialog_vbox5);
  gtk_widget_show (dialog_vbox5);

  table11 = gtk_table_new (2, 2, FALSE);
  gtk_widget_ref (table11);
  gtk_object_set_data_full (GTK_OBJECT (ssh_dialog), "table11", table11,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (table11);
  gtk_box_pack_start (GTK_BOX (dialog_vbox5), table11, TRUE, TRUE, 0);

  label36 = new_label (ssh_dialog,"usrname_label",_("Username:"));
  gtk_table_attach (GTK_TABLE (table11), label36, 0, 1, 1, 2,
                    (GtkAttachOptions) (0),
                    (GtkAttachOptions) (0), 0, 0);

  ssh_login_entry = gnome_entry_new ("user_history");
  gnome_entry_load_history(GNOME_ENTRY(ssh_login_entry));
  
  gtk_widget_ref (ssh_login_entry);
  gtk_object_set_data_full (GTK_OBJECT (ssh_dialog), "ssh_login_entry", ssh_login_entry,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (ssh_login_entry);
  gtk_table_attach (GTK_TABLE (table11), ssh_login_entry, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  ssh_login_combo_entry = gnome_entry_gtk_entry (GNOME_ENTRY (ssh_login_entry));
  gtk_widget_ref (ssh_login_combo_entry);
  gtk_object_set_data_full (GTK_OBJECT (ssh_dialog), "ssh_login_combo_entry", ssh_login_combo_entry,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (ssh_login_combo_entry);

  scrolledwindow5 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_ref (scrolledwindow5);
  gtk_object_set_data_full (GTK_OBJECT (ssh_dialog), "scrolledwindow5", scrolledwindow5,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (scrolledwindow5);
  gtk_table_attach (GTK_TABLE (table11), scrolledwindow5, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow5), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);

  text4 = gtk_text_new (NULL, NULL);
  gtk_widget_ref (text4);
  gtk_object_set_data_full (GTK_OBJECT (ssh_dialog), "text4", text4,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (text4);
  gtk_container_add (GTK_CONTAINER (scrolledwindow5), text4);
  gtk_text_insert (GTK_TEXT (text4), NULL, NULL, NULL,
                   _("If you don't want to see this login box, type user@hostname.com in the host name entry, and to restore the previous settings you can click the pulldown button next to it to retrieve the history. Now please type your user name/login below!"), 238);

   
  dialog_action_area5 = GNOME_DIALOG (ssh_dialog)->action_area;
  gtk_object_set_data (GTK_OBJECT (ssh_dialog), "dialog_action_area5", dialog_action_area5);
  gtk_widget_show (dialog_action_area5);
  gtk_button_box_set_layout (GTK_BUTTON_BOX (dialog_action_area5), GTK_BUTTONBOX_END);
  gtk_button_box_set_spacing (GTK_BUTTON_BOX (dialog_action_area5), 8);

  gnome_dialog_append_button (GNOME_DIALOG (ssh_dialog), GNOME_STOCK_BUTTON_OK);
  ssh_login_ok_button = g_list_last (GNOME_DIALOG (ssh_dialog)->buttons)->data;
  gtk_widget_ref (ssh_login_ok_button);
  gtk_object_set_data_full (GTK_OBJECT (ssh_dialog), "ssh_login_ok_button", ssh_login_ok_button,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (ssh_login_ok_button);
  GTK_WIDGET_SET_FLAGS (ssh_login_ok_button, GTK_CAN_DEFAULT | GTK_HAS_DEFAULT);

//// Cancel button

  gnome_dialog_append_button (GNOME_DIALOG (ssh_dialog), GNOME_STOCK_BUTTON_CANCEL);
  ssh_login_cancel_button = g_list_last (GNOME_DIALOG (ssh_dialog)->buttons)->data;
  gtk_widget_ref (ssh_login_cancel_button);
  gtk_object_set_data_full (GTK_OBJECT (ssh_dialog), "ssh_login_cancel_button", ssh_login_cancel_button,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (ssh_login_cancel_button);

  gtk_signal_connect(GTK_OBJECT (ssh_login_combo_entry),"activate",
    GTK_SIGNAL_FUNC(on_ssh_login_ok_button_clicked),NULL);

  gtk_signal_connect(GTK_OBJECT (ssh_login_ok_button),"clicked",
    GTK_SIGNAL_FUNC(on_ssh_login_ok_button_clicked),NULL);
    
  gtk_signal_connect(GTK_OBJECT(ssh_login_cancel_button),"clicked",
    GTK_SIGNAL_FUNC(on_ssh_login_cancel_button_clicked),NULL);
    
  gtk_window_add_accel_group (GTK_WINDOW (ssh_dialog), accel_group);
  gtk_widget_grab_focus (ssh_login_combo_entry);
  return ssh_dialog;
}

/////////////////////////////////////////// HANDLER /////////////////////////////////////////
char *config_telnet[] =
   {
  "telnet_eight_bit_data_path", 	//1
  "telnet_eight_bit_data_path_output", 	//2 
  "telnet_stop_recognize_esc", 		//3
  "telnet_forward_local_credentials", 	//4
  "telnet_automatic_login",		//5
  "telnet_rlogin_style",		//6
  "telnet_encrypt", 			//7
  "telnet_debug", 			//8
  "telnet_init_char",   		//9
  "telnet_TOS", 			//10
  "telnet_disable_atype", 		//11
  "telnet_realm_host", 			//12
  "telnet_trace_file" 			//13
   };

char *config_ssh[] =
   {
   "ssh_dev_null",			//1
   "ssh_disable_auth_forward",		//2
   "ssh_disable_x11",			//3
   "ssh_tty",				//4
   "ssh_verbose",			//5
   "ssh_no_priv_ports",			//6
   "ssh_quiet",				//7
   "ssh_fork_bg",			//8
   "ssh_compress",			//9
   "ssh_allow_remote_to_forwarded_port",//10
   "ssh_no_request_session_channel",	//11
   "ssh_debug_level", 			//12   
   "ssh_rsa_id",			//13
   "ssh_init_char",			//14
   "ssh_encrypt_algorithm"		//15
  };

char *config_rlogin[] =
{
  "rlogin_eight_bit_data_path",		//1
  "rlogin_stop_recognize_esc",		//2
  "rlogin_kerberos_off",		//3
  "rlogin_litout",			//4
  "rlogin_debug",			//5
  "rlogin_encrypt",			//6
  "rlogin_init_char",  			//7
  "rlogin_realm_host"			//8
};

  enum connect_with {telnet, ssh, rlogin};
  char *connect_with_program[3] = {"telnet","ssh","rlogin"};

void setarg(char *s) {
/*	
   set arguments[n_counter] to s
*/
   arguments[n_counter] = s;
   n_counter++;   
}

void set_string_opt(char *flag, char *s) {
/*
   Set argument with flag + opt -- just for code cleanup
*/
   char *prgopt;
   int length;
   gchar *value;
   
   value=gnome_config_get_string(s);
   length = strlen(value);   
   if (length != 0) {
       prgopt = (char *) malloc (strlen(flag) + length + 2);
       sprintf(prgopt, "%s%s", flag, value);
       setarg(prgopt);
      }
}

void set_direct_string_opt(char *flag, char *value) {
/*
   Set argument with string (directly without fetching from config) + opt -- just for code cleanup
*/
   char *prgopt;
   int length;
   
   length = strlen(value);
   if (length != 0) {
       prgopt = (char *) malloc (strlen(flag) + length + 2);
       sprintf(prgopt, "%s%s", flag, value);
       setarg(prgopt);
      }
}

void set_flag_opt(char *flag, char *s) {
/*
   Set argument with flag -- just for code cleanup
*/
   if (gnome_config_get_bool(s)) setarg(strdup(flag));
}

void setbutton(GtkWidget *button, gchar *s) {
/*
   Just for code cleanup
*/
 gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(button),gnome_config_get_bool(s));  
}

void setbutton_string(GtkWidget *checkbox, GtkWidget *entry, char *s) {
/*
   Just for code clean up
*/

  if (strlen(gnome_config_get_string(s))!= 0) {
     gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbox),TRUE);
     gtk_entry_set_text(GTK_ENTRY(entry),gnome_config_get_string(s));
    }
}

void setaccordingto_string(GtkWidget *checkbox, GtkWidget *entry, gchar *s) {
/*
   Just for code cleanup -- redundancy
*/
   if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkbox))) 
        gnome_config_set_string(s,gtk_entry_get_text(GTK_ENTRY(entry))); 
   else
        gnome_config_set_string(s,"");
}

void setaccordingto(GtkWidget *obj, gchar *s) {
/*
   Set the config
*/
   gboolean b;
   
   b=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(obj));
   gnome_config_set_bool(s,b);
}

void getoption() {
/*
   Get options & parameters for telnet, ssh, rlogin
*/
  int x;

  n_counter = 0;
  for (x=0;x <=15;x++)
    arguments[x] = NULL;

 switch (connection_type) {
 case 0: { // Case Telnet
   setarg(strdup("telnet"));
   gnome_config_push_prefix("gnome-telnet/gtelnet/");
   // DON'T SORT THE ORDER !! Just Don't. Forbidden -- Prana Oct 21, 2000
   set_flag_opt("-8",config_telnet[0]);
   set_flag_opt("-E",config_telnet[2]);
   set_flag_opt("-F",config_telnet[3]);
   set_flag_opt("-L",config_telnet[1]);
   set_string_opt("-S",config_telnet[9]);
   set_string_opt("-X",config_telnet[10]);
   set_flag_opt("-a",config_telnet[4]);
   set_flag_opt("-d",config_telnet[7]);
   set_string_opt("-e",config_telnet[8]);  
   set_string_opt("-k",config_telnet[11]);
   set_string_opt("-n",config_telnet[12]);  
   set_flag_opt("-r",config_telnet[5]);
   set_flag_opt("-x",config_telnet[6]);
   break;
} // End option switch case 0 : telnet
 case 1:  // Case SSH
   setarg(strdup("ssh"));
   gnome_config_push_prefix("gnome-telnet/gtelnet/");   
   // DON'T SORT THE ORDER ! It's a taboo -- Prana Oct 21, 2000   
   set_flag_opt("-n",config_ssh[0]);
   set_flag_opt("-a",config_ssh[1]);
   set_flag_opt("-x",config_ssh[2]);
   set_flag_opt("-t",config_ssh[3]);
   set_flag_opt("-v",config_ssh[4]);
   set_flag_opt("-P",config_ssh[5]);
   set_string_opt("-d",config_ssh[12]);
   set_flag_opt("-q",config_ssh[6]);
   set_flag_opt("-f",config_ssh[7]);
   set_flag_opt("-C",config_ssh[8]);
   set_flag_opt("-g",config_ssh[9]);
   set_flag_opt("-S",config_ssh[10]);
   set_string_opt("-i",config_ssh[12]);
   set_string_opt("-e",config_ssh[13]);
   set_string_opt("-c",config_ssh[14]);
   if (ssh_user)
    if (strcmp(ssh_user,""))
    {
      set_direct_string_opt("-l", ssh_user);
      free(ssh_user);
    }
   break;
    // End case SSH
case 3 : { // case RLOGIN
  setarg(strdup("rlogin"));
  gnome_config_push_prefix("gnome-telnet/gtelnet/");   
  set_flag_opt("-8",config_ssh[0]);
  set_flag_opt("-E",config_ssh[1]);
  set_flag_opt("-K",config_ssh[2]);
  set_flag_opt("-L",config_ssh[3]);
  set_flag_opt("-d",config_ssh[4]);
  set_flag_opt("-x",config_ssh[5]);
  set_string_opt("-e",config_ssh[6]);
  set_string_opt("-k",config_ssh[7]);  
}
} // End Switch
   host = strdup( gtk_entry_get_text(GTK_ENTRY(hostname_combo_entry)) );
   setarg(host);
   port = strdup( gtk_entry_get_text(GTK_ENTRY(port_entry)) );
   if (strcmp(port,"") != 0) setarg(port);
   arguments[n_counter] = NULL;
   gnome_config_pop_prefix();
}


static void free_everything(void) {
/*
   Free everything 
*/
   int x;
   for (x=0;x <=15;x++) if (arguments[x]!=NULL) free(arguments[x]);
}

static void run_program(void) {
/*
   When the user press "Connect" button
*/
        GtkWidget *msgbox;
        
        getoption();
        if (strcmp(host,"")==0)
        {
           msgbox=create_message_box(_("Please fill in the host name :-)"));
           gtk_widget_show(msgbox);
           free_everything();
           return; // we don't want some crash here tooo :-) 
        }
        gnome_entry_prepend_history(GNOME_ENTRY(hostname_entry),TRUE,host);
        gtk_widget_grab_focus (term);
	gnome_appbar_set_status(GNOME_APPBAR(app_statusbar),"Connected");
        gnome_appbar_set_progress(GNOME_APPBAR(app_statusbar),1.0);
        gtk_widget_show(term);
        switch(zvt_term_forkpty(ZVT_TERM(term), TRUE)) {
        case -1:
           on_disconnect_button_clicked(NULL,NULL);
           break;
        case 0:
           execvp(connect_with_program[connection_type],arguments);
           break;
        } // end switch zvt_term_forkpty
        free_everything();
}

void on_connect_button_clicked (GtkButton *button, gpointer user_data) {

    GtkWidget *ssh_dialog_box, *msgbox;
    gchar *temp_error;
#ifndef HAVE_SETENV    
    int len = 0;
    char *the_variable = NULL;
#endif    
    // 15th October 2000
    // Check if the program is available or not...
    // I got a report that when SSH is not installed it cannot do SSH ;) hehehe
    gnome_config_push_prefix("gnome-telnet/gtelnet/");
#ifdef HAVE_SETENV
    setenv("TERM",gnome_config_get_string("terminal_type"),1);
#else
// I forgot who sent me the patch for SunOS..
// If you're the person, please let me know and I'll add you to the credit..
// patch for SunOS 5.x or Solaris 2.x ..
// dirty hack
    len = strlen ("TERM")+1+strlen(gnome_config_get_string("terminal_type"));
    the_variable = (char *) malloc (len + 1);
    sprintf(the_variable, "TERM=%s", gnome_config_get_string("terminal_type") );
    putenv(the_variable);
    free (the_variable);
#endif
    gnome_config_sync();
    gnome_config_pop_prefix();
    
    if (!gnome_is_program_in_path(connect_with_program[connection_type]))
    {
      temp_error = (char *) malloc (300);
      sprintf(temp_error,"'%s' has not been installed in your machine.\nPlease click the Help button on the toolbar\nand press the \"Click here for more documentation\" button", connect_with_program[connection_type]);
      msgbox=create_message_box(temp_error);
      gtk_widget_show(msgbox);
      free(temp_error);
      return; // we don't want some crash here :-) 
    }
    
   if (connection_type!=ssh)
      run_program(); 
   else if (!strchr(gtk_entry_get_text(GTK_ENTRY(hostname_combo_entry)),'@'))
   // if there's no username@hostname prompt for user name
      {
         ssh_dialog_box=create_ssh_dialog();
         gtk_widget_show(ssh_dialog);
      }
   else run_program();
}

void on_term_died (ZvtTerm *term)
{
	zvt_term_closepty(ZVT_TERM(term));
	gnome_appbar_set_status(GNOME_APPBAR(app_statusbar),_("Not connected"));
        gnome_appbar_set_progress(GNOME_APPBAR(app_statusbar),0.0);        
	zvt_term_reset(ZVT_TERM(term), TRUE);        
}

void on_disconnect_button_clicked (GtkButton *button, gpointer  user_data)
/*
   When the user press "Disconnect" button
*/
{
	zvt_term_closepty(ZVT_TERM(term));
	gnome_appbar_set_status(GNOME_APPBAR(app_statusbar),_("Not connected"));
        gnome_appbar_set_progress(GNOME_APPBAR(app_statusbar),0.0);        
	zvt_term_reset(ZVT_TERM(term), TRUE);
}

void on_about_button_clicked (GtkButton *button, gpointer user_data)
/*
   Show up the About dialog
*/
{
 about_dialog = create_about_dialog ();
 gtk_widget_show (about_dialog);
}

void on_preferences_button_clicked (GtkButton *button, gpointer  user_data)
/*
   Show preferences dialog
*/
{
  gchar *s;
  int x;

  property_box = create_property_box ();
  gnome_config_push_prefix("gnome-telnet/gtelnet/");
/*********** Doing telnet ****************/
  for (x=0;x < 8; x++)
     setbutton(telnet_checkbox[x].widget,config_telnet[x]);

  setbutton_string(telnet_checkbox[8].widget,initchar_entry, config_telnet[8]);
  setbutton_string(telnet_checkbox[9].widget,tos_entry, config_telnet[9]);
  setbutton_string(telnet_checkbox[10].widget,atype_entry, config_telnet[10]);    
  setbutton_string(telnet_checkbox[11].widget,realm_entry, config_telnet[11]);  
  setbutton_string(telnet_checkbox[12].widget,tracefile_entry,config_telnet[12]);  
  gnome_file_entry_set_default_path(GNOME_FILE_ENTRY(tracefiles_entry),gnome_config_get_string(config_telnet[12]));

/*********** Doing ssh ****************/

  for (x=0;x < 11; x++)
     setbutton(ssh_checkbox[x].widget,config_ssh[x]);

   setbutton_string(ssh_checkbox[11].widget,ssh_debug_level, config_ssh[11]);   
   setbutton_string(ssh_checkbox[12].widget,rsa_identity, config_ssh[12]);
   gnome_file_entry_set_default_path(GNOME_FILE_ENTRY(rsa_identity_entry),gnome_config_get_string(config_ssh[12]));
   setbutton_string(ssh_checkbox[13].widget,ssh_esc_char_entry,config_ssh[13]);
   s = gnome_config_get_string(config_ssh[14]);
  if (strlen(s)!= 0)
  {
     gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(ssh_checkbox[14].widget),TRUE);  
     for (x=0; x < 11; x++)
     {
       if (strcmp(s,the_encryption_types[x])==0)
       {
        gtk_option_menu_set_history(GTK_OPTION_MENU(ssh_encryption_option),x);
        ssh_encrypt_type=x;
       } // end if
    } // end for
  } // end if
/*********** Doing Rlogin ****************/
  for (x=0;x < 6; x++)
     setbutton(rlogin_checkbox[x].widget,config_rlogin[x]);

  setbutton_string(rlogin_checkbox[6].widget,init_rlogin_esc_entry, config_rlogin[6]);
  setbutton_string(rlogin_checkbox[7].widget,rlogin_ticket_entry, config_rlogin[7]);  

/*********** Doing display settings ****************/

 gnome_color_picker_set_i16(GNOME_COLOR_PICKER(bgcolor_picker), red[17], green[17], blue[17], 0);
 gnome_color_picker_set_i16(GNOME_COLOR_PICKER(fgcolor_picker), red[16], green[16], blue[16], 0);
 gnome_color_picker_set_i16(GNOME_COLOR_PICKER(execolor_picker), red[10], green[10], blue[10], 0);
 gnome_color_picker_set_i16(GNOME_COLOR_PICKER(dircolor_picker), red[12], green[12], blue[12], 0);
 gnome_font_picker_set_font_name(GNOME_FONT_PICKER(fontpicker), fontstr);
 gnome_font_picker_set_mode(GNOME_FONT_PICKER(fontpicker), GNOME_FONT_PICKER_MODE_FONT_INFO);

 /* Image */
 gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(transparent_checkbox),bgimg_transparent);
 gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(swap_del_key_checkbox),swap_del_backspace);
 
 gtk_entry_set_text (GTK_ENTRY (bgimage_fileentry),gnome_config_get_string("background_image")); 
 
 gnome_file_entry_set_default_path(GNOME_FILE_ENTRY(bgimage_combo_entry),image_file_location);
 
 /* Terminal Type */
 gtk_entry_set_text (GTK_ENTRY (term_type_combo_entry), gnome_config_get_string("terminal_type"));
 /********/ 

 gnome_config_sync();
 gnome_config_pop_prefix();
 gtk_widget_show (property_box); 

}

void on_pref_ok_button_clicked (GtkButton *button, gpointer user_data)
/*
   This function is called whenever the user
   press "Apply" or "OK" button in the preferences/property dialog
*/
{
   gboolean select_encr_algrthm;
   int x;
     
  /* Read/Write Configuration */  
  
  gnome_config_push_prefix("gnome-telnet/gtelnet/");
  for (x=0;x < 8; x++)
     setaccordingto(telnet_checkbox[x].widget,config_telnet[x]);

  setaccordingto_string(telnet_checkbox[8].widget, initchar_entry,config_telnet[8]);
  setaccordingto_string(telnet_checkbox[9].widget, tos_entry, config_telnet[9]);
  setaccordingto_string(telnet_checkbox[10].widget,atype_entry, config_telnet[10]);
  setaccordingto_string(telnet_checkbox[11].widget,realm_entry, config_telnet[11]);
         
   if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(telnet_checkbox[12].widget)))
      gnome_config_set_string(config_telnet[12],gnome_file_entry_get_full_path(GNOME_FILE_ENTRY(tracefiles_entry),0));
   else
      gnome_config_set_string(config_telnet[12],"");

/*********** Doing ssh ****************/

  for (x=0;x < 11; x++)
     setaccordingto(ssh_checkbox[x].widget,config_ssh[x]);

  setaccordingto_string(ssh_checkbox[11].widget,ssh_debug_level,config_ssh[11]);

  if (gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON( ssh_checkbox[12].widget ) ))   
     gnome_config_set_string(config_ssh[12],gnome_file_entry_get_full_path(GNOME_FILE_ENTRY(rsa_identity_entry),0));
  else
     gnome_config_set_string(config_ssh[12],"");
  
  setaccordingto_string(ssh_checkbox[13].widget,ssh_esc_char_entry, config_ssh[13]);
  select_encr_algrthm=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(ssh_checkbox[14].widget));
  if (select_encr_algrthm)
     gnome_config_set_string(config_ssh[14],the_encryption_types[ssh_encrypt_type]);
  else
     gnome_config_set_string(config_ssh[14],"");
     
/*********** Doing Rlogin ****************/

  for (x=0;x < 6; x++)
     setaccordingto(rlogin_checkbox[x].widget,config_rlogin[x]);

  setaccordingto_string(rlogin_checkbox[6].widget,init_rlogin_esc_entry, config_rlogin[6]);
  setaccordingto_string(rlogin_checkbox[7].widget,rlogin_ticket_entry, config_rlogin[7]);

/* Here goes Kenth's functions from coloring it from v1.0 - unchanged */

 gdk_color_background.red=(guint16)((GNOME_COLOR_PICKER(bgcolor_picker)->r)*65535.0);
 gdk_color_background.green=(guint16)((GNOME_COLOR_PICKER(bgcolor_picker)->g)*65535.0);
 gdk_color_background.blue=(guint16)((GNOME_COLOR_PICKER(bgcolor_picker)->b)*65535.0);

 red[17]=gdk_color_background.red;
 green[17]=gdk_color_background.green;
 blue[17]=gdk_color_background.blue;
 
 gdk_color_forground.red=(guint16)((GNOME_COLOR_PICKER(fgcolor_picker)->r)*65535.0);
 gdk_color_forground.green=(guint16)((GNOME_COLOR_PICKER(fgcolor_picker)->g)*65535.0);
 gdk_color_forground.blue=(guint16)((GNOME_COLOR_PICKER(fgcolor_picker)->b)*65535.0);
	
 red[16]=gdk_color_forground.red;
 green[16]=gdk_color_forground.green;
 blue[16]=gdk_color_forground.blue;

 gdk_color_blue.red=(guint16)((GNOME_COLOR_PICKER(dircolor_picker)->r)*65535.0);
 gdk_color_blue.green=(guint16)((GNOME_COLOR_PICKER(dircolor_picker)->g)*65535.0);
 gdk_color_blue.blue=(guint16)((GNOME_COLOR_PICKER(dircolor_picker)->b)*65535.0);
	
 red[12]=gdk_color_blue.red;
 green[12]=gdk_color_blue.green;
 blue[12]=gdk_color_blue.blue;

 gdk_color_green.red=(guint16)((GNOME_COLOR_PICKER(execolor_picker)->r)*65535.0);
 gdk_color_green.green=(guint16)((GNOME_COLOR_PICKER(execolor_picker)->g)*65535.0);
 gdk_color_green.blue=(guint16)((GNOME_COLOR_PICKER(execolor_picker)->b)*65535.0);
 
 red[10]=gdk_color_green.red;
 green[10]=gdk_color_green.green;
 blue[10]=gdk_color_green.blue;

 zvt_term_set_color_scheme(ZVT_TERM(term), red, green, blue);

// Leftover from 1st developer... 
// Can't touch this dum dum dum dum

 gnome_config_set_int("col17red", red[17]);
 gnome_config_set_int("col17green", green[17]);
 gnome_config_set_int("col17blue", blue[17]);
 gnome_config_set_int("col16red", red[16]);
 gnome_config_set_int("col16green", green[16]);
 gnome_config_set_int("col16blue", blue[16]);

 gnome_config_set_int("col12red", red[12]);
 gnome_config_set_int("col12green", green[12]);
 gnome_config_set_int("col12blue", blue[12]);
 gnome_config_set_int("col10red", red[10]);
 gnome_config_set_int("col10green", green[10]);
 gnome_config_set_int("col10blue", blue[10]);
 fontstr = strcpy(fontstr,gnome_font_picker_get_font_name(GNOME_FONT_PICKER(fontpicker)));

 zvt_term_set_font_name(ZVT_TERM(term), fontstr);
 gnome_config_set_string("font", fontstr);
 image_file_location = gnome_file_entry_get_full_path(GNOME_FILE_ENTRY(bgimage_combo_entry),1);

 bgimg_transparent  = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(transparent_checkbox));
 gnome_config_set_bool("background_transparent",bgimg_transparent);
 
 swap_del_backspace = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(swap_del_key_checkbox));
 gnome_config_set_bool("swap_del_key",swap_del_backspace);
 
 gnome_config_set_string("background_image",image_file_location);
 zvt_term_set_background(ZVT_TERM(term),image_file_location,bgimg_transparent,4); /* addition since v1.2  */      
 zvt_term_set_del_key_swap(ZVT_TERM(term),swap_del_backspace);
 gnome_config_set_string("terminal_type", gtk_entry_get_text (GTK_ENTRY (term_type_combo_entry) ) );
 
 gnome_config_sync();
 gnome_config_pop_prefix();
}

void on_pref_apply_button_clicked (GtkButton *button, gpointer user_data)
/*
   Just call to the above method
*/
{
   on_pref_ok_button_clicked (button, user_data);
}

void on_dock_leave (GtkWidget *widget, gpointer user_data) {
/*
   I wrote this function because when the gtk_entry is focused, we can focus
   back to the term, which is kinda buggy. The backdraw is that whenever I type
   in the gtk_entry hostname & portname, the mouse has to be within the area of the toolbar
   
*/
        gtk_widget_grab_focus (term);
        gtk_widget_show(term);
}

void on_about_dialog_cancel_clicked (GtkButton  *button, gpointer user_data) {
/*
   This is the handler for OK button from about dialog
*/
  gnome_dialog_close (GNOME_DIALOG (about_dialog));
}

void on_pref_help_button_clicked (GtkButton *button, gpointer user_data) {
/*
   Show the help
*/
   gnome_url_show("ghelp:/usr/share/doc/gnome-telnet-2.4/index.html");
}

void on_ssh_login_ok_button_clicked (GtkButton *button, gpointer user_data)
/*
   If it's click click click click ssssssshhh
*/
{ 
  ssh_user=strdup(gtk_entry_get_text(GTK_ENTRY(ssh_login_combo_entry)));  
  gnome_entry_prepend_history(GNOME_ENTRY(ssh_login_entry),TRUE,ssh_user);  
  gnome_dialog_close (GNOME_DIALOG (ssh_dialog));
  run_program();
}


void on_ssh_login_cancel_button_clicked (GtkButton *button, gpointer user_data)
// If he doesn't want to login...
{
  gnome_dialog_close (GNOME_DIALOG (ssh_dialog));
}

void the_interface_initialize(void)
// Just a bit of initialization... loading config files.. etc
{
  int x;
  
  gnome_config_push_prefix("gnome-telnet/gtelnet/");
  if (gnome_config_get_string("version")==NULL)
  {
      gnome_config_set_string("version", "2.4"); 

      // Telnet configuration read from file..
      
      for (x=0;x < 8;x++)
         gnome_config_set_bool(config_telnet[x],FALSE);

      for (x=8;x < max_telnet_desc;x++)   
         gnome_config_set_string(config_telnet[x],"");
      
       // Reset SSH
      for (x=0;x < 11;x++)
         gnome_config_set_bool(config_ssh[x],FALSE);

      for (x=11;x < max_ssh_desc;x++)   
         gnome_config_set_string(config_ssh[x],"");

      // Yeah RLogin..
      for (x=0;x < 6;x++)
         gnome_config_set_bool(config_rlogin[x],FALSE);

      for (x=6;x < max_rlogin_desc;x++)   
         gnome_config_set_string(config_rlogin[x],"");
      
      gnome_config_set_string("background_image",default_background_location);
      gnome_config_set_bool("background_transparent", FALSE); // -x
      gnome_config_set_bool("swap_del_key", TRUE); // -x
      gnome_config_set_string("terminal_type","xterm");
        

        /* Kenth Andersson part - colors :-) */
	gnome_config_set_int("col17red", 0);
	gnome_config_set_int("col17green", 0);
	gnome_config_set_int("col17blue", 0);
        
	gnome_config_set_int("col16red", 10422);
	gnome_config_set_int("col16green", 65535);
	gnome_config_set_int("col16blue", 6826);

	gnome_config_set_int("col12red", 61548);
	gnome_config_set_int("col12green", 17331);
	gnome_config_set_int("col12blue", 9265);
        
	gnome_config_set_int("col10red", 65535);
	gnome_config_set_int("col10green", 61477);
	gnome_config_set_int("col10blue", 3327);
        /* ---------------------------------- */
	gnome_config_sync();
  }

  red[17]=gnome_config_get_int("col17red");
  green[17]=gnome_config_get_int("col17green");
  blue[17]=gnome_config_get_int("col17blue");

  red[16]=gnome_config_get_int("col16red");
  green[16]=gnome_config_get_int("col16green");
  blue[16]=gnome_config_get_int("col16blue");

  red[12]=gnome_config_get_int("col12red");
  green[12]=gnome_config_get_int("col12green");
  blue[12]=gnome_config_get_int("col12blue");
  
  red[10]=gnome_config_get_int("col10red");
  green[10]=gnome_config_get_int("col10green");
  blue[10]=gnome_config_get_int("col10blue");
  
  fontstr = gnome_config_get_string("font");
  
  image_file_location = gnome_config_get_string("background_image");  
  bgimg_transparent = gnome_config_get_bool("background_transparent");
  swap_del_backspace = gnome_config_get_bool("swap_del_key");
  
  gnome_config_clean_file("gnome-telnet/gtelnet/");
  gnome_config_pop_prefix();
}
