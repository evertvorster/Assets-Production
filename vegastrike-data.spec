Name: vegastrike-data
Summary: Vegastrike - a free 3D space fight simulator (data files)
Version: 0.3
Release: 1
Copyright: GPL
Group: Amusements/Games
Source: vegastrike-data.tar.gz
URL: http://vegastrike.sourceforge.net
Packager: Daniel Horn <hellcatv@hotmail.com>
BuildRoot: /tmp/vsdata
Prefix: /usr/local
Provides: vegastrike-data
Requires: vegastrike

%description
Vega Strike Celeste - Trade, Fight and Explore the Universe

Vega Strike is a 3d OpenGL GPL Action RPG space sim for Windows/Linux that allows a player to trade and bounty hunt in the spirit of Elite. You start in an old beat up Wayfarer cargo ship, with endless possibility before you and just enough cash to scrape together a life. Yet danger lurks in the space beyond.

this archive contains the data files necessary to play Vegastrike.

%prep
rm -rf $RPM_BUILD_ROOT

%setup -n vegastrike-data

%build
echo "nothing to build"

%install
echo "Installing"
mkdir -p $RPM_BUILD_ROOT/usr/local/doc/vegastrike/
mkdir -p $RPM_BUILD_ROOT/usr/local/man/man1/
mkdir -p $RPM_BUILD_ROOT/usr/local/games/vegastrike/data
mkdir -p $RPM_BUILD_ROOT/usr/local/bin/
cp vegastrike.1 $RPM_BUILD_ROOT/usr/local/man/man1/
cp vsinstall.1 $RPM_BUILD_ROOT/usr/local/man/man1/
cp vssetup.1 $RPM_BUILD_ROOT/usr/local/man/man1/
cp vslauncher.1 $RPM_BUILD_ROOT/usr/local/man/man1/
cp readme.txt $RPM_BUILD_ROOT/usr/local/doc/vegastrike/
cp vsinstall $RPM_BUILD_ROOT/usr/local/bin/
cp -R . $RPM_BUILD_ROOT/usr/local/games/vegastrike/data


%clean
rm -rf $RPM_BUILD_ROOT

%files
%docdir /usr/local/doc/vegastrike
/usr/local/doc/vegastrike/readme.txt
%doc /usr/local/man/man1/vegastrike.1
%doc /usr/local/man/man1/vssetup.1
%doc /usr/local/man/man1/vslauncher.1
%doc /usr/local/man/man1/vsinstall.1
/usr/local/bin/vsinstall
# Normal files
/usr/local/share/vegastrike/data
