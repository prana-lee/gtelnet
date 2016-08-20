#ifndef __INTERFACE_H
#define __INTERFACE_H
/*
 *	GTelnet
 *	by: 	Kenth Andersson <d99kan@du.se> (Initial development v1.0)
 *		Prana <*****@*****.***> (v1.1, v1.2, v2.0, v2.1, v2.2, v2.3, v2.4)
 *
 *	Developed partially with Glade <http://glade.pn.org>
 */


#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <netdb.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <gnome.h>
#include <zvt/zvtterm.h>
#include "stoerer.h"
#include "support.h"

#define vertbox 0
#define horzbox 1
#define max_telnet_desc 13
#define max_ssh_desc 15
#define max_rlogin_desc 8

  GtkWidget* create_main_window (int x_count,char *x_choice, char *x_hostname, char *x_port);
  GtkWidget* create_property_box (void);
  GtkWidget* create_message_box (gchar *s);
  GtkWidget* create_about_dialog (void);
  GtkWidget* create_ssh_dialog (void);

  void the_interface_initialize(void);
  void getoption(void);
  void show_term(void);

  // Handling events ...  
  void on_term_died (ZvtTerm *term);
  void on_connect_button_clicked              (GtkButton       *button, gpointer         user_data);
  void on_disconnect_button_clicked           (GtkButton       *button, gpointer         user_data);
  void on_preferences_button_clicked          (GtkButton       *button, gpointer         user_data);
  void on_about_button_clicked                (GtkButton       *button, gpointer         user_data);
  void on_pref_ok_button_clicked              (GtkButton       *button, gpointer         user_data);
  void on_pref_help_button_clicked            (GtkButton       *button, gpointer         user_data);
  void on_pref_apply_button_clicked           (GtkButton       *button, gpointer 	 user_data);
  void on_dock_leave 			      (GtkWidget       *button, gpointer 	 user_data);
  void on_about_dialog_cancel_clicked         (GtkButton       *button, gpointer         user_data);
  void on_ssh_login_ok_button_clicked         (GtkButton       *button, gpointer         user_data);
  void on_ssh_login_cancel_button_clicked     (GtkButton       *button, gpointer         user_data);
  
  // For handling with configuration files...
  void setarg(char *);
  void set_string_opt(char *flag, char *s);
  void set_direct_string_opt(char *flag, char *value);
  void set_flag_opt(char *flag, char *s);
  void setbutton(GtkWidget *button, gchar *s);
  void setbutton_string(GtkWidget *checkbox, GtkWidget *entry, char *s);
  void setaccordingto_string(GtkWidget *checkbox, GtkWidget *entry, gchar *s);
  void setaccordingto(GtkWidget *obj, gchar *s);

  
  int connection_type;
  int ssh_encrypt_type;
  gboolean bgimg_transparent;
  gboolean swap_del_backspace;
  GtkWidget *bgcolor_picker;
  GtkWidget *fgcolor_picker;
  GtkWidget *execolor_picker;
  GtkWidget *dircolor_picker;
  GtkWidget *fontpicker;
  GtkWidget *bgimage_fileentry;
  GtkWidget *transparent_checkbox;
  GtkWidget *bgimage_combo_entry;
  GtkWidget *edit_ssh_key_entry;

  GtkWidget *main_window;
  GtkWidget *about_dialog;
  GtkWidget *property_box;
  GtkWidget *ssh_keygen;  
  GtkWidget *term;
  GtkWidget *term2;

  GdkColor	gdk_color_forground;
  GdkColor	gdk_color_background;
  GdkColor	gdk_color_green;
  GdkColor	gdk_color_blue;

  GtkWidget *connect_via;
  GtkWidget *main_window;
  GtkWidget *hostname_entry;
  GtkWidget *port_entry;
  GtkWidget *tmp_toolbar_icon;
  GtkWidget *app_statusbar;


/* Telnet options */
  GtkWidget *tos_entry;  
  GtkWidget *initchar_entry;  
  GtkWidget *atype_entry;
  GtkWidget *realm_entry;

  GtkWidget *atype_entry;
  GtkWidget *tos_entry; 
  GtkWidget *realm_entry;
  GtkWidget *initchar_entry;
  GtkWidget *tracefiles_entry; // the gnome file entry
  GtkWidget *tracefile_entry; // the input
  GtkWidget *telnet_option;

/* SSH Options */
  GtkWidget *ssh_encryption_option;
  GtkWidget *ssh_encryption_option_menu;  
  GtkWidget *ssh_esc_char_entry;
  GtkWidget *rsa_identity_entry;
  GtkWidget *rsa_identity;
  GtkWidget *ssh_debug_level;
  GtkWidget *swap_del_key_checkbox;

/* RLogin */
  GtkWidget *rlogin_ticket_entry;
  GtkWidget *init_rlogin_esc_entry;
  GtkWidget *hostname_combo_entry;
  // v2.2
  GtkWidget *term_type_entry;
  GtkWidget *term_type_combo_entry;
  GtkWidget *ssh_login_entry;
  GtkWidget *ssh_login_combo_entry;
  GtkWidget *ssh_dialog;
  
  char *options; 		/* options for telnet */
  char *term_environ;		/* term environment variable */
  char *fontstr; 		/* Font name for the term -- Kenth -- unchanged*/
  char *image_file_location; 	/* Background image for Telnet */
  char *terminal_type;		/* Set the terminal type */
  char **pargv;
  
  int run_option; // if used within cmd-line

  gchar *host; /* hostname */
  gchar *port; /* port number */
  gchar *ssh_user; /* SSH user */
  char *arguments[16]; /* argument */
  int n_counter;
 
  struct opt_widget
  {
   GtkWidget *widget;
   char *name;
   gchar *desc;
  };

 struct terminal_colors_type
 {
     gushort red;
     gushort green;
     gushort blue;
 };

#endif
