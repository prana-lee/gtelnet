GNOME Telnet v2.4
--------------------------------------------------------------------------------------------------------------
This is an old GNOME telnet/rsh/ssh GUI. Last included in Redhat 7.1 and Mandriva 2007.0 for i586/x86_64

Copyright (C) 2000 the Free Software Foundation
Written by:
 [x] Kenth Andersson <d99kan@du.se> (v1.0)
 [x] Prana <*******@****.***> (v1.1, v1.2, v2.0, v2.1, v2.3, v2.4)

Language translations by:
 [x] Matthias Wimmer <matthias@matthias-wimmer.de> (Deutsch translation)
 [x] Takeshi Aihana <aihana@muc.biglobe.ne.jp> (Japanese translation)
 [x] Grega Bremec <gregab@gbsoft.org> (Slovene translation + helpful patches for v2.3)

RPM packages fixes & patches by:
 [x] Tim Powers <timp@redhat.com> (Redhat specs and patch to documentation location so that it works)
 [x] Vincent Danen <vdanen@mandrakesoft.com> (Mandrake specs)


Description
--------------------------------------------------------------------------------------------------------------
GNOME Telnet is a nice 3-in-1 frontend to the telnet, ssh, and rlogin client

Requirement
--------------------------------------------------------------------------------------------------------------
- autoconf >= v2.13
- automake >= v1.4
- gettext >= v0.10.34
- gtk+ >= v1.20
- gnome-core >= 1.0.55
- X Window 3.3.6
- Linux (of course) - other than Linux we can't give you a tech support

* Optional:
- SSH or OpenSSH (any version)

COMPILING & INSTALLING GTELNET (***** _IMPORTANT_ *****)
--------------------------------------------------------------------------------------------------------------

*** IMPORTANT NOTICE ***
Mandrake 7.02 doesn't have the right gettext package. Please get the lattest gettext package from
ftp://ftp.flash.net/pub/linux/distributions/mandrake/7.1/Mandrake/RPMS/gettext-0.10.35-13mdk.i586.rpm
Users running Mandrake 7.1 and 7.2 and Corporate Server shouldn't have any problems

You have to log in as a root user

** Easy way to compile it: run ./compile_install (you have to be logged in as ROOT)

Hard way compile it: 
1) "./autogen.sh --prefix=/usr"
   In case it doesn't compile, use "./configure --prefix=/usr" instead
2) make
3) strip src/gnome-telnet
4) make install (you have to log in as root)
5) ./install_shared (you have to log in as root)
6) If you want to reduce the size of the binary, type: "strip /usr/bin/gnome-telnet"
   But I wouldn't recommend doing that for debug purpose. However, this v2.0 is pretty stable enough ;)

The executable can be found in "/usr/bin/gnome-telnet"
I have tested this on Redhat Linux 6.2, Mandrake Linux 7.1 with HelixGnome v1.2
If you encounter that you can't compile this on Slackware or Debian, please e-mail me with the detail of the error messages

TODO LIST:
--------------------------------------------------------------------------------------------------------------
- This is almost the final release of Gnome-Telnet
- Check if SSH is installed or not
- I will add compatibility for OpenSSH for ssh-keygen

History (the same as ChangeLog file)
--------------------------------------------------------------------------------------------------------------
6th January 2000 (v2.4) - Prana
- This is only a maintenance release
- Fixed - it now correctly disconnects when you exits from your session
- Fixed - the color preferences
- Clean up code a little tiny bit

4th December 2000 (v2.3) - Prana
- Added command line argument
- Added Slovene translation by Grega Bremec
- Added (from users request) so that you can specify user@some.host.com and the SSH dialog won't show up
- SunOS patch
- Fixed for specifying the cyphertype (Grega Bremec <- very helpful person)
- Updated documentation
- Thanks to Grega Bremec <http://www.gbsoft.org> for the patches for SSH and the Slovene translation
- Thanks to the unknown person (I apologize - I lost your e-mail), but I remember your putenv() thing
  when I read the e-mail so that this gnome-telnet can work in SunOS too
- Thanks to Tim Powers for the fix for documentation location
- Fix Mandrake's version of the documentation location too - how come everybody is changing to /usr/share/doc ?
- Okay this is the really final one ...

22nd October 2000 (v2.2) - Prana
- IMPORTANT: Change in the binary executable from "Gnome_Telnet" to "gnome-telnet"
- Improved documentation
- Added SSH user login dialog - granted requests from numerous users :)
- Added terminal compatibility with aixterm, hpterm, iris-ansi, vt100, and more!
- Added more and more error checking
- Fixed a very tiny bug: color mapping problem that makes the color blurry when running Pine
- Optimized the non-redundant code generated by the IDE - thus the binary executable
  is now smaller than the previous release
- It seems that it's the final stage of the development, it is stable. It has been
  tested with OpenSSH 2.2.0p1, OpenSSH 1.1.2, SSH 2, telnet, and rlogin
- Moved the documentation to /usr/doc/gnome-telnet-2.2 instead of using /usr/share
- Thank you to people who have suggested features thus making this little program works better :)
- Now it's time to move on and start continuing the development of SubNetwork Explorer
- If you are so inclined, please help poor little kids
  by sponsoring them - visit http://www.worldvision.com :-)

30th August 2000 (v2.1) - Prana
- Improved compatibility with SSH2
- Added Deutsch (Germany) translation by Matthias Wimmer <matthias@matthias-wimmer.de>
- Added documentation and help file
- Added history combo box for the host name entry
- Fixed environment problem (now it's set to xterm)
- Fixed color mapping problem
- Fixed a bug in the preferences dialog
- Fixed Mandrake 7.1 installation bug. Now the RPM package will be seperated from Mandrake 7.02
- Fixed memory allocation problem
- Fixed scrollbar problem when resizing/scrolling the window

28th July, 2000 (v2.0) - Prana
- Added support for SSH
- Added support for Rlogin
- Added scrollbar
- Bug in input entry in the toolbar is fixed (ALL)
- Now if you're connected the status bar will display some kind of light
- And other numerous bug fixes and other several enhancements
- Major code cleanup - (it used to be so messy!)
- Thanks to Takeshi Aihana <aihana@muc.biglobe.ne.jp> for adding the Japanese locale

26th July, 2000 (v2.0) - Prana
-Start coding again

2nd June, 2000 (v1.2) - Prana
- Background images is now supported
- Bug in input entry in the preferences dialog is now fixed (ALL)
- And other numerous bug fixes and other several enhancements

31st May, 2000 (v1.1) - Prana
- Enhancement of GTelnet
- All user interface are changed
- Preferences Dialog (for telnet options)
- etc...

27th September 1999 (v1.0) - Kenth Andersson
- First initial public release of GTelnet
DOCUMENTATION
--------------------------------------------------------------------------------------------------------------
Click "Help" button :)


