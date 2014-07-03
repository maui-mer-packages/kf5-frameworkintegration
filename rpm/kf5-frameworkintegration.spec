# 
# Do NOT Edit the Auto-generated Part!
# Generated by: spectacle version 0.27
# 

Name:       kf5-frameworkintegration

# >> macros
# << macros

Summary:    KDE Frameworks 5 Tier 4 addon with framework integration
Version:    5.0.0
Release:    1
Group:      System/Base
License:    LGPLv2+
URL:        http://www.kde.org
Source0:    %{name}-%{version}.tar.xz
Source100:  kf5-frameworkintegration.yaml
Source101:  kf5-frameworkintegration-rpmlintrc
Requires:   kf5-filesystem
Requires:   oxygen-fonts
Requires(post): /sbin/ldconfig
Requires(postun): /sbin/ldconfig
BuildRequires:  pkgconfig(Qt5Core)
BuildRequires:  pkgconfig(Qt5DBus)
BuildRequires:  pkgconfig(Qt5Xml)
BuildRequires:  pkgconfig(Qt5Network)
BuildRequires:  pkgconfig(Qt5Gui)
BuildRequires:  pkgconfig(Qt5Widgets)
BuildRequires:  pkgconfig(Qt5Concurrent)
BuildRequires:  pkgconfig(Qt5Test)
BuildRequires:  pkgconfig(Qt5X11Extras)
BuildRequires:  kf5-rpm-macros
BuildRequires:  extra-cmake-modules
BuildRequires:  kf5-kconfig-devel
BuildRequires:  kf5-kconfigwidgets-devel
BuildRequires:  kf5-ki18n-devel
BuildRequires:  kf5-kiconthemes-devel
BuildRequires:  kf5-kio-devel
BuildRequires:  kf5-knotifications-devel
BuildRequires:  kf5-kwidgetsaddons-devel
BuildRequires:  oxygen-fonts-devel

%description
Framework Integration is a set of plugins responsible for better integration of
Qt applications when running on a KDE Plasma workspace.

Applications do not need to link to this directly.


%package devel
Summary:    Development files for %{name}
Group:      Development/Libraries
Requires:   %{name} = %{version}-%{release}

%description devel
The %{name}-devel package contains the files necessary to develop applications
that use %{name}.


%prep
%setup -q -n %{name}-%{version}/upstream

# >> setup
# << setup

%build
# >> build pre
%kf5_make
# << build pre



# >> build post
# << build post

%install
rm -rf %{buildroot}
# >> install pre
%kf5_make_install
# << install pre

# >> install post
# << install post

%files
%defattr(-,root,root,-)
%doc COPYING.LIB README.md
%{_kf5_libdir}/libKF5Style.so.*
%{_kf5_datadir}/kf5/infopage/*
%{_kf5_qtplugindir}/kf5/FrameworkIntegrationPlugin.so
%{_kf5_qtplugindir}/platformthemes/KDEPlatformTheme.so
# >> files
# << files

%files devel
%defattr(-,root,root,-)
%{_kf5_includedir}/frameworkintegration_version.h
%{_kf5_includedir}/KStyle
%{_kf5_libdir}/libKF5Style.so
%{_kf5_libdir}/cmake/KF5FrameworkIntegration
# >> files devel
# << files devel