/*
 *	GTelnet
 *	by: 	Kenth Andersson <d99kan@du.se> (Initial development)
 *		Prana <*****@*****.***> (v1.1, v1.2, v2.0, v2.1, v2.2, v2.3, v2.4) 
 *
 *	Developed partially with Glade <http://glade.pn.org>
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#define ALL_CHKBOX
#define NO_XPM_PLEASE

#include <gnome.h>
#include <stdio.h>
#include <unistd.h>
#include <zvt/zvtterm.h>
#include <string.h>
#include <stdlib.h>
#include "interface.h"
#include "support.h"

static void read_configuration_file(void)
/* Read/Write Configuration */
{
  options = (char *) malloc(150);
  fontstr=NULL;
  the_interface_initialize();
  if (fontstr==NULL)
  {
     fontstr= (char *) malloc(100);
     fontstr=strcpy(fontstr,"-dec-terminal-medium-r-normal-*-*-140-*-*-c-*-iso8859-1");
  }
}

static void usage(const char *progname) {
/*
   Display the usage
*/
 char *logo = 
"\nGnome Telnet v2.3\n\
Visit http://***.*****.*** for more software!\n\n";
 
 char *usage= 
 "%s options [ssh_user]@host_name [port]\n\
 [options]:\n\
 \t-? : show this help screen\n\
 \t-h : show this help screen\n\
 \ttelnet: open a telnet connection to the targetted host\n\
 \tssh: secure shell connection to the host specified\n\
 \trlogin: remote login ala old BSD style\n\n\
 For example:\n\
 \t\"gnome-telnet ssh user@some_host.com\"\n\
 \t\"gnome-telnet telnet some_host.com\"\n";

 fprintf(stderr,logo);
 fprintf(stderr,usage,progname);
 exit(1);
}

int main (int argc, char *argv[])
/*
   Main program
*/
{
#ifdef ENABLE_NLS
  bindtextdomain (PACKAGE, PACKAGE_LOCALE_DIR);
  textdomain (PACKAGE);
#endif
  if (argc > 1) // if it's >= 2
  {
     if ( !strcmp(argv[1],"/?") || !strcmp(argv[1],"-?") || !strcmp(argv[1],"-h") || !strcmp(argv[1],"--help") ||
     argc < 3 || argc > 4)
        usage(argv[0]);
  }
  gnome_init ("gnome-telnet", VERSION, argc, argv);
  main_window = create_main_window (argc,argv[1],argv[2],argv[3]);
  read_configuration_file(); 
  gtk_widget_show (main_window);
  show_term ();
  gtk_main ();
  gnome_entry_save_history(GNOME_ENTRY(hostname_entry));
  // no mem leak
  free(options);
  free(fontstr);
  return 0;
}
