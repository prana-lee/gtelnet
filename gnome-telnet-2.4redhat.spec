Summary: GNOME Telnet is a 3-in-1 GNOME shell for Telnet, SSH, and RLogin
Name: gnome-telnet
Version: 2.4
Release: 1
URL: http://***.*****.***/
Source0: http://***.*****.***/downloads/%{name}-%{version}.tar.gz
License: GPL
Group: Applications/Internet
BuildRoot: %{_tmppath}/%{name}-root
PreReq: telnet , openssh , krb5-workstation >= 1.2.1-8
ExcludeArch: sparc

%description
Gnome Telnet is a powerful frontend telnet client for GNOME. It not
only has support for telnet, but for ssh and rlogin as well.

%prep
%setup -q

%build
%configure
make

%install
rm -rf $RPM_BUILD_ROOT
%makeinstall

mkdir -p $RPM_BUILD_ROOT%{_datadir}/gnome/apps/Internet/
mkdir -p $RPM_BUILD_ROOT%{_datadir}/pixmaps/gtelnet
mkdir -p $RPM_BUILD_ROOT%{_datadir}/icons

install -m644 share/GTelnet.desktop $RPM_BUILD_ROOT%{_datadir}/gnome/apps/Internet/
install -m644 share/*.png $RPM_BUILD_ROOT%{_datadir}/pixmaps
install -m644 share/*.jpg $RPM_BUILD_ROOT%{_datadir}/pixmaps/gtelnet
install -m644 share/*.xpm $RPM_BUILD_ROOT%{_datadir}/icons

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root)
%doc docs/* AUTHORS COPYING ChangeLog NEWS README 
%{_bindir}/gnome-telnet
%{_datadir}/locale/*/*/*
%{_datadir}/gnome/apps/Internet/GTelnet.desktop
%{_datadir}/pixmaps/*.png
%{_datadir}/pixmaps/gtelnet
%{_datadir}/icons/*

%changelog
* Tue Feb  6 2001 Tim Powers <timp@redhat.com>
- updated Powertools package
- excludearch sparc

* Sat Jan 06 2001 Prana <*****@*****.***>
- Maintenance v2.4

* Mon Dec 04 2000 Prana <*****@*****.***>
- Update to v2.3.
- Thanks to Tim Powers for the update
- Specfile cleanup

* Fri Oct 27 2000 Tim Powers <timp@redhat.com>
- Initial build for Powertools.
- patched doc location so that the full docs can be displayed through help
